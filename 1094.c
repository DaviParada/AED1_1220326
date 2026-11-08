/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Davi de Oliveira Parada
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1110
Data        : 08/11/2026
Objetivo    : Ajudar a saber a quantidade de cobaias usadas em um laboratório
Dificuldade : Sintaxe do C
Uso de IA   : Erro de sintaxe
-------------------------------------------------------------------------- */
#include <stdio.h>
 
#include <stdio.h>
 
int main() {
    int N;
    scanf("%d", &N);
    
    int qtd = 0;
    int qtd_C = 0;
    int qtd_R = 0;
    int qtd_S = 0;
    int qtd_Total = 0;
    char tipo;

    
    for(int i = 0; i < N; i++){
        scanf("%d %c", &qtd, &tipo);
        
        qtd_Total += qtd;
        
        if(tipo == 'C'){
            qtd_C += qtd;
        }else if(tipo == 'R'){
            qtd_R += qtd;
        }else if(tipo == 'S'){
            qtd_S += qtd;
        }else{
            return -1;
        }
    }
    
    float per_coelhos = (float)qtd_C / qtd_Total * 100;
    float per_ratos = (float)qtd_R / qtd_Total * 100;
    float per_sapos = (float)qtd_S / qtd_Total * 100;
    
    printf("Total: %d cobaias\n", qtd_Total);
    printf("Total de coelhos: %d\n", qtd_C);
    printf("Total de ratos: %d\n", qtd_R);
    printf("Total de sapos: %d\n", qtd_S);
    printf("Percentual de coelhos: %.2f %%\n", per_coelhos);
    printf("Percentual de ratos: %.2f %%\n", per_ratos);
    printf("Percentual de sapos: %.2f %%\n", per_sapos);
    

    return 0;
}
