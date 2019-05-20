/*  ÁRVORE BINÁRIA DE BUSCA (ABB)
 *
 *  Autor  : Gabriel Alejandro L. M.
 *  Arquivo: tadArbin_c.c
 *  Matéria: ESTRUTURA DE DADOS I
 */
#ifndef _TAD_Arbin_H
    #include "tadArbin_h.h"
#endif

/*=============================*/
/* ====== • TAD Arbin • ====== */
/*=============================*/

Arbin inicArbin()
{
    return NULL;
}

Arbin esqArbin(Arbin a)
{
    if(a != NULL)
        return a->esq;
    else
        return NULL;
}

Arbin dirArbin(Arbin a)
{
    if(a != NULL)
        return a->dir;
    else
        return NULL;
}

TipoA raizArbin(Arbin a)
{
    if(a != NULL)
        return a->info;
    else
        return NULL;
}

void destruirArbin(Arbin a)
{
    if(a != NULL)
    {
        destruirArbin(a->esq);
        destruirArbin(a->dir);
        free(a);
    }
}

int vaziaArbin(Arbin a)
{
    if(a == NULL)
        return 1;
    else
        return 0;
}

Arbin insArbinBusca(Arbin a, TipoA elem)
{
    if(a == NULL)
    {
        a = (Arbin) malloc(sizeof(Tarbin));

        a->info = elem;
        a->esq  = NULL;
        a->dir  = NULL;
        return a;
    }
    else if(elem < a->info)
    {
        a->esq = insArbinBusca(a->esq, elem);
    }
    else if(elem > a->info)
    {
        a->dir = insArbinBusca(a->dir, elem);
    }
    return a;
}

void visitar(TipoA elem)
{
    printf("   %d   \n", elem);
}

void preOrdemArbin(Arbin a)
{
    if(!vaziaArbin(a))
    {
        visitar(raizArbin(a));
        preOrdemArbin(esqArbin(a));
        preOrdemArbin(dirArbin(a));
    }
}

int buscaNaArbin(Arbin a, TipoA elem)
{
    if(vaziaArbin(a))
        return 0;
    else if(raizArbin(a) == elem)
        return 1;
    else
        return (buscaNaArbin(esqArbin(a), elem) || buscaNaArbin(dirArbin(a), elem));
}

int buscaNaArbinBusca(Arbin a, TipoA elem)
{
    if(vaziaArbin(a))
        return 0;
    else if(raizArbin(a) == elem)
        return 1;
    else
    {
        if(elem < raizArbin(a))
            return buscaNaArbin(esqArbin(a), elem);
        else
            return buscaNaArbin(dirArbin(a), elem);
    }
}

// Calcular e retornar o peso de uma árvore binária (número de elementos da árvore).
int pesoArbin(Arbin a)
{
    if(vaziaArbin(a))
        return 0;
    else
        return 1 + pesoArbin(a->esq) + pesoArbin(a->dir);
}
// Verificar se um elemento está presente em uma árvore binária.
int estaArbin(Arbin a, TipoA elem)
{
    if(vaziaArbin(a))
        return 0;
    else if(raizArbin(a) == elem)
        return 1;
    else
        return (buscaNaArbin(esqArbin(a), elem) || buscaNaArbin(dirArbin(a), elem));
}

// Calcular o número de folhas de uma Arbin.
int numFolhas(Arbin a)
{
    if(vaziaArbin(a))
        return 0;
    else if(vaziaArbin(a->esq) && vaziaArbin(a->dir))
        return 1;
    else
        return numFolhas(a->esq) + numFolhas(a->dir);
}

// Calcular o número de vezes que um elemento aparece na Arbin.
int numOcorrencias(Arbin a, TipoA elem)
{
    if(vaziaArbin(a))
        return 0;
    else if(raizArbin(a) == elem)
        return 1 + numOcorrencias(a->esq, elem) + numOcorrencias(a->dir, elem);
    else
        return numOcorrencias(a->esq, elem) + numOcorrencias(a->dir, elem);
}

// Verificar se existe um caminho entre dois elementos e1 e e2 de uma Arbin.
int existeCaminhoABB(Arbin a, TipoA e1, TipoA e2)
{
    if(vaziaArbin(a))
        return 0;
    else if(raizArbin(a) == e1)
        return buscaNaArbinBusca(a, e2);
    else
    {
        if(e1 < raizArbin(a))
            return existeCaminhoABB(a->esq, e1, e2);
        return existeCaminhoABB(a->dir, e1, e2);
    }
}

// Retorna o número de elementos de uma Arbin em um determinado nível
int contNivel(Arbin a, int nivel)
{
    if(vaziaArbin(a))
        return 0;
    else if(nivel == 0)
        return 1;
    else
        return contNivel(a->esq, nivel - 1) + contNivel(a->dir, nivel - 1);
}

// Verifica se duas arvores sào iguais
int iguaisArbin(Arbin a, Arbin b)
{
    if(vaziaArbin(a) && vaziaArbin(b))
        return 1;
    else if(pesoArbin(a) == pesoArbin(b) && raizArbin(a) == raizArbin(b))
        return iguaisArbin(esqArbin(a), esqArbin(b)) && iguaisArbin(dirArbin(a), dirArbin(b));
    else
        return 0;
}
