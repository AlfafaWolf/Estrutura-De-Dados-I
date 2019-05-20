/*  ÁRVORE BINÁRIA DE BUSCA (ABB)
 *
 *  Autor  : Gabriel Alejandro L. M.
 *  Arquivo: main.c
 *  Matéria: ESTRUTURA DE DADOS I
 */
#include <stdio.h>
#include <stdlib.h>
#include "tadArbin_c.c"

int main()
{
    printf("=== ARVORE BINARIA DE BUSCA ===\n\n");

    Arbin a = inicArbin();
    a = insArbinBusca(a, 100);
    a = insArbinBusca(a, 20);
    a = insArbinBusca(a, 150);
//    a = insArbinBusca(a, 100);
//    a = insArbinBusca(a, 10);
//    a = insArbinBusca(a, 25);
//    a = insArbinBusca(a, 200);
//    a = insArbinBusca(a, 125);
/*  Representação da Árvore atual:
 *
 *          (100)
 *        /       \
 *      (20)     (150)
 *
 */

    preOrdemArbin(a);
    printf("\n\n");

    int numF = numFolhas(a);
    printf("O numero de folhas da arvore eh %d\n", numF);

    int elemO = 100;
    int numO = numOcorrencias(a, elemO);
    printf("O numero de ocorrencias do numero %d da arvore eh %d\n", elemO, numO);

    int e1 = 100, e2 = 20;
    int exCABB = existeCaminhoABB(a, e1, e2);
    if(exCABB != 0)
        printf("Existe caminho de %d para %d!\n", e1, e2);
    else
        printf("NAO existe caminho de %d para %d!\n", e1, e2);

    int nivel = 1;
    printf("A Arvore possui %d elementos no nivel %d\n", contNivel(a, nivel), nivel);

    return 0;
}
