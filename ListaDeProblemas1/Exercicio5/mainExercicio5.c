#include "exercicio5.h"

int main(){
    Pilha pilha1;
    inicializaPilha(&pilha1);

    inserePilha(1,&pilha1);
    inserePilha(2,&pilha1);
    inserePilha(3,&pilha1);
    inserePilha(4,&pilha1);
    inserePilha(5,&pilha1);

    Pilha pilha2;
    inicializaPilha(&pilha2);

    inserePseudoFila(pilha1, &pilha2);

    desempilha(&pilha1);
    desempilha(&pilha2);
}