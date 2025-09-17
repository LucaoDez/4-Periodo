#include <stdio.h>
#include "Cubo.h"

int main(){
    Cubo *c = Cubo_Criar(2.0);
    float area, volume;

    area = Cubo_Area(c);
    volume = Cubo_Volume(c);

    printf("A area do cubo inicial é: %f", area);
    printf("O volume do cubo inicial é: %f", volume);

    return 0;
}