#include <stdlib.h>
#include "lista.h"

typedef struct Lista Nodo;
struct Lista
{
    Elemento elemento;
    Nodo *proximo;
};

void lista_inicializar(Lista **lista)
{
    *lista = NULL;
}

void lista_liberar(Lista **lista)
{
    Nodo *nodo = NULL;

    while (*lista != NULL)
    {
        nodo = *lista;
        *lista = (*lista)->proximo;
        free(nodo);
    }
}

int lista_obter_tamanho(Lista **lista)
{
    int tamanho = 0;
    Nodo *nodo = *lista;

    while (nodo != NULL)
    {
        nodo = nodo->proximo;
        tamanho++;
    }

    return tamanho;
}

int lista_vazia(Lista **lista)
{
    return *lista == NULL;
}

int lista_adicionar_inicio(Lista **lista, Elemento *elemento)
{
    Nodo *nodo = malloc(sizeof *nodo);

    if (nodo == NULL) return LISTA_SEM_MEMORIA;

    nodo->elemento = *elemento;
    nodo->proximo = *lista;
    *lista = nodo;

    return LISTA_SUCESSO;
}

int lista_adicionar_posicao(Lista **lista, Elemento *elemento, int posicao)
{
    Nodo *nodo = NULL;

    if (posicao < 1 || posicao > lista_tamanho(lista))
    {
        return LISTA_POSICAO_INEXISTENTE;
    }

    nodo = malloc(sizeof *nodo);

    if (nodo == NULL) return LISTA_SEM_MEMORIA;

    nodo->elemento = *elemento;

    if (posicao == 1)
    {
        nodo->proximo = *lista;
        *lista = nodo;
    }
    else
    {
        Nodo *nodo_anterior = NULL, *nodo_atual = *lista;

        for (int i = 1; i < posicao; i++)
        {
            nodo_anterior = nodo_atual;
            nodo_atual = nodo_atual->proximo;
        }

        nodo_anterior->proximo = nodo;
        nodo->proximo = nodo_atual;
    }

    return LISTA_SUCESSO;
}

int lista_adicionar_final(Lista **lista, Elemento *elemento)
{
    Nodo *nodo = malloc(sizeof *nodo);

    if (nodo == NULL) return LISTA_SEM_MEMORIA;

    nodo->elemento = *elemento;

    if (*lista == NULL)
    {
        nodo->proximo = *lista;
        *lista = nodo;
    }
    else
    {
        Nodo *auxiliar = *lista;

        while (auxiliar->proximo != NULL)
        {
            auxiliar = auxiliar->proximo;
        }

        nodo->proximo = auxiliar->proximo;
        auxiliar->proximo = nodo;
    }

    return LISTA_SUCESSO;
}

int lista_remover_inicio(Lista **lista, Elemento *elemento)
{
    Nodo *nodo = *lista;

    if (nodo == NULL) return LISTA_VAZIA;

    *elemento = (*lista)->elemento;
    *lista = (*lista)->proximo;
    free(nodo);

    return LISTA_SUCESSO;
}

int lista_remover_posicao(Lista **lista, Elemento *elemento, int posicao)
{
    Nodo *nodo = *lista;

    if (nodo == NULL) return LISTA_VAZIA;

    if (posicao < 1 || posicao > lista_tamanho(lista))
    {
        return LISTA_POSICAO_INEXISTENTE;
    }

    if (posicao == 1)
    {
        *elemento = nodo->elemento;
        *lista = (*lista)->proximo;
        free(nodo);
    }
    else
    {
        Nodo *auxiliar = NULL;

        for (int i = 1; i < posicao; i++)
        {
            auxiliar = nodo;
            nodo = nodo->proximo;
        }

        *elemento = nodo->elemento;
        auxiliar->proximo = nodo->proximo;
        free(nodo);
    }

    return LISTA_SUCESSO;
}

int lista_remover_final(Lista **lista, Elemento *elemento)
{
    Nodo *nodo = *lista;

    if (nodo == NULL) LISTA_VAZIA;

    if ((*lista)->proximo == NULL)
    {
        *elemento = nodo->elemento;
        *lista = (*lista)->proximo;
        free(nodo);
    }
    else
    {
        Nodo *auxiliar = NULL;

        while (nodo->proximo != NULL)
        {
            auxiliar = nodo;
            nodo = nodo->proximo;
        }

        *elemento = nodo->elemento;
        auxiliar->proximo = nodo->proximo;
        free(nodo);
    }

    return LISTA_SUCESSO;
}

int lista_alterar_inicio(Lista **lista, Elemento *elemento)
{
    if (*lista == NULL) return LISTA_VAZIA;

    (*lista)->elemento = *elemento;

    return LISTA_SUCESSO;
}

int lista_alterar_posicao(Lista **lista, Elemento *elemento, int posicao)
{
    Nodo *nodo = *lista;

    if (nodo == NULL) return LISTA_VAZIA;

    if (posicao < 1 || posicao > lista_tamanho(lista))
    {
        return LISTA_POSICAO_INEXISTENTE;
    }

    for (int i = 1; i < posicao; i++)
    {
        nodo = nodo->proximo;
    }

    nodo->elemento = *elemento;

    return LISTA_SUCESSO;
}

int lista_alterar_final(Lista **lista, Elemento *elemento)
{
    Nodo *nodo = *lista;

    if (nodo == NULL) return LISTA_VAZIA;

    while (nodo->proximo != NULL)
    {
        nodo = nodo->proximo;
    }

    nodo->elemento = *elemento;

    return LISTA_SUCESSO;
}

int lista_obter_inicio(Lista **lista, Elemento *elemento)
{
    if (*lista == NULL) return LISTA_VAZIA;

    *elemento = (*lista)->elemento;

    return LISTA_SUCESSO;
}

int lista_obter_posicao(Lista **lista, Elemento *elemento, int posicao)
{
    Nodo *nodo = *lista;

    if (nodo == NULL) return LISTA_VAZIA;

    if (posicao < 1 || posicao > lista_tamanho(lista))
    {
        return LISTA_POSICAO_INEXISTENTE;
    }

    for (int i = 1; i < posicao; i++)
    {
        nodo = nodo->proximo;
    }

    *elemento = nodo->elemento;

    return LISTA_SUCESSO;
}

int lista_obter_final(Lista **lista, Elemento *elemento)
{
    Nodo *nodo = *lista;

    if (nodo == NULL) return LISTA_VAZIA;

    while (nodo->proximo != NULL)
    {
        nodo = nodo->proximo;
    }

    *elemento = nodo->elemento;

    return LISTA_SUCESSO;
}