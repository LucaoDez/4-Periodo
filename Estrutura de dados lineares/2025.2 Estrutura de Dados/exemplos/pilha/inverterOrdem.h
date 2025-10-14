#define MAX 100

typedef struct pilha Pilha;

Pilha* criar_Pilha();
void destruir_Pilha(Pilha* pi);
int acessar_Topo(Pilha* pi, char* c);
int remover_Topo(Pilha* pi);
int inserir_Pilha(Pilha* pi, char c);
int inverter_Pilha(Pilha* pi, Pilha* pi2);