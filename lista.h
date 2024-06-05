#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <stdbool.h>
#include "Nodo.h"
#include "Util.h"

typedef struct Lista Lista;

typedef Lista* PtrLista;

void* const FinLista;

PtrLista crearLista();
PtrLista destruirLista(PtrLista lista, bool remover);
int obtenerTamanioLista(PtrLista lista);
bool listaVacia(PtrLista lista);
PtrNodo getPrimeroLista(PtrLista lista);
PtrDato getDatoLista(PtrLista lista, int posicion);
PtrDato getCabecera(PtrLista lista);
PtrLista getResto(PtrLista lista);
int longitudLista(PtrLista lista);
void ordenarListaEnteros(PtrLista lista);
PtrLista duplicarLista(PtrLista lista);
void agregarDatoLista(PtrLista lista, PtrDato dato);
void agregarDatoUltimoLista(PtrLista lista, PtrDato dato);
bool insertarDatoLista(PtrLista lista, PtrDato dato, int posicion);
void agregarLista(PtrLista estaLista, PtrLista otraLista);
PtrDato removerDeLista(PtrLista lista, int posicion);
PtrDato removerPrimeroListo(PtrLista lista);
PtrDato removerUltimoLista(PtrLista lista);
bool buscarEnteroLista(PtrLista lista, int entero);
bool estaOrdenadaCrecienteListaEnteros(PtrLista lista);
bool insertarEnOrdenCrecienteListaEnteros(PtrLista lista, int entero);

// Nuevas �ltima Actividad
typedef int (*PtrComparador)(const void*, const void*);
void ordenarListaBurbuja(PtrLista lista, PtrComparador comparador);
void ordenarListaInsercion(PtrLista lista, PtrComparador comparador);
void ordenarListaSeleccion(PtrLista lista, PtrComparador comparador);
PtrNodo busquedaBinariaLista(PtrLista lista, const void* clave, PtrComparador comparador);
PtrNodo busquedaSecuencialLista(PtrLista lista, const void* clave, PtrComparador comparador);
void mostrarLista(PtrLista lista, void (*mostrarDato)(PtrDato));
void insertarEnOrden(PtrLista lista, PtrDato dato, PtrComparador comparador);

#endif // LISTA_H_INCLUDED
