#include <stdio.h>
#include <stdlib.h>
/*
Enunciado 2024 - C1
Realizar un programa que simule las principales funciones del sistema Guarani.
 El sistema debe tener una lista de materias, las materias una lista de inscriptos,
  y cada inscripto debe tener una lista de materias aprobadas con su promedio.
Cada materia tiene un cupo, en caso de que se anoten m�s estudiantes que el cupo se debe generar una cola,
 para generar la cola se evaluar� como prioridad primero la cantidad de materias aprobadas y luego el promedio del estudiante.
*/

#include "materia.h"
#include "lista.h"
#include "nodo.h"
#include "inscripto.h"
#include "materiaCursada.h"

void agregarMateria();
void mostrarMaterias();
void inscribirAlumno();
void mostrarInscriptosEnMateria();
void mostrarInscriptos(PtrLista listaAlumnos);
void agregarMateriaAprobadaAlumno(PtrLista listaMaterias, PtrLista listaInscriptos);
void agregarAlumno(PtrLista listaAlumnos);

int main()
{
    PtrLista listaMaterias = crearLista();
    PtrLista listaAlumnos = crearLista();
    PtrLista listaMateriasAnotadas = crearLista();

    MateriaPtr materia = crearMateria("Matematica",1);
    MateriaPtr materia2 = crearMateria("Algoritmos",3);
    MateriaPtr materia3 = crearMateria("Base de datos",3);

    InscriptoPtr inscripto = crearInscripto("Ariel",43515134);
    InscriptoPtr inscripto2 = crearInscripto("daniel",43515134);
    InscriptoPtr inscripto3 = crearInscripto("Lucas",43515134);

    agregarDatoLista(listaAlumnos,inscripto);
    agregarDatoLista(listaAlumnos,inscripto2);
    agregarDatoLista(listaAlumnos,inscripto3);

    agregarDatoLista(listaMaterias,materia);
    agregarDatoLista(listaMaterias,materia2);
    agregarDatoLista(listaMaterias,materia3);

    setInscriptoMateria(materia,inscripto);
    setInscriptoMateria(materia,inscripto3);
    setInscriptoMateria(materia,inscripto2);

    MateriaCursadaPtr materiaCursada = crearMateria("Matematica",8);
    MateriaCursadaPtr materiaCursada2 = crearMateria("Base de datos",2);
    MateriaCursadaPtr materiaCursada3 = crearMateria("Matematica",8);
    MateriaCursadaPtr materiaCursada4 = crearMateria("Base de datos",2);
    MateriaCursadaPtr materiaCursada5 = crearMateria("Base de datos",10);

    agregarMateriaAprobada(inscripto,materiaCursada);
    agregarMateriaAprobada(inscripto,materiaCursada2);
    agregarMateriaAprobada(inscripto2,materiaCursada3);
    agregarMateriaAprobada(inscripto3,materiaCursada4);
    agregarMateriaAprobada(inscripto3,materiaCursada5);
    mostrarMenu(listaMaterias,listaAlumnos);

    return 0;
}

void mostrarMenu(PtrLista listaMaterias, PtrLista listaAlumnos)
{
    int opcion;

    do
    {
        printf("\nSISTEMA GUARANI SIMULADO\n\n");
        printf("1. Agregar Materia\n");
        printf("2. Agregar Materia Aprobada\n");
        printf("3. Agregar Alumno\n");
        printf("4. Inscribir Alumno\n");
        printf("5. Mostrar Materias\n");
        printf("6. Mostrar Inscriptos en Materia\n");
        printf("7. Mostrar Inscriptos�n\n");
        printf("8. Salir\n");
        printf("\nIngrese una opci�n: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            agregarMateria(listaMaterias);
            break;
        case 2:
            agregarMateriaAprobadaAlumno(listaMaterias,listaAlumnos);
            break;
        case 3:
            agregarAlumno(listaAlumnos);
            break;
        case 4:
            inscribirAlumno(listaMaterias);
            break;
        case 5:
            mostrarMaterias(listaMaterias);
            break;
        case 6:
            menuMostrarInscriptosEnMateria(listaMaterias);
            break;
        case 7:
            mostrarInscriptos(listaAlumnos);
            break;
        case 8:
            printf("\nGracias por usar el Sistema Guarani!\n");
            break;
        default:
            printf("\nOpci�n inv�lida. Intente nuevamente.\n");
        }
    }
    while (opcion != 8);
}

void agregarMateria(PtrLista listaMaterias)
{
    int cupo;
    char nombre[50];

    printf("Ingrese el nombre de la materia: \n");
    scanf("%s", nombre);

    printf("Ingrese el cupo de la materia: \n");
    scanf("%d", &cupo);

    MateriaPtr materia = crearMateria(nombre,cupo);
    agregarDatoLista(listaMaterias,materia);
    printf("Materia agregada correctamente.\n");
}

void mostrarMaterias(PtrLista lista)
{
    printf("Materias:\n");
    PtrNodo actual = getPrimeroLista(lista);

    while(actual != NULL)
    {
        MateriaPtr materia = (MateriaPtr)getDato(actual);
        printf("%s",getNombreMateria(materia));
        printf("\n");
        actual = getSiguiente(actual);
    }
    printf("\n\n");
}

void inscribirAlumno(PtrLista listaMaterias)
{
    mostrarMaterias(listaMaterias);

    int opcionMateria;
    do
    {
        printf("\nIngrese el número de la materia que desea inscribir (0 para salir): ");
        scanf("%d", &opcionMateria);
    }
    while (opcionMateria < 0 || opcionMateria > longitudLista(listaMaterias));

    if (opcionMateria > 0)
    {
        MateriaPtr materiaSeleccionada = (MateriaPtr) getDatoLista(listaMaterias, opcionMateria - 1);
        char nombre[50];
        int dni;

        printf("\nIngrese el nombre del inscripto: ");
        scanf("%s",nombre);

        printf("\nIngrese el dni del inscripto: ");
        scanf("%d",&dni);

        setInscriptoMateria(materiaSeleccionada,crearInscripto(nombre,dni));
    }
    else
    {
        printf("\nSaliendo de la inscripción...\n");
    }
}


void menuMostrarInscriptosEnMateria(PtrLista listaMaterias)
{
    if (longitudLista(listaMaterias) == 0)
    {
        printf("\nNo hay materias disponibles\n");
        return;
    }

    printf("\nMaterias disponibles:\n");
    PtrNodo *actual = getPrimeroLista(listaMaterias);
    int i = 1;
    while (actual)
    {
        MateriaPtr materia = (MateriaPtr) getDato(actual);
        printf("%d. %s\n", i++, getNombreMateria(materia));
        actual = getSiguiente(actual);
    }


    int opcionMateria;
    do
    {
        printf("\nIngrese el número de la materia que desea ver (0 para salir): ");
        scanf("%d", &opcionMateria);
    }
    while (opcionMateria < 0 || opcionMateria > i);

    if (opcionMateria > 0)
    {
        PtrNodo *actual = getPrimeroLista(listaMaterias);
        MateriaPtr materiaSeleccionada = NULL;
        for (int j = 1; j < opcionMateria; j++)
        {
            actual = getSiguiente(actual);
        }
        materiaSeleccionada = (MateriaPtr) getDato(actual);
        mostrarInscriptosMateria(materiaSeleccionada);
    }
    else
    {
        printf("\nSaliendo del programa...\n");
    }
}

void mostrarInscriptos(PtrLista listaAlumnos) {
    printf("Alumnos:\n");
    PtrNodo actual = getPrimeroLista(listaAlumnos);

    while(actual != NULL)
    {
        InscriptoPtr inscripto = (InscriptoPtr)getDato(actual);
        printf("\nNombre: %s",getNombreInscripto(inscripto));
        printf("\nDNI: %d",getDniInscripto(inscripto));
        printf("\n");
        mostrarMateriasAprobadas(inscripto);
        actual = getSiguiente(actual);
    }
    printf("\n\n");
}

void agregarMateriaAprobadaAlumno(PtrLista listaMaterias, PtrLista listaInscriptos)
{
    if (longitudLista(listaMaterias) == 0)
    {
        printf("\nNo hay materias disponibles\n");
        return;
    }

    printf("\nMaterias disponibles:\n");
    PtrNodo *actual = getPrimeroLista(listaMaterias);
    int i = 1;
    while (actual)
    {
        MateriaPtr materia = (MateriaPtr) getDato(actual);
        printf("%d. %s\n", i++, getNombreMateria(materia));
        actual = getSiguiente(actual);
    }


    int opcionMateria;
    do
    {
        printf("\nIngrese el número de la materia que desea ver (0 para salir): ");
        scanf("%d", &opcionMateria);
    }
    while (opcionMateria < 0 || opcionMateria > i);

    if (opcionMateria > 0)
    {
        PtrNodo *actual = getPrimeroLista(listaMaterias);
        MateriaPtr materiaSeleccionada = NULL;
        for (int j = 1; j < opcionMateria; j++)
        {
            actual = getSiguiente(actual);
        }
        materiaSeleccionada = (MateriaPtr) getDato(actual);

        agregarMateriaInscripto(listaInscriptos, materiaSeleccionada);

    }
    else
    {
        printf("\nSaliendo del programa...\n");
    }
}

void agregarAlumno(PtrLista listaAlumnos)
{
    char nombre[50];
    int dni;
    printf("\nIngrese el nombre del alumno: ");
    scanf("%s",nombre);
    printf("\nIngrese el dni del alumno: ");
    scanf("%d",&dni);
    agregarDatoLista(listaAlumnos,crearInscripto(nombre,dni));
}

void agregarMateriaInscripto(PtrLista listaInscriptos, MateriaPtr materia)
{
    int nota;
    if (longitudLista(listaInscriptos) == 0)
    {
        printf("\nNo hay inscriptos disponibles\n");
        return;
    }

    printf("\Inscriptos disponibles:\n");
    PtrNodo *actual = getPrimeroLista(listaInscriptos);
    int i = 1;
    while (actual)
    {
        InscriptoPtr inscripto = (InscriptoPtr) getDato(actual);
        printf("%d. %s\n", i++, getNombreMateria(inscripto));
        actual = getSiguiente(actual);
    }


    int opcionMateria;
    do
    {
        printf("\nIngrese el número del inscriptos que desea seleccionar(0 para salir): ");
        scanf("%d", &opcionMateria);
    }
    while (opcionMateria < 0 || opcionMateria > i);
    if (opcionMateria > 0)
    {
        PtrNodo *actual = getPrimeroLista(listaInscriptos);
        InscriptoPtr inscriptoSeleccionado = NULL;
        for (int j = 1; j < opcionMateria; j++)
        {
            actual = getSiguiente(actual);
        }
        inscriptoSeleccionado = (InscriptoPtr) getDato(actual);

        printf("\n Ingrese la nota del inscripto: ");
        scanf("%d",&nota);


        agregarMateriaAprobada(inscriptoSeleccionado,crearMateria(getNombreMateria(materia),8));
        calcularPromedio(inscriptoSeleccionado);
    }
    else
    {
        printf("\nSaliendo del programa...\n");
    }
}
