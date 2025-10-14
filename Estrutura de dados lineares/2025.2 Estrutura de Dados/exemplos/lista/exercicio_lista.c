#include <stdio.h>
#include <stdlib.h>

struct elemento{
    int dado;
    struct elemento *prox;
};

typedef struct elemento Elem;
typedef Elem* Lista; 

Lista* cria_lista(){
    Lista* li = malloc(sizeof(Lista));
    if(li != NULL){
        *li = NULL; 
    }
    return li;
}

int insere_inicio(Lista* li, int dado){
    if(li == NULL){
        return 0;
    }
    Elem *no = malloc(sizeof(Elem));

    no->dado = dado;
    no->prox = *li;
    *li = no;

    return 1;
}

int tamanho_lista(Lista* li){
    if(li == NULL){
        return -1;
    }
    int cont = 0;
    Elem *no = *li;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int main(){
    Lista* lista = cria_lista();
    int tamanho;

    insere_inicio(lista, 1);
    insere_inicio(lista, 2);
    insere_inicio(lista, 3);

    tamanho = tamanho_lista(lista);

    printf("O tamanho da lista eh: %d", tamanho);

    return 0;
}