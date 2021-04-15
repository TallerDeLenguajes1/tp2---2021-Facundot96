#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct compu{
  int velocidad;//entre 1 y 3 Gherz
  int anio;//entre 2000 y 2017
  int cantidad;//entre 1 y 4
  char *tipo_cpu;//valores del arreglo tipos
};

void cargarPC(struct compu *, char *, int);
void mostrarPCS(struct compu *, int);
void vieja(struct compu *, int);
void masRapida(struct compu *, int);

int main() {
  
  int cantPC = 5 ;
  struct compu *computadoras;
  char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};
  char *tipo = &tipos[0][0];

  computadoras = (struct compu*) malloc(sizeof(struct compu) * cantPC);
  
  cargarPC(computadoras, tipo, cantPC);
  mostrarPCS(computadoras, cantPC);
  vieja(computadoras, cantPC);
  masRapida(computadoras, cantPC);

  free(computadoras);
  
  return 0;
}

void cargarPC(struct compu *computadora, char * tipos, int cantidad){

  int tipo;
  srand (time(NULL));

  for(int i = 0; i < cantidad; i++){

    computadora[i].velocidad = 1 + rand() % 3;
    computadora[i].anio = 2000 + rand() % 18;
    computadora[i].cantidad = 1 + rand() % 4;

    tipo = rand() % 6;

    computadora[i].tipo_cpu = tipos + tipo*10;

  }

  return;
}

void mostrarPCS(struct compu *computadora, int cantidad){

  for(int i = 0; i<cantidad ; i++){

    printf("\nPC Nº: %d ", i+1);
    printf("\nClock : %d GHz", computadora[i].velocidad);
    printf(" - Año : %d ", computadora[i].anio);
    printf(" - Cant de nucleos. %d", computadora[i].cantidad);
    printf("- Modelo : %s", computadora[i].tipo_cpu);

  }

  return;
}

void vieja(struct compu* computadoras, int cantidad){

  int aux, posicion;
  aux = 2018;

  for(int i = 0; i < cantidad; i++){

    if(aux > computadoras[i].anio){

      aux = computadoras[i].anio;
      posicion = i;

    }        
    
  }

  printf("\n\nPC Nº: %d ", posicion+1);
  printf("\nClock : %d GHz", computadoras[posicion].velocidad);
  printf(" - Año : %d ", computadoras[posicion].anio);
  printf(" - Cant de nucleos. %d", computadoras[posicion].cantidad);
  printf("- Modelo : %s", computadoras[posicion].tipo_cpu);

  return;
}

void masRapida(struct compu * computadoras, int cantidad){

  int aux, posicion;
  aux = 0;

  for(int i = 0; i < cantidad; i++){

    if(aux < computadoras[i].velocidad){

      aux = computadoras[i].velocidad;
      posicion = i;

    }        
    
  }

  printf("\n\nPC Nº: %d ", posicion+1);
  printf("\nClock : %d GHz", computadoras[posicion].velocidad);
  printf(" - Año : %d ", computadoras[posicion].anio);
  printf(" - Cant de nucleos. %d", computadoras[posicion].cantidad);
  printf("- Modelo : %s", computadoras[posicion].tipo_cpu);

  return;
}