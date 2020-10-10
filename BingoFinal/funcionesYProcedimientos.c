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
int cuantosCartones()
{
    int opci=0;
    system("cls");
    printf("\n------Seleccion de cartones------\n");
    printf("\nCon cuantos cartones te gustaria jugar?\n Solo podes elegir 1, 2 o 3...");
    scanf("%d",&opci);
    while((opci>3)||(opci<1))
    {
        printf("\n!!!!!  ERROR NUMERO NO VALIDO ELIJA OTRO... \n");
        printf(" .....CON CUANTOS CARTONES QUIERES JUGAR? CON 1 CON 2 O 3 \n");
        scanf("%d",&opci);
    }
    return opci;
}

int tipoDeCarton()
{
    int opci1;
    printf("\nQue tipo de cartones desea usar ?\n");
    printf(" 1 : Comprar cartones aleatorios\n");
    printf(" 2 : Comprar cartones personalizados\n");
    scanf("%d",&opci1);
    while ((opci1<1)||(opci1>2)){
        printf("!!!!!!RESPUETA NO VALIDA INGRESE UN NUMERO DE LAS OPCIONES");
        printf("\nQue tipo de cartones desea usar ?\n");
        printf(" 1 : Comprar cartones aleatorios\n");
        printf(" 2 : Comprar cartones personalizados\n");
        scanf("%d",&opci1);
    }
    system("cls");
    return opci1;

}

int busqueda(int v[] , int cantidad , int buscar ){
    int posicion = -1;

    for(int i = 0;i<cantidad;i++){
        if(v[i] == buscar){
            posicion = 1;
        }
    }
    return posicion;
}

void cargarBolsa(int v[], int cantidad){
    int numero = 0;
    int resultado = -1;

    for(int i = 0;i<cantidad;i++){
        numero = 1 + rand()%90;
        resultado = busqueda(v , cantidad , numero);
        while(resultado == 1){
            numero = 1 + rand()%90;
            resultado = busqueda(v , cantidad , numero);
        }
        v[i] = numero;
    }
}

