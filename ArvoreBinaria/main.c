/*  ÁRVORE BINÁRIA DE BUSCA (ABB)
 *
 *  Autor  : Gabriel Alejandro L. M.
 *  Arquivo: main.c
 *  Matéria: ESTRUTURA DE DADOS I
 */
#include <stdio.h>
#include <stdlib.h>
#include "fila.c"
//#include "lista.c"
#include "tadArbin_c.c"

int main()
{
    printf("=== ARVORE BINARIA DE BUSCA ===\n\n");

    Arbin a = inicArbin();
    a = insArbinBusca(a, 100);
    a = insArbinBusca(a, 20);
    a = insArbinBusca(a, 150);
    /*  Representação da Árvore A:
     *
     *          (100)
     *        /       \
     *      (20)     (150)
     *
     */

    Arbin b = inicArbin();
    b = insArbinBusca(b, 100);
    b = insArbinBusca(b, 20);
    b = insArbinBusca(b, 150);

    //Arbin c = inicArbin();

    Arbin d = inicArbin();
    d = insArbinBusca(d, 100);
    d = insArbinBusca(d, 20);
    d = insArbinBusca(d, 150);
    d = insArbinBusca(d, 200);

    Arbin e = inicArbin();
    e = insArbinBusca(e, 10);
    e = insArbinBusca(e, 5);
    e = insArbinBusca(e, 20);
    e = insArbinBusca(e, 30);

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


    int maiorElem = maiorElementoArbin(a);
    printf("O maior elemento da Arvore eh %d\n", maiorElem);

    int isomorfo = isomorfos(a, b);
    if(isomorfo != 0)
        printf("As duas arvores sao isomorfas!\n");
    else
        printf("As duas arvores NAO sao isomorfas!\n");

    int completa = completaArbin(a);
    if(completa != 0)
        printf("A arvore eh completa!\n");
    else
        printf("A arvore NAO eh completa!\n");

    int cheia = cheiaArbin(a);
    if(cheia != 0)
        printf("A arvore esta cheia!\n");
    else
        printf("A arvore esta QUASE cheia!\n");

    int ocorre = ocorreArbin(a, b);
    if(ocorre != 0)
        printf("A arvore a2 ocorre em a1!\n");
    else
        printf("A arvore a2 NAO ocorre em a1!\n");

    int nv = nivelArbin(a, e1);
    printf("O elemento %d esta no nivel %d\n", e1, nv);

    return 0;
}
