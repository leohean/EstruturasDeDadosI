#include <stdio.h>
#include <stdlib.h>

typedef struct nohDuplo{
    int valor;
    struct nohDuplo *prox;
    struct nohDuplo *ant;
}NohDuplo;

void insereOrdenado(int valor, NohDuplo **lista);
void imprimir(NohDuplo *lista);