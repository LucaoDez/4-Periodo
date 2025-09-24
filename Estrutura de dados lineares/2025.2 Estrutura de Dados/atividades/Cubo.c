#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Cubo.h"

struct cubo{
    float aresta;
};

Cubo* Cubo_Criar(float a){
    Cubo* c = (Cubo*) malloc(sizeof(Cubo));
    if(c != NULL) c->aresta = a;

    return c;
}

void Cubo_Destruir(Cubo* c){
    free(c);
}

float Cubo_Acessar(Cubo* c){
    return c->aresta;
}

void Cubo_Atribuir(Cubo* c, float a){
    c->aresta = a;
}

float Cubo_Area(Cubo* c){
    float area = 6 * pow(c->aresta, 2);

    return area;
}

float Cubo_Volume(Cubo* c){
    float volume = pow(c->aresta, 3);

    return volume;
}
