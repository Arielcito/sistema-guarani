
#ifndef COLA_H
#define COLA_H
#include "nodo.h"
typedef struct cola {
  PtrNodo primero;
  PtrNodo ultimo;
} cola_t;

// Prototipos de funciones
cola_t *crear_cola();
void destruir_cola(cola_t *cola);
void encolar(cola_t *cola, int dato);
PtrNodo desencolar(cola_t *cola);
int cola_vacia(cola_t *cola);
int cola_vacia(cola_t *cola);
cola_t *copiar_cola(cola_t *cola_original);
#endif

