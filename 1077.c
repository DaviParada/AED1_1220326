/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Davi de Oliveira Parada
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/2448
Data        : 11/10/2026
Objetivo    : Infixa em posfixa
Dificuldade : Utilizacao de lista encadeada com pilhas
Uso de IA   : Utilizei como tutora para entender como funcionava lista encadeada com pilhas e sintaxe do C
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct No{
    char dado;
    struct No *prox;
}No;

void push(No **topo, char c){
    No *novo = malloc(sizeof(No));
    novo->dado = c;
    novo->prox = *topo;
    *topo = novo;
}

char pop(No **topo){
    No *temp = *topo;
    char c = temp->dado;
    *topo = temp->prox;
    free(temp);
    return c;

}

int vazia(No *topo){
    return topo == NULL;
}

char espiar(No *topo){
    return topo->dado;
}

void esvaziar(No **topo){
    while(!vazia(*topo)){
        pop(topo);
    }
}

int prec(char c){
    if(c == '+' || c == '-'){
        return 1;
    }
    else if(c == '*' || c == '/'){
        return 2;
    }
    else if(c == '^'){
        return 3;
    }else{
        return 0;
    }
}



int main(void){
    int n;
    char linha[400];

    scanf("%d", &n);


    while(n--){
        No *pilha = NULL;
        
        do{
            if(fgets(linha, sizeof(linha), stdin) == NULL) break;
        } while(linha[0] == '\n' || linha[0] == '\r');

        for(int i = 0; linha[i] != '\0'; i++){
            char c = linha[i];
            if(c == '\n' || c == '\r') break;

            if(isalnum(c)){
                printf("%c", c);   // Se for um operando, imprime diretamente
            }
            else if(c == '('){
                push(&pilha, c);  // Se for um '(', empilha
            }
            else if(c == ')'){
                while(!vazia(pilha) && espiar(pilha) != '('){
                    printf("%c", pop(&pilha));  // Desempilha e imprime até encontrar '('                   
                }
                if(!vazia(pilha) && espiar(pilha) == '('){
                    pop(&pilha); //Remove o '(' da pilha
                }
            }
            else{
                while(!vazia(pilha) && prec(espiar(pilha)) >= prec(c)){
                    printf("%c", pop(&pilha));
                }
                push(&pilha, c); // Empilha o operador atual
            }

        }

        while(!vazia(pilha)){
            printf("%c", pop(&pilha)); // Desempilha e imprime os operadores restantes
        }


        printf("\n");
        esvaziar(&pilha);

    }

    return 0;
}
