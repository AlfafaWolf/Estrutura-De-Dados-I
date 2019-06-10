#ifndef FILA_H_INCLUDED
    #include "fila.h"
#endif

Fila inicFila(void)
{
    Fila f = NULL;
    f = (Fila) malloc(sizeof(Tfila));
    if(f == NULL)
    {
        printf("ERRO. Nao foi possivel alocar a Fila");
        exit(1);
    }
    f->primeiro = -1;
    f->ultimo = -1;
    return f;
}
void adicFila(Fila f, TipoF elem)
{
    if(f->primeiro == -1)
    {
        f->info[0]  = elem;
        f->primeiro = 0;
        f->ultimo   = 0;
    }
    else if((f->ultimo + 1)%MAX_FILA == f->primeiro)
    {
        printf("Fila Cheia\n");
    }
    else
    {
        f->ultimo = (f->ultimo + 1)%MAX_FILA;
        f->info[f->ultimo] = elem;
    }
}
TipoF elimFila(Fila f)
{
    TipoF primElem;
    if(f->primeiro == -1)
    {
        printf("ERRO. Fila Vazia\n");
        return NULL;
    }
    else if(f->primeiro == f->ultimo)
    {
        primElem = f->info[f->primeiro];
        f->primeiro = -1;
        f->ultimo = -1;
        return primElem;
    }
    else
    {
        primElem = f->info[f->primeiro];
        f->primeiro = (f->primeiro + 1)%MAX_FILA;
        return primElem;
    }
}
TipoF infoFila(Fila f)
{
    if(f->primeiro == -1)
    {
        printf("ERRO. Fila Vazia\n");
        return NULL;
    }
    else
    {
        return f->info[f->primeiro];
    }
}
int vaziaFila(Fila f)
{
    return (f->primeiro == -1) ? 1 : 0;
}
void destruirFila(Fila f)
{
    free(f);
}
//void printFila(Fila f)
//{
//    Fila aux = inicFila();
//    printf("(|");
//    while(!vaziaFila(f))
//    {
//        TipoF elem = elimFila(f);
//        adicFila(aux, elem);
//        printf(" %d |", elem);
//    }
//    printf(")\n");
//
//    // RESTAURAR FILA ORIGINAL
//    while(!vaziaFila(aux))
//    {
//        adicFila(f, elimFila(aux));
//    }
//    destruirFila(aux);
//}
Fila copiarFila(Fila f)
{
    Fila copia = inicFila();
    Fila aux   = inicFila();
    while(!vaziaFila(f))
    {
        adicFila(aux, elimFila(f));
    }
    while(!vaziaFila(aux))
    {
        TipoF elem = elimFila(aux);
        adicFila(f, elem);
        adicFila(copia, elem);
    }
    destruirFila(aux);
    return copia;
}
int longFila(Fila f)
{
    Fila aux = inicFila();
    int i = 0;
    while(!vaziaFila(f))
    {
        adicFila(aux, elimFila(f));
        i++;
    }
    while(!vaziaFila(aux))
    {
        adicFila(f, elimFila(aux));
    }
    destruirFila(aux);
    return i;
}
