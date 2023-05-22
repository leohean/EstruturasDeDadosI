#include "exercicio3-4.h"

bool verificaOrdemCrescenteRecursao(Noh *lista){
    if((lista==NULL)||(lista->prox==NULL)){
        return true;
    }else{
        if(lista->valor<lista->prox->valor)
            verificaOrdemCrescenteRecursao(lista->prox);
        else
            return false;
    }
}

bool verificaOrdemCrescente(Noh *lista){
    for(Noh *aux=lista;aux->prox!=NULL;aux=aux->prox){
        if(aux->valor>aux->prox->valor){
            return false;
        }
    }
    return true;
}