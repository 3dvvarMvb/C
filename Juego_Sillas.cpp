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

const char *fifo_path1 = "./my_fifo1"; // Escritura hacia el observador
const char *fifo_path2 = "./my_fifo2"; // Lectura desde el observador

// Función para generar un número aleatorio en un rango dado [min, max]
int generarNumeroAleatorio(int min, int max) {
    return min + rand() % (max - min + 1);
}

int main() {
    srand(time(NULL)); // Inicializar semilla aleatoria

    int n; 
    cout << "Ingrese el número de jugadores: ";
    cin >> n;

    // Crear los FIFOs si no existen
    if (mkfifo(fifo_path1, 0666) == -1 && errno != EEXIST) {
        cerr << "Error al crear FIFO para escritura: " << strerror(errno) << endl;
        exit(EXIT_FAILURE);
    }

    if (mkfifo(fifo_path2, 0666) == -1 && errno != EEXIST) {
        cerr << "Error al crear FIFO para lectura: " << strerror(errno) << endl;
        exit(EXIT_FAILURE);
    }

    // Abrir FIFO para escritura
    int fd_write = open(fifo_path1, O_WRONLY);
    if (fd_write == -1) {
        cerr << "Error al abrir FIFO para escritura (my_fifo1): " << strerror(errno) << endl;
        exit(EXIT_FAILURE);
    }
    cout << "FIFO para escritura (my_fifo1) abierto correctamente." << endl;

    // Escribir el número de jugadores
    if (write(fd_write, &n, sizeof(n)) != sizeof(n)) {
        cerr << "Error al escribir el número de jugadores" << endl;
        close(fd_write);
        exit(EXIT_FAILURE);
    }
    cout << "Número de jugadores escrito en FIFO (my_fifo1)." << endl;

    // Creación de procesos hijos
    pid_t pids[n];
    pids[0] = getpid();  // El padre

    // Voto del padre
    int voto = generarNumeroAleatorio(1, n);
    if (write(fd_write, &voto, sizeof(voto)) != sizeof(voto)) {
        cerr << "Error al escribir el voto del padre" << endl;
        close(fd_write);
        exit(EXIT_FAILURE);
    }
    cout << "Voto del padre escrito en FIFO (my_fifo1)." << endl;

    for (int i = 1; i < n; i++) {
        pid_t pid = fork();
        if (pid < 0) {
            cerr << "Error en fork" << endl;
            exit(1);
        } else if (pid == 0) { // Proceso hijo
            // Generar un voto aleatorio y escribir en el FIFO
            voto = generarNumeroAleatorio(1, n);
            int fd_child_write = open(fifo_path1, O_WRONLY);

            if (fd_child_write == -1) {
                cerr << "Error al abrir FIFO para escritura desde el hijo: " << strerror(errno) << endl;
                exit(EXIT_FAILURE);
            }
            cout << "FIFO para escritura (my_fifo1) abierto correctamente por el hijo (PID: " << getpid() << ")." << endl;
            
            if (write(fd_child_write, &voto, sizeof(voto)) != sizeof(voto)) {
                cerr << "Error al escribir el voto del hijo" << endl;
                close(fd_child_write);
                exit(EXIT_FAILURE);
            }
            cout << "Voto del hijo (PID: " << getpid() << ") escrito en FIFO (my_fifo1)." << endl;

            close(fd_child_write);
            cout << "FIFO para escritura (my_fifo1) cerrado por el hijo (PID: " << getpid() << ")." << endl;
            break;

        } else { // Proceso padre
            pids[i] = pid;
        }
    }

    close(fd_write); // Cerrar escritura
    cout << "FIFO para escritura (my_fifo1) cerrado por el padre." << endl;

    // Leer al jugador con más votos desde el observador
    if(pids[0] == getpid()){
    int jugadorConMasVotos;
    int fd_read = open(fifo_path2, O_RDONLY);

    if (fd_read == -1) {
        cerr << "Error al abrir my_fifo2: " << strerror(errno) << endl;
        exit(EXIT_FAILURE);
    }
    cout << "FIFO para lectura abierto correctamente." << endl;

    if (read(fd_read, &jugadorConMasVotos, sizeof(jugadorConMasVotos)) != sizeof(jugadorConMasVotos)) {
        cerr << "Error al leer el jugador con más votos" << endl;
        close(fd_read);
        exit(EXIT_FAILURE);
    }
    cout << "Jugador con más votos leído desde FIFO (my_fifo2): " << jugadorConMasVotos << endl;

    // Leer el número actualizado de jugadores restantes
    if (read(fd_read, &n, sizeof(n)) != sizeof(n)) {
        cerr << "Error al leer el número de jugadores restantes" << endl;
        close(fd_read);
        exit(EXIT_FAILURE);
    }
    cout << "Número de jugadores restantes leído desde FIFO (my_fifo2): " << n << endl;

    close(fd_read); // Cerrar lectura
    cout << "FIFO para lectura (my_fifo2) cerrado." << endl;
    
    }
    exit(0);

    // Esperar a que terminen todos los hijos
    for (int i = 1; i < n; i++) {
        waitpid(pids[i], NULL, 0);
    }

    return 0;
}