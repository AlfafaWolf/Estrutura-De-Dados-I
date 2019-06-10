#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#ifndef _TAD_Arbin_H
    #include "tadArbin_h.h"
#endif // _TAD_Arbin_H

typedef Arbin TipoL;
typedef struct ListaNo
{
    TipoL info;
    struct ListaNo *prox;
} *pListaNo;
typedef struct Tlista
{
    pListaNo primeiro, ultimo, iterador;
    int longitude;
} *Lista;
Lista inicLista(void);
void anxLista(Lista lst, TipoL elem);
void insLista(Lista lst, TipoL elem);
void elimLista(Lista lst);
void primLista(Lista lst);
void ultLista(Lista lst);
void segLista(Lista lst);
void posLista(Lista lst, int pos);
TipoL infoLista(Lista lst);
int longLista(Lista lst);
int fimLista(Lista lst);
void printLista(Lista lst);

#endif // LISTA_H_INCLUDED
