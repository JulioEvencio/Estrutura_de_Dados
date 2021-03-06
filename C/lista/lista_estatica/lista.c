#include <stdlib.h>
#include "lista.h"

struct Lista
{
    int tamanho;
    int tamanho_max;
    Elemento *elemento;
};

int lista_inicializar(Lista **lista, int tamanho)
{
    if (tamanho < 1) return LISTA_TAMANHO_INVALIDO;

    *lista = malloc(sizeof **lista);

    if (*lista == NULL) return LISTA_SEM_MEMORIA;

    (*lista)->elemento = malloc(sizeof((*lista)->elemento) * tamanho);

    if ((*lista)->elemento == NULL)
    {
        free(*lista);
        return LISTA_SEM_MEMORIA;
    }

    (*lista)->tamanho = 0;
    (*lista)->tamanho_max = tamanho;

    return LISTA_SUCESSO;
}

void lista_liberar(Lista **lista)
{
    free((*lista)->elemento);
    free(*lista);
}

int lista_obter_tamanho(Lista **lista)
{
    return (*lista)->tamanho;
}

int lista_vazia(Lista **lista)
{
    return (*lista)->tamanho == 0;
}

int lista_cheia(Lista **lista)
{
    return (*lista)->tamanho == (*lista)->tamanho_max;
}

int lista_adicionar_inicio(Lista **lista, Elemento *elemento)
{
    if (lista_cheia(lista)) return LISTA_CHEIA;

    for (int i = (*lista)->tamanho; i >= 1; i--)
    {
        (*lista)->elemento[i] = (*lista)->elemento[i - 1];
    }

    (*lista)->elemento[0] = *elemento;
    (*lista)->tamanho++;

    return LISTA_SUCESSO;
}

int lista_adicionar_posicao(Lista **lista, Elemento *elemento, int posicao)
{
    if (lista_cheia(lista)) return LISTA_CHEIA;

    if (posicao < 1 || posicao > (*lista)->tamanho) return LISTA_POSICAO_INEXISTENTE;

    for (int i = (*lista)->tamanho; i > (posicao - 1); i--)
    {
        (*lista)->elemento[i] = (*lista)->elemento[i - 1];
    }

    (*lista)->elemento[posicao - 1] = *elemento;
    (*lista)->tamanho++;

    return LISTA_SUCESSO;
}

int lista_adicionar_final(Lista **lista, Elemento *elemento)
{
    if (lista_cheia(lista)) return LISTA_CHEIA;

    (*lista)->elemento[(*lista)->tamanho] = *elemento;
    (*lista)->tamanho++;

    return LISTA_SUCESSO;
}

int lista_remover_inicio(Lista **lista, Elemento *elemento)
{
    if (lista_vazia(lista)) return LISTA_VAZIA;

    *elemento = (*lista)->elemento[0];

    for (int i = 0; i < (*lista)->tamanho; i++)
    {
        (*lista)->elemento[i] = (*lista)->elemento[i + 1];
    }

    (*lista)->tamanho--;

    return LISTA_SUCESSO;
}

int lista_remover_posicao(Lista **lista, Elemento *elemento, int posicao)
{
    if (lista_vazia(lista)) return LISTA_VAZIA;

    if (posicao < 1 || posicao > (*lista)->tamanho) return LISTA_POSICAO_INEXISTENTE;

    *elemento = (*lista)->elemento[posicao - 1];

    for (int i = posicao; i < (*lista)->tamanho; i++)
    {
        (*lista)->elemento[i] = (*lista)->elemento[i + 1];
    }

    (*lista)->tamanho--;

    return LISTA_SUCESSO;
}

int lista_remover_final(Lista **lista, Elemento *elemento)
{
    if (lista_vazia(lista)) return LISTA_VAZIA;

    *elemento = (*lista)->elemento[(*lista)->tamanho - 1];
    (*lista)->tamanho--;

    return LISTA_SUCESSO;
}

int lista_alterar_inicio(Lista **lista, Elemento *elemento)
{
    if (lista_vazia(lista)) return LISTA_VAZIA;

    (*lista)->elemento[0] = *elemento;

    return LISTA_SUCESSO;
}

int lista_alterar_posicao(Lista **lista, Elemento *elemento, int posicao)
{
    if (lista_vazia(lista)) return LISTA_VAZIA;

    if (posicao < 1 || posicao > (*lista)->tamanho) return LISTA_POSICAO_INEXISTENTE;

    (*lista)->elemento[posicao - 1] = *elemento;

    return LISTA_SUCESSO;
}

int lista_alterar_final(Lista **lista, Elemento *elemento)
{
    if (lista_vazia(lista)) return LISTA_VAZIA;

    (*lista)->elemento[(*lista)->tamanho - 1] = *elemento;

    return LISTA_SUCESSO;
}

int lista_obter_inicio(Lista **lista, Elemento *elemento)
{
    if (lista_vazia(lista)) return LISTA_VAZIA;

    *elemento = (*lista)->elemento[0];

    return LISTA_SUCESSO;
}

int lista_obter_posicao(Lista **lista, Elemento *elemento, int posicao)
{
    if (lista_vazia(lista)) return LISTA_VAZIA;

    if (posicao < 1 || posicao > (*lista)->tamanho) return LISTA_POSICAO_INEXISTENTE;

    *elemento = (*lista)->elemento[posicao - 1];

    return LISTA_SUCESSO;
}

int lista_obter_final(Lista **lista, Elemento *elemento)
{
    if (lista_vazia(lista)) return LISTA_VAZIA;

    *elemento = (*lista)->elemento[(*lista)->tamanho - 1];

    return LISTA_SUCESSO;
}