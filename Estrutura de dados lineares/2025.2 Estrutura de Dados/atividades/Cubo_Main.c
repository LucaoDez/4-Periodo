#include <stdio.h>
#include "Cubo.h"

int main(){
    Cubo *c = Cubo_Criar(2.0);
    float a1, a2;
    float area, volume;

    a1 = Cubo_Acessar(c);

    area = Cubo_Area(c);
    volume = Cubo_Volume(c);

    printf("A aresta do cubo inicial eh: %.2f\n", a1);
    printf("A area do cubo inicial eh: %.2f\n", area);
    printf("O volume do cubo inicial eh: %.2f\n\n", volume);

    Cubo_Atribuir(c, 3);
    a2 = Cubo_Acessar(c);


    area = Cubo_Area(c);
    volume = Cubo_Volume(c);

    printf("A aresta do novo cubo eh: %.2f\n", a2);
    printf("A area do novo cubo eh: %.2f\n", area);
    printf("O volume do novo cubo eh: %.2f", volume);

    Cubo_Destruir(c);

    return 0;
}