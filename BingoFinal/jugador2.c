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

struct JugadorPc{
    int numDeCartones;
    Carton cartonPc[NUMCARTONES];
};
//-------CONSTRUCTOR--------
Jugador2 cargarJugadorPc(int cant){
    Jugador2 j2 = malloc(sizeof(struct JugadorPc));
    j2->numDeCartones = cant;
    for(int i = 0 ;i<cant;i++){
        j2->cartonPc[i] = cargarCarton(1);
    }

    return j2;
}

//---------MOSTRAR----------
void mostrarJugador2(Jugador2 j2){
    printf("-------------------Cartones Jugador PC-----------------------\n");
    mostrarCartones(j2->cartonPc , j2->numDeCartones);
}
//-----------GETS-----------

//-----------SETS-----------

//-----------OTROS-----------
