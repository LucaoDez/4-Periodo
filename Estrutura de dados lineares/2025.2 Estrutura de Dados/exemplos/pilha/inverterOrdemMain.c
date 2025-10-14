#include <stdio.h>
#include <string.h>
#include "inverterOrdem.h"

int main(){
    char palavra[MAX];
    Pilha* pi = criar_Pilha();

    printf("Digite sua palavra: ");
    scanf("%s", palavra);

    for(int i = 0; i < strlen(palavra); i++){
        inserir_Pilha(pi, palavra[i]);
    }

    printf("Palavra invertida: ");

    char letra;
    while(acessar_Topo(pi, &letra)){
    printf("%c", letra);
    remover_Topo(pi);
    }

    destruir_Pilha(pi);

    return 0;
}
