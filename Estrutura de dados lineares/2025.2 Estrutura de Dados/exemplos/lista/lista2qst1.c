#include <stdio.h>
#include <stdlib.h>

typedef struct elemento{
    int dado;
    struct elemento* prox;
}Elem;

typedef Elem* Lista;

Lista* criar_lista(){
    Lista* li = malloc(sizeof(Lista));
    if(li != NULL){
        *li = NULL;
    }
    return li;
}

void libera_lista(Lista *li){
    if(li != NULL){
        Elem *no;
        while(*li != NULL){
            no = *li;
            *li = no->prox;
            free(no);
        }
        free(li);
    }
}

int lista_vazia(Lista *li){
    if(li == NULL){
        return 1;
    }
    return 0;
}

int tamanho_lista(Lista *li){
    if(li == NULL)
        return -1;
    Elem *no = *li;
    int cont = 0;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int insere_inicio(Lista *li, int dado){
    if(li == NULL){
        return 0;
    }
    Elem *no = malloc(sizeof(Elem));
    no->dado = dado;
    no->prox = *li;
    *li = no;

    return 1;
}

int insere_final(Lista *li, int dado){
    if(li == NULL){
        return 0;
    }
    Elem *no = malloc(sizeof(Elem));
    if(no == NULL){
        return 0;
    }
    no->dado = dado;
    no->prox = NULL;
    if(*li == NULL){
        *li = no;
    }
    else{
        Elem *aux = *li;
        while(aux->prox != NULL){
            aux = aux->prox;
        } 
        aux->prox = no;
    }
    return 1;
}

int remove_inicio(Lista *li){
    if(li == NULL)
        return 0;
    Elem *no = *li;
    *li = no->prox;
    free(no);
    return 1;
}

int remove_final(Lista *li){
    if(li == NULL || *li == NULL)
        return 0;
    Elem *atual = *li;
    Elem *ant = NULL;
    while(atual->prox != NULL){
        ant = atual;
        atual = atual->prox;
    }
    if(ant == NULL){ // só um elemento
        *li = NULL;
    }else{
        ant->prox = NULL;
    }
    free(atual);
    return 1;
}

void imprime_lista(Lista* li){
    if(li == NULL) return;
    Elem *aux = *li;
    while(aux->prox != NULL){
        printf("%d ", aux->dado);
        aux = aux->prox;
    }
    printf("\n");
}