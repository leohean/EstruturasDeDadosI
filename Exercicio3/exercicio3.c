#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "exercicio3.h"

void inicializaFila(Fila *fila){
    fila->inicio=NULL;
    fila->fim=NULL;
}

int contaClientes(Fila *fila){
    Cliente *cliente=fila->inicio;

    int cont=0;
    for(;cliente!=NULL;cliente=cliente->prox){
        cont++;
    }
    return cont;
}

void criaCliente(Fila *fila, int numItens){
    Cliente *novoCliente=(Cliente*)malloc(sizeof(Cliente)); 
    novoCliente->numItens=numItens; 
    novoCliente->prox=NULL;

    if(fila->inicio==NULL){
        fila->inicio=novoCliente;
        fila->fim=novoCliente;
    }else{
        fila->fim->prox=novoCliente;
        fila->fim=novoCliente;
    }
}

void geraClientes(){
    srand(time(NULL));

    int numClientesNormais=(rand()%4)+1;
    int numClientesPref=(rand()%10)+10;

    int numItens;
    for(int i=0; i<numClientesNormais; i++){
        printf("Número de itens do cliente comum %d de %d\n-> ", (i+1), numClientesNormais);
        scanf("%d", &numItens);

        criaCliente(&filaNormal, numItens);

        printf("\n");
    }

    for(int i=0; i<numClientesPref; i++){
        printf("Número de itens do cliente preferencial %d de %d\n-> ", (i+1), numClientesPref);
        scanf("%d", &numItens);

        criaCliente(&filaPref, numItens);

        printf("\n");
    }

    enfileiraCaixaPref(&filaPref);
    enfileiraCaixasNormais(&filaNormal);
}

void enfileiraCaixasNormais(Fila *fila){
    Cliente *cliente=fila->inicio;

    for(;cliente!=NULL;cliente=cliente->prox){
        if(cliente->numItens<=10){
            if(caixaRapido.inicio==NULL){
                caixaRapido.inicio=cliente;
                caixaRapido.fim=cliente;
            }else{
                caixaRapido.fim->prox=cliente;
                caixaRapido.fim=cliente;
            }
        }else{
            if(caixaConvencional.inicio==NULL){
                caixaConvencional.inicio=cliente;
                caixaConvencional.fim=cliente;
            }else{
                caixaConvencional.fim->prox=cliente;
                caixaConvencional.fim=cliente;
            }
        }
    }
}

void enfileiraCaixaPref(Fila *fila){
    Cliente *cliente=fila->inicio;
    
    for(;cliente!=NULL;cliente=cliente->prox){
        if(caixaPreferencial.inicio==NULL){
            caixaPreferencial.inicio=cliente;
            caixaPreferencial.fim=cliente;
        }else{
            caixaPreferencial.fim->prox=cliente;
            caixaPreferencial.fim=cliente;
        }
    }
}