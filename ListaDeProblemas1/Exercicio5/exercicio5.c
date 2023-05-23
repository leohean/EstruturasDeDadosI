#include "exercicio5.h"

void inicializaPilha(Pilha *pilha){
    pilha->topo=NULL;
}

void inserePilha(int valor, Pilha *pilha){
    Noh *novoNoh=(Noh*)malloc(sizeof(Noh));
    novoNoh->valor=valor;
    novoNoh->prox=NULL;

    if(pilha->topo==NULL){
        pilha->topo=novoNoh;
    }else{
        novoNoh->prox=pilha->topo;
        pilha->topo=novoNoh;
    }
}

void inserePseudoFila(Pilha pilha1, Pilha *pilha2){
    for(Pilha aux=pilha1; aux.topo!=NULL; aux.topo=aux.topo->prox){
        inserePilha(aux.topo->valor,pilha2);
    }
}

void desempilha(Pilha *pilha){
    for(Pilha *aux=pilha; aux->topo!=NULL; aux->topo=aux->topo->prox){
        printf("\n%d",aux->topo->valor);
    }

    printf("\n");
}