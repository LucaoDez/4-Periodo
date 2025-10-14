#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "quadrado.h"

struct quadrado{
    float aresta;
};

Quadrado* criar_Quadrado(float a){
    Quadrado* q;
    q = (Quadrado*) malloc(sizeof(struct quadrado));
    if(q != NULL){
        q->aresta = a;
    }
    return q;
}

void Quadrado_Destruir(Quadrado* q){
    free(q);
}

int acessar_Quadrado(Quadrado* q, float* l){
    if(q == NULL){
        return 0;
    }
    *l = q->aresta;
    return 1;
}

int atribuir_Quadrado(Quadrado* q, float l){
    if(q == NULL){
        return 0;
    }
    q->aresta = l;
    return 1;
}

int perimetro_Quadrado(Quadrado* q, float* p){
    if(q == NULL){
        return 0;
    }
    *p = 4 * q->aresta;
    return 1;
}

int area_Quadrado(Quadrado* q, float* area){
    if(q == NULL){
        return 0;
    }
    *area = q->aresta * q->aresta;
    return 1;
}

int diagonal_Quadrado(Quadrado* q, float* d){
    if(q == NULL){
        return 0;
    }
    *d = q->aresta*sqrt(2);
    return 1;
}
