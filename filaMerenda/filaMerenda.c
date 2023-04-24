#include <stdio.h>
#include <stdlib.h>

typedef struct pessoa{
    struct pessoa *prox;
}Pessoa;

typedef struct{
    Pessoa *primeira;
    Pessoa *ultima;
}Fila;

void inicializaFila(Fila *fila){
    fila->primeira=NULL;
    fila->ultima=NULL;
}

void adicionaPessoa(Fila *fila){
    Pessoa *novaPessoa=(Pessoa*)malloc(sizeof(Pessoa));
    novaPessoa->prox=NULL;

    if(fila->primeira==NULL){
        fila->primeira=novaPessoa;
        fila->ultima=novaPessoa;
    }else{
        fila->ultima->prox=novaPessoa;
        fila->ultima=novaPessoa;
    }
}

void atendePessoa(Fila *fila){
    Pessoa *aux=fila->primeira;
    fila->primeira=fila->primeira->prox;
    free(aux);
}

int contaPessoas(Fila fila){
    int cont=0;
    for(Pessoa *aux=fila.primeira; aux!=NULL; aux=aux->prox){
        cont++;
    }

    return cont;
}

void encerrarExpediente(Fila *fila){
    Pessoa *pessoa=fila->primeira;
    while(pessoa!=NULL){
        Pessoa *aux=pessoa;
        pessoa=pessoa->prox;
        free(aux);
    }
}

int main(){
    Fila fila;
    inicializaFila(&fila);

    int resposta;
    do{
        printf("O que você deseja fazer?\n1 - Adicionar nova pessoa na fila da merenda\n2 - Atender uma pessoa na fila\n3 - Ver quantas pessoas tem na fila\n0 - Encerrar por hoje\n->");
        scanf("%d", &resposta);

        printf("\n");

        switch(resposta){
            case 1:
                adicionaPessoa(&fila);
            break;
            case 2:
                atendePessoa(&fila);
            break;
            case 3:
                printf("O número de pessoas na fila é %d\n", contaPessoas(fila));
            break;
            case 0:
            break;
        }
    }while(resposta!=0);

    return 0;
}