#include "lista.h"

Noh* criaNoh(int valor, Noh *lista){
    Noh *novoNoh=(Noh*)malloc(sizeof(Noh));
    novoNoh->valor=valor;
    novoNoh->prox=NULL;

    if(lista==NULL){
        lista=novoNoh;
    }else{
        novoNoh->prox=lista;
        lista=novoNoh;
    }
    return lista;
}

void apagaLista(Noh *lista){
    while(lista!=NULL){
        Noh *aux=aux;
        lista=lista->prox;
        free(aux);
    }
}

void imprime(Noh *lista){
    for(;lista!=NULL;lista=lista->prox){
        printf("\n%d",lista->valor);
    }
    printf("\n\n");
}