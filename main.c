#include <stdio.h>
#include <stdlib.h>
/*
Enunciado 2024 - C1
Realizar un programa que simule las principales funciones del sistema Guarani.
 El sistema debe tener una lista de materias, las materias una lista de inscriptos,
  y cada inscripto debe tener una lista de materias aprobadas con su promedio.
Cada materia tiene un cupo, en caso de que se anoten más estudiantes que el cupo se debe generar una cola,
 para generar la cola se evaluará como prioridad primero la cantidad de materias aprobadas y luego el promedio del estudiante.
 materias -> lista de inscriptos -> alumnos


*/
int main()
{
    // Inicialización de variables globales
  listaMaterias = NULL;
  listaEspera = NULL;

  // Menú principal
  mostrarMenu();

  return 0;
}

void mostrarMenu() {
  int opcion;

  do {
    printf("\n\nSISTEMA GUARANI SIMULADO\n\n");
    printf("1. Agregar Materia\n");
    printf("2. Mostrar Materias\n");
    printf("3. Inscribir Alumno\n");
    printf("4. Mostrar Inscriptos en Materia\n");
    printf("5. Mostrar Cola de Inscripción\n");
    printf("6. Salir\n");
    printf("\nIngrese una opción: ");
    scanf("%d", &opcion);

    switch (opcion) {
      case 1:
        agregarMateria();
        break;
      case 2:
        mostrarMaterias();
        break;
      case 3:
        inscribirAlumno();
        break;
      case 4:
        mostrarInscriptosEnMateria();
        break;
      case 5:
        mostrarColaInscripcion();
        break;
      case 6:
        printf("\n¡Gracias por usar el Sistema Guarani Simulado!\n");
        break;
      default:
        printf("\nOpción inválida. Intente nuevamente.\n");
    }
  } while (opcion != 6);
}
