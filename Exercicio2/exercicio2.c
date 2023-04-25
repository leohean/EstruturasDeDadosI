#include <stdio.h>
#include <stdlib.h>

typedef struct palavra{
    char primLetra, segLetra, tercLetra, quarLetra;
    struct palavra *prox;
}Palavra;

typedef struct{
    Palavra *topo;
}Pilha;


void inserePalavra(char primLetra, char segLetra, char tercLetra, char quarLetra, Pilha *pilha){
    Palavra *novaPalavra=(Palavra*)malloc(sizeof(Palavra));
    novaPalavra->primLetra=primLetra;
    novaPalavra->segLetra=segLetra;
    novaPalavra->tercLetra=tercLetra;
    novaPalavra->quarLetra=quarLetra;
    novaPalavra->prox=NULL;

    if(pilha->topo==NULL){
        pilha->topo=novaPalavra;
    }else{
        novaPalavra->prox=pilha->topo;
        pilha->topo=novaPalavra;
    }
}

void inicializaPilha(Pilha *pilha){
    pilha->topo=NULL;
    inserePalavra('F','A','C','E',pilha);
}

int qtdPremios(Pilha *pilha){
    Palavra *aux;
    if((pilha->topo!=NULL)&&(pilha->topo->prox!=NULL)){
        aux=pilha->topo;
        pilha->topo=pilha->topo->prox;

        if((aux->primLetra==pilha->topo->quarLetra)&&(aux->segLetra==pilha->topo->tercLetra)&&(aux->tercLetra==pilha->topo->segLetra)&&(aux->quarLetra==pilha->topo->primLetra)){
            free(aux);
            return 1+qtdPremios(pilha);
        }else{
            free(aux);
            return 0+qtdPremios(pilha);
        }
    }else{
        return 0;
    }
}

int main(){
    Pilha pilha;
    inicializaPilha(&pilha);

    /*
    int resposta;
    do{
        printf('O que você deseja fazer?\n1 - Adicionar novas letras\n2 - Ver quantos prêmios foram dados\n0 - finalizar\n');
        scanf("%d", &resposta);

        switch(){
            case 1:
            break;
            case 2:
            break;
            case 0:
            break;
        }

    }while(resposta!=0);
    */

    inserePalavra('E','C','A','F',&pilha);
    inserePalavra('E','C','F','A',&pilha);
    inserePalavra('A','C','E','F',&pilha);
    inserePalavra('F','E','C','A',&pilha);
    inserePalavra('A','C','E','F',&pilha);

    printf("%d",qtdPremios(&pilha));
    return 0;
}