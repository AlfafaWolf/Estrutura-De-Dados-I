/*  ÁRVORE BINÁRIA DE BUSCA (ABB)
 *
 *  Autor  : Gabriel Alejandro L. M.
 *  Arquivo: tadArbin_h.h
 *  Matéria: ESTRUTURA DE DADOS I
 */
#ifndef _TAD_Arbin_H
#define _TAD_Arbin_H

#include <stdio.h>
#include <limits.h>

/*=============================*/
/* ====== • TAD Arbin • ====== */
/*=============================*/

/* Tipo de dado armazenado na árvore */
typedef int TipoA;

/* Estrutura do NÓ da árvore */
typedef struct NodoArbin {
    TipoA info;
    struct NodoArbin *esq, *dir;
} Tarbin, *Arbin;


/*
 *  Cria e retorna uma arvore binaria vazia
 */
Arbin inicArbin(void);

/*
 *  Retorna a subarvore esquerda
 */
Arbin esqArbin(Arbin a);

/*
 *  Retorna a subarvore direita
 */
Arbin dirArbin(Arbin a);


/*
 *  Retorna o elemento da raiz
 */
TipoA raizArbin(Arbin a);

/*
 *  Destrói a árvore binária, retornando toda a memória ocupada
 */
void destruirArbin(Arbin a);

/*
 *  Retorna 1 caso a árvore binária esteja vazia, caso contrário, retorna 0
 */
int vaziaArbin(Arbin a);

Arbin insArbinBusca(Arbin a, TipoA elem);
void visitar(TipoA elem);
void preOrdemArbin(Arbin a);
int buscaNaArbin(Arbin a, TipoA elem);
int buscaNaArbinBusca(Arbin a, TipoA elem);

/*
 *  Calcular e retornar o peso de uma árvore binária
 *  (número de elementos da árvore)
 */
int pesoArbin(Arbin a);

/*
 *  Verifica se um elemento está presente em uma árvore binária
 */
int estaArbin(Arbin a, TipoA elem);

/*
 *  Retorna o número de folhas de uma Arbin
 */
int numFolhas(Arbin a);

/*
 *  Retorna o número de vezes que um elemento aparece na Arbin
 */
int numOcorrencias(Arbin a, TipoA elem);

/*  Tipo: ABB
 *  Retorna 1 caso exista um caminho entre dois elementos, e1 e e2 , de uma Arbin,
 *  caso contrário retorna 0
 */
int existeCaminhoABB(Arbin a, TipoA e1, TipoA e2);

/*
 *  Retorna o número de elementos de uma Arbin em um dado nível
 */
int contNivel(Arbin a, int nivel);

/*
 *  Retorna o número de elementos de uma Arbin em um determinado nível
 */
int iguaisArbin(Arbin a, Arbin b);

/*
 *  Verificar se duas Arbin a1 e a2 são isomorfas
 */
int isomorfos(Arbin a1, Arbin a2);

/*
 *  Verificar se Arbin a é completa.
 */
int completaArbin(Arbin a);

/*
 *  Verificar se Arbin a é cheia.
 */
int cheiaArbin(Arbin a);

//Lista buscaCaminhoArbin(Arbin a, TipoA elem);

/*
 *  Verifica se a Arbin a2 ocorre na Arbin a1.
 */
int ocorreArbin(Arbin a, Arbin b);

/*
 *  Calcular o nível em que aparece o elemento elem
 */
int nivelArbin(Arbin a, TipoA elem);

void niveisArbin(Arbin a);

/*
 *  Esta função retorna o maior elemento da Arbin a
 *  Utilizando o caminhamento recursivo In-ordem
 *  Obs.: Requer <limits.h>
 */
int maiorElementoArbin(Arbin a);

int semelhantesArbin(Arbin a1, Arbin a2);

#endif // _TAD_Arbin_H
