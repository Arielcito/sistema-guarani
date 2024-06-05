#include "inscripto.h"
#include "lista.h"
#include "materiaCursada.h"

InscriptoPtr crearInscripto(char *nombre, int dni  ){
    InscriptoPtr inscripto = (InscriptoPtr) malloc(sizeof(Inscripto));

    strncpy(inscripto->nombre,nombre, sizeof(inscripto->nombre));
    inscripto->dni = dni;
    inscripto->listaDeMaterias = crearLista();

    return inscripto;
}

void setNombreInscripto(InscriptoPtr inscripto, char *nombre){
    strncpy(inscripto->nombre,nombre, sizeof(inscripto->nombre));
}
void setDniInscripto(InscriptoPtr inscripto, int dni){
    inscripto->dni=dni;
}

void agregarMateriaAprobada(InscriptoPtr inscripto, MateriaCursadaPtr materia){
    agregarDatoLista(inscripto->listaDeMaterias,materia);
}
char* getNombreInscripto(InscriptoPtr inscripto){
    return inscripto->nombre;
}
int getDniInscripto(InscriptoPtr inscripto){
    return inscripto->dni;
}
float calcularPromedio(InscriptoPtr inscripto) {
  float sumaNotas = 0;
  int cantidadMaterias = 0;

  PtrNodo *actual = getPrimeroLista(inscripto->listaDeMaterias);
  while (actual) {
    MateriaCursadaPtr materia = (MateriaCursadaPtr)getDato(actual);
    sumaNotas += getNotaMateriaCursada(materia);
    cantidadMaterias++;
    actual = getSiguiente(actual);
  }

  if (cantidadMaterias > 0) {
    return sumaNotas / cantidadMaterias;
  } else {
    return 0; // No hay materias aprobadas
  }
}

int cantidadMaterias(InscriptoPtr inscripto) {
  int cantidadMaterias = 0;

  PtrNodo actual = getPrimeroLista(inscripto->listaDeMaterias);
  while (actual) {
    cantidadMaterias++;
    actual = getSiguiente(actual);
  }

  if (cantidadMaterias > 0) {

    return cantidadMaterias;
  } else {
    return 0; // No hay materias aprobadas
  }
}

void mostrarMateriasAprobadas(InscriptoPtr i)
{
    printf("\nMaterias Aprobadas de %s:\n", getNombreInscripto(i));
    PtrNodo actual = getPrimeroLista(i->listaDeMaterias);

    while(actual != NULL)
    {
        MateriaCursadaPtr materia = (MateriaCursadaPtr)getDato(actual);
        printf("\nNombre: %s",getNombreMateria(getMateriaCursada(materia)));
        printf("\nNota: %d",getNotaMateriaCursada(materia));
        printf("\n");
        actual = getSiguiente(actual);
    }
    printf("\n\n");
}


