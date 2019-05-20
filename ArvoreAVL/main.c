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

// C program to insert a node in AVL tree
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CHAR 50

// Tipo de dado da Árvore AVL
typedef char TipoAVL[MAX_CHAR];

// Nodo da Árvore AVL
struct NodoAVL
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

/* Helper function that allocates a new node with the given key and
    NULL left and right pointers. */
struct NodoAVL* newNode(TipoAVL elem)
{
    struct NodoAVL* node = (struct NodoAVL*)
                        malloc(sizeof(struct NodoAVL));
    strcpy(node->info, elem); //node->info   = elem;
    node->esq    = NULL;
    node->dir    = NULL;
    node->altura = 0;  // new node is initially added at leaf
    return(node);
}

// A utility function to right rotate subtree rooted with y
// See the diagram given above.
struct NodoAVL *rightRotate(struct NodoAVL *y)
{
    struct NodoAVL *x  = y->esq;
    struct NodoAVL *T2 = x->dir;

    // Perform rotation
    x->dir = y;
    y->esq = T2;

    // Update heights
    y->altura = max(altura(y->esq), altura(y->dir));
    x->altura = max(altura(x->esq), altura(x->dir));

    // Return new root
    return x;
}

// A utility function to left rotate subtree rooted with x
// See the diagram given above.
struct NodoAVL *leftRotate(struct NodoAVL *x)
{
    struct NodoAVL *y  = x->dir;
    struct NodoAVL *T2 = y->esq;

    // Perform rotation
    y->esq = x;
    x->dir = T2;

    //  Update heights
    x->altura = max(altura(x->esq), altura(x->dir));
    y->altura = max(altura(y->esq), altura(y->dir));

    // Return new root
    return y;
}

// Get Balance factor of node N
int getBalance(struct NodoAVL *N)
{
    if (N == NULL)
        return 0;
    return altura(N->esq) - altura(N->dir);
}

// Recursive function to insert a key in the subtree rooted
// with node and returns the new root of the subtree.
struct NodoAVL* insert(struct NodoAVL* node, TipoAVL key)
{
    /* 1.  Perform the normal BST insertion */
    if (node == NULL)
        return(newNode(key));

    if (strcmp(key, node->info) < 0)      //(key < node->info)
        node->esq = insert(node->esq, key);
    else if (strcmp(key, node->info) > 0) //(key > node->info)
        node->dir = insert(node->dir, key);
    else // Equal keys are not allowed in BST
        return node;

    /* 2. Update height of this ancestor node */
    node->altura = max(altura(node->esq),
                           altura(node->dir));

    /* 3. Get the balance factor of this ancestor
          node to check whether this node became
          unbalanced */
    int balance = getBalance(node);

    // If this node becomes unbalanced, then
    // there are 4 cases

    // Left Left Case
    if (balance > 1 && (strcmp(key, node->esq->info) < 0))  //(balance > 1 && key < node->esq->info)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && (strcmp(key, node->dir->info) > 0)) //(balance < -1 && key > node->dir->info)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && (strcmp(key, node->esq->info) > 0))  //(balance > 1 && key > node->esq->info)
    {
        node->esq =  leftRotate(node->esq);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && (strcmp(key, node->dir->info) < 0)) //(balance < -1 && key < node->dir->info)
    {
        node->dir = rightRotate(node->dir);
        return leftRotate(node);
    }

    /* return the (unchanged) node pointer */
    return node;
}

void preOrder(struct NodoAVL *root)
{
    if(root != NULL)
    {
        printf("%s ", root->info);
        preOrder(root->esq);
        preOrder(root->dir);
    }
}

void inOrder(struct NodoAVL *root)
{
    if(root != NULL)
    {
        inOrder(root->esq);
        printf("%s ", root->info);
        inOrder(root->dir);
    }
}

// Lê um arquivo TXT com 1 palavra a cada linha e a insere em uma árvore AVL
struct NodoAVL* readFile(TipoAVL nomeArquivo, struct NodoAVL *raiz)
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
                   raiz = insert(raiz, auxiliar);
                   printf("\tinsert('%s')\n", auxiliar); // DEBUG
                }
                i = 0;
            }
        }while(C != EOF);
        fclose(arquivo);
    }
    return raiz;
}

/* Representação do trabalho*/
int main()
{
    /* Criar raiz da arvore AVL */
    struct NodoAVL *raiz = NULL;

    /* Arvore AVL construida com o arquivo "entrada.txt"
             C
           /   \
          B     D
        /  \     \
       A    AB    E

       inOrder  : A AB B C D E
       preOrder : A B AB C D E
    */

    printf("\n> Lendo Arquivo . . .\n");
    raiz = readFile("entrada.txt", raiz);

    /* Imprimir InOrder e PreOrder */
    printf("\nIn Order:\n"); inOrder(raiz);
    printf("\nPre Order:\n"); preOrder(raiz);

    printf("\n");

    return 0;
}
