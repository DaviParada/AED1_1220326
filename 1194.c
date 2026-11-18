/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Davi de Oliveira Parada
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1194
Data        : 18/11/2026
Objetivo    : Colocar a arvore na ordem posfixa
Dificuldade : lógica de recursão para ir para esquerda e direita
Uso de IA   : Sintaxe e entender a lógica de recursão em árvores binárias
-------------------------------------------------------------------------- */
#include <stdio.h>

int busca(char *in, char c, int n){
    for(int k = 0; k < n; k++){
        if(in[k] == c){
            return k;
        }
    }
    return -1;
}

void posfixa(char *pre, char *in, int n){
    if(n == 0) return;  // caso base

    int k = busca(in, pre[0], n);   // k = nós da esquerda

    posfixa(pre + 1, in, k);   // esquerda
    posfixa(pre + 1 + k, in + k + 1, n - 1 -k);  //direita
    printf("%c", pre[0]);  //raiz por ultimo

}


int main(){
    int c, n;
    char s1[60], s2[60];

    scanf("%d", &c);

    while(c--){
        scanf("%d %s %s", &n, s1, s2);
        posfixa(s1, s2, n);
        printf("\n");
    }

    return 0;
}
