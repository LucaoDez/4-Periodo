#define MAX 100

typedef struct pilha Pilha;

struct aluno{
    int matricula;
    char nome[30];
    float n1, n2, n2;
};

Pilha* cria_pilha();

void libera_pilha(Pilha *pi);
int acessa_topo_Pilha(Pilha *pi, struct aluno *al);
int insere_Pilha(Pilha *pi, struct aluno al);
int remove_Pilha(Pilha *pi);
int tamanho_Pilha(Pilha *pi);
int Pilha_vazia(Pilha *pi);
int Pilha_cheia(Pilha *pi);