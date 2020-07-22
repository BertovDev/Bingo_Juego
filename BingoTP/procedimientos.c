#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "procedimientos.h"

void datosJugador() {

    char nombre[20];
    char apellido[20];
    long int documento = 0; //Tipo de dato entero mas largo para almacenar el documento
    int cantCartones = 0;

    printf("Bienvenido al Bingo 3.0\n");
    printf("Ingrese sus datos para poder jugar !\n");
    //Datos del jugador
    printf("Ingrese su nombre\n");
    scanf("%s",nombre);
    printf("Ingrese su apeliido\n");
    scanf("%s",apellido);
    printf("Ingrese su documento\n");
    scanf("%d",&documento);
    //Fin datos del jugador

    //Inicio cant Cartones
    printf("Con cuantos cartones desea jugar 1 , 2 o 3?\n");
    scanf("%d",&cantCartones);
    //Si la opcion no es valida se ejecuta el siguiente codigo
    if(cantCartones < 1 || cantCartones > 3) {
            while(cantCartones < 1 || cantCartones > 3) {
                printf("Porfavor eliga una opcion valida\n");
                printf("Con cuantos cartones desea jugar 1,2 o 3?\n");
                scanf("%d",&cantCartones);
            }
    }
    //Fin cant cartones
}
/*proceso para cargar los cartones aleatorios
void cargarVectorConAleatoriosSinRepetir(int m[][COLUMNAS], int tam, int mini,int maxi){

     int numeroNuevo = 0;
     int resultadoBusqueda = 0 ;

    for ( int i = 0; i<tam; i++){

        do{
        numeroNuevo = aleatorioEntre(mini, maxi);
        resultadoBusqueda = busquedaSecuencial(m, tam, numeroNuevo);
        }while(resultadoBusqueda!=-1);
            m[i][COLUMNAS]= numeroNuevo;
    }
}

void crearCartones() {
    int respuesta = 0;
    int cartonJuego[3][5];
    printf("Que carton desea comprar?\n 1)aleatorio\n 2)personalizado\n");
    switch(respuesta) {
        case 1:
            cargarVectorConAleatoriosSinRepetir(cartonJuego,)
        break;
    }

}
*/
