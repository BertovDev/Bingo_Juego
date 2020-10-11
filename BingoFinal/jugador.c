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

struct Jugador{
    char nombre[20];
    char apellido[20];
    char dni[9];
    int numDeCartones;
    Carton vCarton[NUMCARTONES];
    int puntos;
    int bolillas[90];
    int columna1[5];
    int fila[3];
};


//-------CONSTRUCTOR--------
Jugador1 cargarJugador(){

    Jugador1 j = malloc(sizeof(struct Jugador));

    char auxNombre[20]= " ";
    char auxApellido[20]= " ";
    char auxDni[9] = " ";
    int manualOAleatorio=0;

    printf("    ------Bienvenido al Bingo 3.0------\n");
    printf("    Ingrese sus datos para poder jugar !\n");
    printf("\n    Ingrese su nombre : ");
    gets(auxNombre);
    strcpy(j->nombre, auxNombre);
    printf("\n    Ingrese su apellido : ");
    fflush(stdin);
    gets(auxApellido);
    strcpy(j->apellido, auxApellido);
    printf("\n    Ingrese su Dni : ");
    fflush(stdin);
    gets(auxDni);
    strcpy(j->dni,auxDni);

    printf("    Datos ingresados son exito ! ");
    printf("\n    Guardando...");
    sleep(1);

    j->numDeCartones = cuantosCartones();
    cargarCartones(j->vCarton , j->numDeCartones);

    return j;
}

//JUEGO JUEGO JUEGO
//ESTA FUNCION TIRA EL ERROR
/*void comienzoDelJuego(Jugador1 j1 , Jugador2 j2){
    int colPuntos = 0;
    j1->puntos = 0;
    int contadorBolillas = 0;
    int contadorBingoPc = 0;
    int contadorBingoJugador = 0;
    int salida = -1;
    int cant = j1->numDeCartones;
    int i = 0;
    cargarBolsa(j1->bolillas , 90); //Cargo la bolsa de bolillas
    for(int x = 0;x<5;x++){
        j1->columna1[x] = 0;
    }
    do{
        printf("SALIO EL NUMERO ---> %d\n",j1->bolillas[i]);
        printf("PUNTOSSSS : %d\n",j1->puntos);
        contadorBolillas = contadorBolillas + 1;
        sleep(1);
        for(int j = 0;j<cant;j++){
            for(int r = 0;r<RENGLON;r++){
                for(int colum = 0;colum<COLUMNA;colum++){
                        //CARTON JUGADOR 1
                        if(j1->vCarton[j]->cartones[r][colum] == j1->bolillas[i]){
                            j1->vCarton[j]->cartones[r][colum] = -1;
                            system("cls");
                            mostrarJugadores(j1,j2);
                            printf("\nFELICIDADES SCASTE EL NUMERO %d\n",j1->bolillas[i]);
                            //cantarColumna(j1 , cant);
                            contadorBingoJugador = contadorBingoJugador + 1;
                            sleep(3);
                        }
                        //CARTON JUGADOR MAQUINA
                        if(j2->cartonPc[j]->cartones[r][colum] == j1->bolillas[i]){
                            j2->cartonPc[j]->cartones[r][colum] = -1;
                            system("cls");
                            mostrarJugadores(j1,j2);
                            printf("\nEL JUGADOR 2 SACO EL NUMERO %d\n",j1->bolillas[i]);
                            contadorBingoPc = contadorBingoPc + 1;
                            sleep(3);
                        }
                }
            }
        }
        i++;
        if(contadorBingoJugador == 15){
            printf("Felicidades GANASTE !\n");
            j1->puntos = j1->puntos + 70;
            printf("PUNTAJE : %d\n",j1->puntos);
            salida = 0;
        }
        if(contadorBingoPc == 15){
            printf("PERDISTE GANO LA PC! :( \n");
            printf("PUNTAJE : %d\n",j1->puntos);
            salida = 0;
        }
    }while(salida == -1);
}
*/
//-------DESTRUCTOR---------

//---------MOSTRAR----------
void mostrarJugador1(Jugador1 j){
    printf("\n-------------------Cartones Jugador %s:-----------------------\n",j->nombre);
    mostrarCartones(j->vCarton,j->numDeCartones);


}
//-----------GETS-----------
int getNumDeCartones(Jugador1 j1){
    return j1->numDeCartones;
}
//-----------SETS-----------
