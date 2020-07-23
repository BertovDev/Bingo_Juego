#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "procedimientos.h"
int cuantosCartones();
void tipoDeCarton(int m[][RENGLON][COLUMNA],int opci);
int main()
{
    int numeroDeCartones=0;
    srand(time(NULL));
    datosJugador();
       numeroDeCartones = cuantosCartones();

   int matrizJugador[numeroDeCartones][3][5];//MATRIZ DEL JUGADOR

   cargarMatrizDeCeros(matrizJugador,numeroDeCartones);

   tipoDeCarton(matrizJugador,numeroDeCartones);

   mostrarMatriz(matrizJugador,numeroDeCartones);
    return 0;
}
