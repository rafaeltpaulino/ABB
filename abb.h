#include <stdbool.h>

#ifndef _ABB_H
#define _ABB_H

//Estrutura dos nós da árvore binária de busca
typedef struct No {
    int info;//Valor do nó
    struct No *esq;//Filho esquerdo
    struct No *dir;//Filho direito
} No;

//Função para criar um novo nó
No *criaNo(int info);

//Função para inserir um nó na árvore binária de busca
No *insereNo(No *raiz, int info);

//Função auxiliar que encontra o menor nó em uma árvore
No *menorNo(No *raiz);

//Função para remover um nó da árvore
//raiz = raiz da árvore, info = valor do nó a ser removido da árvore
No *removeNo(No *raiz, int info);

//Função que imprime a árvore em ordem
void emOrdem(No *raiz);

//Função que imprime a árvore pre ordem
void preOrdem(No *raiz);

//Função que imprime a árvore pos ordem
void posOrdem(No *raiz);

//Função que calcula a altura da árvore
int altura(No *raiz);

//Função que calcula a quantidade de nós na árvore
int quantNos(No *raiz);

//Função que imprime a árvore em largura
void imprimeBFS(No *raiz);

//Função que soma os valores de todos os nós da árvore
int somaNos(No *raiz);

//Função que verifica se a árvore binária é estritamente binária
//Uma árvore estritamente binária é uma árvore onde todos os nós tem 0 ou 2 filhos
bool eEstBinaria(No *raiz);

//Função que verifica se a árvore binária enviada é uma árvore cheia
//Uma árvore cheia consiste de uma árvore onde todos os nós folha da árvore estão no mesmo nível
bool eCheia(No *raiz);

//Função que busca um nó e retorna sua posição na árvore
//Essa função utiliza a tecnica de busca em largura (BFS)
//Essa função não busca ser eficiente ou otimizada, apenas implementei ela para treinar busca em largura.
int buscaNo(No *raiz, int info);

//Função que verifica se a árvore binária é quase cheia
//Uma árvore quase cheia é uma árvore onde todos os níveis da árvore estão cheios, exceto o último
bool eQuaseCheia(No *raiz);

//Função para liberar a memória depois da utilização
void destroiArvore(No *raiz);

#endif