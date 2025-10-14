#include <stdio.h>
#include <stdlib.h>
#include "copiarPilha.h"

typedef struct pilha{
    int qtd;
    struct aluno dados[MAX];
};

Pilha* cria_Pilha(){
    Pilha *pi;
    pi = (Pilha*) malloc(sizeof(struct pilha));
    if(pi != NULL){
        pi->qtd = 0;
    }
    return pi;
}

void libera_Pilha(Pilha* pi){
    free(pi);
}

int Pilha_vazia(Pilha* pi){
    if(pi == NULL){
        return -1;
    }
    return (pi->qtd == 0);
}

int Pilha_cheia(Pilha* pi){
    if(pi == NULL){
        return -1;
    }
    return (pi->qtd == MAX);
}

int tamanho_Pilha(Pilha* pi){
    if(pi == NULL){
        return 0;
    }
    return pi->qtd;
}

int acessa_topo_Pilha(Pilha* pi, struct aluno *al){
    if(pi == NULL ||  pi->qtd == 0){
        return 0;
    }
    *al = pi->dados[pi->qtd-1];
    return 1;
}

int insere_Pilha(Pilha* pi, struct aluno al){
    if(pi == NULL || pi->qtd == MAX){
        return 0;
    }

    pi->dados[pi->qtd] = al;
    pi->qtd++;

    return 1;
} // push

int remove_Pilha(Pilha* pi){
    if(pi == NULL || pi->qtd == 0){
        return 0;
    }
    pi->qtd--;
    return 1;
} // pop

int copiar_Pilha(Pilha* pi, Pilha* pi2){
    int i;
    if(pi == NULL || pi2 == NULL){
        return 0;
    }
    pi2->qtd = 0;
    for(i = 0; i < pi->qtd; i++){
        pi2->dados[i] = pi->dados[i];
        pi2->qtd++;
    }
    return 1;
}