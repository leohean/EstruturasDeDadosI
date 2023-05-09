#include <stdbool.h>

typedef struct cliente{
    char nome;
    int numItens;
    bool tipoCliente;
    struct cliente *prox;
    struct cliente *ant;
}Cliente;

typedef struct fila{
    Cliente *inicio;
    Cliente *fim;
}Fila;

Fila filaNormal;
Fila filaPref;

Fila caixaConvencional;
Fila caixaRapido;
Fila caixaPreferencial;

void inicializaFila(Fila *fila);

void geraClientes();
void criaCliente(Fila *fila, int numItens);

void enfileiraCaixasNormais(Fila *fila);
void enfileiraCaixaPref(Fila *fila);

int contaClientes(Fila *fila);

