#include <string.h>
#include "materia.h"
#include "lista.h"
#include "cola.h"
#include "inscripto.h"

MateriaPtr crearMateria(char *nombre, int cupo)
{
    MateriaPtr materia = (MateriaPtr) malloc(sizeof(Materia));

    strncpy(materia->nombre,nombre, sizeof(materia->nombre));
    materia->cupo = cupo;

    materia->listaInscriptos = crearLista();
    materia->colaEspera = crear_cola();
    return materia;
}

char* getNombreMateria(MateriaPtr materia)
{
    return materia->nombre;
}

int getCupoMateria(MateriaPtr materia)
{
    return materia->cupo;
}

int getCantidadInscripto(MateriaPtr materia)
{
    int tamanio = longitudLista(materia->listaInscriptos);

    return tamanio;
}

PtrLista getListaInscriptosMateria(MateriaPtr materia){
    return materia->listaInscriptos;
}
void setInscriptoMateria(MateriaPtr materia, InscriptoPtr inscripto)
{
    if(getCupoMateria(materia) > getCantidadInscripto(materia))
    {
        agregarDatoLista(materia->listaInscriptos, inscripto);
        printf("\nInscripto agregado!");
    }else{
        encolar(materia->colaEspera,inscripto);

        printf("\nInscripto a la cola de espera");
    }
}


void mostrarInscriptosMateria(MateriaPtr materia) {
    if (longitudLista(materia->listaInscriptos) == 0) {
        printf("\nNo hay inscriptos en la materia %s\n", materia->nombre);
        return;
    }

    printf("\nInscriptos en la lista de la materia %s:\n", materia->nombre);
    PtrNodo *actualLista = getPrimeroLista(materia->listaInscriptos);
    while (actualLista) {
        InscriptoPtr inscriptoLista = (InscriptoPtr) getDato(actualLista);
        printf("\nNombre: %s", getNombreInscripto(inscriptoLista));
        printf("\nDNI: %d", getDniInscripto(inscriptoLista));

        actualLista = getSiguiente(actualLista);
    }
    cola_t *copiaCola = copiar_cola(materia->colaEspera);
    if (cola_vacia(copiaCola)) {
        printf("\nNo hay inscriptos en la cola de espera de la materia %s\n", materia->nombre);
        return;
    }

    printf("\nInscriptos en la cola de espera de la materia %s:\n", materia->nombre);

    while (!cola_vacia(copiaCola)) {
        InscriptoPtr inscriptoCola = desencolar(copiaCola);
        printf("\nNombre: %s", getNombreInscripto(inscriptoCola));
        printf("\nDNI: %d", getDniInscripto(inscriptoCola));
    }
}



