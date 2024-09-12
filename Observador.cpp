#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <cerrno>
#include <map>
#include <climits>
#include <cstring>

using namespace std;

const char *fifo_path1 = "./my_fifo1"; // Lectura de los votos
const char *fifo_path2 = "./my_fifo2"; // Escritura del resultado

// Función para inicializar el mapa con n jugadores, todos con un conteo de 0 votos
map<int, int> inicializarMapa(int n) {
    map<int, int> jugadores;  
    for (int i = 1; i <= n; ++i) {
        jugadores[i] = 0;  
    }
    return jugadores;  
}

// Función para encontrar la clave con el valor más grande en un mapa
int encontrarMaximo(const map<int, int> &jugadores) {
    if (jugadores.empty()) {
        cerr << "El mapa está vacío." << endl;
        return -1; 
    }

    // Valores mínimos
    int claveMaxima = -1;  
    int valorMaximo = INT_MIN;  

    // Recorremos el mapa para encontrar el valor máximo
    for (const auto &par : jugadores) {
        if (par.second > valorMaximo) {
            valorMaximo = par.second;  
            claveMaxima = par.first;  
        }
    }

    return claveMaxima;  // Retornamos la clave con el valor máximo de votos
}

int main() {
    int fd_read, fd_write;
    int voto;
    int n;

    // Crear los FIFOs si no existen
    if (mkfifo(fifo_path1, 0666) == -1 && errno != EEXIST) {
        cerr << "Error al crear FIFO para lectura (my_fifo1): " << strerror(errno) << endl;
        exit(EXIT_FAILURE);
    }

    if (mkfifo(fifo_path2, 0666) == -1 && errno != EEXIST) {
        cerr << "Error al crear FIFO para escritura (my_fifo2): " << strerror(errno) << endl;
        exit(EXIT_FAILURE);
    }

    // Abrir el FIFO para lectura
    fd_read = open(fifo_path1, O_RDONLY);
    if (fd_read == -1) {
        cerr << "Error al abrir FIFO para lectura (my_fifo1): " << strerror(errno) << endl;
        exit(EXIT_FAILURE);
    }
    cout << "FIFO para lectura (my_fifo1) abierto correctamente." << endl;

    // Leer el número de jugadores desde el FIFO
    if (read(fd_read, &n, sizeof(n)) != sizeof(n)) {
        cerr << "Error al leer el número de jugadores" << endl;
        close(fd_read);
        exit(EXIT_FAILURE);
    }
    cout << "Número de jugadores leído desde FIFO (my_fifo1): " << n << endl;

    // Inicializar el mapa de votos
    map<int, int> votos = inicializarMapa(n);

    // Leer los votos del FIFO
    for (int i = 0; i < n; i++) {
        if (read(fd_read, &voto, sizeof(voto)) != sizeof(voto)) {
            cerr << "Error al leer el voto" << endl;
            close(fd_read);
            exit(EXIT_FAILURE);
        }
        votos[voto]++;
        cout << "Voto leído desde FIFO (my_fifo1): " << voto << endl;
    }

    close(fd_read); // Cerrar el FIFO de lectura
    cout << "FIFO para lectura (my_fifo1) cerrado." << endl;

    // Encontrar el jugador con más votos
    int jugadorConMasVotos = encontrarMaximo(votos);

    // Abrir el FIFO para escritura
    fd_write = open(fifo_path2, O_WRONLY);
    if (fd_write == -1) {
        cerr << "Error al abrir FIFO para escritura (my_fifo2): " << strerror(errno) << endl;
        exit(EXIT_FAILURE);
    }
    cout << "FIFO para escritura (my_fifo2) abierto correctamente." << endl;

    // Escribir el jugador con más votos en el FIFO
    if (write(fd_write, &jugadorConMasVotos, sizeof(jugadorConMasVotos)) != sizeof(jugadorConMasVotos)) {
        cerr << "Error al escribir el jugador con más votos" << endl;
        close(fd_write);
        exit(EXIT_FAILURE);
    }
    cout << "Jugador con más votos escrito en FIFO (my_fifo2): " << jugadorConMasVotos << endl;

    // Escribir el número actualizado de jugadores en el FIFO
    n--;  // Restar uno al número de jugadores
    if (write(fd_write, &n, sizeof(n)) != sizeof(n)) {
        cerr << "Error al escribir el número de jugadores restantes" << endl;
        close(fd_write);
        exit(EXIT_FAILURE);
    }
    cout << "Número de jugadores restantes escrito en FIFO (my_fifo2): " << n << endl;

    close(fd_write); // Cerrar el FIFO de escritura
    cout << "FIFO para escritura (my_fifo2) cerrado." << endl;

    return 0;
}