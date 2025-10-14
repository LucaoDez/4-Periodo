#include <stdio.h>
#include <stdlib.h>

struct elemento{
    int dado;
    struct elemento *prox;
    struct elemento *ant;
};

typedef struct elemento Elem;

struct descritor{
    Elem *inicio;
    Elem *final;
    int qtd;
};

typedef struct descritor Lista;

Lista* cria_lista(){
    Lista *li = malloc(sizeof(Lista));
    if(li != NULL){
        li->inicio = NULL;
        li->final = NULL;
        li->qtd = 0;
    }
    return li;
}

int insere_inicio(Lista *li, int valor){
    if(li == NULL){
        return 0;
    }
    Elem *no = malloc(sizeof(Elem));
    if(no == NULL){
        return 0;
    }
    no->dado = valor;
    no->ant = NULL;
    no->prox = li->inicio;
    if(li->inicio != NULL){
        li->inicio->ant = no;
    }else{
        li->final = no;
    }
    li->inicio = no;
    li->qtd++;
    return 1;
}

int tamanho_lista(Lista *li){
    if(li == NULL){
        return -1;
    }
    return li->qtd;
}

int remove_inicio(Lista *li){
    if(li == NULL || li->inicio == NULL){
        return 0;
    }
    Elem *no = li->inicio;
    li->inicio = no->prox;
    if(li->inicio != NULL){
        li->inicio->ant = NULL;
    }else{
        li->final = NULL;
    }
    free(no);
    li->qtd--;
    return 1;
}

int lista_vazia(Lista *li){
    if(li == NULL){
        return -1;
    }
    return (li->qtd == 0);
}

int busca_lista(Lista *li, int valor){
    if(li == NULL){
        return -1;
    }
    Elem *no = li->inicio;
    while(no != NULL){
        if(no->dado == valor){
            return 1;
        }
        no = no->prox;
    }
    return 0;
}

int main(){
    int buscar;
    Lista *li = cria_lista();
    insere_inicio(li, 1);
    insere_inicio(li, 2);
    insere_inicio(li, 3);

    printf("Tamanho da lista: %d\n", tamanho_lista(li));
    printf("Digite um valor para buscar na lista: ");
    scanf("%d", &buscar);
    if(busca_lista(li, buscar)){
        printf("Valor %d encontrado na lista!\n", buscar);
    }else{
        printf("Valor %d nao encontrado na lista!\n", buscar);
    }

    return 0;
}