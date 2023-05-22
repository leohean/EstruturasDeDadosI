#include "exercicio1.h"

Noh* listaPares(Noh *lista, Noh *acm){
    if(lista==NULL){
        return acm;
    }else if((lista->valor%2)==0){
        acm=criaNoh(lista->valor, acm);
        listaPares(lista->prox, acm);
    }else if((lista->valor%2)==1){
        listaPares(lista->prox, acm);
    }
}