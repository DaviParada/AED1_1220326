/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Davi de Oliveira Parada
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1080
Data        : 20/08/2026
Objetivo    : Ler cem valores inteiros e mostrar o maior e sua posicao.
Dificuldade : Otimização do código
Uso de IA   : Utilizei para verificar possíveis otimizações, como deixar o primeiro scanf fora do loop
-------------------------------------------------------------------------- */

#include <stdio.h>
 
int main() {
    int maior, x;
    int posicao = 1;
    
    scanf("%d", &maior);  //Armazenar o primeiro valor como o maior, fora do loop
                         //para não ter que ficar verificando toda hora
                         
    for(int i = 2; i <= 100; i++){
        scanf("%d", &x);
        
        if(x > maior){    //O novo Valor é maior que o maior valor até agora?
            maior = x;    //Guardo o novo maior valor
            posicao = i;  //Armazeno a posicao do novo maior valor
        }
    }
    
    printf("%d\n", maior);
    printf("%d\n", posicao);
    
    return 0;
}
