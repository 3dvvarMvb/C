#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <time.h>
#include <sys/mman.h> 
#include <unistd.h>   
#include <sys/stat.h> 

#define PIPE_NAME_READ "votos_pipe"

typedef struct {
    int N;
    int jugador_mas_votado;
} DatosCompartidos;

void llenar_con_ceros(int votos[], int N) {
    for (int i = 0; i < N; i++) {
        votos[i] = 0;
    }
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
    DatosCompartidos data;

    // Crear la memoria compartida.
    shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);
    if (shm_fd == -1) {
        perror("Error al abrir la memoria compartida");
        exit(1);
    }

    // Establecer el tamaño de la memoria compartida.
    ftruncate(shm_fd, sizeof(DatosCompartidos));

    // Mapear la memoria compartida.
    ptr = mmap(0, sizeof(DatosCompartidos), PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if (ptr == MAP_FAILED) {
        perror("Error al mapear la memoria compartida");
        exit(1);
    }

    data.N = ptr->N;

    // Bucle del observador: mientras queden jugadores
    while(data.N > 1){    
        int votos[data.N]; // Inicializamos el conteo de votos
        int voto;

        llenar_con_ceros(votos, data.N);

        printf("numero jugadores: %d\n", data.N);

        // Leer los votos desde el pipe
        printf("Esperando votos...\n");

        for (int i = 0; i < data.N; i++) {
            read(pipe_fd, &voto, sizeof(int));
            votos[voto]++; // Contamos el voto
        }

        // Determinar el jugador más votado
        int max_votos = 0, jugador_eliminado = -1;
        for (int i = 0; i < data.N; i++) {
            if (votos[i] > max_votos) {
                max_votos = votos[i];
                jugador_eliminado = i + 1; // Mantén el +1 si el índice de jugadores empieza en 1
            }
        }

        printf("El jugador %d fue el más votado y será eliminado.\n", jugador_eliminado);

        data.jugador_mas_votado = jugador_eliminado;

        // Actualizar la memoria compartida
        ptr->jugador_mas_votado = data.jugador_mas_votado;

        // Actualizar el valor de N después de eliminar un jugador
        data.N--;
        ptr->N = data.N;
    }

    close(pipe_fd);

    // Limpiar
    munmap(ptr, sizeof(int));
    close(shm_fd);

    printf("¡Tenemos un ganador!\n");
    return 0;
}