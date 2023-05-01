typedef struct tarefa{
    char descricao[20];
    struct tarefa *prox;
    struct tarefa *ant;
}Tarefa;

void insereInicio(char tarefas[], Tarefa **lista);

void insereMeio(char tarefas[], Tarefa **lista, int pos);

void insereFinal(char tarefas[], Tarefa **lista);

void imprimiTarefa(Tarefa *lista, int numTaf);

void voidFinalizaTarefas(Tarefa *lista);