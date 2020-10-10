#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED

struct Jugador;

typedef struct  Jugador * Jugador1;

//-------CONSTRUCTOR--------
Jugador1 cargarJugador();

//void comienzoDelJuego(Jugador1 j1 , Jugador2 j2);
//-------DESTRUCTOR---------

//---------MOSTRAR----------
void mostrarJugador1(Jugador1 j1);
//-----------GETS-----------
int getNumDeCartones(Jugador1 j1);
//-----------SETS-----------

#endif // JUGADOR_H_INCLUDED
