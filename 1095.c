/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Davi de Oliveira Parada
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1110
Data        : 08/11/2026
Objetivo    : Reescrever uma sequência
Dificuldade : Fazer de forma eficiente
Uso de IA   : Erro de sintaxe
-------------------------------------------------------------------------- */
#include <stdio.h>
 
int main() {
    int i = 1;
    
    for(int j = 60; j >= 0; j = j - 5){
        printf("I=%d J=%d\n", i, j);
        i+=3;
    }
                
    return 0;
}
