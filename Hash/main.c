#include <stdio.h>
#include <stdlib.h>

#define numEntradas 8

typedef struct _Hash
{
    int chave;
    struct _Hash *prox;
} *Hash;

typedef Hash TADTabelaHash[numEntradas];

int funcaoHashing(int num)
{
    return num % numEntradas;
}

void inserirHash(TADTabelaHash tabela, int n)
{
    Hash novo = NULL;
    int pos = funcaoHashing(n);
    novo = (Hash) malloc(sizeof(struct _Hash));
    novo->chave = n;
    novo->prox = tabela[pos];
    tabela[pos] = novo;
}

Hash localizarHash(TADTabelaHash tabela, int num)
{
    int pos = funcaoHashing(num);
    Hash aux;
    if(tabela[pos] != NULL)
    {
        if(tabela[pos]->chave == num)
            return tabela[pos];
        else
        {
            aux = tabela[pos]->prox;
            while(aux != NULL && aux->chave != num)
                aux = aux->prox;
            return aux;
        }
    }
    else
        return NULL;
}

void excluirHash(TADTabelaHash tabela, int num)
{
    int pos = funcaoHashing(num);
    Hash aux;
    if(tabela[pos] != NULL)
    {
        if(tabela[pos]->chave == num)
        {
            aux = tabela[pos];
            tabela[pos] = tabela[pos]->prox;
            free(aux);
        }
        else
        {
            aux = tabela[pos]->prox;
            Hash ant = tabela[pos];
            while(aux != NULL && aux->chave != num)
            {
                ant = aux;
                aux = aux->prox;
            }
            if(aux != NULL)
            {
                ant->prox = aux->prox;
                free(aux);
            }
            else
                printf("\nNumero nao encontrado.\n");
        }
    }
    else
        printf("\nNumero nao encontrado.\n");
}
void mostrarHash(TADTabelaHash tabela)
{
    int i;
    Hash aux;
    for(i = 0; i < numEntradas; i++)
    {
        printf("%d |", i);
        aux = tabela[i];
        while(aux != NULL)
        {
            printf(" %.3d ->", aux->chave);
            aux = aux->prox;
        }
        printf("\n");
    }
}

void inicTabelaHash(TADTabelaHash tabela)
{
    int i;
    for(i = 0; i < numEntradas; i++)
        tabela[i] = NULL;
}

int main()
{
    TADTabelaHash tabelaHash;
    inicTabelaHash(tabelaHash);

    inserirHash(tabelaHash, 0); inserirHash(tabelaHash, 8); inserirHash(tabelaHash, 16);
    inserirHash(tabelaHash, 1);
    inserirHash(tabelaHash, 2); inserirHash(tabelaHash, 10);
    inserirHash(tabelaHash, 3); inserirHash(tabelaHash, 11);
    inserirHash(tabelaHash, 4);
    inserirHash(tabelaHash, 5);
    inserirHash(tabelaHash, 6);
    inserirHash(tabelaHash, 7);

    excluirHash(tabelaHash, 6);
    excluirHash(tabelaHash, 11);

    mostrarHash(tabelaHash);

    return 0;
}
