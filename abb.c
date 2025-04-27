#include "abb.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

No *criaNo(int info) {
    No *novoNo = malloc(sizeof(No));

    if(!novoNo) {
        printf("\nErro ao alocar memoria para criar um novo no.\n");
        return NULL;
    }

    novoNo->info = info;
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    
    return novoNo;
}

No *insereNo(No *raiz, int info) {
    if(!raiz) {
        return criaNo(info);
    }

    if(info < raiz->info) {
        raiz->esq = insereNo(raiz->esq, info);
    } else if(info > raiz->info) {
        raiz->dir = insereNo(raiz->dir, info);
    } else {
        printf("\nO numero enviado ja esta na arvore e nao sao permitidos numeros repetido na arvore binaria de busca.\n");
        return raiz;
    }

    return raiz;
}

No *menorNo(No *raiz) {
    if(!raiz) {
        printf("\nA arvore enviada esta vazia.\n");
        return raiz;
    }

    No *temp = raiz;

    while(temp->esq) {
        temp = temp->esq;
    }

    return temp;
}

No *removeNo(No *raiz, int info) {
    if(!raiz) {
        printf("\nO elemento a ser removido nao esta na arvore enviada.\n");
        return raiz;
    }

    if(info < raiz->info) {
        raiz->esq = removeNo(raiz->esq, info);
    } else if(info > raiz->info) {
        raiz->dir = removeNo(raiz->dir, info);
    } else {
        if(!raiz->esq) {
            No *temp = raiz->dir;
            free(raiz);
            return temp;
        } else if (!raiz->dir) {
            No *temp = raiz->esq;
            free(raiz);
            return temp;
        } else {
            No *temp = menorNo(raiz->dir);
            raiz->info = temp->info;
            raiz->dir = removeNo(raiz->dir, temp->info);
        }
    }

    return raiz;
}

void emOrdem(No *raiz) {
    if(raiz) {
        emOrdem(raiz->esq);
        printf("%i ", raiz->info);
        emOrdem(raiz->dir);
    }
}

void preOrdem(No *raiz) {
    if(raiz) {
        printf("%i ", raiz->info);
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);
    }
}

void posOrdem(No *raiz) {
    if(raiz) {
        posOrdem(raiz->esq);
        posOrdem(raiz->dir);
        printf("%i ", raiz->info);
    }
}

int altura(No *raiz) {
    if(!raiz) {
        return 0;
    }

    int alturaE = altura(raiz->esq);
    int alturaD = altura(raiz->dir);

    return 1 + (alturaE > alturaD ? alturaE : alturaD);
}

int quantNos(No *raiz) {
    if(!raiz) {
        return 0;
    }

    return 1 + quantNos(raiz->esq) + quantNos(raiz->dir);
}

void imprimeBFS(No *raiz) {
    if(!raiz) {
        printf("\nA arvore enviada esta vazia\n");
        return;
    }

    No *fila[quantNos(raiz) + 1];
    int frente = 0, tras = 0, nivel = 0;
    fila[tras++] = raiz;

    while(frente < tras) {
        int tamNivel = tras - frente;

        printf("Nivel %i: ", nivel++);
        for(int j = 0; j < (quantNos(raiz) - tras) / 2; j++) {
            printf("  ");
        }
        for(int i = 0; i < tamNivel; i++) {
            No *atual = fila[frente++];

            printf("%i   ", atual->info);

            if(atual->esq) {
                fila[tras++] = atual->esq;
            }
            if(atual->dir) {
                fila[tras++] = atual->dir;
            }
        }

        printf("\n");
    }
}

int somaNos(No *raiz) {
    if(!raiz) {
        return 0;
    }

    return raiz->info + somaNos(raiz->esq) + somaNos(raiz->dir);
}

bool eEstBinaria(No *raiz) {
    if(!raiz){
        return true;
    }

    if(!raiz->esq && raiz->dir) {
        return false;
    } else if (raiz->esq && !raiz->dir) {
        return false;
    }

    return eEstBinaria(raiz->esq) && eEstBinaria(raiz->dir);
}

bool eCheia(No *raiz) {
    if(!raiz) {
        printf("\nA arvore enviada esta vazia.\n");
        return false;;
    }

    if(quantNos(raiz) == pow(2,altura(raiz)) - 1) {
        return true;
    } else {
        return false;
    }
}

int buscaNo(No *raiz, int info) {
    if(!raiz) {
        printf("\nA arvore enviada esta vazia.\n");
        return 0;;
    }

    No *fila[quantNos(raiz) + 1];
    int frente = 0, tras = 0, i = 0;
    fila[tras++] = raiz;

    while (frente < tras) {
        No *atual = fila[frente++];

        if(atual->info == info) {
            return i;
        }

        i++;
        if(atual->esq) {
            fila[tras++] = atual->esq;
        }
        if(atual->dir) {
            fila[tras++] = atual->dir;
        }
    }
}

bool eQuaseCheia(No *raiz) {
    if(eCheia(raiz)) {
        return false;
    }

    if(!raiz) {
        printf("\nA arvore enviada esta vazia.\n");
        return false;
    }

    No *fila[quantNos(raiz) + 1];
    int frente = 0, tras = 0;
    bool noIncompleto = false;
    fila[tras++] = raiz;

    while(frente < tras) {
        No *atual = fila[frente++];

        if(atual->esq) {
            if(noIncompleto) {
                return false;
            }
            fila[tras++] = atual->esq;
        } else {
            noIncompleto = true;
        }

        if(atual->dir) {
            if(noIncompleto) {
                return false;
            }
            fila[tras++] = atual->dir;
        } else {
            noIncompleto = true;
        }
    }

    return true;
}

void destroiArvore(No *raiz) {
    if(raiz) {
        destroiArvore(raiz->esq);
        destroiArvore(raiz->dir);
        free(raiz);
    }
}
