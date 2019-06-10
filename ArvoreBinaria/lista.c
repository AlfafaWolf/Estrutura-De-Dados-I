#ifndef LISTA_H_INCLUDED
    #include "lista.h"
#endif // LISTASE_H_INCLUDED

// CRIA E RETORNA UMA LISTA VAZIA
Lista inicLista(void)
{
    // ALOCAR
    Lista lst = NULL;
    lst = (Lista) malloc(sizeof(struct Tlista));
    if(lst == NULL)
    {
        printf("ERRO, nao foi possivel alocar a Lista\n");
        exit(1);
    }

    // VALORES INICIAIS
    lst->iterador  = NULL;
    lst->longitude = 0;
    lst->primeiro  = NULL;
    lst->ultimo    = NULL;

    return lst;
}
// ADICIONA UM ELEMENTO DEPOIS DO INTERATOR
void anxLista(Lista lst, TipoL elem)
{
    // CASO O INTERADOR FOR NULO
    if(lst->iterador == NULL && longLista(lst) > 0)
    {
        printf("ERRO, interador nao definido, nao foi possivel anexar elemento\n");
        return;
    }

    // ALOCAR
    pListaNo pLstNo = NULL;
    pLstNo = (pListaNo) malloc(sizeof(struct ListaNo));
    if(pLstNo == NULL)
    {
        printf("ERRO, nao foi possivel alocar o elemento\n");
        exit(1);
    }
    //lst->longitude++; ERRO NO CODIGO, PQ???????

    // VALORES INICIAIS
    pLstNo->info = elem;
    pLstNo->prox = NULL;

    // CASO A LISTA SEJA VAZIA
    if(longLista(lst) == 0)
    {
        lst->iterador = pLstNo;
        lst->primeiro = pLstNo;
        lst->ultimo   = pLstNo;
        lst->longitude++;
        return;
    }

    // CASO NÃO
    pLstNo->prox = lst->iterador->prox;
    lst->iterador->prox = pLstNo;
    lst->longitude++;

    // CASO O NOVO BLOCO FOR O ÚLTIMO DA LISTA
    if(pLstNo->prox == NULL)
    {
        lst->ultimo = pLstNo;
    }
}
// ADICIONA UM ELEMENTO ANTES DO INTERADOR
void insLista(Lista lst, TipoL elem)
{
    // CASO O INTERADOR FOR NULO
    if(lst->iterador == NULL && longLista(lst) > 0)
    {
        printf("ERRO, interador nao definido, nao foi possivel anexar elemento\n");
        return;
    }

    // ALOCAR
    pListaNo pLstNo = NULL;
    pLstNo = (pListaNo) malloc(sizeof(struct ListaNo));
    if(pLstNo == NULL)
    {
        printf("ERRO, nao foi possivel alocar o elemento\n");
        exit(1);
    }
    lst->longitude++;

    // VALORES INICIAIS
    pLstNo->info = elem;
    pLstNo->prox = NULL;

    // CASO A LISTA SEJA VAZIA
    if(longLista(lst) == 0)
    {
        lst->iterador = NULL;
        lst->primeiro = NULL;
        lst->ultimo   = NULL;
        return;
    }

    // CASO O INTERADOR FOR O PRIMEIRO ELEMENTO
    if(lst->iterador == lst->primeiro)
    {
        pLstNo->prox  = lst->iterador;
        lst->primeiro = pLstNo;
        return;
    }

    // CASO NÃO
    pLstNo->prox = lst->iterador;

    // VARIÁVEIS DE REFERÊNCIA
    pListaNo pLstNoAnt, pLstNoIter;  // Iniciar variáveis de referências a nós
    pLstNoIter = lst->iterador;      // armazenar interador
    pLstNoAnt  = lst->primeiro;      // armazenar nó anterior ao interador /?????????

    // BUSCAR ELEMENTO PRÉ INTERADOR
    for(primLista(lst); pLstNoAnt->prox != pLstNoIter; segLista(lst))
    {
        pLstNoAnt = lst->iterador->prox;
    }
    pLstNoAnt->prox = pLstNo;        // Nó anterior ao interador agora se refere ao novo nó
    lst->iterador   = pLstNoIter;    // voltar ao interador original

}
// ELIMINA O ELEMENTO QUE ESTÁ SOB O INTERADOR
void elimLista(Lista lst)
{
    // CASO O ITERADOR ESTIVER INDEFINIDO
    if(lst->iterador == NULL)
    {
        printf("ERRO, interador nao definido, nao eh possivel eliminar\n");
        return;
    }

    // CASO FOR UMA LISTA VAZIA
    if(longLista(lst) == 0)
        return;

    // ARMAZENAR NÓ A SER ELIMINADO
    pListaNo pLstNoElim;
    pLstNoElim = lst->iterador;

    // CASO FOR UMA LISTA DE UM SÓ ELEMENTO
    if(longLista(lst) == 1)
    {
        lst->iterador = NULL;
        lst->primeiro = NULL;
        lst->ultimo = NULL;
        lst->longitude--;
        free(pLstNoElim);
        return;
    }

    // CASO O ITERADOR FOR O PRIMEIRO ELEMENTO
    // CASO O ITERADOR FOR O ULTIMO ELEMENTO
    // CASO CONTRÁRIO, ELE ESTÁ ENTRE O RESTANTE
    if(lst->iterador == lst->primeiro)
    {
        lst->primeiro = lst->primeiro->prox;
        primLista(lst);
    }
    else if(lst->iterador == lst->ultimo)
    {
        for(primLista(lst); lst->iterador->prox != lst->ultimo; segLista(lst))
        {
        }
        lst->iterador->prox = NULL;
        lst->ultimo = lst->iterador;
        lst->iterador = NULL;
    }
    else
    {
        for(primLista(lst); lst->iterador->prox != pLstNoElim; segLista(lst))
        {
        }
        lst->iterador->prox = pLstNoElim->prox;
    }
    lst->longitude--;
    free(pLstNoElim);
}
// COLOCA O INTERATOR SOB O PRIMEITO ELEMENTO DA LISTA
void primLista(Lista lst)
{
    lst->iterador = lst->primeiro;
}
// COLOCA O INTERATOR SOBRE O ÚLTIMO ELEMENTO DA LISTA
void ultLista(Lista lst)
{
    lst->iterador = lst->ultimo;
}
// AVANÇA O INTERATOR EM UMA POSIÇAO
void segLista(Lista lst)
{
    lst->iterador = lst->iterador->prox;
}
// COLOCA O ITERADOR SOBRE A POSIÇÃO POS
void posLista(Lista lst, int pos)
{
    // CASO A POSIÇCÃO FOR MAIOR QUE A LONGITUDE
    if(pos > lst->longitude || pos == 0)
    {
        lst->iterador = NULL;
        return;
    }

    int i;
    for(primLista(lst), i = 1; !fimLista(lst) && i < pos; segLista(lst), i++)
    {
    }
}
// RETORNA O ELEMENTO SOB O INTERATOR
TipoL infoLista(Lista lst)
{
    if(lst->iterador == NULL)
    {
        printf("ERRO, interador nao definido\n");
        exit(1);
    }
    return lst->iterador->info;
}
// RETORNA O ELEMENTO SOB O INTERATOR
int longLista(Lista lst)
{
    if(lst->longitude < 0)
    {
        printf("ERRO, longitude negativa\n");
    }
    return lst->longitude;
}
// RETORNA VERDADEITO SE O INTERATOR ESTIVER INDEFINIDO
int fimLista(Lista lst)
{
    if(lst->iterador == NULL)
        return 1;
    else
        return 0;
}
//void printLista(Lista lst)
//{
//    printf("{|");
//    for(primLista(lst); fimLista(lst) != 1; segLista(lst))
//    {
//        printf(" %d |", infoLista(lst));
//    }
//    printf("}\n\n");
//}
