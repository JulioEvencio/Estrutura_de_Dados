#include <stdlib.h>
#include "pilha.h"

typedef struct Pilha Nodo;
struct Pilha
{
    Elemento elemento;
    Nodo *proximo;
};

void pilha_inicializar(Pilha **pilha)
{
    *pilha = NULL;
}

void pilha_liberar(Pilha **pilha)
{
    Nodo *nodo = NULL;

    while (*pilha != NULL)
    {
        nodo = *pilha;
        *pilha = (*pilha)->proximo;
        free(nodo);
    }
}

int pilha_obter_tamanho(Pilha **pilha)
{
    int tamanho = 0;
    Nodo *nodo = *pilha;

    while (nodo != NULL)
    {
        nodo = nodo->proximo;
        tamanho++;
    }

    return tamanho;
}

int pilha_vazia(Pilha **pilha)
{
    return *pilha == NULL;
}

int pilha_empilhar(Pilha **pilha, Elemento *elemento)
{
    Nodo *nodo = malloc(sizeof *nodo);

    if (nodo == NULL) return PILHA_SEM_MEMORIA;

    nodo->elemento = *elemento;
    nodo->proximo = *pilha;
    *pilha = nodo;

    return PILHA_SUCESSO;
}

int pilha_desempilhar(Pilha **pilha, Elemento *elemento)
{
    Nodo *nodo = *pilha;

    if (nodo == NULL) return PILHA_VAZIA;

    *elemento = (*pilha)->elemento;
    *pilha = (*pilha)->proximo;
    free(nodo);

    return PILHA_SUCESSO;
}

int pilha_alterar(Pilha **pilha, Elemento *elemento)
{
    if (*pilha == NULL) return PILHA_VAZIA;

    (*pilha)->elemento = *elemento;

    return PILHA_SUCESSO;
}

int pilha_obter(Pilha **pilha, Elemento *elemento)
{
    if (*pilha == NULL) return PILHA_VAZIA;

    *elemento = (*pilha)->elemento;

    return PILHA_SUCESSO;
}