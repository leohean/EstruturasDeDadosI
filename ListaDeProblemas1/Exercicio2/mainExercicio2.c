#include "exercicio2.h"

int main(){
    NohDuplo *lista=NULL;
    insereOrdenado(4, &lista);
    insereOrdenado(1, &lista);
    insereOrdenado(-1, &lista);
    insereOrdenado(19, &lista);
    insereOrdenado(14, &lista);
    insereOrdenado(-10000, &lista);

    imprimir(lista);
}