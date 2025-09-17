typedef struct cubo Cubo;

Cubo* Cubo_Criar(float a);
void Cubo_Destruir(Cubo* c);
float Cubo_Acessar(Cubo* c);
void Cubo_Atribuir(Cubo* c, float a);
float Cubo_Area(Cubo* c);
float Cubo_Volume(Cubo* c);