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

struct EstructuraCarton{

    int Cartones[RENGLON][COLUMNA];
};


//-------CONSTRUCTOR--------
Carton cargarCarton(int tipo){

    Carton c = malloc(sizeof(struct EstructuraCarton));
    int i,x;
    int almacen = 0;
    int posi = 0;
    if (tipo==1)
    {
        for (i=0; i<RENGLON; i++)
        {
            for (x=0; x<COLUMNA; x++)
            {
                do
                {
                    almacen= 1+ (rand()%90);
                    posi=buscarNumeroRepe(c->Cartones,almacen);
                }
                while(posi!=-1);

                c->Cartones[i][x]=almacen;
            }
        }
    }
    else
    {
        int r,colum;
        for (r=0; r<RENGLON; r++)
        {
            for (colum=0; colum<COLUMNA; colum++)
            {
                printf("Ingrese el numero en la posicion: renglon %d columna %d",r,colum);
                scanf("%d",&almacen);
                while ((almacen>90) ||(almacen<1))
                {
                    printf("¡Ingrese un numero entre 1 Y 90! \n");
                    printf("Ingrese el numero en la posicion: renglon %d columna %d \n",i,r,colum);
                    scanf("%d",&almacen);
                }
                posi=buscarNumeroRepe(c->Cartones,almacen);
                while (posi!= -1 )
                {
                    printf("¡El numero %d ya existe, elija uno nuevo! \n",almacen);
                    printf("Ingrese el numero en la posicion: renglon %d columna %d \n",i,r,colum);
                    scanf("%d",&almacen);
                    posi=buscarNumeroRepe(c->Cartones,almacen);

                }
                c->Cartones[r][colum]=almacen;
            }
        }
    }

    return c;
}

void cargarCartones(Carton c[],int opcion)
{
    int i;
    int opciMA;
    opciMA= tipoDeCarton();
    for (i=0; i<opcion; i++)
    {


        c[i]=cargarCarton(opciMA);

    }

}
//-------DESTRUCTOR---------

//---------MOSTRAR----------
void mostrarCarton(Carton c)
{
    int i,x;
    for (i=0; i<RENGLON; i++)
    {
        for (x=0; x<COLUMNA; x++)
        {

            printf(" %d ", c->Cartones[i][x]);

            if (c->Cartones[i][x]<10)
            {
                printf(" ");
            }
        }
        printf("\n");

    }

}

void mostrarCartones(Carton c[],int opcion )
{
    int i;

    for (i=0; i<opcion; i++)
    {
        mostrarCarton(c[i]);
        printf("\n");

    }


}
//-----------GETS-----------

//-----------SETS-----------

//-----------OTROS-----------
int buscarNumeroRepe(Carton c[RENGLON][COLUMNA],int busco)
{
    int posi = -1;
    int r,colum;
    for (r=0; r<RENGLON; r++)
    {
        for (colum=0; colum<COLUMNA; colum++)
        {

            if (c[r][colum] == busco)
            {
                posi=colum;
            }
        }
    }

    return posi;

}
