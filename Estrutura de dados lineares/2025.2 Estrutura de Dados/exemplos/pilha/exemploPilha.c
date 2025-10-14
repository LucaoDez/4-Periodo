/*
    Implementação da pilha sequencial estática

    Estrutura interna (oculta):
    - struct pilha contém:
        * int qtd  → quantidade de elementos atualmente no array;
        * struct aluno dados[MAX] → armazenamento contíguo dos elementos.
    - Esses campos NÃO são visíveis no main(); o usuário só manipula a pilha
      por meio das funções declaradas no .h (tipo opaco).

    Observações do livro:
    - Em pilha sequencial estática, o sucessor de um elemento ocupa a posição
      física seguinte no array.
    - O campo 'qtd' indica quanto do array já está ocupado.
    - Ideal para pilhas pequenas ou quando o tamanho máximo é bem definido.
*/
#include <stdio.h>
#include <stdlib.h>
#include "exemploPilha.h"

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

