#include <stdbool.h>
#include "Lista.h"
#include "Util.h"
#include "Nodo.h"

struct Lista{
     PtrNodo primero;
};

void* const FinLista=NULL;

PtrDato getDatoLista(PtrLista lista, int posicion);

PtrLista crearLista(){
    PtrLista lista=obtenerMemoria(sizeof(Lista));
    lista->primero=FinLista;
    return lista;
}

PtrLista destruirLista(PtrLista lista, bool remover){
    if(remover){
        while(!listaVacia(lista)){
            removerDeLista(lista,0);
        }
        free(lista);
    }
    return FinLista;
}
PtrNodo getPrimeroLista(PtrLista lista){
    return lista->primero;
}
int obtenerTamanioLista(PtrLista lista) {
    int tamanio = 0;
    PtrNodo nodo = lista->primero;
    while (nodo != FinLista) {
        tamanio++;
        nodo = getSiguiente(nodo);
    }
    return tamanio;
}

bool listaVacia(PtrLista lista){
    return (lista->primero==FinLista);
}


PtrNodo getNodoLista(PtrLista lista, int posicion){
    PtrNodo nodo=lista->primero;
    int posicionActual=0;
    if(nodo!=FinLista){
        while(posicionActual<posicion && getSiguiente(nodo)!=FinLista){
            posicionActual++;
            nodo=getSiguiente(nodo);
        }
    }
    return nodo;
}

PtrNodo getUltimoLista(PtrLista lista){
    if (lista->primero == FinLista) {
        return FinLista;
    }
    PtrNodo nodo = lista->primero;
    while (getSiguiente(nodo) != FinLista) {
        nodo = getSiguiente(nodo);
    }
    return nodo;
}

PtrDato getDatoLista(PtrLista lista, int posicion){
    PtrDato dato=FinLista;

    PtrNodo nodo=getNodoLista(lista,posicion);
    if(nodo!=FinLista){
        dato=getDato(nodo);
    }
    return dato;
}

PtrDato getCabecera(PtrLista lista){
    PtrDato dato=FinLista;
    if(lista->primero!=FinLista){
        dato=getDato(lista->primero);
    }
    return dato;
}

PtrLista getResto(PtrLista lista){
    PtrLista resto=crearLista();
    if(lista->primero!=FinLista){
        resto->primero=getSiguiente(lista->primero);
    }
    return resto;
}

int longitudLista(PtrLista lista){
    int longitud=0;
    PtrNodo nodo=lista->primero;
    while(nodo!=FinLista){
        nodo=getSiguiente(nodo);
        longitud++;
    }
    return longitud;
}

void ordenarListaEnteros(PtrLista lista) {
    int tamanio = obtenerTamanioLista(lista);
    if (tamanio <= 1) {
        return;
    }

    bool intercambio;
    do {
        intercambio = false;
        PtrNodo actual = lista->primero;
        PtrNodo siguiente = getSiguiente(actual);
        while (siguiente != FinLista) {
            int datoActual = *(int*)getDato(actual);
            int datoSiguiente = *(int*)getDato(siguiente);
            if (datoActual > datoSiguiente) {
                intercambiarDatos(actual, siguiente);
                intercambio = true;
            }
            actual = siguiente;
            siguiente = getSiguiente(siguiente);
        }
    } while (intercambio);
}

PtrLista duplicarLista(PtrLista lista) {
    PtrLista nuevaLista = crearLista();
    PtrNodo nodo = lista->primero;
    while (nodo != FinLista) {
        PtrDato dato = getDato(nodo);
        agregarDatoUltimoLista(nuevaLista, dato);
        nodo = getSiguiente(nodo);
    }
    return nuevaLista;
}

void agregarDatoLista(PtrLista lista, PtrDato dato){
    PtrNodo nuevoNodo=crearNodo(dato);
    setSiguiente(nuevoNodo,lista->primero);
    lista->primero=nuevoNodo;
}

void agregarDatoUltimoLista(PtrLista lista, PtrDato dato){
    PtrNodo nuevoNodo = crearNodo(dato);
    if (lista->primero == FinLista) {
        lista->primero = nuevoNodo;
    } else {
        PtrNodo nodo = lista->primero;
        while (getSiguiente(nodo) != FinLista) {
            nodo = getSiguiente(nodo);
        }
        setSiguiente(nodo, nuevoNodo);
    }
}

bool insertarDatoLista(PtrLista lista, PtrDato dato, int posicion){
    PtrNodo nodo=getNodoLista(lista,posicion);
    bool resultado=false;
    if (nodo!=FinLista){
        PtrNodo nuevoNodo=crearNodo(dato);
        setSiguiente(nuevoNodo,getSiguiente(nodo));
        setSiguiente(nodo,nuevoNodo);
        resultado=true;
    }
    return resultado;
}



void agregarLista(PtrLista estaLista, PtrLista otraLista){
    if(estaLista->primero==FinLista){
        estaLista->primero=otraLista->primero;
    } else {
        PtrNodo nodo=estaLista->primero;
        while(getSiguiente(nodo)!=FinLista){
            nodo=getSiguiente(nodo);
        }
        setSiguiente(nodo,otraLista->primero);
    }

}


PtrDato removerDeLista(PtrLista lista, int posicion){
    PtrDato dato=NULL;
    PtrDato nodoEliminar=NULL;
    if(lista->primero!=FinLista){
        if (posicion==0){
            nodoEliminar=lista->primero;
            dato=getDato(nodoEliminar);
            lista->primero=getSiguiente(lista->primero);
            destruirNodo(nodoEliminar);

        } else {

            PtrNodo nodo=getNodoLista(lista,posicion-1);
            if(nodo!=FinLista){
                nodoEliminar=getSiguiente(nodo);
                if(nodoEliminar!=FinLista){
                    dato=getDato(nodoEliminar);
                    setSiguiente(nodo,getSiguiente(nodoEliminar));
                    destruirNodo(nodoEliminar);
                }
            }
        }
    }
    return dato;
}

PtrDato removerPrimeroListo(PtrLista lista){
    PtrDato dato = NULL;
    if (lista->primero != FinLista) {
        PtrNodo nodoEliminar = lista->primero;
        dato = getDato(nodoEliminar);
        lista->primero = getSiguiente(lista->primero);
        destruirNodo(nodoEliminar);
    }
    return dato;
}

PtrDato removerUltimoLista(PtrLista lista){
    PtrDato dato = NULL;
    if (lista->primero != FinLista) {
        PtrNodo nodo = lista->primero;
        PtrNodo nodoAnterior = FinLista;
        while (getSiguiente(nodo) != FinLista) {
            nodoAnterior = nodo;
            nodo = getSiguiente(nodo);
        }
        dato = getDato(nodo);
        if (nodoAnterior != FinLista) {
            setSiguiente(nodoAnterior, FinLista);
        } else {
            lista->primero = FinLista;
        }
        destruirNodo(nodo);
    }
    return dato;
}
bool buscarEnteroLista(PtrLista lista, int entero) {
    PtrNodo nodo = lista->primero;
    while (nodo != FinLista) {
        int dato = *(int*)getDato(nodo);
        if (dato == entero) {
            return true;
        }
        nodo = getSiguiente(nodo);
    }
    return false;
}

bool estaOrdenadaCrecienteListaEnteros(PtrLista lista) {
    PtrNodo nodo = lista->primero;
    int valorAnterior = INT_MIN;
    while (nodo != FinLista) {
        int valorActual = *(int*)getDato(nodo);
        if (valorActual < valorAnterior) {
            return false;
        }
        valorAnterior = valorActual;
        nodo = getSiguiente(nodo);
    }
    return true;
}
bool insertarEnOrdenCrecienteListaEnteros(PtrLista lista, int entero) {
    if (!estaOrdenadaCrecienteListaEnteros(lista)) {
        return false;
    }

    PtrNodo nodo = lista->primero;
    PtrNodo nodoAnterior = FinLista;
    while (nodo != FinLista) {
        int dato = *(int*)getDato(nodo);
        if (dato >= entero) {
            PtrNodo nuevoNodo = crearNodo(&entero);
            if (nodoAnterior == FinLista) {
                setSiguiente(nuevoNodo, lista->primero);
                lista->primero = nuevoNodo;
            } else {
                setSiguiente(nuevoNodo, getSiguiente(nodoAnterior));
                setSiguiente(nodoAnterior, nuevoNodo);
            }
            return true;
        }
        nodoAnterior = nodo;
        nodo = getSiguiente(nodo);
    }

    PtrNodo nuevoNodo = crearNodo(&entero);
    if (nodoAnterior == FinLista) {
        lista->primero = nuevoNodo;
    } else {
        setSiguiente(nodoAnterior, nuevoNodo);
    }
    return true;
}

void intercambiarDatos(PtrNodo nodo1, PtrNodo nodo2) {
    PtrDato temp = getDato(nodo1);
    setDato(nodo1, getDato(nodo2));
    setDato(nodo2, temp);
}

typedef int (*PtrComparador)(const void*, const void*);

void ordenarListaBurbuja(PtrLista lista, PtrComparador comparador) {
    int tamanio = obtenerTamanioLista(lista);
    if (tamanio <= 1) {
        return;
    }

    bool intercambio;
    do {
        intercambio = false;
        PtrNodo actual = lista->primero;
        PtrNodo siguiente = getSiguiente(actual);
        while (siguiente != FinLista) {
            if (comparador(getDato(actual), getDato(siguiente)) > 0) {
                intercambiarDatos(actual, siguiente);
                intercambio = true;
            }
            actual = siguiente;
            siguiente = getSiguiente(siguiente);
        }
    } while (intercambio);
}

void ordenarListaInsercion(PtrLista lista, PtrComparador comparador) {
    int tamanio = obtenerTamanioLista(lista);
    if (tamanio <= 1) {
        return;
    }

    PtrNodo actual = getSiguiente(lista->primero);
    while (actual != FinLista) {
        PtrNodo recorrido = lista->primero;
        PtrNodo anterior = FinLista;
        while (recorrido != actual && comparador(getDato(recorrido), getDato(actual)) <= 0) {
            anterior = recorrido;
            recorrido = getSiguiente(recorrido);
        }

        if (recorrido != actual) {
            PtrNodo siguiente = getSiguiente(actual);
            if (anterior == FinLista) {
                setSiguiente(actual, lista->primero);
                lista->primero = actual;
            } else {
                setSiguiente(actual, getSiguiente(anterior));
                setSiguiente(anterior, actual);
            }
            actual = siguiente;
        } else {
            actual = getSiguiente(actual);
        }
    }
}

void ordenarListaSeleccion(PtrLista lista, PtrComparador comparador) {
    int tamanio = obtenerTamanioLista(lista);
    if (tamanio <= 1) {
        return;
    }

    PtrNodo actual = lista->primero;
    while (actual != FinLista) {
        PtrNodo minimo = actual;
        PtrNodo siguiente = getSiguiente(actual);
        while (siguiente != FinLista) {
            if (comparador(getDato(siguiente), getDato(minimo)) < 0) {
                minimo = siguiente;
            }
            siguiente = getSiguiente(siguiente);
        }
        if (minimo != actual) {
            intercambiarDatos(actual, minimo);
        }
        actual = getSiguiente(actual);
    }
}

PtrNodo busquedaBinariaLista(PtrLista lista, const void* clave, PtrComparador comparador) {
    int inicio = 0;
    int fin = longitudLista(lista) - 1;

    while (inicio <= fin) {
        int medio = (inicio + fin) / 2;
        PtrDato datoMedio = getDatoLista(lista, medio);
        int comparacion = comparador(clave, datoMedio);

        if (comparacion == 0) {
            return getNodoLista(lista, medio);
        } else if (comparacion < 0) {
            fin = medio - 1;
        } else {
            inicio = medio + 1;
        }
    }

    return FinLista;
}

PtrNodo busquedaSecuencialLista(PtrLista lista, const void* clave, PtrComparador comparador) {
    PtrNodo nodo = lista->primero;
    while (nodo != FinLista) {
        if (comparador(clave, getDato(nodo)) == 0) {
            return nodo;
        }
        nodo = getSiguiente(nodo);
    }
    return FinLista;
}

void mostrarLista(PtrLista lista, void (*mostrarDato)(PtrDato)) {
    PtrNodo nodo = lista->primero;
    while (nodo != FinLista) {
        mostrarDato(getDato(nodo));
        nodo = getSiguiente(nodo);
    }
}

void insertarEnOrden(PtrLista lista, PtrDato dato, PtrComparador comparador) {
    PtrNodo nuevoNodo = crearNodo(dato);
    if (lista->primero == FinLista || comparador(getDato(lista->primero), dato) >= 0) {
        setSiguiente(nuevoNodo, lista->primero);
        lista->primero = nuevoNodo;
        return;
    }

    PtrNodo actual = lista->primero;
    while (getSiguiente(actual) != FinLista && comparador(getDato(getSiguiente(actual)), dato) < 0) {
        actual = getSiguiente(actual);
    }
    setSiguiente(nuevoNodo, getSiguiente(actual));
    setSiguiente(actual, nuevoNodo);
}
