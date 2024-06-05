#ifndef MATERIA.h\
#define MATERIA.h

#include "inscripto.h"
// Definición de estructuras
typedef struct Materia {
  char nombre[50];
  int cupo;
  int inscriptos;
  InscriptoPtr listaInscriptos
} Materia;

typedef MateriaPtr *Materia;
void crearMateria(MateriaPtr materia);
void liberarMateria(MateriaPtr materia);

void setNombre(MateriaPtr materia, char nombre);
void setCupo(MateriaPtr materia,int cupo);


void agregarInscripto(MateriaPtr materia,Inscripto inscripto);
void mostrarMaterias();
#endif // MATERIA
