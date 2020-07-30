#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "procedimientos.h"
#define RENGLON 3
#define COLUMNA 5


void limpiarPantalla(){
    system("cls");          //Limpia la consola
}

void datosJugador() {

    char nombre[20];
    char apellido[20];
    long int documento = 0; //Tipo de dato entero mas largo para almacenar el documento
    int cantCartones = 0;
    long int documentoError;
    
    limpiarPantalla();

    printf("------Bienvenido al Bingo 3.0------\n");
    printf("\nIngrese sus datos para poder jugar !\n");
    //Datos del jugador
    printf("Ingrese su nombre: ");
    scanf("%s",nombre);
    printf("Ingrese su apellido: ");
    scanf("%s",apellido);

        /*Se pide el numero de documento, y se corrobora que solo se ingrese numeros.*/
    do
    {
        printf("Ingrese su documento: ");
        while (getchar() != '\n');
        
    } while (scanf("%d", &documento) !=1);

    
    //Fin datos del jugador
    //Fin cant cartones
}

//inicio codigo sergio
int cuantosCartones(){
    int opci=0;
    int numeroDeCartones=0;
    
    limpiarPantalla();

    printf(" \n\n Con cuantos cartones te gustaria jugar?\n Solo podes elegir 1, 2 o 3...");
    scanf("%d",&opci);
    
    while((opci>3)||(opci<1)){
            printf("\n!!!!!  ERROR NUMERO NO VALIDO ELIJA OTRO... \n");
            printf(" .....CON CUANTOS CARTONES QUIERES JUGAR? CON 1 CON 2 O 3 \n");
            scanf("%d",&opci);
    }
    return opci;
}

void tipoDeCarton(int m[][RENGLON][COLUMNA],int opci){
    int opci2;
   printf("\n\n!!!!!QUE TIPO DE CARTONES QUIERES?!!!!!!\n");
   printf(" 1 : COMPRAR UNOS CARTONES ALEATORIOS\n");
   printf(" 2 : COMPRAR UNOS CARTONES PERSONALIZADOS\n");
   scanf("%d",&opci2);

    while ((opci2<1)||(opci2>2)) {
            printf("!!!!!!RESPUETA NO VALIDA INGRESE UN NUMERO DE LAS OPCIONES");
            printf("!!!!!QUE TIPO DE CARTONES QUIERES?!!!!!!\n");
            printf(" 1 : COMPRAR UNOS CARTONES ALEATORIOS\n");
            printf(" 2 : COMPRAR UNOS CARTONES PERSONALIZADOS\n");
            scanf("%d",&opci2);
    }

    if (opci2==1) {
          cargarMatrizAleatoriaSinRepetir(m, opci);
    }else{
        cargarManualmenteMatriz( m ,opci);
    }

}

void cargarMatrizDeCeros(int m [][RENGLON][COLUMNA],int opcion){
    int i,r,c;
    for (i=0;i<opcion;i++){
            for (r=0;r<3;r++) {
                    for (c=0;c<5;c++){
                        m [i][r][c] = 0;
                        }
                }
        }
}

int buscarNumeroRepe(int m [][RENGLON][COLUMNA],int opcion,int busco){
    int posi = -1;
    int i,r,c;
    for (i=0;i<opcion;i++){
            for (r=0;r<3;r++){
                    for (c=0;c<5;c++){

                        if (m[i][r][c] == busco){
                            posi=c;
                            }
                        }
                }
        }
        return posi;

}

void cargarMatrizAleatoriaSinRepetir(int m[][RENGLON][COLUMNA],int opcion){
    int i,r,c;
    int almacen=0;
    int posicion= -1;
     for (i=0;i<opcion;i++){
            for (r=0;r<RENGLON;r++) {
                    for (c=0;c<COLUMNA;c++){
                        almacen= 1 + rand()%90;
                        posicion=buscarNumeroRepe(m,opcion,almacen);
                        while (posicion!= -1){
                                almacen= 1 + rand()%90;
                                posicion=buscarNumeroRepe(m,opcion,almacen);

                        }
                        m [i][r][c]=almacen;
                    }
            }
    }

}

void mostrarMatriz(int m[][RENGLON][COLUMNA],int opcion){
    int i,r,c;
    /*Agregar limpiar pantalla una vez terminado el muestreo de la matriz de la pc*/

    printf("Tus cartones son: \n\n");

    for (i=0;i<opcion;i++){
            for (r=0;r<3;r++) {
                    for (c=0;c<5;c++){
                            printf(" %d ", m[i][r][c]);
                            if (m[i][r][c]<10){
                                printf(" ");
                            }
                        }
                        printf("\n");
                }
                printf("\n\n");
        }
}

void cargarManualmenteMatriz(int m [][RENGLON][COLUMNA],int opcion){
    int i,r,c;
    int almacen=0;
    int posicion= -1;
     for (i=0;i<opcion;i++){
            for (r=0;r<RENGLON;r++) {
                    for (c=0;c<COLUMNA;c++){
                       printf("INGRESE EL NUMERO PARA EL CARTON %d en el renglon %d columna %d \n",i,r,c);
                       scanf("%d",&almacen);
                       while ((almacen>90) ||(almacen<1)){
                            printf("!!!!!!!NUMERO NO VALIDO ENGRESE UN NUMERO ENTRE 1 Y 90 \n");
                            printf("INGRESE EL NUMERO PARA EL CARTON %d en el renglon %d columna %d \n",i,r,c);
                            scanf("%d",&almacen);
                       }
                        posicion=buscarNumeroRepe(m,opcion,almacen);
                        while (posicion!= -1 ){
                                printf("!!!!!EL NUMERO %d YA EXISTE INGRESE UNO NUEVO \n",almacen);
                                printf("INGRESE EL NUMERO PARA EL CARTON %d en el renglon %d columna %d \n",i,r,c);
                                scanf("%d",&almacen);
                                posicion=buscarNumeroRepe(m,opcion,almacen);

                        }
                        m [i][r][c]=almacen;
                    }
            }
    }
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
