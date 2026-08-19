#include <stdio.h>
#include <stdbool.h>

bool verifica_linha(int matriz[9][9]){
	
	for(int i = 0; i < 9; i++){
		
		bool visto[10] = {false};    //	Nova array em cada linha preenchido com falsos (a posicao 0 sera ignorada)
		
			for(int j = 0; j < 9; j++){
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

bool verifica_coluna(int matriz[9][9]){
	for(int j = 0; j < 9; j++){      //Troquei os loops entre i e j para ficar alterando as linhas toda hora
		
		bool visto[10] = {false};    //	Nova array em cada coluna preenchido com falsos (a posicao 0 sera ignorada)
		
			for(int i = 0; i < 9; i++){
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

bool verifica_bloco(int matriz[9][9]){
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
	int matriz[9][9];
	scanf("%d", &n);
	
	
	while(count <= n){
		
		for(int i = 0; i < 9; i++){
			for(int j = 0; j < 9; j++){
				scanf("%d", &matriz[i][j]);
			}
		}
		
		if(verifica_linha(matriz) && verifica_coluna(matriz) && verifica_bloco(matriz)){
			printf("Instancia %d\n", count);
			printf("SIM\n\n");
		}
		else{
			printf("Instancia %d\n", count);
			printf("NAO\n\n");
		}
		
		count++;
	}
	
	return 0;
}
