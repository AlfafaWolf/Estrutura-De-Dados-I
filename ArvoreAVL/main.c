/* �RVORE AVL
 *
 * Autor  : Gabriel Alejandro L. M.
 * Mat�ria: ESTRUTURA DE DADOS I
 *
 * INFO:
 * Trabalho do 2Bi do 3o Per�odo
 *     Ler um arquivo de texto e fazer a inser��o de cada palavra na �rvore AVL.
 *
 * AJUDA:
 * Vizualizar inser��o na �rvore AVL
 *     https://www.cs.usfca.edu/~galles/visualization/AVLtree.html
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvoreAVL.c"

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
