#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "organizaTarefas.h"

int main(){
    Tarefa *lista=NULL;

    int resposta, respoTaf, respostaGeren, numTaf=1;
    do{
        printf("O que você deseja fazer?\n1 - Nova tarefa\n2 - Mostrar tarefas\n0 - Sair\n-> ");
        scanf("%d", &resposta);

        printf("\n");

        switch(resposta){
            case 1:
                printf("Você deseja adicionar no...\n1 - Ínicio\n2 - Meio\n3 - Final\n-> ");
                scanf("%d", &respoTaf);

                char tarefa[20];
                printf("\nQual vai ser a tarefa?\n-> ");
                fscanf(stdin, "%s", tarefa);

                int pos;
                switch(respoTaf){
                    case 1:
                        insereInicio(tarefa, &lista);
                    break;
                    case 2:
                        printf("\nQual vai ser a posição?\n-> ");
                        scanf("%d",&pos);

                        insereMeio(tarefa, &lista, pos);
                    break;
                    case 3:
                        insereFinal(tarefa, &lista);
                    break;
                }

                printf("\n");

            break;
            case 2:
                imprimiTarefa(lista, numTaf);
                Tarefa *aux=lista;

                do{
                    printf("\nVocê deseja fazer...\n1 - Próxima tarefa\n2 - Tarefa anterior\n0 - Menu\n-> ");
                    scanf("%d", &respostaGeren);

                    if((respostaGeren==1)&&(aux!=NULL)){
                        aux=aux->prox;
                        numTaf++;
                        imprimiTarefa(aux, numTaf);
                    }else if((respostaGeren==2)&&(aux!=NULL)){
                        aux=aux->ant;
                        numTaf--;
                        imprimiTarefa(aux, numTaf);
                    }else if(aux==NULL){
                        printf("\nNão há tarefas para serem mostradas\n");
                        respostaGeren=0;
                    }

                }while(respostaGeren!=0);

                numTaf=1;

                printf("\n");

            break;
            case 0:
                voidFinalizaTarefas(lista);
            break;
        }
    }while(resposta!=0);
}