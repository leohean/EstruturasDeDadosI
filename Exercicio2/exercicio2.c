#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

int qtdGanhadores(Pilha *pilha){
    int qtdPremios=0;
    Palavra *palavra=pilha->topo;
    Palavra *anterior=NULL;

    while((palavra!=NULL)&&(palavra->prox!=NULL)){

        if((palavra->primLetra==palavra->prox->quarLetra)&&(palavra->segLetra==palavra->prox->tercLetra)&&(palavra->tercLetra==palavra->prox->segLetra)&&(palavra->quarLetra==palavra->prox->primLetra)){
            if(pilha->topo==palavra){ 
                pilha->topo=palavra->prox->prox;
            }else{
                anterior->prox=palavra->prox->prox;
            }

            Palavra *aux=palavra, *aux2=palavra->prox;
            palavra=palavra->prox->prox;
            free(aux);
            free(aux2);
   
            qtdPremios++;
        }else{
            anterior=palavra;
            palavra=palavra->prox;
        }
        
    }

    if(pilha->topo==NULL){
        inicializaPilha(pilha);
    }

    if(qtdPremios==0){
        return qtdPremios;
    }else{
        return qtdPremios+qtdGanhadores(pilha);
    }
}

int main(){
    Pilha pilha;
    inicializaPilha(&pilha);

    int n;
    printf("Quantos visitantes vão receber letras?\n-> ");
    scanf("%d",&n);

    printf("\n");

    for(int i=0;i<n;i++){
        char primLetra, segLetra, tercLetra, quarLetra;

        printf("#%d palavra\n",(i+1));

        getchar();
        printf("Qual vai ser a primeira letra?\n-> ");
        scanf("%c",&primLetra);
        primLetra=toupper(primLetra);

        getchar();
        printf("\nQual vai ser a segunda letra?\n-> ");
        scanf("%c",&segLetra);
        segLetra=toupper(segLetra);

        getchar();
        printf("\nQual vai ser a terceira letra?\n-> ");
        scanf("%c",&tercLetra);
        tercLetra=toupper(tercLetra);

        getchar();
        printf("\nQual vai ser a quarta letra?\n-> ");
        scanf("%c",&quarLetra);
        quarLetra=toupper(quarLetra);

        printf("\n");

        inserePalavra(primLetra, segLetra, tercLetra, quarLetra, &pilha);
    }

    printf("O número de ganhadores de prêmios é %d\n",qtdGanhadores(&pilha));

    return 0;
}