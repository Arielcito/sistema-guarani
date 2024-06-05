#ifndef MATERIAAPROBADA_H_INCLUDED
#define MATERIAAPROBADA_H_INCLUDED
#include "materia.h"

typedef struct MateriaCursada {
  char nombreMateria[50];
  int nota;
}MateriaCursada;

typedef MateriaCursada * MateriaCursadaPtr;

MateriaCursadaPtr crearMateriaCursada(char *nombreMateria,int nota );
void liberarMateriaCursada(MateriaCursadaPtr materia);
char *getMateriaCursada(MateriaCursadaPtr m);
#endif //
