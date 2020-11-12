#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
//VARIABLES GLOBALES
#define RENGLON 3
#define COLUMNA 5
#define NUMCARTONES 3
#define CANTIDAD 10

struct Cartones {
   int carton[RENGLON][COLUMNA];
};

struct Jugador {
   char nombre[20];
   char apellido[20];
   char dni[9];
   int numDeCartones;                     //Cantidad de cartones
   struct Cartones vCarton[NUMCARTONES];  //Matriz jugador
   float puntos;
   int bolillas[90];                      //Las bolillas que salieron
   int columna1[5];                       //Columnas cantadas
   int fila[3];                           //Lineas cantadas
};

struct JugadorPc {
   int numDeCartones;
   struct Cartones cartonPc[NUMCARTONES]; //Matriz Pc
};

struct Puntaje {
   char nombre[20];
   char apellido[20];
   float puntos;
};

//PRE: NO TIENE.
//POSTCONDICONES: MUESTRA UN MENU PARA SABER CON CUANTOS CARTONES QUERES JUGAR Y DEVUELVE EL NUMERO ELEJIDO
int cuantosCartones();
//PRE: Debe existir la strcut jugador
//POSTCONDICONES: carga la struct con los datos por teclado
struct Jugador cargarJugador();
//PRE:Debe existir struct jugadr y jugadorPC
//POSTCONDICONES:Muestra los cartones de ambos jugadores
void mostrarJugadores(struct Jugador p, struct JugadorPc maquina);
//PRE:La matriz debe tener valores y debe haber un numero a buscar
//POSTCONDICONES:Busca numero repetido en la matriz y retorna su posicion
int buscarNumeroRepe(int m[RENGLON][COLUMNA], int busco);
//PRE:Debe existir la struct Cartones
//POSTCONDICONES:Carga la matriz auxiliar con numeros no repetidos para retornarla
struct Cartones cargarCarton(int tipo);
//PRE:Debe existir los cartones con sus posiciones llenas
//POSTCONDICONES:Muestra los cartones de juego
void mostrarCarton(struct Cartones e);
//PRE:Debe existir cargarCarton y tipoDeCarton
//POSTCONDICONES:Carga la matriz con los numeros no repetidos elegidos en cargarCarton
void cargarCatones(struct Cartones c[], int opcion);
//PRE:Debe existir mostrarCarton
//POSTCONDICONES:Muestra si hay mas de un carton de cada jugador
void mostrarCartones(struct Cartones c[], int opcion);
//PRE:No nesecita
//POSTCONDICONES:Retorna el tipo de carton elegido(aleatorio , manual)
int tipoDeCarton();
//PRE:Debe existir jugador1 y la cantidad de cartones elegidos
//POSTCONDICONES:Carga el carton de la PC con las caracteristicas elegidas por el usuario
struct JugadorPc cargarJugadorPC(int cant);
//PRE:Debe existir el vector su capacidad y el numero a buscar
//POSTCONDICONES:Retorna la posicion del numero buscado en el vector
int busqueda(int vector[], int cantidad, int buscar);
//PRE:Debe existir busqueda()
//POSTCONDICONES:carga el vector con numeros aleatorios no repetidos hasta 90
void cargarBolsa(int vector[], int cantidad);
//PRE:Debe estar cargada la bolsa y definida
//POSTCONDICONES:Muestra la bolsa de los numeros uno por uno
void mostrarBolsa(int vector[], int cantidad);
//PRE:Debe existir jugador1 y jugadorPc2 y sus cartones deben estar cargados , tambien debe estar cargado la bolsa de bolillas
//POSTCONDICONES:Da comienzo al juego de bingo , calcula puntaje , rellena las posiciones que van saliendo de la matriz
void comienzoDelJuego(struct Jugador jugador1, struct JugadorPc jugadorPc2);
//PRE:Debe haber un vector definido y su tamanio
//POSTCONDICONES:Carga de 0 ese vector escogido
void cargarDeCero(int num[], int tam);
//PRE:El juego debe estar empezado y la matriz tiene que estar llena
//POSTCONDICONES:Cuando el jugador completa una fila retorna -1 en referencia a que lo logro
int buscarRenglon(struct Cartones car[], int cant);
//PRE:El juego debe estar empezado y la matriz tiene que estar llena
//POSTCONDICONES:Cuando el jugador completa una columna retorna -1 en referencia a que lo logro
int buscarColumna(struct Cartones car[], int cant);
//-----------------ARCHIVO.TXT--------------------
//PRE:Nesecita un array con el formato correspondiente
//POST:transforma el array mencionado y lo retorna como struct Puntaje
struct Puntaje pasarCharAJugador(char c[], int n);
//PRE:el array de struct tiene que estar declarado y la cantidad n tiene que ser distinto de 0
//POST:coloca un -1 en cada posicion para identificar que no esta usada esa misma posicion
void iniciarPuntaje(struct Puntaje p[], int n);
//PRE:tiene que estar creado el archivo y tener los indicadores de separacion correspondientes
//POST:carga el array con los puntajes leidos en el archivo txt
void cargarPuntajeTxt(struct Puntaje p[], int n);
//PRE:Tiene que haber un array cargado con algun dato
//POST:Muestra por pantalla los datos guardados en el array
void mostrarPuntaje(struct Puntaje p[], int n);
//PRE:Debe haber lugar en el array p y el puntaje  p1 debe estar creado
//POST:Agrega la structura p1 al array de strucs
void agregarAlArray(struct Puntaje p[], int n, struct Puntaje p1);
//PRE:El array debe tener datos ingresados
//POST:Ordena por nombre todos los punajes del array mayor a menor
void ordenarPorPuntaje(struct Puntaje p[], int n);
//PRE:Debe existir struct de jugador
//POSTCONDICONES:Escribe nombre apellido y puntos en el archivoTXT
void escribirJugadorEnArchivo(struct Jugador j1);
//------------------------------------------------

int main() {
   system("cls");
   srand(time(0));

   struct Puntaje puntosJugadores[CANTIDAD];
   struct Jugador jugador1;
   struct JugadorPc jugador2;

   jugador1 = cargarJugador();
   int cant = jugador1.numDeCartones;
   jugador2 = cargarJugadorPC(cant);
   mostrarJugadores(jugador1, jugador2);
   comienzoDelJuego(jugador1, jugador2);

   //ARCHIVO
   iniciarPuntaje(puntosJugadores, CANTIDAD);
   cargarPuntajeTxt(puntosJugadores, CANTIDAD);
   ordenarPorPuntaje(puntosJugadores, CANTIDAD);
   mostrarPuntaje(puntosJugadores, CANTIDAD);
   return 0;
}

struct Cartones cargarCarton(int tipo) {
   int i, x;
   int almacen = 0;
   int posi = 0;
   struct Cartones aux;

   if (tipo == 1) {
      for (i = 0; i < RENGLON; i++) {
         for (x = 0; x < COLUMNA; x++) {
            do {
               almacen = 1 + (rand() % 90);
               posi = buscarNumeroRepe(aux.carton, almacen);
            }
            while (posi != -1);

            aux.carton[i][x] = almacen;
         }
      }
   } else {
      int r, c;
      for (r = 0; r < RENGLON; r++) {
         for (c = 0; c < COLUMNA; c++) {
            printf("Ingrese el numero que desea en el renglon %d y columna %d  -> ", r, c);
            scanf("%d", & almacen);
            while ((almacen > 90) || (almacen < 1)) {
               printf("El numero debe ser entre los numeros 1 y 90.");
               printf("Ingrese el numero que desea en el renglon %d y columna %d  -> ", r, c);
               scanf("%d", & almacen);
            }
            posi = buscarNumeroRepe(aux.carton, almacen);
            while (posi != -1) {
               printf("\nEl numero %d no se puede repetir.\n", almacen);
               printf("Ingrese el numero que desea en el renglon %d y columna %d  -> ", r, c);
               scanf("%d", & almacen);
               posi = buscarNumeroRepe(aux.carton, almacen);

            }
            aux.carton[r][c] = almacen;
         }
      }
   }

   return aux;

}
void mostrarCarton(struct Cartones e) {
   int i, x;
   for (i = 0; i < RENGLON; i++) {
      for (x = 0; x < COLUMNA; x++) {

         printf("| ");
         if (e.carton[i][x] >= 10) {
            printf(" %d |", e.carton[i][x]);
         }
         if ((e.carton[i][x] < 10) && (e.carton[i][x] > 0)) {
            printf(" %d  |", e.carton[i][x]);
         }
         if (e.carton[i][x] < 0) {
            printf(" %d |", e.carton[i][x]);
         }

      }
      printf("\n|---------------------------------|\n");

   }

}

int buscarNumeroRepe(int m[RENGLON][COLUMNA], int busco) {
   int posi = -1;
   int r, c;
   for (r = 0; r < RENGLON; r++) {
      for (c = 0; c < COLUMNA; c++) {

         if (m[r][c] == busco) {
            posi = c;
         }
      }
   }

   return posi;

}

void cargarCatones(struct Cartones c[], int opcion) {

   int i;
   int opciMA;
   opciMA = tipoDeCarton();
   for (i = 0; i < opcion; i++) {

      c[i] = cargarCarton(opciMA);

   }

}
void mostrarCartones(struct Cartones c[], int opcion) {
   int i;

   for (i = 0; i < opcion; i++) {
      mostrarCarton(c[i]);
      printf("\n");

   }

}

struct Jugador cargarJugador() {
   char auxNombre[20] = " ";
   char auxApellido[20] = " ";
   char auxDni[9] = " ";
   struct Jugador jugador;
   printf("|-------------------- !Bingo! ------------------|\n");
   printf("| Integrantes:                                  |\n");
   printf("| Mauro Kinjuk | Berto Bautista | Sergio Cadima |\n");
   printf("| Grupo: 16                                     |\n");
   printf("|-----------------------------------------------|\n\n");
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
   strcpy(jugador.dni, auxDni);

   printf("Datos ingresados son exito ! ");
   printf("\nGuardando...");
   sleep(1);

   jugador.numDeCartones = cuantosCartones();

   cargarCatones(jugador.vCarton, jugador.numDeCartones);

   return jugador;
};

struct JugadorPc cargarJugadorPC(int cant) {
   struct JugadorPc jPc;
   jPc.numDeCartones = cant;
   for (int i = 0; i < cant; i++) {
      jPc.cartonPc[i] = cargarCarton(1);
   }

   return jPc;
};

void mostrarJugadores(struct Jugador p, struct JugadorPc maquina) {
   printf("---------Cartones Jugador %s:------\n", p.nombre);
   mostrarCartones(p.vCarton, p.numDeCartones);
   printf("---------Cartones Jugador PC-------\n");
   mostrarCartones(maquina.cartonPc, maquina.numDeCartones);
}

int cuantosCartones() {
   int opci = 0;
   system("cls");
   printf("\n\n|   ->Cartones<-   |\n");
   printf("| Con cuantos cartones deseas jugar: \n");
   printf("| 1. Uno\n| 2. Dos\n| 3. Tres\n Escriba el numero: ");
   scanf("%d", & opci);
   while ((opci > 3) || (opci < 1)) {
      printf("\nDebe elegir entre 1 y 3 cartones.\n");
      printf("| 1. Uno\n| 2. Dos\n| 3. Tres\n Escriba el numero: ");
      scanf("%d", & opci);
   }
   return opci;
}

int tipoDeCarton() {
   int opci1;
   printf("\n| Que tipo de cartones deseas usar: \n");
   printf("| 1. Modo aletorio automatico\n| 2. Modo manual (Debe cargar todos los numeros manualmente)");
   printf("\nEscriba el numero: ");
   scanf("%d", & opci1);
   while ((opci1 < 1) || (opci1 > 2)) {

      printf("\n\nDebe elegir una de las dos opciones.");
      printf("\nQue tipo de cartones deseas usar: \n");
      printf("| 1. Modo aletorio automatico\n| 2. Modo manual (Debe cargar todos los numeros manualmente)");
      printf("\nEscriba el numero: ");
      scanf("%d", & opci1);
   }
   system("cls");
   return opci1;

}

void cargarBolsa(int vector[], int cantidad) {
   int numero = 0;
   int resultado = -1;

   for (int i = 0; i < cantidad; i++) {
      numero = 1 + (rand() % 90);
      resultado = busqueda(vector, cantidad, numero);
      while (resultado == 1) {
         numero = 1 + (rand() % 90);
         resultado = busqueda(vector, cantidad, numero);

      }

      vector[i] = numero;
   }

}

int busqueda(int vector[], int cantidad, int buscar) {
   int posicion = -1;

   for (int i = 0; i < cantidad; i++) {
      if (vector[i] == buscar) {
         posicion = 1;
      }
   }
   return posicion;
}

void mostrarBolsa(int vector[], int cantidad) {
   printf("\n-------------------Bolsa de Bolillas--------------------\n");
   for (int i = 0; i < cantidad; i++) {
      printf("%d Salio el numero ---> %d\n", i + 1, vector[i]);
      sleep(1);
   }

}

//PROCEDIMIENTO DA COMIENZO AL BUCLE DE JUEGO
void comienzoDelJuego(struct Jugador jugador1, struct JugadorPc jugadorPc2) {
   jugador1.puntos = 0;
   int contadorBolillas = 0;
   int primeraLinea = 0;
   int primeraColumna = 0;
   int primeraLineaPC = 0;
   int primeraColumnaPC = 0;
   int salida = -1;
   int cant = jugador1.numDeCartones;
   int contadorBingoPc[cant];
   int contadorBingoJugador[cant];
   cargarDeCero(contadorBingoJugador, cant);
   cargarDeCero(contadorBingoPc, cant);

   int i = 0;
   cargarBolsa(jugador1.bolillas, 90); //cargo la bolsa de bolillas
   for (int x = 0; x < 5; x++) {
      jugador1.columna1[x] = 0;
   }
   for (int x = 0; x < 3; x++) {
      jugador1.fila[x] = 0;
   }
   do {
      printf("Salio el numero ---> %d\n", jugador1.bolillas[i]);
      contadorBolillas = contadorBolillas + 1;
      sleep(1);
      for (int j = 0; j < cant; j++) {
         for (int r = 0; r < RENGLON; r++) {
            for (int c = 0; c < COLUMNA; c++) {
               //CARTON JUGADOR 1
               if (jugador1.vCarton[j].carton[r][c] == jugador1.bolillas[i]) {
                  jugador1.vCarton[j].carton[r][c] = -1;
                  system("cls");
                  mostrarJugadores(jugador1, jugadorPc2);
                  printf("Felicidades! Sacaste el numero: %d\n", jugador1.bolillas[i]);
                  contadorBingoJugador[j] = contadorBingoJugador[j] + 1;
                  //CODIGO CANTAR COLUMNA Y LINEA JUGADOR
                  if ((primeraColumna == 0) && (primeraColumnaPC == 0)) {
                     primeraColumna = buscarColumna(jugador1.vCarton, cant);
                     if (primeraColumna == -1) {
                        printf("\n Cantaste una columna! \n");
                        sleep(1);

                     }
                  }
                  if ((primeraLinea == 0) && (primeraLineaPC == 0)) {
                     primeraLinea = buscarRenglon(jugador1.vCarton, cant);
                     if (primeraLinea == -1) {
                        printf("\nCantaste Linea!\n");
                        sleep(1);

                     }
                  }
                  if (contadorBingoJugador[j] == 15) {
                     j = cant;
                     r = RENGLON;
                     c = COLUMNA;
                  }
                  sleep(1);
               }
               //FIN CODIGO COLUMNA LINEA
               //CARTON JUGADOR MAQUINA
               if (jugadorPc2.cartonPc[j].carton[r][c] == jugador1.bolillas[i]) {
                  jugadorPc2.cartonPc[j].carton[r][c] = -1;
                  system("cls");
                  mostrarJugadores(jugador1, jugadorPc2);
                  printf("La Pc saco el numero: %d\n", jugador1.bolillas[i]);
                  contadorBingoPc[j] = contadorBingoPc[j] + 1;
                  //CODIGO CANTAR COLUMNA Y LINEA MAQUINA
                  if ((primeraColumna == 0) && (primeraColumnaPC == 0)) {
                     primeraColumnaPC = buscarColumna(jugadorPc2.cartonPc, cant);
                     if (primeraColumna == -1) {
                        printf("\nLa maquina canto Columna. \n");
                        sleep(1);

                     }
                  }
                  if ((primeraLinea == 0) && (primeraLineaPC == 0)) {
                     primeraLineaPC = buscarRenglon(jugadorPc2.cartonPc, cant);
                     if (primeraLineaPC == -1) {
                        printf("\nLa maquina canto Linea. \n");
                        sleep(1);

                     }
                  }
                  if (contadorBingoPc[j] == 15) {
                     j = cant;
                     r = RENGLON;
                     c = COLUMNA;
                  }
                  sleep(1);
               }
            }
         }

      }

      i++;
      //COMIENZO CALCULO DE PUNTOS
      int j;
      for (j = 0; j < cant; j++) {
         if (contadorBingoJugador[j] == 15) {
            printf("Felicidades Ganaste!\n");
            jugador1.puntos = 70;
            if (primeraColumna == -1) {
               jugador1.puntos = jugador1.puntos + 10;

            }
            if (primeraLinea == -1) {
               jugador1.puntos = jugador1.puntos + 20;
            }
            if ((contadorBolillas) > 80) {
               jugador1.puntos = jugador1.puntos * 1.26;
            }
            if ((contadorBolillas > 70) && (contadorBolillas <= 80)) {
               jugador1.puntos = jugador1.puntos * 1.33;
            }
            if ((contadorBolillas <= 70) && (contadorBolillas >= 50)) {
               jugador1.puntos = jugador1.puntos * 1.5;
            }
            if ((contadorBolillas < 50) && (contadorBolillas >= 30)) {
               jugador1.puntos = jugador1.puntos * 1.7;
            }
            if (contadorBolillas < 30) {
               jugador1.puntos = jugador1.puntos * 2;
            }
            printf("Salieron %d bolillas\n", contadorBolillas);
            printf("|--------------|\n");
            printf("|Puntaje: %2.f |\n", jugador1.puntos);
            printf("|--------------|\n");
            escribirJugadorEnArchivo(jugador1);
            salida = 0;
         }

         if (contadorBingoPc[j] == 15) {
            printf("Perdiste. Gano la Pc.\n");

            if (primeraColumna == -1) {
               jugador1.puntos = jugador1.puntos + 10;

            }
            if (primeraLinea == -1) {
               jugador1.puntos = jugador1.puntos + 20;

            }
            printf("Salieron %d bolillas\n", contadorBolillas);
            printf("|--------------|\n");
            printf("|Puntaje: %2.f |\n", jugador1.puntos);
            printf("|--------------|\n");
            salida = 0;

         }
      }

      //FIN CALCULO DE PUNTOS
   }
   while (salida == -1);
}

void cargarDeCero(int num[], int tam) {

   int i;
   for (i = 0; i < tam; i++) {

      num[i] = 0;
   }
}

int buscarColumna(struct Cartones car[], int cant) {

   int columna = 0;
   for (int i = 0; i < cant; i++) {
      for (int r = 0; r < COLUMNA; r++) {

         if ((car[i].carton[0][r] == -1) && (car[i].carton[1][r] == -1) && (car[i].carton[2][r] == -1)) {

            columna = -1;
         }
      }
   }
   return columna;
}

int buscarRenglon(struct Cartones car[], int cant) {
   int Linea = 0;
   for (int i = 0; i < cant; i++) {
      for (int r = 0; r < RENGLON; r++) {
         if ((car[i].carton[r][0] == -1) && (car[i].carton[r][1] == -1) && (car[i].carton[r][2] == -1) && (car[i].carton[r][3] == -1) && (car[i].carton[r][4] == -1)) {

            Linea = -1;

         }
      }
   }
   return Linea;

}

//----------AREA ARCHIVO----------------------
void iniciarPuntaje(struct Puntaje p[], int n) {
   for (int i = 0; i < n; i++) {
      p[i].puntos = -1;
      strcpy(p[i].nombre, " ");
      strcpy(p[i].apellido, " ");
   }
}

void mostrarPuntaje(struct Puntaje p[], int n) {
   sleep(3);
   system("cls");
   printf("|--------------- TOP 10 PUNTAJES ------------------|\n");
   for (int i = 0; i < n; i++) {
      if (p[i].puntos != -1 && p[i].puntos != 0) {
         printf("Nombre : %s, Apellido : %s, Puntos : %.2f\n", p[i].nombre, p[i].apellido, p[i].puntos);
      }
   }
}

struct Puntaje pasarCharAJugador(char c[], int n) {
   char auxNombre[40] = " ";
   char auxApellido[40] = " ";
   char auxPuntos[40] = " ";

   int pos1 = -1;
   int pos2 = -2;
   struct Puntaje p1;
   //BUSCO SEPARADOR
   for (int i = 0; i < n; i++) {
      if (c[i] == ';') {
         pos1 = i;
         i = n;
      }
   }
   for (int i = pos1 + 1; i < n; i++) {
      if (c[i] == ';') {
         pos2 = i;
      }
   }
   //FIN BUSQUEDA
   for (int i = 0; i < pos1; i++) {
      auxNombre[i] = c[i];
   }
   for (int i = pos1 + 1; i < pos2; i++) {
      auxApellido[i - (pos1 + 1)] = c[i];
   }
   for (int i = pos2 + 1; i < n; i++) {
      auxPuntos[i - (pos2 + 1)] = c[i];
   }

   strcpy(p1.nombre, auxNombre);
   strcpy(p1.apellido, auxApellido);
   p1.puntos = atof(auxPuntos);

   return p1;
}

void cargarPuntajeTxt(struct Puntaje p[], int n) {
   FILE * puntero;
   puntero = fopen("Puntaje.txt", "r");
   while (!feof(puntero)) {
      char aux[40] = " ";
      fgets(aux, 40, puntero);

      struct Puntaje p1 = pasarCharAJugador(aux, 40);
      agregarAlArray(p, n, p1);
   }
   fclose(puntero);
}

void agregarAlArray(struct Puntaje p[], int n, struct Puntaje p1) {
   for (int i = 0; i < n; i++) {
      if (p[i].puntos == -1) {
         p[i] = p1;
         i = n;
      }
   }
}

void ordenarPorPuntaje(struct Puntaje p[], int n) {
   char auxNombre[20] = " ";
   char auxApellido[20] = " ";
   float auxPuntaje = 0;
   for (int i = 0; i < n; i++) {
      for (int k = 0; k < n - 1; k++) {
         if (p[k].puntos < p[k + 1].puntos) {
            //cambio puntaje
            auxPuntaje = p[k].puntos;
            p[k].puntos = p[k + 1].puntos;
            p[k + 1].puntos = auxPuntaje;
            //cambio nombre
            strcpy(auxNombre, p[k].nombre);
            strcpy(p[k].nombre, p[k + 1].nombre);
            strcpy(p[k + 1].nombre, auxNombre);
            //cambio apellido
            strcpy(auxApellido, p[k].apellido);
            strcpy(p[k].apellido, p[k + 1].apellido);
            strcpy(p[k + 1].apellido, auxApellido);
         }
      }
   }
}

void escribirJugadorEnArchivo(struct Jugador j1) {
   FILE * puntero;
   puntero = fopen("Puntaje.txt", "a");
   fprintf(puntero, "%s;%s;%.2f\n", j1.nombre, j1.apellido, j1.puntos);
   fclose(puntero);

}
