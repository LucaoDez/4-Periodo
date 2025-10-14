#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct fila{
    int inicio, final, qtd;
    int dados[MAX];
}Fila;

Fila* criar_Fila(){
    Fila* fi = (Fila*) malloc(sizeof(struct fila));
    if(fi != NULL){
        fi->final = 0;
        fi->inicio = 0;
        fi->qtd = 0;
    }
    return fi;
}

void destruir_fila(Fila* fi){
    free(fi);
}

int inserir_Fila(Fila* fi, int dado){
    if(fi == NULL || fi->qtd == MAX){
        return 0;
    }
    fi->dados[fi->final] = dado;
    fi->final = (fi->final+1) % MAX;
    fi->qtd++;
    return 1;
}

int remover_Fila(Fila* fi, int* dado){
    if(fi == NULL || fi->qtd == 0){
        return 0;
    }
    *dado = fi->dados[fi->inicio];
    fi->inicio = (fi->inicio+1) % MAX;
    fi->qtd--;
    return 1;
}

int inicio_Fila(Fila* fi, int*dado){
    if(fi ==NULL || fi->qtd == 0){
        return 0;
    }
    *dado = fi->dados[fi->inicio];
    return 1;
}

int Fila_cheia(Fila* fi){
    if(fi == NULL){
        return -1;
    }
    return (fi->qtd == MAX);
}

int Fila_vazia(Fila* fi){
    if(fi == NULL){
        return -1;
    }
    return (fi->qtd == 0);
}