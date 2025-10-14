#include <stdio.h>
#include <stdlib.h>

typedef struct elemento{
    int dado;
    struct elemento *prox;
}Elem;

typedef struct descritor{
    Elem *topo;
    int qtd;
}Pilha;

Pilha *cria_pilha(){
    Pilha *pi = malloc(sizeof(Pilha));
    if(pi != NULL){
        pi->topo = NULL;
        pi->qtd = 0;
    }
    return pi;
}

int insere_pilha(Pilha *pi, int x){
    if(pi == NULL)
        return 0;
    Elem *no = malloc(sizeof(Elem));
    if(no == NULL) return 0;

    no->dado = x;
    no->prox = pi->topo;
    pi->topo = no;
    pi->qtd++;
    return 1;
}

int remove_pilha(Pilha *pi){
    if(pi == NULL || pi->topo == NULL)
        return 0;
    Elem *no = pi->topo;
    pi->topo = no->prox;
    free(no);
    pi->qtd--;
    return 1;
}

int acessa_topo_pilha(Pilha *pi, int *x){
    if(pi == NULL || pi->topo == NULL){
        return 0;
    }
    *x = pi->topo->dado;
    return 1;
}

int pilha_vazia(Pilha *pi){
    if(pi == NULL) return -1;
    return (pi->qtd == 0);
}

int tamanho_pilha(Pilha *pi){
    if(pi == NULL) return -1;
    return pi->qtd;
}

void libera_pilha(Pilha *pi){
    if(pi != NULL){
        Elem *no;
        while(pi->topo != NULL){
            no = pi->topo;
            pi->topo = pi->topo->prox;
            free(no);
        }
        free(pi);
    }
}

int main(){
    Pilha *pi = cria_pilha();
    int tamanho, topo, vazia;

    insere_pilha(pi, 10);
    printf("Numero 10 inserido no topo da pilha.\n");
    insere_pilha(pi, 20);
    printf("Numero 20 inserido no topo da pilha.\n");
    insere_pilha(pi, 30);
    printf("Numero 30 inserido no topo da pilha.\n");

    tamanho = tamanho_pilha(pi);
    printf("Tamanho da pilha: %d\n", tamanho);
    vazia = pilha_vazia(pi);
    if(vazia == 1)
        printf("A pilha esta vazia.\n");
    else
        printf("A pilha nao esta vazia.\n");
    acessa_topo_pilha(pi, &topo);
    printf("Elemento no topo da pilha: %d\n", topo);

    remove_pilha(pi);
    printf("Elemento no topo removido.\n");
    acessa_topo_pilha(pi, &topo);
    printf("Novo elemento no topo da pilha: %d\n", topo);

    libera_pilha(pi);

    return 0;
}