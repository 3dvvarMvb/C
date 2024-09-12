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
#include <map>
#include <climits>

using namespace std;

const char *fifo_path1 = "./my_fifo1"; //Escritura
const char *fifo_path2 = "./my_fifo2"; //Lectura

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

int main(){
    int fd[2];
    int voto;
    int n;

    // Crear el FIFO si no existe
    mkfifo(fifo_path1, 0666);
    mkfifo(fifo_path2, 0666);

    // Abrir el FIFO en modo lectura
    fd[1] = open(fifo_path2, O_RDONLY);

    // Leer el número de jugadores desde el FIFO
    read(fd[1], &n, sizeof(n));

    // Inicializar el mapa de votos
    map<int, int> votos = inicializarMapa(n);

    // Leer los votos del FIFO
    for (int i = 0; i < n ; i++) {  
        read(fd[1], &voto, sizeof(voto));
        votos[voto]++;
    }

    // Encontrar el jugador con la mayor cantidad de votos
    int jugadorConMasVotos = encontrarMaximo(votos);

    // Mostrar el resultado
    if (jugadorConMasVotos != -1) {
        cout << "El jugador con la mayor cantidad de votos es: Jugador " << jugadorConMasVotos << endl;
    }

    // Cierro lectura
    close(fd[1]);

    // Escribir jugador con mas votos 
    fd[0] = open(fifo_path1, O_WRONLY);
    write(fd[0],&jugadorConMasVotos, sizeof(jugadorConMasVotos));
    
    n--;//

    write(fd[0],&n, sizeof(n));

    //cierro escritura
    close(fd[0]);

    unlink(fifo_path1);
    unlink(fifo_path2);

    exit(0);
    return 0;
}