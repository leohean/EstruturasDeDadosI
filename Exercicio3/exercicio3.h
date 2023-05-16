#include <stdbool.h>

typedef struct cliente{
    char nome[30];
    int numItens;
    bool preferencial;
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
bool verificaNull(Fila *fila);

void geraClientes();
void criaCliente(Fila *fila, char nome[], int numItens, bool prioritario);

void enfileiraCaixasNormais(Fila *fila);
void enfileiraCaixaPref(Fila *fila);
void desenfileiraCaixa(Fila *fila);

int contaClientes(Fila *fila);

