#include "cola.h"
#include <stddef.h>
cola_t *crear_cola()
{
    cola_t *nueva_cola = malloc(sizeof(cola_t));
    if (nueva_cola)
    {
        nueva_cola->primero = NULL;
        nueva_cola->ultimo = NULL;
    }
    return nueva_cola;
}

void destruir_cola(cola_t *cola)
{
    PtrNodo *aux;
    while (cola->primero)
    {
        aux = cola->primero;
        cola->primero = cola->primero->sgte;
        free(aux);
    }
    free(cola);
}

void encolar(cola_t *cola, int dato)
{
    PtrNodo nuevo_nodo = malloc(sizeof(PtrNodo));
    if (nuevo_nodo)
    {
        nuevo_nodo->dato = dato;
        nuevo_nodo->sgte     = NULL;

        if (!cola->primero)
        {
            cola->primero = nuevo_nodo;
        }
        else
        {
            cola->ultimo->sgte = nuevo_nodo;
        }

        cola->ultimo = nuevo_nodo;
    }
}

PtrNodo desencolar(cola_t *cola)
{
    if (cola->primero)
    {
        PtrNodo dato_frente = cola->primero;
        PtrNodo aux = cola->primero;
        cola->primero = cola->primero->sgte;

        if (!cola->primero)
        {
            cola->ultimo = NULL;
        }

        free(aux);
        return dato_frente;
    }
    else
    {
        return -1;
    }
}

int cola_vacia(cola_t *cola)
{
    return cola->primero == NULL; // Retorna 1 si la cola está vacía, 0 si no
}


cola_t *copiar_cola(cola_t *cola_original) {
    if (!cola_original) {
        return NULL;
    }

    cola_t *nueva_cola = crear_cola();
    if (!nueva_cola) {
        return NULL;
    }

    Nodo *actual = cola_original->primero;
    while (actual) {
        encolar(nueva_cola, actual->dato);
        actual = actual->sgte;
    }

    return nueva_cola;
}
