/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Davi de Oliveira Parada
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1195
Data        : 11/11/2026
Objetivo    : Criar uma arvore binaria
Dificuldade : Função inserir No
Uso de IA   : Revisão sobre árvores binárias
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int conteudo;
    struct No *esq;
    struct No *dir;
} No;

typedef No *arvore;

arvore criarNo(int valor){
    arvore novo = malloc(sizeof(No));
    if(novo == NULL) exit(1);
    novo->conteudo = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

void inserir(arvore *raiz, int valor){
    if(*raiz == NULL){
        *raiz = criarNo(valor);
        return;
    }
    if(valor < (*raiz)->conteudo){     // se for menor que a raiz
        inserir(&(*raiz)->esq, valor); //endereco de memoria da raiz->esq
    }
    else if(valor > (*raiz)->conteudo){  // se for maior que a raiz
        inserir(&(*raiz)->dir, valor);  // endereco de memoria da raiz->dir
    }
    
}

void red(arvore raiz){
    if(raiz != NULL){
        printf(" %d", raiz->conteudo);
        red(raiz->esq);
        red(raiz->dir);
    }
}

void erd(arvore raiz){
    if(raiz != NULL){
        erd(raiz->esq);
        printf(" %d", raiz->conteudo);
        erd(raiz->dir);
    }
}

void edr(arvore raiz){
    if(raiz != NULL){
        edr(raiz->esq);
        edr(raiz->dir);
        printf(" %d", raiz->conteudo);
    }
}

void liberar(arvore raiz){
    if(raiz != NULL){
        liberar(raiz->esq);
        liberar(raiz->dir);
        free(raiz);
    }
}


int main(){
    int c;
    int n;

    scanf("%d", &c);

    for(int i = 0; i < c; i++){
        scanf("%d", &n);

        arvore raiz = NULL;

        for(int j = 0; j < n; j++){
            int valor;
            scanf("%d", &valor);
            inserir(&raiz, valor);
        }

        printf("Case %d:\n", i+1);
        printf("Pre.:");
        red(raiz);

        printf("\n");

        printf("In..:");
        erd(raiz);

        printf("\n");

        printf("Post:");
        edr(raiz);

        printf("\n\n");

        liberar(raiz);
    }

    return 0;
}
