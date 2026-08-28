/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Davi de Oliveira Parada
Linguagem   : C++
Problema    : https://judge.beecrowd.com/pt/problems/view/1080
Data        : 28/08/2026
Objetivo    : Ler cem valores inteiros e mostrar o maior e sua posicao.
Dificuldade : Organização do código
Uso de IA   : Utilizei para correções de sintaxe da linguagem C++
-------------------------------------------------------------------------- */

#include <iostream>
using namespace std;
 
int main() {
    int *vetor = new int[100];
    
    cin >> vetor[0]; 
    int maior = vetor[0]; // assumindo o primeiro valor como o maior
    
    int posicao = 1;

    
    for(int i = 1; i < 100;i++){
        cin >> vetor[i]; //Armazenando no vetor
        if(vetor[i] > maior){  //Verificando quem e maior
            posicao = i + 1;
            maior = vetor[i];
        }
    }
    
    cout << maior << "\n";
    cout << posicao << "\n";
    
    delete[] vetor;
    
    return 0;
}
