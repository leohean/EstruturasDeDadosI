#include <stdio.h>
#include <stdlib.h>

typedef struct noh{
    int valor;
    struct noh *dir;
    struct noh *esq;
}Noh;

void inicializarArvore(Noh **raiz);
void inserirNoh(int valor, Noh **raiz);


void imprimirPreOrdem(Noh *raiz);
void imprimirInOrdem(Noh *raiz);