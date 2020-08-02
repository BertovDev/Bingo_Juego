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

    /*cargarMatrizDeCeros(matrizJugador, numeroDeCartones);
  cargarMatrizDeCeros(matrizPc, numeroDeCartones);*/

    cargarMatrizAleatoriaSinRepetir(matrizPc, numeroDeCartones);

    /*Se elige el tipo de carton*/
    tipoDeCarton(matrizJugador, numeroDeCartones);

    /*Se muetra la matriz del jugador y de la pc ---------> El de la pc se muestra
   * solo para testear que esta bien*/
    limpiarPantalla();
    mostrarMatriz(matrizJugador, numeroDeCartones);
    printf("-------------------Cartones PC:-----------------------\n");
    mostrarMatriz(matrizPc, numeroDeCartones);

    return 0;
}
