#include "exercicio4.h"

int main(){
    Noh *raiz;

    inicializarArvore(&raiz);

    inserirNoh(20, &raiz);
    inserirNoh(15, &raiz);
    inserirNoh(10, &raiz);
    inserirNoh(25, &raiz);
    inserirNoh(23, &raiz);
    inserirNoh(24, &raiz);
    inserirNoh(30, &raiz);
    inserirNoh(28, &raiz);
    inserirNoh(35, &raiz);

    imprimirPreOrdem(raiz);
    printf("\n");
    imprimirInOrdem(raiz);
}