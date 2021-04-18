#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

#define FILA_SUCESSO 0
#define FILA_SEM_MEMORIA -1
#define FILA_VAZIA -2

struct Elemento {
    int x;
};
typedef struct Elemento Elemento;

typedef struct Nodo Fila;

void fila_inicializar(Fila **fila);
void fila_liberar(Fila **fila);

int fila_tamanho(Fila **fila);
int fila_vazia(Fila **fila);

int fila_adicionar(Fila **fila, Elemento *elemento);
int fila_remover(Fila **fila);

int fila_obter(Fila **fila, Elemento *elemento);

#endif