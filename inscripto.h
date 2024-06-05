#ifndef INSCRIPTO.H
#define INSCRIPTO

#include "materia.h"

typedef struct Inscripto {
  char nombre[50];
  char codigo[10];
    Materia *listaMateriasAprobadas;
  float promedio;
} Inscripto;

typedef struct InscriptoPtr *Inscripto;
#endif // INSCRIPTO

