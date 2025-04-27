#include "abb.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

int main() {
    printf("----------ARVORE BINARIA DE BUSCA----------\n");

    srand(time(NULL)); 
    int v[10], i = 0;
    No *raiz = NULL;

    //Preenche o vetor com números aleatórios entre 1 e 100
    for(i = 0; i < 10; i++) {
        v[i] = 1 + rand() % (100 - 1 + 1);
    }

    printf("Numeros a serem inseridos na arvore: ");
    for(i = 0; i < 10; i++) {
        printf("%i ", v[i]);
    }

    for(i = 0; i < 10; i++) {
        raiz = insereNo(raiz, v[i]);
    }

    printf("\nArvore em ordem: ");
    emOrdem(raiz);

    printf("\nArvore pre ordem: ");
    preOrdem(raiz);

    printf("\nArvore pos ordem: ");
    posOrdem(raiz);

    printf("\nArvore em largura\n");
    imprimeBFS(raiz);

    printf("\nAltura da arvore: %i", altura(raiz));

    printf("\nQuantidade de nos na arvore: %i", quantNos(raiz));

    printf("\nSoma dos valores dos nos na arvore: %i", somaNos(raiz));

    printf("\nA arvore eh estritamente binaria?: %s", eEstBinaria(raiz) ? "Sim" : "Nao");

    printf("\nA arvore eh cheia?: %s", eCheia(raiz) ? "Sim" : "Nao");

    printf("\nA arvore eh quase cheia?: %s", eQuaseCheia(raiz) ? "Sim" : "Nao");

    printf("\nRemovendo a raiz (%i)", raiz->info);
    removeNo(raiz, raiz->info);

    printf("\nArvore em largura\n");
    imprimeBFS(raiz);

    printf("\nAltura da arvore: %i", altura(raiz));

    printf("\nQuantidade de nos na arvore: %i", quantNos(raiz));

    printf("\nSoma dos valores dos nos na arvore: %i", somaNos(raiz));

    printf("\nA arvore eh estritamente binaria?: %s", eEstBinaria(raiz) ? "Sim" : "Nao");

    printf("\nA arvore eh cheia?: %s", eCheia(raiz) ? "Sim" : "Nao");

    printf("\nA arvore eh quase cheia?: %s", eQuaseCheia(raiz) ? "Sim" : "Nao");

    printf("\n");

    destroiArvore(raiz);

    system("pause");

    return 0;
}
