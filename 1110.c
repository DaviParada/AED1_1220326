/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Davi de Oliveira Parada
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1110
Data        : 28/08/2026
Objetivo    : Manipular uma lista encadeada em jogo de cartas
Dificuldade : Manipular listas encadeadas e ponteiros
Uso de IA   : Utilizei para entender listas encadeadas e suas funções
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

typedef struct No{
    int valor;
    struct No *proximo;
}No;

No *criarCabeca(int valor){
    No *cabeca = (No*) malloc(sizeof(No));
    cabeca->valor = valor;
    cabeca->proximo = NULL;
    
    return cabeca;
}

No *inserirNo(No *cabeca, int valor){
    No *novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = NULL;

    if(cabeca == NULL){
        return novo;  //Lista vazia
    }

    No *atual = cabeca;
    while(atual->proximo != NULL){  //Percorrendo a lista
        atual = atual->proximo;  
    }

    atual->proximo = novo; //Cheguei no ultimo e conecto o No no final

    return cabeca;

}

No *jogarFora(No *cabeca){
    No *antiga_cabeca = cabeca;
    No *nova_cabeca = cabeca->proximo;

    free(antiga_cabeca);

    return nova_cabeca;
}

No *moverCabecaParaOFim(No *cabeca){
     if(cabeca == NULL || cabeca->proximo == NULL){
        return cabeca;
     }

    No *novaCabeca = cabeca->proximo; // Segundo no vira a prox cabeca

    No *atual = novaCabeca;
    while(atual->proximo != NULL){   //Vai ate o ultimo
        atual = atual->proximo;
    }

    atual->proximo = cabeca;  //O ultimo no aponta para antiga cabeca
    cabeca->proximo = NULL;  //Ultimo aponta para o NULL

    return novaCabeca;

}

 
int main() {
    int n;

    cin >> n;
    while(n != 0){
        No *cabeca = NULL;
        int descartados[49];

        //Constroi a lista
        for(int i = 0; i < n;i++){
            if(i == 0){
                cabeca = criarCabeca(i+1);
            }else{
                cabeca = inserirNo(cabeca, i+1);
            }
        }

        int tamanhoAtual = n;
        int countDescartados = 0;

        while(tamanhoAtual >= 2){
            descartados[countDescartados] = cabeca->valor;
            countDescartados++;

            cabeca = jogarFora(cabeca);
            cabeca = moverCabecaParaOFim(cabeca);

            tamanhoAtual--;
        }

        printf("Discarded cards: ");
        for(int i = 0; i < countDescartados; i++){
            if(i > 0){
                printf(", ");
            }
            printf("%d", descartados[i]);
        }
        printf("\n");

        printf("Remaining card: %d\n", cabeca->valor);

        free(cabeca);
        cin >> n;

    }

    return 0;
}
