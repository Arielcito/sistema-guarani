#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef void* PtrDato;

typedef struct Nodo {
    PtrDato dato;
    struct Nodo *sgte;
} Nodo;

typedef Nodo* PtrNodo;

void* const SinNodoSgte;

PtrNodo crearNodo(PtrDato dato);
PtrNodo destruirNodo(PtrNodo nodo);
void setDato(PtrNodo nodo, PtrDato dato);
PtrDato getDato(PtrNodo nodo);
void setSiguiente(PtrNodo esteNodo, PtrNodo siguienteNodo);
PtrNodo getSiguiente(PtrNodo nodo);

#endif // NODO_H_INCLUDED
