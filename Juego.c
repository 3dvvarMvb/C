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

#define PIPE_NAME_WRITE "votos_pipe"

typedef struct {
    int N;
    pid_t jugadores[100];  // Arreglo de PIDs de los jugadores
    pid_t pid_mas_votado;
} DatosCompartidos;

void Crear_jugadores(int N, pid_t jugadores[], pid_t pid_padre) {
    for (int i = 1; i < N; i++) {
        pid_t jugador = fork();

        if (pid_padre == getpid()) {
            jugadores[i] = jugador;  // Crear un proceso por cada jugador
            printf("Jugador %d creado (PID: %d)\n", i + 1, jugador);
        } else {
            break;  // Salir del bucle en los hijos
        }
    }
}

void votar(int pipe_fd, int N) {
    srand(time(NULL) + getpid());
    int voto = rand() % N;  // Votar por uno de los jugadores restantes
    write(pipe_fd, &voto, sizeof(int));
}

int main() {
    unlink(PIPE_NAME_WRITE);

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

    // Capturar valor desde la consola
    int N;
    printf("Introduce la cantidad de jugadores: ");
    scanf("%d", &N);
    ptr->N = N;

    mkfifo(PIPE_NAME_WRITE, 0666);
    int pipe_fd = open(PIPE_NAME_WRITE, O_WRONLY);

    pid_t pid_padre = getpid();
    Crear_jugadores(N, ptr->jugadores, pid_padre);

    while (ptr->N > 1) {
        votar(pipe_fd, ptr->N);

        sleep(2);  // Aseguramos que todos los jugadores voten

        // Leer el PID del jugador más votado desde la memoria compartida
        pid_t pid_eliminado = ptr->pid_mas_votado;

        // Si el jugador actual es el que fue votado, se termina
        if (getpid() == pid_eliminado) {
            execl("./Se_Amurra", "", NULL);
            exit(0);
        }

        // Esperar para la próxima ronda
        sleep(2);
    }

    close(pipe_fd);

    // Limpiar
    munmap(ptr, sizeof(DatosCompartidos));
    close(shm_fd);

    if (getpid() == pid_padre) {
        printf("¡Soy el ganador, PID: %d!\n", getpid());
    }

    return 0;
}
