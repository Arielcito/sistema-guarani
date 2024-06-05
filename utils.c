
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Util.h"

void* obtenerMemoria(size_t tamanio){
    void* ptr=malloc(tamanio);
    if(ptr==NULL){
        printf("No se ha podido obtener memoria\n");
        exit(1);
    }
    return ptr;
}

char* stringDinamico(char* literal){
    char* buffer=(char*)obtenerMemoria(sizeof(literal));
    strcpy(buffer,literal);
    return buffer;
}

