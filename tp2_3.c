#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define filas 15

void cargarMatriz(int *, int);
void mostrarMatriz(int *, int);
int paresFila(int *);
void vectorPares(int *, int , int *);
void mostrarVector(int*);

int main() {
  
  int columnasMin = 5, columnasMax = 15, columnas;

  srand(time(NULL));//genero un numero aleatorio entre 5 y 15
  columnas = (int) 5 + rand() % ( 15 - 5 );

  int mt [filas] [columnas], vectorPar[filas],*punteroVt, *punteromt;

  punteromt = &mt[0][0];
  punteroVt = &vectorPar[0];

  cargarMatriz(punteromt , columnas);
  mostrarMatriz(punteromt, columnas);
  vectorPares(punteromt, columnas, punteroVt);
  
  
  return 0;
}

void cargarMatriz(int *matriz, int columnas){

  int *valElemento = matriz;

  for(int i = 0; i <= filas; i++){

    for(int j = 0; j < columnas ; j++){

      srand( time(NULL) );
      *valElemento =  (int) 100 + rand() % ( 999 - 100 );

      valElemento++;

    }

  }

  return;
}

void mostrarMatriz(int *matriz, int columnas){

  int *valElemento = matriz;

  for(int i = 0; i <= filas; i++){

    for(int j = 0; j < columnas ; j++){

      printf("%d", *valElemento);

      valElemento++;

    }

    printf("\n");

  }

  return;
}

int paresFila(int * matriz){

  int *valElemento = matriz;
  int cantPares = 0;

  for(int i = 0 ; i < filas; i++){

    if( *valElemento % 2 == 0){

      cantPares++;

    }

  }

  return cantPares;
}

void vectorPares(int * matriz, int columnas, int * vector){

  int *valElemento = matriz;
  int *valVector = vector;

  for(int i = 0; i < columnas; i++){

    *valVector = paresFila(matriz);
    valElemento = valElemento + filas;

    valVector++;

  }

  return;
}

void mostrarVector(int* vector){

  int *valElemento = vector;

  for(int i = 0; i < filas; i++){

    printf("%d - ", *valElemento);
    valElemento++;

  }

  return;
}