#include <stdio.h>
#include "quadrado.h"

int main(){
    Quadrado* q = criar_Quadrado(5.0);
    float a, p, area, d;
    acessar_Quadrado(q, &a);
    perimetro_Quadrado(q, &p);
    area_Quadrado(q, &area);
    diagonal_Quadrado(q, &d);

    if(q != NULL){
        printf("Quadrado criado.\n");
    }
    else{
        printf("Erro ao cirar o quadrado.\n");
        return 0;
    }
    printf("Tamanho da aresta: %.2f\n", a);
    printf("Tamanho do perimetro: %.2f\n", p);
    printf("Tamanho da area: %.2f\n", area);
    printf("Tamanho da diagonal: %.2f\n", d);

    Quadrado_Destruir(q);
    return 0;
}