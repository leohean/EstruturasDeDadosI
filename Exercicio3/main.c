#include <stdio.h>
#include <stdlib.h>
#include "exercicio3.h"

int main(){

    inicializaFila(&filaNormal);
    inicializaFila(&filaPref);

    inicializaFila(&caixaConvencional);
    inicializaFila(&caixaRapido);
    inicializaFila(&caixaPreferencial);

    geraClientes();

    printf("%d\n",contaClientes(&filaNormal));
    printf("%d\n",contaClientes(&filaPref));

    return 0;
}