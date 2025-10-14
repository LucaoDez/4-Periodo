#include <stdio.h>
#include "copiarPilha.h"

int main(){
    Pilha* pi = cria_Pilha();
    if(pi == NULL){
        printf("Erro ao criar pilha.\n");
        return 1;
    }
    printf("Pilha 1 criada com sucesso.\n");
    printf("Tamanho inicial da pilha 1: %d\n", tamanho_Pilha(pi));
    printf("Esta vazia?\n");
    if(Pilha_vazia(pi)){
        printf("Sim\n");
    }else{
        printf("Nao\n");
    }

    Pilha* pi2 = cria_Pilha();
    if(pi2 == NULL){
        printf("Erro ao criar pilha.\n");
        return 1;
    }
    printf("Pilha 2 criada com sucesso.\n");
    printf("Tamanho inicial da pilha 2: %d\n", tamanho_Pilha(pi2));
    printf("Esta vazia?\n");
    if(Pilha_vazia(pi2)){
        printf("Sim\n");
    }else{
        printf("Nao\n");
    }

    struct aluno a1 = {101, "Ana",   8.0f, 7.5f, 9.0f};
    struct aluno a2 = {202, "Bruno", 6.0f, 8.0f, 7.0f};
    struct aluno a3 = {303, "Clara", 9.0f, 9.5f, 8.5f};

    struct aluno topo;

    printf("\nInserindo Aluno...\n");
    insere_Pilha(pi, a1);
    printf("Tamanho: %d\n", tamanho_Pilha(pi));
    if (acessa_topo_Pilha(pi, &topo)){
        printf("Topo: %d - %s\n", topo.matricula, topo.nome);
    }
        

    printf("\nInserindo Aluno...\n");
    insere_Pilha(pi, a2);
    printf("Tamanho: %d\n", tamanho_Pilha(pi));
    if (acessa_topo_Pilha(pi, &topo)){
        printf("Topo: %d - %s\n", topo.matricula, topo.nome);
    }
        
    printf("\nInserindo Aluno...\n");
    insere_Pilha(pi, a3);
    printf("Tamanho: %d\n", tamanho_Pilha(pi));
    if (acessa_topo_Pilha(pi, &topo)){
        printf("Topo: %d - %s\n", topo.matricula, topo.nome);
    }
        

    printf("\nEsta vazia? ");
    if (Pilha_vazia(pi)){
        printf("Sim\n"); 
    }        
    else{
        printf("Nao | Tamanho: %d\n\n", tamanho_Pilha(pi));
    }
        
    printf("Copiando para pilha 2...\n");
    copiar_Pilha(pi, pi2);

    acessa_topo_Pilha(pi, &topo);

    printf("Topo da pilha 2: %d - %s\n\n", topo.matricula, topo.nome);

    printf("Removendo topo da linha dois...\n");
    remove_Pilha(pi2);
    acessa_topo_Pilha(pi2, &topo);
    printf("Topo da pilha 2: %d - %s\n\n", topo.matricula, topo.nome);


    libera_Pilha(pi);
    libera_Pilha(pi2);
    return 0;
}