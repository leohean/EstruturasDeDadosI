#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno{
    int matricula;
    char nome[30];
    float notaP1;
    float notaP2;
    float notaExs;
    struct aluno *prox;
}Aluno;

void inicializaLista(Aluno **lista){
    lista=NULL;
}

int matricula=0;
int novaMatricula(){
    matricula++;
    return matricula;
}

int numeroDeAlunos(Aluno *lista){
    int cont=0;
    for(Aluno *aux=lista;aux!=NULL;aux=aux->prox)
        cont++;
    
    return cont;
}

void criaAluno(int matricula, char nome[], float notaP1, float notaP2, float notaExs, Aluno **lista){
    if(numeroDeAlunos(*lista)<=50){
        Aluno *novoAluno=(Aluno*)malloc(sizeof(Aluno));
        novoAluno->matricula=matricula;
        strcpy(novoAluno->nome, nome);
        novoAluno->notaP1=notaP1;
        novoAluno->notaP2=notaP2;
        novoAluno->notaExs=notaExs;
        novoAluno->prox=NULL;

        if(*lista==NULL)
            *lista=novoAluno;
        else{
            Aluno *aux=*lista;
            for(;aux->prox!=NULL;aux=aux->prox);
            aux->prox=novoAluno;
        } 
    }else{
        printf("\nNão é possível inserir mais alunos\n");
    }
}

void deletaAluno(int matricula, Aluno **lista){
    Aluno *aux=*lista;
    Aluno *anterior;

    while(aux!=NULL){
        if(aux->matricula==matricula){
            if(aux==*lista){
                *lista=aux->prox;        
            }else{
                anterior->prox=aux->prox;
            }  
            free(aux);
            break;
        }
        anterior=aux;
        aux=aux->prox;
    }
}

void deletaLista(Aluno *lista){
    if(lista!=NULL){
        Aluno *aux=lista;
        lista=lista->prox;
        free(aux);
        deletaLista(lista);
    }
}

void resultadoDosAlunos(Aluno *lista){
    printf("\n");
    for(Aluno *aux=lista; aux!=NULL; aux=aux->prox){
        if((aux->notaP1+aux->notaP2+aux->notaExs)/3>=5){
            printf("O aluno %s de matricula n° %d foi APROVADO\n", aux->nome, aux->matricula);
        }
        else{
            printf("O aluno %s de matricula n° %d foi REPROVADO\n", aux->nome, aux->matricula);
        }
    }
    printf("\n");
}

Aluno* resultadosEspecificos(Aluno *lista){
    Aluno *alunosEspecificos=NULL,*alunoMaiorP1, *alunoMaiorMed, *alunoMenorMed;
    int maiorP1=-1, maiorMed=-1, menorMed=11;

    for(Aluno *aux=lista; aux!=NULL; aux=aux->prox){
        int medAux=(aux->notaP1+aux->notaP2+aux->notaExs)/3;

        if(aux->notaP1>maiorP1){
            maiorP1=aux->notaP1;
            alunoMaiorP1=aux;
        }
        if(medAux>maiorMed){
            maiorMed=medAux;
            alunoMaiorMed=aux;
        }
        if(medAux<menorMed){
            menorMed=medAux;
            alunoMenorMed=aux;
        }
    }

    criaAluno(alunoMaiorP1->matricula, alunoMaiorP1->nome, alunoMaiorP1->notaP1, alunoMaiorP1->notaP2, alunoMaiorP1->notaExs, &alunosEspecificos);
    criaAluno(alunoMaiorMed->matricula, alunoMaiorMed->nome, alunoMaiorMed->notaP1, alunoMaiorMed->notaP2, alunoMaiorMed->notaExs, &alunosEspecificos);
    criaAluno(alunoMenorMed->matricula, alunoMenorMed->nome, alunoMenorMed->notaP1, alunoMenorMed->notaP2, alunoMenorMed->notaExs, &alunosEspecificos);

    return alunosEspecificos;
}

void print(Aluno *lista){
    printf("\n");
    for(Aluno *aux=lista;aux!=NULL;aux=aux->prox)
        printf("|\tMatricula: %d\t|\tNome: %s\t|\tProva 1: %f\t|\tProva 2: %f\t|\tExercícios: %f\t|\n", aux->matricula, aux->nome, aux->notaP1, aux->notaP2, aux->notaExs);

    printf("\n");
}
 
int main(){
    Aluno *lista=NULL;
    inicializaLista(&lista);
    
    int resposta; 
    do{
        
        printf("O que você deseja fazer?\n1 - Registrar novos alunos\n2 - Ver quantos aluno há na turma\n3 - Deletar um aluno\n4 - Mostrar o aluno com a maior nota da primeira prova, o com a maior média geral e o com a menor média\n5 - Ver quais alunos passaram e quais reprovaram\n0 - Sair\n-> ");
        scanf("%d",&resposta);
        
        switch(resposta){
            int n, matricula;
            Aluno *alunosEspecificos;
            case 1:   
                printf("\nQuantos novos alunos você quer inserir?\n-> ");
                scanf("%d",&n);
                
                for(int i=0; i<n; i++){
                    char nome[30];
                    float np1, np2, ne;

                    int matricula=novaMatricula();

                    getchar();
                    printf("\nQual o nome do aluno?\n-> ");
                    fscanf(stdin, "%s", nome);
                    
                    printf("\nQual vai ser a nota da prova 1?\n-> ");
                    scanf("%f", &np1);

                    printf("\nQual vai ser a nota da prova 2?\n-> ");
                    scanf("%f", &np2);

                    printf("\nQual vai ser a nota dos exercícios?\n-> ");
                    scanf("%f", &ne);

                    criaAluno(matricula, nome, np1, np2, ne, &lista);  
                         
                }

                print(lista);
            break;
            case 2:
                printf("\nNúmero de alunos na turma: %d\n\n", numeroDeAlunos(lista));
            break;
            case 3:
                printf("\nDigite o número da mátricula do aluno que você deseja deletar\n-> ");
                scanf("%d",&matricula);

                deletaAluno(matricula, &lista);
            break;
            case 4:
                alunosEspecificos=resultadosEspecificos(lista);

                printf("\n");
                for(Aluno *aux=alunosEspecificos;aux!=NULL;aux=aux->prox)
                    printf("|\tMatricula: %d\t|\tNome: %s\t|\n", aux->matricula, aux->nome);
                
                printf("\n");
            break;
            case 5:
                resultadoDosAlunos(lista);
            break;
            case 0:
                deletaLista(lista);
            break;
        }
    }while(resposta!=0);

    return 0;
}