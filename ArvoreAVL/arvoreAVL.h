#ifndef ARVOREAVL_H_INCLUDED
#define ARVOREAVL_H_INCLUDED

// Tamanho da palavra
#define MAX_CHAR 50

// Tipo de dado da Árvore AVL
typedef char TipoAVL[MAX_CHAR];

// Nodo da Árvore AVL
typedef struct NodoAVL
{
    TipoAVL info;
    struct NodoAVL *esq;
    struct NodoAVL *dir;
    int altura;
} TArvAVL, *ArvAVL;

/* Cria e retorna uma arvore AVL vazia */
ArvAVL inicArvAVL();

/* Retorna a altura do nodo */
int altura(ArvAVL nodo);

/* Retorna o maior elemento de dois inteiros */
int max(int a, int b);

/* Função auxiliar de insAVL, aloca na memória um novo nodo de arvore AVL com o elemento dado */
ArvAVL novoNodo(TipoAVL elem);

/* Rotação a direita */
ArvAVL rotacaoDir(ArvAVL y);

/* Rotação a esquerda */
ArvAVL rotacaoEsq(ArvAVL x);

/* Calcula e Retorna o valor de balanceamento do nodo */
int getBalance(ArvAVL nodo);

/* Adiciona um novo elemento na arvore e retorna a nova raiz, fazendo as devidas rotaões */
ArvAVL insAVL(ArvAVL nodo, TipoAVL elem);

/* Imprimi no console a arvore AVL em preOrder */
void preOrder(ArvAVL raiz);

/* Imprimi no console a arvore AVL em inOrder */
void inOrder(ArvAVL raiz);

/* Lê um arquivo TXT e faz inserções na raiz de acordo com os elementos do arquivo */
ArvAVL readFile(TipoAVL nomeArquivo, ArvAVL raiz);

#endif // ARVOREAVL_H_INCLUDED
