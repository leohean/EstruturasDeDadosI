#include <stdio.h>
#include <stdlib.h>

typedef struct prato{
    struct prato *prox;
}Prato;

typedef struct{
    Prato *topoDaPilha;
}Pilha;

void inicializaPilha(Pilha *pilha){
    pilha->topoDaPilha=NULL;
}

void colocaPrato(Pilha *pilha){
    Prato *novoPrato=(Prato*)malloc(sizeof(Prato));
    novoPrato->prox=pilha->topoDaPilha;
    pilha->topoDaPilha=novoPrato;
}

void lavaPrato(Pilha *pilha){
    Prato *aux=pilha->topoDaPilha;
    pilha->topoDaPilha=pilha->topoDaPilha->prox;
    free(aux);
}

int contaPratos(Pilha pilha){
    Pilha aux=pilha;
    int cont=0;
    while(aux.topoDaPilha!=NULL){
        aux.topoDaPilha=aux.topoDaPilha->prox;
        cont++;
    }
    return cont;
}

void quebraPratos(Pilha *pilha){
    Prato *aux;
    
    while(pilha->topoDaPilha!=NULL){
        aux=pilha->topoDaPilha;
        pilha->topoDaPilha=pilha->topoDaPilha->prox;
        free(aux);
    }
}

int main(){
    Pilha pilha;
    inicializaPilha(&pilha);

    int resposta;
    do{
        printf("Digite o que você deseja fazer\n1 - Adicionar prato\n2 - Lavar prato\n3 - Quantos pratos tem pra lavar?\n0 - Finalizar\n-> ");
        scanf("%d",&resposta);

        printf("\n");

        switch(resposta){
            case 1:
                colocaPrato(&pilha);
            break;
            case 2:
                lavaPrato(&pilha);
            break;
            case 3:
                printf("Tem %d pratos para lavar\n\n", contaPratos(pilha));
            break;
            case 0:
                quebraPratos(&pilha);
            break;
        }
    }while(resposta!=0);

    
    return 0;
}