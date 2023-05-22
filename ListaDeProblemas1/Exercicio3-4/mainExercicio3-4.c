#include "exercicio3-4.h"

int main(){
    Noh *lista=NULL;

    lista=criaNoh(6,lista);
    lista=criaNoh(5,lista);
    lista=criaNoh(4,lista);
    lista=criaNoh(3,lista);
    lista=criaNoh(2,lista);
    lista=criaNoh(1,lista);

    imprime(lista);

    printf("A lista é crescente? %d",verificaOrdemCrescente(lista));
}