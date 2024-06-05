
#ifndef INSCRIPTO_H_INCLUDED
#define INSCRIPTO_H_INCLUDED

#include "materia.h"
#include "lista.h"

typedef struct Inscripto
{
    char nombre[50];
    int dni;
    PtrLista listaDeMaterias;
}Inscripto;

typedef Inscripto* InscriptoPtr;

InscriptoPtr crearInscripto(char *nombre, int dni  );

void setNombreInscripto(InscriptoPtr inscripto, char *nombre);
void setDniInscripto(InscriptoPtr inscripto, int dni);

char* getNombreInscripto(InscriptoPtr inscripto);
int getDniInscripto(InscriptoPtr inscripto);

int compararInscriptos(InscriptoPtr inscripto1, InscriptoPtr inscripto2);
#endif // INSCRIPTO

