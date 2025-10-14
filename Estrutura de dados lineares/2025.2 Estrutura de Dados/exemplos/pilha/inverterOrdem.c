#include <stdio.h>
#include <stdlib.h>
#include "inverterOrdem.h"

struct pilha{
    int qtd;
    char palavra[MAX];
};

Pilha* criar_Pilha(){
    Pilha* pi;
    pi = (Pilha*) malloc(sizeof(struct pilha));
    if(pi != NULL){
        pi->qtd = 0;
    }
    return pi;
}

void destruir_Pilha(Pilha* pi){
    free(pi);
}

int acessar_Topo(Pilha* pi, char* c){
    if(pi == NULL || pi->qtd == 0){
        return 0;
    }
    *c = pi->palavra[pi->qtd-1];
    return 1;
}

int remover_Topo(Pilha* pi){
    if(pi == NULL || pi->qtd == 0){
        return 0;
    }
    pi->qtd--;
    return 1;
}

int inserir_Pilha(Pilha* pi, char c){
    if(pi == NULL || pi->qtd == MAX){
        return 0;
    }
    pi->palavra[pi->qtd] = c;
    pi->qtd++;
    return 1;
}

int inverter_Pilha(Pilha* pi, Pilha* pi2){
    int i;
    if(pi == NULL || pi2 == NULL){
        return 0;
    }
    pi2->qtd = 0;
    for(i = pi->qtd-1; i >= 0; i--){
        pi2->palavra[pi2->qtd] = pi->palavra[i];
        pi2->qtd++;
    }

    return 1;
}
