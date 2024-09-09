#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <cstring>
#include <fcntl.h>
#include <sys/stat.h>
#include <cerrno>

using namespace std;

const char *fifo_path1 = "./my_fifo1"; //Escritura
const char *fifo_path2 = "./my_fifo2"; //Lectura

// Función para generar un número aleatorio en un rango dado [min, max]
int generarNumeroAleatorio(int min, int max) {
    return min + rand() % (max - min + 1);
}

int main() {
    //inicializar la semilla aleatoria con la hora actual
    srand(time(NULL));

    //numero de jugadores
    int n; 
    cout << "Ingrese el número de jugadores: ";
    cin >> n;

    //crear el FIFO si no existe
    mkfifo(fifo_path1, 0666);
    mkfifo(fifo_path2, 0666);

    //abrir el FIFO para escritura 
    int fd[2];
    fd[0]=open(fifo_path1, O_WRONLY);
    
    //escribir el número de jugadores
    write(fd[0], &n, sizeof(n));

    //creación de procesos hijos
    pid_t pids[n];
    pids[0] = getpid();  // El padre
    
    //voto del padre
    int voto = generarNumeroAleatorio(1, n);
    write(fd[0], &voto, sizeof(voto));

    for (int i = 1; i < n; i++) {
        pid_t pid = fork();  // Crear un nuevo proceso
        if (pid < 0) {
            cerr << "Error en fork" << endl;
            exit(1);
        } 
        else if (pid == 0) { // Proceso hijo
            // Generar un voto aleatorio y escribir en el FIFO
            int voto = generarNumeroAleatorio(1, n);
            write(fd[0], &voto, sizeof(voto));
        } 
        else {// Proceso padre
            // Generar un voto aleatorio y escribir en el FIFO
            pids[i] = pid;  // Guardar el PID del proceso hijo en el arreglo
        }
    }
    //cierro escritura
    close(fd[0]);

    //se lee al jugador con mas votos desde el observador
    int jugadorConMasVotos;
    fd[1] = open(fifo_path2, O_RDONLY);
    read(fd[1], &jugadorConMasVotos, sizeof(jugadorConMasVotos));

    // Esperar a que todos los hijos terminen
    for (int i = 1; i < n; i++) {
        waitpid(pids[i], NULL, 0);
    }

    if(pids[jugadorConMasVotos] == getpid()){
        execlp("./Se_Amurra","",NULL);
    };
    
    // Eliminar el FIFO después de usarlo
    unlink(fifo_path1);
    unlink(fifo_path2);

    return 0;
}