
#ifndef MATERIA_H_INCLUDED
#define MATERIA_H_INCLUDED

#include "inscripto.h"
#include "lista.h"
#include "cola.h"

typedef struct Materia {
  char nombre[50];
  int cupo;
  PtrLista listaInscriptos;
  cola_t* colaEspera;
}Materia;

typedef Materia * MateriaPtr;

MateriaPtr crearMateria(char *nombre,int cupo );
void liberarMateria(MateriaPtr materia);

void setNombre(MateriaPtr materia, char nombre);
void setCupo(MateriaPtr materia,int cupo);

char *getNombreMateria(MateriaPtr materia);
int getCupoMateria(MateriaPtr materia);
int getInscriptos(MateriaPtr materia);
PtrLista getListaInscriptosMateria(MateriaPtr materia);

cola_t getColaDeEspera(MateriaPtr materia);
void agregarInscripto(MateriaPtr materia,PtrLista inscripto);
void ordernarColaPrioridad(PtrLista lista);
void mostrarMaterias();
#endif // MATERIA
