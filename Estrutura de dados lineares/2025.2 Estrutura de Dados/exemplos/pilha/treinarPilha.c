#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct pilha{
    int qtd;
    int dados[MAX];
}Pilha;

Pilha* criar_Pilha(){
    Pilha* pi = (Pilha*) malloc(sizeof(struct pilha));
    if(pi != NULL){
        pi->qtd = 0;
    }
    return pi;
}

void destruir_Pilha(Pilha* pi){
    free(pi);
}

int inserir_Pilha(Pilha* pi, int dado){
    if(pi == NULL || pi->qtd == MAX){
        return 0;
    }
    pi->dados[pi->qtd] = dado;
    pi->qtd++;
    return 1;
}

int remover_Pilha(Pilha* pi, int* dado){
    if(pi == NULL || pi->qtd == 0){
        return 0;
    }
    *dado = pi->dados[pi->qtd-1];
    pi->qtd--;
    return 1;
}

int topo_Pilha(Pilha* pi, int* dado){
    if(pi == NULL){
        return 0;
    }
    *dado = pi->dados[pi->qtd-1];
    return 1;
}

int pilha_vazia(Pilha* pi){
    if(pi == NULL){
        return -1;
    }
    return (pi->qtd == 0);
}

int pilha_cheia(Pilha* pi){
    if(pi == NULL){
        return -1;
    }
    return (pi->qtd == MAX);
}

int tamanho_Pilha(Pilha* pi){
    if(pi == NULL){
        return -1;
    }
    return pi->qtd;
}