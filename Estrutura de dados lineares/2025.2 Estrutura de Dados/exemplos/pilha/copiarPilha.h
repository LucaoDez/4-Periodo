#define MAX 100
struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};

// Tipo opaco: a definição real está no .c
typedef struct pilha Pilha;
int Pilha_cheia(Pilha* pi);
// Operações expostas ao usuário da biblioteca
Pilha* cria_Pilha();
void libera_Pilha(Pilha* pi);
int acessa_topo_Pilha(Pilha* pi, struct aluno *al);
int insere_Pilha(Pilha* pi, struct aluno al); // push
int remove_Pilha(Pilha* pi); // pop
int tamanho_Pilha(Pilha* pi);
int Pilha_vazia(Pilha* pi);
int Pilha_cheia(Pilha* pi);
int copiar_Pilha(Pilha* pi, Pilha*pi2);