/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Davi de Oliveira Parada
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1383
Data        : 28/08/2026
Objetivo    : Verificar uma suposta solução do jogo Sudoku
Dificuldade : Alocação dinâmica de matrizes
Uso de IA   : Utilizei para me explicar sobre alocação dinâmica de matrizes
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool verifica_linha(int **matriz, int linhas, int colunas){
	
	for(int i = 0; i < linhas; i++){
		
		bool visto[10] = {false};    //	Nova array em cada linha preenchido com falsos (a posicao 0 sera ignorada)
		
			for(int j = 0; j < colunas; j++){
				int numero = matriz[i][j];  
				
				if(numero < 1 || numero > 9){  //Se o valor condiz com o jogo
				return false;				
				}
				
				if(visto[numero] == true){    //Se o numero ja apareceu na array,retorno falso
					return false;
				}
				
				visto[numero] = true;   //Caso nao tenha aparecido entao coloco como visto
								
			}			
	}	
	return true;
}

bool verifica_coluna(int **matriz, int linhas, int colunas){
	for(int j = 0; j < colunas; j++){      //Troquei os loops entre i e j para ficar alterando as linhas toda hora
		
		bool visto[10] = {false};    //	Nova array em cada coluna preenchido com falsos (a posicao 0 sera ignorada)
		
			for(int i = 0; i < linhas; i++){
				int numero = matriz[i][j];  
				
				if(numero < 1 || numero > 9){  //Se o valor condiz com o jogo
				return false;				
				}
				
				if(visto[numero] == true){    //Se o numero ja apareceu na array,retorno falso
					return false;
				}
				
				visto[numero] = true;   //Caso nao tenha aparecido entao coloco como visto
								
			}			
	}
	return true;	
}

bool verifica_bloco(int **matriz){
	for(int bloco = 0; bloco < 9; bloco++){
		
		int inicio_linha = (bloco / 3) * 3;    //Para saber onde começa a linha do bloco
		int inicio_coluna = (bloco % 3) * 3;  //Para saber onde começa a coluna do bloco
		
		bool visto[10] = {false};
		
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){
				
				int numero = matriz[inicio_linha + i][inicio_coluna + j];
				
				if(numero < 1 || numero > 9){
					return false;
				}
				
				if(visto[numero] == true){
					return false;
				}
				
				visto[numero] = true;
			}
		}
    }
	return true;	
	
}

int main(){
	int n, count = 1;
	int linhas = 9, colunas = 9;
	scanf("%d", &n);
	
	
	while(count <= n){
	    int **matriz = malloc(linhas * sizeof(int*));
	    for(int i = 0; i < linhas; i++){
	        matriz[i] = malloc(colunas * sizeof(int));
	    }
		
		for(int i = 0; i < linhas; i++){
			for(int j = 0; j < colunas; j++){
				scanf("%d", &matriz[i][j]);
			}
		}
		
		printf("Instancia %d\n", count);
		if(verifica_linha(matriz, linhas, colunas) && verifica_coluna(matriz, linhas, colunas) && verifica_bloco(matriz)){
			printf("SIM\n\n");
		}
		else{
			printf("NAO\n\n");
		}
		
		count++;
		
		for(int i = 0; i < linhas; i++){
            free(matriz[i]);
        }
    
        free(matriz);
    
	}
	
	
	return 0;
}
