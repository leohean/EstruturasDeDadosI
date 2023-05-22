#include "exercicio1.h"

int main(){
    Noh *lista=NULL;
    Noh *acm=NULL;

    lista=criaNoh(1,lista);
    lista=criaNoh(2,lista);
    lista=criaNoh(3,lista);
    lista=criaNoh(4,lista);
    lista=criaNoh(5,lista);
    lista=criaNoh(6,lista);

    acm=listaPares(lista,acm);

    printf("Lista Original:");
    imprime(lista);

    printf("Lista de Pares:");
    imprime(acm);

    apagaLista(lista);
    apagaLista(acm);
}