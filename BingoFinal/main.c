#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
//----------------
#define RENGLON 3
#define COLUMNA 5
#define NUMCARTONES 3
//----------------
#include "jugador.h"
#include "cartones.h"
#include "funcionesYProcedimientos.h"
#include "jugador2.h"

int main()
{
    srand(time(NULL));
    Jugador1 j1 = cargarJugador();
    Jugador2 j2 = cargarJugadorPc(getNumDeCartones(j1));
    mostrarJugador1(j1);
    mostrarJugador2(j2);

    return 0;
}
