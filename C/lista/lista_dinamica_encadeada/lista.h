#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

enum
{
    LISTA_SUCESSO,
    LISTA_SEM_MEMORIA,
    LISTA_VAZIA,
    LISTA_POSICAO_INEXISTENTE,
};

struct Elemento
{
    int x;
};
typedef struct Elemento Elemento;

typedef struct Lista Lista;

void lista_inicializar(Lista **lista);
void lista_liberar(Lista **lista);

int lista_obter_tamanho(Lista **lista);
int lista_vazia(Lista **lista);

int lista_adicionar_inicio(Lista **lista, Elemento *elemento);
int lista_adicionar_posicao(Lista **lista, Elemento *elemento, int posicao);
int lista_adicionar_final(Lista **lista, Elemento *elemento);

int lista_remover_inicio(Lista **lista, Elemento *elemento);
int lista_remover_posicao(Lista **lista, Elemento *elemento, int posicao);
int lista_remover_final(Lista **lista, Elemento *elemento);

int lista_alterar_inicio(Lista **lista, Elemento *elemento);
int lista_alterar_posicao(Lista **lista, Elemento *elemento, int posicao);
int lista_alterar_final(Lista **lista, Elemento *elemento);

int lista_obter_inicio(Lista **lista, Elemento *elemento);
int lista_obter_posicao(Lista **lista, Elemento *elemento, int posicao);
int lista_obter_final(Lista **lista, Elemento *elemento);

#endif