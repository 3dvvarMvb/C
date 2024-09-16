#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <time.h>
#include <sys/mman.h>
#include <sys/types.h>

#define PIPE_NAME_READ "votos_pipe"

typedef struct {
    int N;
    pid_t jugadores[100];  // Arreglo de PIDs de los jugadores
    pid_t pid_mas_votado;
} DatosCompartidos;

void llenar_con_ceros(int votos[], int N) {
    for (int i = 0; i < N; i++) {
        votos[i] = 0;
    }
}

void eliminar_jugador(DatosCompartidos *ptr, int jugador_eliminado) {
    // Eliminar el jugador del arreglo de PIDs
    for (int i = jugador_eliminado; i < ptr->N - 1; i++) {
        ptr->jugadores[i] = ptr->jugadores[i + 1];
    }
    ptr->N--;  // Reducir el número de jugadores restantes
}

int main() {
    // Eliminar los FIFOs si ya existen
    unlink(PIPE_NAME_READ);
    
    // Crear los FIFOs
    mkfifo(PIPE_NAME_READ, 0666);

    int pipe_fd = open(PIPE_NAME_READ, O_RDONLY);

    const char *name = "/mi_memoria_compartida";
    int shm_fd;
    DatosCompartidos *ptr;

    // Crear la memoria compartida
    shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);
    if (shm_fd == -1) {
        perror("Error al abrir la memoria compartida");
        exit(1);
    }

    // Establecer el tamaño de la memoria compartida
    ftruncate(shm_fd, sizeof(DatosCompartidos));

    // Mapear la memoria compartida
    ptr = mmap(0, sizeof(DatosCompartidos), PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if (ptr == MAP_FAILED) {
        perror("Error al mapear la memoria compartida");
        exit(1);
    }

    while (ptr->N > 1) {
        int votos[ptr->N];  // Inicializamos el conteo de votos
        int voto;

        llenar_con_ceros(votos, ptr->N);

        printf("Número de jugadores: %d\n", ptr->N);

        // Leer los votos desde el pipe
        printf("Esperando votos...\n");

        for (int i = 0; i < ptr->N; i++) {
            read(pipe_fd, &voto, sizeof(int));
            votos[voto]++;  // Contamos el voto
        }

        // Determinar el jugador más votado
        int max_votos = 0, jugador_eliminado = -1;
        for (int i = 0; i < ptr->N; i++) {
            if (votos[i] > max_votos) {
                max_votos = votos[i];
                jugador_eliminado = i;  // Índice del jugador eliminado
            }
        }

        printf("El jugador con índice %d será eliminado.\n", jugador_eliminado);

        // Guardar el PID del jugador eliminado en la memoria compartida
        ptr->pid_mas_votado = ptr->jugadores[jugador_eliminado];

        // Eliminar el jugador del arreglo
        eliminar_jugador(ptr, jugador_eliminado);

        // Esperar un tiempo para que los jugadores lean el PID y eliminen el proceso
        sleep(2);
    }

    close(pipe_fd);

    // Limpiar
    munmap(ptr, sizeof(DatosCompartidos));
    close(shm_fd);

    printf("¡Tenemos un ganador!\n");
    return 0;
}
