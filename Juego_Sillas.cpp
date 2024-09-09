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
    // Inicializar la semilla aleatoria con la hora actual
    srand(time(NULL));

    int n; // Número de jugadores
    cout << "Ingrese el número de jugadores: ";
    cin >> n;

    // Crear el FIFO si no existe
    mkfifo(fifo_path1, 0666);
    mkfifo(fifo_path2, 0666);

    // Abrir el FIFO para escritura y cerrar lectura
    int fdwrite = open(fifo_path1, O_WRONLY);
    int fdread = 

    // Escribir el número de jugadores
    write(fdwrite, &n, sizeof(n));

    // Creación de procesos hijos
    pid_t pids[n];
    pids[0] = getpid();  // El padre
    
    //voto del padre
    int voto = generarNumeroAleatorio(1, n);
    write(fdwrite, &voto, sizeof(voto));

    for (int i = 1; i < n; i++) {
        pid_t pid = fork();  // Crear un nuevo proceso
        if (pid < 0) {
            cerr << "Error en fork" << endl;
            exit(1);
        } 
        else if (pid == 0) { // Proceso hijo
            // Generar un voto aleatorio y escribir en el FIFO
            int voto = generarNumeroAleatorio(1, n);
            write(fdwrite, &voto, sizeof(voto));
            exit(0);  // Importante para que el hijo termine aquí
        } 
        else {// Proceso padre
            // Generar un voto aleatorio y escribir en el FIFO
            pids[i] = pid;  // Guardar el PID del proceso hijo en el arreglo
        }
    }

    // Esperar a que todos los hijos terminen
    for (int i = 1; i < n; i++) {
        waitpid(pids[i], NULL, 0);
    }

    // Cerrar el descriptor de archivo
    close(fdwrite);

    

    // Eliminar el FIFO después de usarlo
    unlink(fifo_path1);

    return 0;
}