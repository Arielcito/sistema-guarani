#include "materiaCursada.h"

MateriaCursadaPtr crearMateriaCursada(char *nombre,int nota )
{
    MateriaCursadaPtr m = (MateriaCursadaPtr) malloc(sizeof(MateriaCursada));

    strncpy(m->nombreMateria,nombre, sizeof(m->nombreMateria));
    m->nota = nota;
    return m;
}

char *getMateriaCursada(MateriaCursadaPtr m){
    return m->nombreMateria;
}

int getNotaMateriaCursada(MateriaCursadaPtr m){return m->nota;}
