/* ÁRVORE AVL
 *
 * Autor  : Gabriel Alejandro L. M.
 * Matéria: ESTRUTURA DE DADOS I
 *
 * INFO:
 * Trabalho do 2Bi do 3o Período
 *     Ler um arquivo de texto e fazer a inserção de cada palavra na árvore AVL.
 *
 * AJUDA:
 * Vizualizar inserção na Árvore AVL
 *     https://www.cs.usfca.edu/~galles/visualization/AVLtree.html
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

// A utility function to get the height of the tree
int altura(struct NodoAVL *N)
{
    if (N == NULL)
        return -1;
    return N->altura;
}

// A utility function to get maximum of two integers
int max(int a, int b)
{
    return (a > b)? a : b;
}

ArvAVL inicArvAVL()
{
    return NULL;
}

/* Helper function that allocates a new node with the given key and
    NULL left and right pointers. */
ArvAVL newNode(TipoAVL elem)
{
    ArvAVL node = (ArvAVL) malloc(sizeof(struct NodoAVL));
    strcpy(node->info, elem);
    node->esq    = NULL;
    node->dir    = NULL;
    node->altura = 0;  // new node is initially added at leaf
    return(node);
}

// A utility function to right rotate subtree rooted with y
// See the diagram given above.
ArvAVL rotacaoDir(ArvAVL y)
{
    ArvAVL x  = y->esq;
    ArvAVL T2 = x->dir;

    // Perform rotation
    x->dir = y;
    y->esq = T2;

    // Update heights
    y->altura = max(altura(y->esq), altura(y->dir)) + 1;
    x->altura = max(altura(x->esq), altura(x->dir)) + 1;

    // Return new root
    return x;
}

// A utility function to left rotate subtree rooted with x
// See the diagram given above.
ArvAVL rotacaoEsq(ArvAVL x)
{
    ArvAVL y  = x->dir;
    ArvAVL T2 = y->esq;

    // Perform rotation
    y->esq = x;
    x->dir = T2;

    //  Update heights
    x->altura = max(altura(x->esq), altura(x->dir)) + 1;
    y->altura = max(altura(y->esq), altura(y->dir)) + 1;

    // Return new root
    return y;
}

// Get Balance factor of node N
int getBalance(ArvAVL nodo)
{
    if (nodo == NULL)
        return 0;
    return altura(nodo->esq) - altura(nodo->dir);
}

// Recursive function to insert a key in the subtree rooted
// with node and returns the new root of the subtree.
ArvAVL insAVL(ArvAVL nodo, TipoAVL elem)
{
    /* 1.  Perform the normal BST insertion */
    if (nodo == NULL)
        return(newNode(elem));

    if (strcmp(elem, nodo->info) < 0)      //(key < node->info)
        nodo->esq = insAVL(nodo->esq, elem);
    else if (strcmp(elem, nodo->info) > 0) //(key > node->info)
        nodo->dir = insAVL(nodo->dir, elem);
    else // Equal keys are not allowed in BST
        return nodo;

    /* 2. Update height of this ancestor node */
    nodo->altura = 1 + max(altura(nodo->esq),
                           altura(nodo->dir));

    /* 3. Get the balance factor of this ancestor
          node to check whether this node became
          unbalanced */
    int balance = getBalance(nodo);

    // If this node becomes unbalanced, then
    // there are 4 cases

    // Left Left Case
    if (balance > 1 && (strcmp(elem, nodo->esq->info) < 0))  //(balance > 1 && key < node->esq->info)
        return rotacaoDir(nodo);

    // Right Right Case
    if (balance < -1 && (strcmp(elem, nodo->dir->info) > 0)) //(balance < -1 && key > node->dir->info)
        return rotacaoEsq(nodo);

    // Left Right Case
    if (balance > 1 && (strcmp(elem, nodo->esq->info) > 0))  //(balance > 1 && key > node->esq->info)
    {
        nodo->esq =  rotacaoEsq(nodo->esq);
        return rotacaoDir(nodo);
    }

    // Right Left Case
    if (balance < -1 && (strcmp(elem, nodo->dir->info) < 0)) //(balance < -1 && key < node->dir->info)
    {
        nodo->dir = rotacaoDir(nodo->dir);
        return rotacaoEsq(nodo);
    }

    /* return the (unchanged) node pointer */
    return nodo;
}

void preOrder(ArvAVL raiz)
{
    if(raiz != NULL)
    {
        printf("%s ", raiz->info);
        preOrder(raiz->esq);
        preOrder(raiz->dir);
    }
}

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
                   printf("\tinsert('%s')\n", auxiliar); // DEBUG
                }
                i = 0;
            }
        }while(C != EOF);
        fclose(arquivo);
    }
    return raiz;
}

int main()
{
    /* Criar raiz da arvore AVL */
    ArvAVL raiz = inicArvAVL();

    /* Arvore AVL construida com o arquivo "entrada.txt"
             C
           /   \
          B     D
        /  \     \
       A    AB    E

       inOrder  : A AB B C D E
       preOrder : B A AB D C E
    */

    printf("\n> Lendo Arquivo . . .\n");
    raiz = readFile("entrada.txt", raiz);

    /* Imprimir InOrder e PreOrder */
    printf("\nIn Order:\n"); inOrder(raiz);
    printf("\nPre Order:\n"); preOrder(raiz);

    printf("\n");

    return 0;
}
