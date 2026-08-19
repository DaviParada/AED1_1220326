#include <stdio.h>

int min(int n, int X[n]){
    int posicao = 0;
    
    for(int i = 0; i < n; i++){     
        scanf("%d", &X[i]);
        if(X[i] < X[posicao]){     // Verifico qual o indice do menor numero
            posicao = i;
        }
    }
    return posicao;
}


int main() {
    int n;
    scanf("%d", &n);
    int X[n];
    
    int posicao = min(n, X[n]);
    
    printf("Menor valor: %d\n", X[posicao]);
    printf("Posicao: %d\n", posicao);
 

    return 0;
}
