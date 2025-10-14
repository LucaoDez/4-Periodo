#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct pilha {
    int qtd;
    char dados[100];
} Pilha;

Pilha* criar_Pilha() {
    Pilha* pi = (Pilha*) malloc(sizeof(Pilha)); 
    if (pi != NULL) { 
        pi->qtd = 0;  
    }
    return pi; 
}

void destruir_pilha(Pilha* pi){
    free(pi);
}

int Pilha_vazia(Pilha* pi){
    if (pi == NULL){
        return -1;
    }
    return (pi->qtd == 0);
}

int inserir_Pilha(Pilha* pi, char dado){ // push
    if(pi == NULL || pi->qtd == 100){
        return 0;
    }
    pi->dados[pi->qtd++] = dado;
    return 1;
}

int remover_Pilha(Pilha* pi, char* dado){ // pop
    if(pi == NULL || pi->qtd == 0){
        return 0;
    }
    *dado = pi->dados[--pi->qtd];
    return 1;
}

char topo_Pilha(Pilha* pi){ // peek
    if(pi == NULL || pi->qtd == 0){
        return '\0';
    }
    return pi->dados[pi->qtd - 1];
}

int precedencia(char op){
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    return 0;
}

void infixa_para_posfixa(char* infixa, char* posfixa){
    Pilha* pi = criar_Pilha();
    int i, k = 0;
    char c, topo;

    for(i = 0; infixa[i] != '\0'; i++){
        c = infixa[i];

        if(isalnum(c)){ 
            posfixa[k++] = c; // operando vai direto
        }
        else if(c == '('){
            inserir_Pilha(pi, c);
        }
        else if(c == ')'){
            while(!Pilha_vazia(pi) && topo_Pilha(pi) != '('){
                remover_Pilha(pi, &topo);
                posfixa[k++] = topo;
            }
            remover_Pilha(pi, &topo); // remove o '('
        }
        else { // operador
            while(!Pilha_vazia(pi) && precedencia(topo_Pilha(pi)) >= precedencia(c)){
                remover_Pilha(pi, &topo);
                posfixa[k++] = topo;
            }
            inserir_Pilha(pi, c);
        }
    }

    // desempilha resto
    while(!Pilha_vazia(pi)){
        remover_Pilha(pi, &topo);
        posfixa[k++] = topo;
    }

    posfixa[k] = '\0'; // fim da string
    destruir_pilha(pi);
}

int main(){
    char infixa[100], posfixa[100];
    printf("Digite a expressao infixa: ");
    scanf("%s", infixa);

    infixa_para_posfixa(infixa, posfixa);

    printf("Expressao posfixa: %s\n", posfixa);
    return 0;
}