#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

/*  Constantes */
#define LISTA_SUCESSO 0
#define LISTA_ENDERECO_INVALIDO -1
#define LISTA_LISTA_CHEIA -2
#define LISTA_LISTA_VAZIA -3
#define LISTA_POSICAO_INEXISTENTE -4
#define LISTA_TAMANHO_INVALIDO -5

/*  Estruturas */
struct Tipo_Lista
{
    int tamanho;
    int tamanho_max;
    Elemento *elemento;
};
typedef struct Tipo_Lista Lista;

/*  Funcoes */
int LISTA_InicializarLista(Lista *lista, int tamanho_max)
{
    if(lista == NULL) return LISTA_ENDERECO_INVALIDO;
    if(tamanho_max < 1) return LISTA_TAMANHO_INVALIDO;
    lista->tamanho = 0;
    lista->tamanho_max = tamanho_max;
    lista->elemento = malloc(sizeof(Elemento) * lista->tamanho_max);
    if(lista->elemento == NULL) return LISTA_LISTA_CHEIA;
    return LISTA_SUCESSO;
}

int LISTA_LiberarLista(Lista *lista)
{
    if(lista == NULL) return LISTA_ENDERECO_INVALIDO;
    free(lista->elemento);
    return LISTA_SUCESSO;
}

int LISTA_VerificarListaTamanho(Lista *lista)
{
    if(lista == NULL) return LISTA_ENDERECO_INVALIDO;
    return lista->tamanho;
}

int LISTA_VerificarListaCheia(Lista *lista)
{
    if(lista == NULL) return LISTA_ENDERECO_INVALIDO;
    return lista->tamanho == lista->tamanho_max;
}

int LISTA_VerificarListaVazia(Lista *lista)
{
    if(lista == NULL) return LISTA_ENDERECO_INVALIDO;
    return lista->tamanho == 0;
}

int LISTA_IncluirElemento(Lista *lista, Elemento *elemento)
{
    if(lista == NULL || elemento == NULL) return LISTA_ENDERECO_INVALIDO;
    if(LISTA_VerificarListaCheia(lista)) return LISTA_LISTA_CHEIA;
    lista->elemento[lista->tamanho] = *elemento;
    lista->tamanho++;
    return LISTA_SUCESSO;
}

int LISTA_ExcluirElemento(Lista *lista, int posicao)
{
    if(lista == NULL) return LISTA_ENDERECO_INVALIDO;
    if(LISTA_VerificarListaVazia(lista)) return LISTA_LISTA_VAZIA;
    if(posicao < 1 || posicao > lista->tamanho) return LISTA_POSICAO_INEXISTENTE;
    for(int i = posicao; i < lista->tamanho; i++)
    {
        lista->elemento[i - 1] = lista->elemento[i];
    }
    lista->tamanho--;
    return LISTA_SUCESSO;
}

int LISTA_AlterarElemento(Lista *lista, Elemento *elemento, int posicao)
{
    if(lista == NULL || elemento == NULL) return LISTA_ENDERECO_INVALIDO;
    if(LISTA_VerificarListaVazia(lista)) return LISTA_LISTA_VAZIA;
    if(posicao < 1 || posicao > lista->tamanho) return LISTA_POSICAO_INEXISTENTE;
    lista->elemento[posicao - 1] = *elemento;
    return LISTA_SUCESSO;
}

int LISTA_ObterElemento(Lista *lista, Elemento *elemento, int posicao)
{
    if(lista == NULL || elemento == NULL) return LISTA_ENDERECO_INVALIDO;
    if(LISTA_VerificarListaVazia(lista)) return LISTA_LISTA_VAZIA;
    if(posicao < 1 || posicao > lista->tamanho) return LISTA_POSICAO_INEXISTENTE;
    *elemento = lista->elemento[posicao - 1];
    return LISTA_SUCESSO;
}

int LISTA_FormatarLista(Lista *lista)
{
    if(lista == NULL) return LISTA_ENDERECO_INVALIDO;
    lista->tamanho = 0;
    return LISTA_SUCESSO;
}

#endif