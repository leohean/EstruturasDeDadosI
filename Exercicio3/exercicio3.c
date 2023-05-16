#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "exercicio3.h"

void inicializaFila(Fila *fila){
    fila->inicio=NULL;
    fila->fim=NULL;
}

bool verificaNull(Fila *fila){
    if(fila->inicio==NULL)
        return true;
    else
        return false;
}

int contaClientes(Fila *fila){
    Cliente *cliente=fila->inicio;

    int cont=0;
    for(;cliente!=NULL;cliente=cliente->prox){
        cont++;
    }
    return cont;
}

void criaCliente(Fila *fila, char nome[], int numItens, bool preferencial){
    Cliente *novoCliente=(Cliente*)malloc(sizeof(Cliente)); 
    novoCliente->numItens=numItens; 
    strcpy(novoCliente->nome, nome);
    novoCliente->preferencial=preferencial;
    novoCliente->prox=NULL;
    novoCliente->ant=NULL;

    if(fila->inicio==NULL){
        fila->inicio=novoCliente;
        fila->fim=novoCliente;
    }else{
        novoCliente->ant=fila->fim;
        fila->fim->prox=novoCliente;
        fila->fim=novoCliente;
    }
}

void geraClientes(){
    srand(time(NULL));

    int numClientesNormais=(rand()%10)+10;
    int numClientesPref=(rand()%4)+1;

    int numItens;
    char nome[30];

    for(int i=0; i<numClientesNormais; i++){
        printf("# Cliente Comum %d de %d\n", (i+1), numClientesNormais);

        printf("Nome\n-> ");
        scanf("%s",nome);

        printf("Número de itens\n-> ");
        scanf("%d", &numItens);

        criaCliente(&filaNormal, nome, numItens, false);
        getchar();

        printf("\n");
    }

    for(int i=0; i<numClientesPref; i++){
        printf("# Cliente Preferencial %d de %d\n", (i+1), numClientesPref);

        printf("Nome\n-> ");
        scanf("%s",nome);

        printf("Número de itens\n-> ");
        scanf("%d", &numItens);

        criaCliente(&filaPref, nome, numItens, true);
        getchar();

        printf("\n");
    }

    enfileiraCaixaPref(&filaPref);
    enfileiraCaixasNormais(&filaNormal);
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
        printf("\nCliente adicionado(a) ao Caixa Preferencial");
    }

    printf("\n");

    caixaPreferencial.fim->prox=NULL;
}

void enfileiraCaixasNormais(Fila *fila){
    Cliente *cliente=fila->inicio;

    int contCaixaConvencional=0, contCaixaRapido=0;

    for(;cliente!=NULL;cliente=cliente->prox){
        if((cliente->numItens<=10)&&(contCaixaRapido<7)){
            if(caixaRapido.inicio==NULL){
                caixaRapido.inicio=cliente;
                caixaRapido.fim=cliente;
            }else{
                caixaRapido.fim->prox=cliente;
                caixaRapido.fim=cliente;
            }

            contCaixaRapido++;
            if(contCaixaRapido==7){
                printf("\nCliente adicionado(a) ao Caixa Rápido");
                printf("\nCAIXA RÁPIDO FECHADO\n");
            }  
            else
                printf("\nCliente adicionado(a) ao Caixa Rápido");

        }else if((cliente->numItens>10)&&(contCaixaConvencional<5)){
            if(caixaConvencional.inicio==NULL){
                caixaConvencional.inicio=cliente;
                caixaConvencional.fim=cliente;
            }else{
                caixaConvencional.fim->prox=cliente;
                caixaConvencional.fim=cliente;
            }

            contCaixaConvencional++;
            if(contCaixaConvencional==5){
                printf("\nCliente adicionado(a) ao Caixa Convencional");
                printf("\nCAIXA CONVENCIONAL FECHADO\n");
            }  
            else
                printf("\nCliente adicionado(a) ao Caixa Convencional");
        }else{
            caixaPreferencial.fim->prox=cliente;
            caixaPreferencial.fim=cliente;
            printf("\nCliente adicionado(a) ao Caixa Preferencial");
        }

        printf("\n");
    }

    if(!verificaNull(&caixaConvencional))
        caixaConvencional.fim->prox=NULL;
    if(!verificaNull(&caixaRapido))
        caixaRapido.fim->prox=NULL;
    
    caixaPreferencial.fim->prox=NULL;
}

void desenfileiraCaixa(Fila *fila){
    float tempoTotal=0;
    int numClientes=0;
    while(fila->inicio!=NULL){
        Cliente *aux=fila->inicio;
        fila->inicio=fila->inicio->prox;

        if(aux->preferencial==true)
            printf("O(A) cliente prioritário %s com %d itens está sendo atendido(a)\n",aux->nome, aux->numItens);
        else
            printf("O(A) cliente comum %s com %d itens está sendo atendido(a)\n",aux->nome, aux->numItens);

        tempoTotal+=aux->numItens;
        numClientes++;

        free(aux);  
    }

    if(numClientes!=0){
        float tempoMedio=tempoTotal/numClientes;
        printf("O tempo medio de serviço para este caixa é %f\n",tempoMedio);
    }
}

