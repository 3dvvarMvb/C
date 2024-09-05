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

#define FIFO_PATH "/tmp/mi_fifo"

using namespace std;

volatile int votos[26];

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

    int time = generarNumeroAleatorio(n - 1, n);

    // Creación de procesos
    pid_t pids[n];
    pids[0] = getpid();

    for (int i = 1; i < n; i++) {
        pid_t pid = fork();  // Crear un nuevo proceso

        if (pid < 0) {
            // Error en la creación del proceso
            cerr << "Error en fork" << endl;
            exit(1);
        } 
        else if (pid == 0) {
            // Este bloque es ejecutado solo por el proceso hijo
            cout << "Soy el proceso hijo " << i + 1 << " con PID " << getpid() << endl;
            
            // Realizar una tarea específica (por ejemplo, dormir un segundo)
            sleep(1);
            exit(0);
        } 
        else {
            // Este bloque es ejecutado solo por el proceso padre
            cout << "Soy el proceso padre con PID " << getpid() << endl;
            pids[i] = pid;  // Guardar el PID del proceso hijo en el arreglo
        }
    }

    // Votos de los jugadores
    for (int i = 0; i < time; i++) {
        int votacion = generarNumeroAleatorio(0, n - 1);
        votos[i] = votacion;
        sleep(2);
        for (int i = 0; i < n; i++)
        {
            cout<<votos[i]<<" "<<"voto: "<<i<<" Votador: "<<getpid()<<endl;
        }
        
    }

    return 0;
}
