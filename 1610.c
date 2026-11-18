/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Davi de Oliveira Parada
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1610
Data        : 18/11/2026
Objetivo    : Detectar loops dentro dos grafos
Dificuldade : Quase em toda a questão
Uso de IA   : Entender como funciona grafos e os loops dentro
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>

#define MAXN 10001

typedef struct no {
    int dest;
    struct no *prox;
} No;

No *adj[MAXN];  // lista dos documentos dos quais a depende
int cor[MAXN];  // 0 = branco, 1 = cinza, 2 = preto

// insere a aresta a -> b no começo da lista de a
void adiciona(int a, int b){
    No *novo = malloc(sizeof(No));
    novo->dest = b;
    novo->prox = adj[a];
    adj[a] = novo;
}

// devolve 1 se encontrar ciclo a partir de v, 0 caso contrário
int dfs(int v){
    cor[v] = 1;      // entro em v cinza
    for(No *p = adj[v]; p != NULL; p = p->prox){
        int w = p->dest;
        if(cor[w] == 1) return 1;   //aresta for para o caminho atual é um ciclo
        if(cor[w] == 0 && dfs(w)) return 1;   // vai descendo, se achar ele propaga
    }
    cor[v] = 2;   //acabou, v preto
    return 0;
}

// liberando a memória dos nós
void libera(int n){
    for(int i = 1; i <= n; i++){
        No *p = adj[i];
        while(p != NULL){
            No *prox = p->prox;
            free(p);
            p = prox;
        }
        adj[i] = NULL;
    }
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int n, m;
        scanf("%d %d", &n, &m);

        for(int i = 1; i <= n; i++){
            adj[i] = NULL; cor[i] = 0;
        }

        for (int i = 0; i < m; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            adiciona(a, b);
        }

        int achou = 0;
        for (int v = 1; v <= n && !achou; v++)
            if (cor[v] == 0 && dfs(v)) achou = 1;

        if(achou){
            printf("SIM\n");
        } else{
            printf("NAO\n");
        }

        libera(n);
    }
}
