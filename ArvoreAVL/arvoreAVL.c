#ifndef ARVOREAVL_H_INCLUDED
    #include "arvoreAVL.h"
#endif

/* Cria e retorna uma arvore AVL vazia */
ArvAVL inicArvAVL()
{
    return NULL;
}

/* Retorna a altura do nodo */
int altura(ArvAVL nodo)
{
    if (nodo == NULL)
        return -1;
    return nodo->altura;
}

/* Retorna o maior elemento de dois inteiros */
int max(int a, int b)
{
    return (a > b)? a : b;
}

/* Função auxiliar de insAVL
 * Aloca na memória um novo nodo de arvore AVL com o elemento dado
 */
ArvAVL novoNodo(TipoAVL elem)
{
    ArvAVL nodo = (ArvAVL) malloc(sizeof(struct NodoAVL));
    strcpy(nodo->info, elem);
    nodo->esq    = NULL;
    nodo->dir    = NULL;
    nodo->altura = 0;
    return(nodo);
}

/* Rotação a direita */
ArvAVL rotacaoDir(ArvAVL y)
{
    ArvAVL x  = y->esq;
    ArvAVL T2 = x->dir;

    // Realiza rotação
    x->dir = y;
    y->esq = T2;

    // Atualiza alturas
    y->altura = max(altura(y->esq), altura(y->dir)) + 1;
    x->altura = max(altura(x->esq), altura(x->dir)) + 1;

    // Retorna nova raiz
    return x;
}

/* Rotação a esquerda */
ArvAVL rotacaoEsq(ArvAVL x)
{
    ArvAVL y  = x->dir;
    ArvAVL T2 = y->esq;

    // Realiza rotação
    y->esq = x;
    x->dir = T2;

    // Atualiza alturas
    x->altura = max(altura(x->esq), altura(x->dir)) + 1;
    y->altura = max(altura(y->esq), altura(y->dir)) + 1;

    // Retorna nova raiz
    return y;
}

/* Calcula e Retorna o valor de balanceamento do nodo */
int getBalance(ArvAVL nodo)
{
    if (nodo == NULL)
        return 0;
    return altura(nodo->esq) - altura(nodo->dir);
}

/* Adiciona um novo elemento na arvore e retorna a nova raiz, fazendo as devidas rotaões */
ArvAVL insAVL(ArvAVL nodo, TipoAVL elem)
{
    /* 1. Tenta fazer inserção do elemento */
    if (nodo == NULL)
        return(novoNodo(elem));

    if (strcmp(elem, nodo->info) < 0)
        nodo->esq = insAVL(nodo->esq, elem);
    else if (strcmp(elem, nodo->info) > 0)
        nodo->dir = insAVL(nodo->dir, elem);
    else // Elementos iguais não são permidos
        return nodo;

    /* 2. Atualiza a altura do nodo */
    nodo->altura = 1 + max(altura(nodo->esq),
                           altura(nodo->dir));

    /* 3. Calcula o balanceamento da arvore e
          reestabelece o balanceamento usando rotações */
    int balance = getBalance(nodo);

    // Caso ocorreu desbalanceamento
    // existe 4 possiveis casos

    // Esquerda Esquerda
    if (balance > 1 && (strcmp(elem, nodo->esq->info) < 0))
        return rotacaoDir(nodo);

    // Direita Direita
    if (balance < -1 && (strcmp(elem, nodo->dir->info) > 0))
        return rotacaoEsq(nodo);

    // Esquerda Direita
    if (balance > 1 && (strcmp(elem, nodo->esq->info) > 0))
    {
        nodo->esq = rotacaoEsq(nodo->esq);
        return rotacaoDir(nodo);
    }

    // Direita Esquerda
    if (balance < -1 && (strcmp(elem, nodo->dir->info) < 0))
    {
        nodo->dir = rotacaoDir(nodo->dir);
        return rotacaoEsq(nodo);
    }

    /* Retorna o nodo caso não ocorreu desbalanceamento */
    return nodo;
}

// Imprimi no console a arvore AVL em preOrder
void preOrder(ArvAVL raiz)
{
    if(raiz != NULL)
    {
        printf("%s ", raiz->info);
        preOrder(raiz->esq);
        preOrder(raiz->dir);
    }
}

// Imprimi no console a arvore AVL em inOrder
void inOrder(ArvAVL raiz)
{
    if(raiz != NULL)
    {
        inOrder(raiz->esq);
        printf("%s ", raiz->info);
        inOrder(raiz->dir);
    }
}

// Lê um arquivo TXT com 1 palavra a cada linha e a insere em uma árvore AVL
ArvAVL readFile(TipoAVL nomeArquivo, ArvAVL raiz)
{
    int i = 0;
    char C;
    TipoAVL auxiliar;
    FILE *arquivo;
    arquivo = fopen(nomeArquivo, "r");
    if(arquivo == 0)
    {
        printf("Erro ao tentar abrir o arquivo");
        fclose(arquivo);
    }
    else
    {
        i = 0;
        do
        {
            C = getc(arquivo);
            if(C != '\n' && C != EOF)
            {
                auxiliar[i] = C;
                i++;
            }
            else
            {
                auxiliar[i] = '\0';
                if(auxiliar[0] != '\0')
                {
                   raiz = insAVL(raiz, auxiliar);
                   printf("\tinsere('%s')\n", auxiliar); // DEBUG
                }
                i = 0;
            }
        }while(C != EOF);
        fclose(arquivo);
    }
    return raiz;
}
