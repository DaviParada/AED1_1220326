/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Davi de Oliveira Parada
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1200
Data        : 18/11/2026
Objetivo    : Implementar uma árvore binária de busca de letras que obedece a comandos de inserir, buscar e imprimir os percursos
Dificuldade : Resolver o problema dos espaços em branco
Uso de IA   : Utilizei para pensar na lógica de árvore e o problema de espaços em branco do BeeCrowd
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int primeiro;

typedef struct No{
    char chave;
    struct No *esq;
    struct No *dir;
} No;

typedef No *arvore;

void imprime(char c){
    if(primeiro){
        printf("%c", c);
        primeiro = 0;
    } else {
        printf(" %c", c);
    }
}

void inserir(No **raiz, char c){
    if(*raiz == NULL){
        arvore novo = malloc(sizeof(No));
        novo->chave = c;
        novo->esq = NULL;
        novo->dir = NULL;
        *raiz = novo;
        return; 
    }

    if(c < (*raiz)->chave){
        inserir(&(*raiz)->esq, c);
    }else{
        inserir(&(*raiz)->dir, c);
    }
}

int buscar(No *raiz, char c){
    if(raiz == NULL) return 0;
    if(c == raiz->chave) return 1;
    if(c < raiz->chave){
        return buscar(raiz->esq, c);
    } else{
        return buscar(raiz->dir, c);
    }
}

void infixa(No *raiz){
    if(raiz != NULL) {
        infixa(raiz->esq);
        imprime(raiz->chave);
        infixa(raiz->dir);
    }
}

void prefixa(No *raiz){
    if(raiz != NULL){
        imprime(raiz->chave);
        prefixa(raiz->esq);
        prefixa(raiz->dir);
    }
}

void posfixa(No *raiz){
    if(raiz != NULL){
        posfixa(raiz->esq);
        posfixa(raiz->dir);
        imprime(raiz->chave);
    }
}

int main(){
    No *raiz = NULL;
    char cmd[10];
    char c;

    while(scanf("%s", cmd) != EOF){
        if(strcmp(cmd, "I") == 0){
            scanf(" %c", &c);
            inserir(&raiz, c);
        } else if(strcmp(cmd, "P") == 0){
            scanf(" %c", &c);
            if(buscar(raiz, c))
                printf("%c existe\n", c);
            else
                printf("%c nao existe\n", c);
        } else if(strcmp(cmd, "INFIXA") == 0){
            primeiro = 1;
            infixa(raiz);
            printf("\n");
        } else if(strcmp(cmd, "PREFIXA") == 0){
            primeiro = 1;
            prefixa(raiz);
            printf("\n");
        } else if(strcmp(cmd, "POSFIXA") == 0){
            primeiro = 1;
            posfixa(raiz);
            printf("\n");
        }
    }
    return 0;
}
