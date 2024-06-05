#include "materiaCursada.h"

MateriaCursadaPtr crearMateriaCursada(MateriaPtr materia,int nota )
{
    MateriaCursadaPtr m = (MateriaCursadaPtr) malloc(sizeof(MateriaCursada));

    m->materia = materia;
    m->nota = nota;
    return m;
}

MateriaPtr getMateriaCursada(MateriaCursadaPtr m){
    return m->materia;
}

int getNotaMateriaCursada(MateriaCursadaPtr m){return m->nota;}
