#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#define RENGLON 3
#define COLUMNA 5
#define NUMCARTONES 3
struct Cartones
{
    int carton[RENGLON][COLUMNA];
};
struct Jugador
{
    char nombre[20];
    char apellido[20];
    char dni[9];
    int numDeCartones;
    struct Cartones vCarton[NUMCARTONES];
    int puntos;
    int bolillas[90];
    int columna1[5];
    int fila[3];
};
struct JugadorPc
{
    int numDeCartones;
    struct Cartones cartonPc[NUMCARTONES];
};
//PRE: NO TIENE.
//POSTCONDICONES: MUESTRA UN MENU PARA SABER CON CUANTOS CARTONES QUERES JUGAR Y DEVUELVE EL NUMERO ELEJIDO
int cuantosCartones();
//PRE: NO TIENE.
//POSTCONDICONES:
struct Jugador cargarJugador();
//PRE: NO TIENE.
//POSTCONDICONES:
void mostrarJugadores(struct Jugador p, struct JugadorPc maquina);
//PRE: NO TIENE.
//POSTCONDICONES:
int buscarNumeroRepe(int m[RENGLON][COLUMNA],int busco);
//PRE: NO TIENE.
//POSTCONDICONES:
struct Cartones cargarCarton(int tipo);
//PRE: NO TIENE.
//POSTCONDICONES:
void mostrarCarton(struct Cartones e);
//PRE: NO TIENE.
//POSTCONDICONES:
void cargarCatones(struct Cartones c[],int opcion);
//PRE: NO TIENE.
//POSTCONDICONES:
void mostrarCartones(struct Cartones c[],int opcion );
//PRE: NO TIENE.
//POSTCONDICONES:
int tipoDeCarton();
//PRE: NO TIENE.
//POSTCONDICONES:
struct JugadorPc cargarJugadorPC(int cant);
//PRE: NO TIENE.
//POSTCONDICONES:
int busqueda (int vector[], int cantidad, int buscar);
//PRE: NO TIENE.
//POSTCONDICONES:
void cargarBolsa(int vector[], int cantidad);
//PRE: NO TIENE.
//POSTCONDICONES:
void mostrarBolsa (int vector[], int cantidad);
//PRE: NO TIENE.
//POSTCONDICONES:
void comienzoDelJuego(struct Jugador jugador1 , struct JugadorPc jugadorPc2 );
//PRE: NO TIENE.
//POSTCONDICONES:
void cantarColumna(struct Jugador jugador1 , int cant);

int main()
{
    srand(time(0));
    struct Jugador jugador1;
    struct JugadorPc jugador2;

    jugador1=cargarJugador();
    int cant = jugador1.numDeCartones;
    jugador2 = cargarJugadorPC(cant);
    mostrarJugadores(jugador1 , jugador2);
    comienzoDelJuego(jugador1 , jugador2);
    return 0;
}
struct Cartones cargarCarton(int tipo){
    int i,x;
    int almacen=0;
    int posi=0;
    struct Cartones aux;

    if (tipo==1)
    {
        for (i=0; i<RENGLON; i++)
        {
            for (x=0; x<COLUMNA; x++)
            {
                do
                {
                    almacen= 1+ (rand()%90);
                    posi=buscarNumeroRepe(aux.carton,almacen);
                }
                while(posi!=-1);

                aux.carton[i][x]=almacen;
            }
        }
    }
    else
    {
        int r,c;
        for (r=0; r<RENGLON; r++)
        {
            for (c=0; c<COLUMNA; c++)
            {
                printf("INGRESE EL NUMERO en la posicion: renglon %d columna %d \n",r,c);
                scanf("%d",&almacen);
                while ((almacen>90) ||(almacen<1))
                {
                    printf("!!!!!!!NUMERO NO VALIDO ENGRESE UN NUMERO ENTRE 1 Y 90 \n");
                    printf("INGRESE EL NUMERO PARA EL CARTON %d en el renglon %d columna %d \n",i,r,c);
                    scanf("%d",&almacen);
                }
                posi=buscarNumeroRepe(aux.carton,almacen);
                while (posi!= -1 )
                {
                    printf("!!!!!EL NUMERO %d YA EXISTE INGRESE UNO NUEVO \n",almacen);
                    printf("INGRESE EL NUMERO PARA EL CARTON %d en el renglon %d columna %d \n",i,r,c);
                    scanf("%d",&almacen);
                    posi=buscarNumeroRepe(aux.carton,almacen);

                }
                aux.carton[r][c]=almacen;
            }
        }
    }

    return aux;

}
void mostrarCarton(struct Cartones e)
{
    int i,x;
    for (i=0; i<RENGLON; i++)
    {
        for (x=0; x<COLUMNA; x++)
        {

            printf(" %d ", e.carton[i][x]);

            if (e.carton[i][x]<10)
            {
                printf(" ");
            }
        }
        printf("\n");

    }

}

int buscarNumeroRepe(int m[RENGLON][COLUMNA],int busco)
{
    int posi = -1;
    int r,c;
    for (r=0; r<RENGLON; r++)
    {
        for (c=0; c<COLUMNA; c++)
        {

            if (m[r][c] == busco)
            {
                posi=c;
            }
        }
    }

    return posi;

}

void cargarCatones(struct Cartones c[],int opcion)
{

    int i;
    int opciMA;
    opciMA= tipoDeCarton();
    for (i=0; i<opcion; i++)
    {


        c[i]=cargarCarton(opciMA);

    }

}
void mostrarCartones(struct Cartones c[],int opcion )
{
    int i;

    for (i=0; i<opcion; i++)
    {
        mostrarCarton(c[i]);
        printf("\n");

    }


}

struct Jugador cargarJugador()
{
    char auxNombre[20]= " ";
    char auxApellido[20]= " ";
    char auxDni[9] = " ";
    int manualOAleatorio=0;
    struct Jugador jugador;
    printf("------Bienvenido al Bingo 3.0------\n");
    printf("Ingrese sus datos para poder jugar !\n");
    printf("\nIngrese su nombre : ");
    gets(auxNombre);
    strcpy(jugador.nombre, auxNombre);
    printf("\nIngrese su apellido : ");
    fflush(stdin);
    gets(auxApellido);
    strcpy(jugador.apellido, auxApellido);
    printf("\nIngrese su Dni : ");
    fflush(stdin);
    gets(auxDni);
    strcpy(jugador.dni,auxDni);

    printf("Datos ingresados son exito ! ");
    printf("\nGuardando...");
    sleep(1);

    jugador.numDeCartones=cuantosCartones();

    cargarCatones(jugador.vCarton,jugador.numDeCartones);

    return jugador;
};

struct JugadorPc cargarJugadorPC(int cant){
    struct JugadorPc jPc;
    jPc.numDeCartones = cant;
    for(int i = 0;i<cant;i++){
        jPc.cartonPc[i] =  cargarCarton(1);
    }

    return jPc;
};


void mostrarJugadores(struct Jugador p , struct JugadorPc maquina){
    printf("-------------------Cartones Jugador %s:-----------------------\n",p.nombre);
    mostrarCartones(p.vCarton,p.numDeCartones);
    printf("-------------------Cartones Jugador PC-----------------------\n");
    mostrarCartones(maquina.cartonPc , maquina.numDeCartones);
}

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


void cargarBolsa(int vector[], int cantidad){
    int numero = 0;
    int resultado = -1;

    for (int i = 0; i < cantidad; i++)
    {
        numero = 1 + rand()%90;
        resultado = busqueda(vector, cantidad, numero);
        while (resultado == 1)
        {
            numero = 1 + rand()%90;
            resultado = busqueda(vector, cantidad, numero);

        }

        vector[i] = numero;
    }

}

int busqueda(int vector[], int cantidad, int buscar){
    int posicion = -1;

    for (int i = 0; i < cantidad; i++)
    {
        if (vector[i] == buscar){
            posicion = 1;
        }
    }
    return posicion;
}

void mostrarBolsa (int vector[], int cantidad){
    printf("\n-------------------Bolsa de Bolillas--------------------\n");
    for (int i = 0; i < cantidad; i++)
    {
        printf("%d SALIO EL NUMERO  -----> %d !!\n",i+1,vector[i]);
        sleep(1);
    }

}
//PROCEDIMIENTO DA COMIENZO AL BUCLE DE JUEGO
void comienzoDelJuego(struct Jugador jugador1 , struct JugadorPc jugadorPc2 ){
    int colPuntos = 0;
    jugador1.puntos = 0;
    int contadorBolillas = 0;
    int contadorBingoPc = 0;
    int contadorBingoJugador = 0;
    int salida = -1;
    int cant = jugador1.numDeCartones;
    int i = 0;
    cargarBolsa(jugador1.bolillas , 90); //cargo la bolsa de bolillas
    for(int x = 0;x<5;x++){
        jugador1.columna1[x] = 0;
    }
    do{
        printf("SALIO EL NUMERO ---> %d\n",jugador1.bolillas[i]);
        printf("PUNTOSSSSSS : %d\n",jugador1.puntos);
        contadorBolillas = contadorBolillas + 1;
        sleep(1);
        for(int j = 0;j<cant;j++){
            for(int r = 0;r<RENGLON;r++){
                for(int c = 0;c<COLUMNA;c++){
                        //CARTON JUGADOR 1
                        if(jugador1.vCarton[j].carton[r][c] == jugador1.bolillas[i]){
                            jugador1.vCarton[j].carton[r][c] = -1;
                            system("cls");
                            mostrarJugadores(jugador1,jugadorPc2);
                            printf("\nFELICIDADES SCASTE EL NUMERO %d\n",jugador1.bolillas[i]);
                            cantarColumna(jugador1 , cant);
                            contadorBingoJugador = contadorBingoJugador + 1;
                            sleep(3);
                        }
                        //CARTON JUGADOR MAQUINA
                        if(jugadorPc2.cartonPc[j].carton[r][c] == jugador1.bolillas[i]){
                            jugadorPc2.cartonPc[j].carton[r][c] = -1;
                            system("cls");
                            mostrarJugadores(jugador1,jugadorPc2);
                            printf("\nEL JUGADOR 2 SACO EL NUMERO %d\n",jugador1.bolillas[i]);
                            contadorBingoPc = contadorBingoPc + 1;
                            sleep(3);
                        }
                }
            }
        }
        i++;
        if(contadorBingoJugador == 15){
            printf("Felicidades GANASTE !\n");
            jugador1.puntos = jugador1.puntos + 70;
            printf("PUNTAJE : %d\n",jugador1.puntos);
            salida = 0;
        }
        if(contadorBingoPc == 15){
            printf("PERDISTE GANO LA PC! :( \n");
            printf("PUNTAJE : %d\n",jugador1.puntos);
            salida = 0;
        }
    }while(salida == -1);
}

//La logica de esta funcion anda bien lo unico que no puedo lograr es sumar los puntos
//SI LAS POSICIONES DE LA MATRIZ SON -1 Y LA LA MATRIZ COLUMA ESTA EN 0(SIGNIFICA QUE NO FUE CANTADA) SUMA LOS PUNTOS
void cantarColumna(struct Jugador jugador1 , int cant){
    for(int i = 0;i<cant;i++){
        for(int c=0;c<COLUMNA;c++){
            if((jugador1.vCarton[i].carton[0][c] == -1) && (jugador1.vCarton[i].carton[1][c] == -1) && (jugador1.vCarton[i].carton[2][c] == -1) && ((jugador1.columna1[c]) == 0) ){
                jugador1.puntos = jugador1.puntos + 10;
                jugador1.columna1[c] = -1;
                printf("FELICIDADES HICISTE COLUMNA\n");
                printf("putnos : %d\n",jugador1.puntos);
            }
        }
    }
}
