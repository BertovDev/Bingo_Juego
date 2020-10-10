#ifndef CARTONES_H_INCLUDED
#define CARTONES_H_INCLUDED

struct EstructuraCarton;
typedef struct EstructuraCarton * Carton;

//-------CONSTRUCTOR--------
Carton cargarCarton(int tipo);
void cargarCartones(Carton c[],int opcion);
//-------DESTRUCTOR---------

//---------MOSTRAR----------
void mostrarCarton(Carton c);
void mostrarCartones(Carton c[],int opcion);
//-----------GETS-----------

//-----------SETS-----------

//-----------OTROS-----------


#endif // CARTONES_H_INCLUDED
