#include <stdio.h>
#include <stdlib.h>
#include "ex6-TAD.h"

struct no
{
    int info;
    struct no *prox;
    struct no *ant;
};

/*
    ENTRADA: -
    PRÉ-CONDICÃO: -
    PROCESSO: criar uma instancia de lista
    SAÍDA: NULL
    PÓS-CONDICÃO: -
*/
lista cria_lista()
{
    return NULL;
}

/*
    ENTRADA: lista A
    PRÉ-CONDICÃO: -
    PROCESSO: verificar se a lista está vazia
    SAÍDA: 1(sucesso) ou 0(falha)
    PÓS-CONDICÃO: -
*/
int lista_vazia(lista A)            // confere se há elementos na lista
{
    if(A == NULL)
    {
        return 1;       // lista vazia
    }
    else
    {
        return 0;       // nao vazia
    }
}

/*
    ENTRADA: endereco da lista, elemento a ser inserido
    PRÉ-CONDICÃO: alocacão não falhar
    PROCESSO: inserir o elemento na lista
    SAÍDA: 1(sucesso) ou 0(falha)
    PÓS-CONDICÃO: lista com o elemento inserido
*/
int insere_elem(lista *A, int elem)             // insere elementos na lista
{
    lista N = (lista)malloc(sizeof(struct no));
    if(N==NULL)
    {
        return 0;       // no nao alocado
    }
    N->info = elem;

    N->ant = NULL;
    N->prox = (*A);

    if(lista_vazia(*A)==0)
    {
        (*A)->ant = N;
    }
    *A = N;

    return 1;
}

/*
    ENTRADA: endereco da lista e o elemento a ser removido
    PRÉ-CONDICÃO: lista não estar vazia
    PROCESSO: remover o elemento da lista
    SAÍDA: 1(sucesso) ou 0(falha)
    PÓS-CONDICÃO: lista sem o elemento
*/
int remove_elem(lista *A, int elem)         // remove elementos da lista
{
    if(lista_vazia(*A)==1)
    {
        return 0;     // falha
    }

    lista aux = (*A);

    while(aux->prox != NULL && aux->info != elem)
    {
        aux = aux->prox;
    }

    if(aux->info != elem)
    {
        return 0;
    }
    if(aux->prox != NULL)
    {
        aux->prox->ant = aux->ant;
    }
    if(aux->ant != NULL)
    {
        aux->ant->prox = aux->prox;
    }
    if(aux == *A)
    {
        // (*A)->prox->ant = NULL
        *A = aux->prox;
    }
    free(aux);

    return 1;
}

/*
    ENTRADA: lista e a posicão do elemento que será removido
    PRÉ-CONDICÃO: posicão existir na lista
    PROCESSO: encontrar o elemento da posicão solicitada
    SAÍDA: elemento da posicão solicitada
    PÓS-CONDICÃO: -
*/
int get_elem_pos(lista A, int pos)         // obtem elementos da lista
{
    lista aux = A;
    int i;

    for(i=1; i<pos; i++)
    {
        aux = aux->prox;
    }
    return aux->info;
}

/*
    ENTRADA: endereco da lista
    PRÉ-CONDICÃO: lista existir
    PROCESSO: liberar memória ocupada pela lista
    SAÍDA: -
    PÓS-CONDICÃO: memória liberada e lista apagada
*/
void apaga_lista(lista *A)          // apaga a lista por completo
{
    free(*A);
    (*A) = NULL;
}

/*
    ENTRADA: endereco da lista
    PRÉ-CONDICÃO: lista existir e não ser vazia
    PROCESSO: remover maior elemento da lista
    SAÍDA: elemento removido
    PÓS-CONDICÃO: lista sem o elemento retornado
*/
int remove_maior(lista *A)
{
    int maior = (*A)->info;
    lista aux = *A;         // percorre
    lista aux2;             // guarda o antecessor do maior

    if(lista_vazia(*A)!=1)
    {
        if((*A)->prox==NULL)
        {
            (*A) = NULL;
            return maior;
        }

        while(aux->prox!=NULL)
        {
            if(aux->info >= maior)
            {
                maior = aux->info;
                aux2 = aux;
            }
            aux = aux->prox;
        }

        if(aux->info >= maior)
        {
            maior = aux->info;
            aux2 = aux;
        }

        if(aux2->ant == NULL)
        {
            (*A) = (*A)->prox;
            (*A)->ant = NULL;
        }

        else if(aux2->prox == NULL)
        {
            aux2->ant->prox = NULL;
        }

        else
        {
            aux2->ant->prox = aux2->prox;
            aux2->prox->ant = aux2->ant->prox;
        }

        return maior;
    }
    else
    {
        return 0;
    }
}

/*
    ENTRADA: endereco da lista
    PRÉ-CONDICÃO: lista existir e nao ser vazia
    PROCESSO: remover os numeros pares da lista
    SAÍDA: quantidade de elementos removidos
    PÓS-CONDICÃO: lista sem numeros pares
*/
int remove_pares(lista *A)          // retorna a quantidade de elementos removidos
{
    lista auxx = *A;
    int pares = 0;

    while(auxx->prox!=NULL)
    {
        if((auxx->info!=1) && ((auxx->info) % 2) == 0)
        {
            auxx->prox->ant = auxx->ant;
            if(auxx->ant!=NULL)
            {
                auxx->ant->prox = auxx->prox;
            }
            else
            {
                (*A)=(*A)->prox;
            }
            pares++;
        }
        auxx = auxx->prox;
    }

    if((auxx->info!=1) && ((auxx->info) % 2) == 0)
    {
        if(auxx->ant!=NULL)
        {
            auxx->ant->prox = NULL;
        }
        else
        {
            (*A) = NULL;
        }
        pares++;
    }

    return pares;
}

/*
    ENTRADA: endereco da lista, elemento e a posicao que o elemento sera inserido
    PRÉ-CONDICÃO: lista existir, posicao ser válida, numero ser inteiro
    PROCESSO: inserir o elemento na posicao solicitada
    SAÍDA: 1(sucesso) ou 0(falha)
    PÓS-CONDICÃO: lista com o elemento inserido na posicao solicitada
*/
int insere_posicao(lista *A, int pos, int elem)
{
    lista aux = *A;
    lista N = (lista)malloc(sizeof(struct no));

    if(N==NULL)
    {
        return 0;       // no nao alocado
    }
    N->info = elem;

    if(lista_vazia(*A)==1 && pos>1)
    {
        return 0;
    }

    if(pos==1)                  // entrar no inicio
    {
        N->prox = *A;
        N->ant = NULL;
        if(lista_vazia(*A)==0)
        {
            (*A)->ant = N;
        }

        *A = N;

        return 1;
    }

    while(pos>1 && aux->prox!=NULL)
    {
        aux = aux->prox;
        pos--;
    }

    if(aux->prox == NULL && pos == 1)   // entrar de penultimo
    {
        N->ant = aux->ant;
        N->prox = aux->ant->prox;
        aux->ant->prox = N;
        aux->ant = N;

        return 1;
    }

    else if(aux->prox == NULL && pos ==2)       // entrar de ultimo
    {
        N->ant = aux->ant->prox;
        N->prox = NULL;
        aux->prox = N;

        return 1;
    }

    else if(aux->prox != NULL && pos == 1)      // entrar no meio
    {
        N->ant = aux->ant;
        N->prox = aux->ant->prox;
        aux->ant->prox = N;
        aux->ant = N;

        return 1;
    }
    else
    {
        return 0;
    }
}

/*
    ENTRADA: endereco de duas listas
    PRÉ-CONDICÃO: listas alocadas
    PROCESSO: inserir os elementos de uma lista com os
                        elementos invertidos em relacao à origem em outra lista
    SAÍDA: 1(sucesso) ou 0(falha)
    PÓS-CONDICÃO: segunda lista com os elementos invertidos da primeira
*/
int inverte_lista(lista *A, lista *B)
{
    lista aux = *A;

    while(aux->prox!=NULL)
    {
        insere_elem(&*B, aux->info);
        aux = aux->prox;
    }
    insere_elem(&*B, aux->info);

    if(lista_vazia(*B)==1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
