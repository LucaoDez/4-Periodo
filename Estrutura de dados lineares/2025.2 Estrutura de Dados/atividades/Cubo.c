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
    float area = 6 * (pow(2, c->aresta));

    return area;
}

float Cubo_Volume(Cubo* c){
    float volume = pow(3, c->aresta);

    return volume;
}
