/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Davi de Oliveira Parada
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1068
Data        : 29/08/2026
Objetivo    : Verificar se os parenteses das expressoes abrem e fecham
Dificuldade : Manipular pilhas e ponteiros
Uso de IA   : Utilizei para entender pilhas, uas funções e otimizacao de logica
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    int array[1000];
    int topo;
} pilha;

//Inicializar a pilha
void inicializar(pilha *p){
    p->topo = -1;
}

//Verificar se a pilha esta vazia
bool verificaVazio(pilha *p){
    return p->topo == -1;
}

//Adiciona algo a pilha
bool push(pilha *p, int valor){
    if(p->topo == 999) return false;
    p->topo++;
    p->array[p->topo] = valor;
    return true;
}

//"Remove" o topo da pilha
bool pop(pilha *p){
    if(p->topo == -1) return false;
    p->topo--;
    return true;
}

//Algoritmo que verifica a expressao
bool estaCorreta(pilha *p, char *string){
    for(int i = 0; string[i] != '\0'; i++){
        if(string[i] == '('){
            if(push(p,1) == false) return false;
        }
        else if(string[i] == ')'){
            if(pop(p) == false) return false;
        }
    }

    return verificaVazio(p);

}


int main(){
    char expressao[1002];
    pilha minhaPilha;

    while(fgets(expressao, sizeof(expressao), stdin) != NULL){
        inicializar(&minhaPilha);

        if(estaCorreta(&minhaPilha, expressao) == true){
            printf("correct\n");
        }else{
            printf("incorrect\n");
        }
    }

    return 0;
}

