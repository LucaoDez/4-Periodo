#include <stdio.h>

int main(){
    float peso, altura, imc;
    float *a = &peso, *b = &altura;

    printf("Digite o seu peso: ");
    scanf("%f", a);

    printf("Digite a sua altura: ");
    scanf("%f", b);

    imc = (peso / (altura * altura));
    printf("Seu IMC eh: %.2f", imc);

    return 0;
}