#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "procedimientos.c"
#include "procedimientos.h"

int main() {
    srand(time(NULL));

    datosJugador();
    int numeroDeCartones = cuantosCartones();
    int matrizJugador[numeroDeCartones][3][5];  // MATRIZ DEL JUGADOR
    int matrizPc[numeroDeCartones][3][5];       // Matriz de la PC

    /*Carga de matriz, tanto del jugador como de la PC*/

    cargarMatrizDeCeros(matrizJugador, numeroDeCartones);

    /*Se elige el tipo de carton*/
    tipoDeCarton(matrizJugador, numeroDeCartones);

    /*Se muetra la matriz del jugador*/
    limpiarPantalla();
    mostrarMatriz(matrizJugador, numeroDeCartones);

    return 0;
}
