#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

#ifndef _TAD_Arbin_H
    #include "tadArbin_h.h"
#endif // _TAD_Arbin_H

#define MAX_FILA 1000

typedef Arbin TipoF;

typedef struct{
    TipoF info[MAX_FILA]; // vetor circular
    int primeiro;    // posição do primeiro elemento
    int ultimo;      // posição do último elemento
} Tfila, *Fila;

Fila inicFila(void);
void adicFila(Fila f, TipoF elem);
TipoF elimFila(Fila f);
TipoF infoFila(Fila f);
int vaziaFila(Fila f);
void destruirFila(Fila f);
Fila copiarFila(Fila f);
int longFila(Fila f);


#endif // FILA_H_INCLUDED
