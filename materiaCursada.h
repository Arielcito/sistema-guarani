#ifndef MATERIAAPROBADA_H_INCLUDED
#define MATERIAAPROBADA_H_INCLUDED
#include "materia.h"

typedef struct MateriaCursada {
  MateriaPtr materia;
  int nota;
}MateriaCursada;

typedef MateriaCursada * MateriaCursadaPtr;

MateriaCursadaPtr crearMateriaCursada(MateriaPtr materia,int nota );
void liberarMateriaCursada(MateriaCursadaPtr materia);
MateriaPtr getMateriaCursada(MateriaCursadaPtr m);
#endif //
