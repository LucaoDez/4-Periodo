//Dada uma fila de números, reorganize para que os pares fiquem na frente e os ímpares atrás, preservando ordem relativa.
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct fila {
    int inicio, fim, qtd;
    int dados[MAX]; 
}Fila;

Fila* criar_fila(){
    Fila* fi = (Fila*) malloc(sizeof(struct fila));
    if(fi != NULL){
        fi->inicio = 0;
        fi->fim = 0;
        fi->qtd = 0;
    }
    return fi;
}

void destruir_fila(Fila* fi){
    free(fi);
}

int fila_vazia(Fila* fi){
    if(fi == NULL){
        return -1;
    }
    return (fi->qtd == 0);
}

int fila_cheia(Fila* fi){
    if(fi == NULL){
        return -1;
    }
    return (fi->qtd == MAX);
}

int inserir_fila(Fila* fi, int valor){
    if(fi == NULL || fila_cheia(fi)){
        return 0;
    }
    fi->dados[fi->fim] = valor;
    fi->fim = (fi->fim + 1) % MAX;
    fi->qtd++;
    return 1;
}

int remover_fila(Fila* fi, int* valor){
    if(fi == NULL || fila_vazia(fi)){
        return 0;
    }
    *valor = fi->dados[fi->inicio];
    fi->inicio = (fi->inicio + 1) % MAX;
    fi->qtd--;
    return 1;
}

void parFrenteImparAtras(Fila* fi){
    Fila* pares = criar_fila();
    Fila* impares = criar_fila();
    int num;
    
    while(!fila_vazia(fi)){
        remover_fila(fi, &num);
        if(num % 2 == 0){
            inserir_fila(pares, num);
        }else{
            inserir_fila(impares, num);
        }
    }

    printf("Fila reorganizada (pares na frente, impares atras): ");

    while(!fila_vazia(pares)){
        remover_fila(pares, &num);
        printf("%d ", num);
    }
    while(!fila_vazia(impares)){
        remover_fila(impares, &num);
        printf("%d ", num);
    }

    printf("\n");

    destruir_fila(pares);
    destruir_fila(impares);
}

int main(){
    Fila* fi = criar_fila();
    int n, numero, i;

    printf("Digite quantos numeros serao inseridos: ");
    scanf("%d", &n);
    while(n > MAX){
        printf("Numero invlido. Numero deve ser menor ou igual a 100, digite novemente: ");
        scanf("%d", &n);
    }
    for(i = 0; i < n; i++){
        printf("Insira o %d numero: ",i+1);
        scanf("%d", &numero);
        inserir_fila(fi, numero);
    }

    parFrenteImparAtras(fi);
    destruir_fila(fi);
    
    return 0;
}