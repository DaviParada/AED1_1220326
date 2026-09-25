/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Davi de Oliveira Parada
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/2448
Data        : 25/09/2026
Objetivo    : Calcular o tempo que um carteiro demora para percorrer uma rua com vetores utilizando busca binária
Dificuldade : Pensar onde encaixar a busca binária
Uso de IA   : Criava a lógica no meu caderno (pseudocódigo) e perguntava para a IA se era um bom caminho, e sintaxe do C
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>

int buscaBinaria(int low, int high, int valor, int casas_ordenadas[]){
    //Casos base
    if(low > high){
        return -1;
    }
    int meio = low + (high - low)/2;  //meio eh o indice do num da casa
    if(casas_ordenadas[meio] == valor){
        return meio;
    }

    //Casos recursivos
    if(casas_ordenadas[meio] > valor){
        high = meio - 1;
        return buscaBinaria(low, high, valor, casas_ordenadas);
    }
    else{
        low = meio + 1;
        return buscaBinaria(low, high, valor, casas_ordenadas);
    }

}



int main(){
    // leitura e inicializacao dos vetores
    int num_casas, num_encomendas;
    scanf("%d", &num_casas);
    scanf("%d", &num_encomendas);

    int casas_ordenadas[num_casas];
    int ordem_encomendas[num_encomendas];

    for(int i = 0; i < num_casas; i++){
        scanf("%d", &casas_ordenadas[i]);
    }
    for(int i = 0; i < num_encomendas; i++){
        scanf("%d", &ordem_encomendas[i]);
    }


    //Entregando encomenda por encomenda
    long long tempo = 0;
    int indice_onde_estou = 0, indice_prox_casa;
    int low = 0, high = num_casas - 1;  //pegando o indice do inicio e o indice final do vetor de casas ordenado
    
    for(int i = 0; i < num_encomendas; i++){
        int valor = ordem_encomendas[i];  //puxando o num da casa na ordem das encomendas
        indice_prox_casa = buscaBinaria(low, high, valor, casas_ordenadas);
        tempo += abs(indice_prox_casa - indice_onde_estou);
        indice_onde_estou = indice_prox_casa;
    }

    //Imprimindo o resultando
    printf("%lld\n", tempo);

    return 0;
}
