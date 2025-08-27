#include <stdio.h> 

int main(){
    float altura, peso, imc;

    printf("Digite a sua altura:");
    scanf("%f", &altura);

    printf("Digite o seu peso:");
    scanf("%f", &peso);

    imc = (peso / (altura * altura));

    printf("Seu IMC eh: %.2f", imc);

    return 0;
}