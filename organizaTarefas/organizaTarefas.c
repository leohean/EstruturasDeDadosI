#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "organizaTarefas.h"

void insereInicio(char tarefas[], Tarefa **lista){
    Tarefa *novaTarefa=(Tarefa*)malloc(sizeof(Tarefa));
    strcpy(novaTarefa->descricao, tarefas);
    novaTarefa->prox=NULL;
    novaTarefa->ant=NULL;

    if(*lista==NULL){
        *lista=novaTarefa;
    }else{
        novaTarefa->prox=*lista;
        (*lista)->ant=novaTarefa;
        *lista=novaTarefa;
    }
}

void insereMeio(char tarefas[], Tarefa **lista, int pos){
    Tarefa *novaTarefa=(Tarefa*)malloc(sizeof(Tarefa));
    strcpy(novaTarefa->descricao, tarefas);
    novaTarefa->prox=NULL;
    novaTarefa->ant=NULL;

    if(*lista==NULL){

    }else{
        Tarefa *aux=*lista;
        for(int i=1;i!=(pos-1);i++){
            aux=aux->prox;
        }
        novaTarefa->prox=aux->prox;
        novaTarefa->ant=aux;
        aux->prox->ant=novaTarefa;
        aux->prox=novaTarefa;
    }
}

void insereFinal(char tarefas[], Tarefa **lista){
    Tarefa *novaTarefa=(Tarefa*)malloc(sizeof(Tarefa));
    strcpy(novaTarefa->descricao, tarefas);
    novaTarefa->prox=NULL;
    novaTarefa->ant=NULL;

    Tarefa *aux=*lista;
    for(;aux->prox!=NULL;aux=aux->prox);

    aux->prox=novaTarefa;
    novaTarefa->ant=aux;
}

void imprimiTarefa(Tarefa *lista, int numTaf){
    if(lista!=NULL)
        printf("#%d Tarefa %s\n", numTaf, lista->descricao);
}

void voidFinalizaTarefas(Tarefa *lista){
    Tarefa *aux;
    while(lista!=NULL){
        aux=lista;
        lista=lista->prox;
        free(aux);
    }
}