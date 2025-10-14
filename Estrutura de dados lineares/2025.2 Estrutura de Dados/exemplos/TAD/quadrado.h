typedef struct quadrado Quadrado;

Quadrado* criar_Quadrado(float a);
void Quadrado_Destruir(Quadrado* q);
int acessar_Quadrado(Quadrado* q, float* l);
int atribuir_Quadrado(Quadrado* q, float l);
int perimetro_Quadrado(Quadrado* q, float* p);
int area_Quadrado(Quadrado* q, float* area);
int diagonal_Quadrado(Quadrado* q, float* d);
