#include <stdio.h>
#include <stdlib.h>

typedef struct noh{
    int valor;
    struct noh *prox;
}Noh;

typedef struct pilha{
    Noh *topo;
}Pilha;

void inicializaPilha(Pilha *pilha);
void inserePilha(int valor, Pilha *pilha);
void inserePseudoFila(Pilha pilha1, Pilha *pilha2);
void desempilha(Pilha *pilha);