#include "inscripto.h"
#include "lista.h"
#include "materiaCursada.h"

InscriptoPtr crearInscripto(char *nombre, int dni  )
{
    InscriptoPtr inscripto = (InscriptoPtr) malloc(sizeof(Inscripto));

    strncpy(inscripto->nombre,nombre, sizeof(inscripto->nombre));
    inscripto->dni = dni;
    inscripto->listaDeMaterias = crearLista();
    inscripto->promedio = 0;
    inscripto->cantidadMateriasAprobadas = 0;
    return inscripto;
}

void setNombreInscripto(InscriptoPtr inscripto, char *nombre)
{
    strncpy(inscripto->nombre,nombre, sizeof(inscripto->nombre));
}
void setDniInscripto(InscriptoPtr inscripto, int dni)
{
    inscripto->dni=dni;
}

void setPromedioInscripto(InscriptoPtr inscripto, float promedio)
{
    inscripto->promedio = promedio;
}
void setCantidadAprobadasInscripto(InscriptoPtr inscripto, int cantidadAprobadas)
{
    inscripto->cantidadMateriasAprobadas = cantidadAprobadas;
}

void agregarMateriaAprobada(InscriptoPtr inscripto, MateriaCursadaPtr materia)
{
    agregarDatoLista(inscripto->listaDeMaterias,materia);
}
int getCantidadMaterias(InscriptoPtr i){
    return i->cantidadMateriasAprobadas;
}
float getPromedioMaterias(InscriptoPtr i){
    return i->promedio;
}
char* getNombreInscripto(InscriptoPtr inscripto)
{
    return inscripto->nombre;
}
int getDniInscripto(InscriptoPtr inscripto)
{
    return inscripto->dni;
}
float calcularPromedio(InscriptoPtr inscripto)
{
    float sumaNotas = 0;
    int cantidadMaterias = 0;

    PtrNodo actual = getPrimeroLista(inscripto->listaDeMaterias);
    while (actual)
    {
        MateriaCursadaPtr materia = (MateriaCursadaPtr)getDato(actual);

        sumaNotas += getNotaMateriaCursada(materia);
        cantidadMaterias++;
        actual = getSiguiente(actual);
    }

    if (cantidadMaterias > 0)
    {
        float promedio = sumaNotas / cantidadMaterias;
        setCantidadAprobadasInscripto(inscripto,cantidadMaterias);
        setPromedioInscripto(inscripto, promedio);
        printf("\nNuevo promedio: %f",inscripto->promedio);
        printf("\nNueva cantidad Materias: %d",inscripto->cantidadMateriasAprobadas);
        return promedio;
    }
    else
    {
        return 0;
    }
}



void mostrarMateriasAprobadas(InscriptoPtr i)
{
    printf("\nMaterias Aprobadas de %s:\n", getNombreInscripto(i));
    PtrNodo actual = getPrimeroLista(i->listaDeMaterias);

    while(actual != NULL)
    {
        MateriaCursadaPtr materia = (MateriaCursadaPtr)getDato(actual);
        MateriaPtr m = getMateriaCursada(materia);
        printf("\nNombre: %s",getNombreMateria(m));
        printf("\nNota: %d",getNotaMateriaCursada(materia));
        printf("\n");
        actual = getSiguiente(actual);
    }
    printf("\n\n");
}


