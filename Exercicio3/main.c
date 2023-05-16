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

    printf("\n");

    printf("Caixa Convencional: %d\n",contaClientes(&caixaConvencional));
    printf("Caixa Rapido: %d\n",contaClientes(&caixaRapido));
    printf("Caixa Preferencial: %d\n",contaClientes(&caixaPreferencial));

    printf("\nCaixa Preferencial:\n");
    desenfileiraCaixa(&caixaPreferencial);
    printf("\nCaixa Rápido:\n");
    desenfileiraCaixa(&caixaRapido);
    printf("\nCaixa Convencional:\n");
    desenfileiraCaixa(&caixaConvencional);

    return 0;
}