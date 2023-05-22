#include <stdio.h>
#include <stdlib.h>

typedef struct noh{
    int valor;
    struct noh *prox;
}Noh;

Noh* criaNoh(int valor, Noh *lista);
void apagaLista(Noh *lista);
void imprime(Noh *lista);
