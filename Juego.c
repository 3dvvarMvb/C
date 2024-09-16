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

#define PIPE_NAME_WRITE "votos_pipe"

typedef struct {
    int N;
    int jugador_mas_votado;
    pid_t pid_mas_votado;

} DatosCompartidos;

void Crear_jugadores(int N, pid_t jugadores[], pid_t pid_padre) {
    for (int i = 1; i < N; i++) {
        pid_t jugador = fork();

        if (pid_padre == getpid()) {
            jugadores[i] = jugador;  // Crear un proceso por cada jugador
            printf("Jugador %d creado (PID: %d)\n", i + 1, jugador);

        } 
        else {
            break;
        }
    }
}

void votar(int pipe_fd, int N) {
    srand(time(NULL) + getpid());
    int voto = rand() % N;

    write(pipe_fd, &voto, sizeof(int));
}

int main() {
    unlink(PIPE_NAME_WRITE);

    const char *name = "/mi_memoria_compartida";
    int shm_fd;
    DatosCompartidos *ptr;
    DatosCompartidos data;

    // Capturar valor desde la consola.
    printf("Introduce la cantidad de jugadores: ");
    scanf("%d", &data.N);

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

    // Escribir el valor ingresado en la memoria compartida.
    ptr->N = data.N;

    printf("Valor %d escrito en la memoria compartida.\n", ptr->N);

    mkfifo(PIPE_NAME_WRITE, 0666);
    int pipe_fd = open(PIPE_NAME_WRITE, O_WRONLY);

    pid_t jugadores[data.N];
    jugadores[0]=getpid();
    
    Crear_jugadores(data.N,jugadores,jugadores[0]);

    while (data.N > 1) {
        votar(pipe_fd,data.N);

        sleep(2);

        data.jugador_mas_votado = ptr->jugador_mas_votado;

        ptr->pid_mas_votado = jugadores[(data.jugador_mas_votado)-1];

        data.pid_mas_votado=ptr->pid_mas_votado;

        if(getpid() == data.pid_mas_votado){
            execlp("./Se_Amurra", "", NULL);
            exit(0);
        }
        data.N = (data.N)-1;
        ptr->N = data.N;
    }

    //printf("Jugador ganador de pid: %d\n", getpid());
    
    close(pipe_fd);

    //printf("El juego ha terminado.\n");

    // Limpiar.
    munmap(ptr, sizeof(int));
    close(shm_fd);

    return 0;
}