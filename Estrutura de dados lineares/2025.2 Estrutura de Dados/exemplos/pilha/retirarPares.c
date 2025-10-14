#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct pilha {
    int qtd;
    char dados[MAX];
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
    if(pi == NULL || pi->qtd == MAX){
        return 0;
    }
    pi->dados[pi->qtd] = dado;
    pi->qtd++;
    return 1;
}

int remover_Pilha(Pilha* pi){ // pop
    if(pi == NULL || pi->qtd == 0){
        return 0;
    }
    pi->qtd--;
    return 1;
}

char topo_Pilha(Pilha* pi){ // peek
    if(pi == NULL || pi->qtd == 0){
        return '\0';
    }
    return pi->dados[pi->qtd - 1];
}

void removerPares(char* str){
    Pilha* pi = criar_Pilha();
    for(int i=0; str[i] != '\0'; i++){
        char topo;
        if(!Pilha_vazia(pi) && (topo_Pilha(pi) == str[i])){
        remover_Pilha(pi); 
        } else {
            inserir_Pilha(pi, str[i]);
        }
    }

    
    for(int i=0; i < pi->qtd; i++){
        str[i] = pi->dados[i];
    }
    str[pi->qtd] = '\0';

    destruir_pilha(pi);
}

int main(){
    char str[MAX];
    printf("Digite a string: ");
    scanf("%s", str);

    removerPares(str);

    printf("Resultado: %s\n", str);
    return 0;
}