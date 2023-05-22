#include "exercicio2.h"

void insereOrdenado(int valor, NohDuplo **lista){
    NohDuplo *novoNoh=(NohDuplo*)malloc(sizeof(NohDuplo));
    novoNoh->valor=valor;
    novoNoh->prox=NULL;
    novoNoh->ant=NULL;

    if(*lista==NULL){
        *lista=novoNoh;
    }else if((novoNoh->valor<(*lista)->valor)){
        novoNoh->prox=*lista;
        (*lista)->ant=novoNoh;
        *lista=novoNoh;
    }else{
        NohDuplo *aux=*lista;
        while((novoNoh->valor>aux->valor)&&(aux->prox!=NULL)){
            aux=aux->prox;
        }
        novoNoh->prox=aux->prox;
        novoNoh->ant=aux;
        aux->prox=novoNoh;
        aux->prox->ant=novoNoh;
             
    }
}

void imprimir(NohDuplo *lista){
    for(NohDuplo *aux=lista;aux!=NULL;aux=aux->prox){
        printf("%d\n",aux->valor);
    }
}