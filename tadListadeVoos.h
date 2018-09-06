typedef struct Celula *Ponteiro;
typedef struct {
  Voo voo;
  Ponteiro prox;
} Celula;

typedef struct {
  Ponteiro primeiro, ultimo;

} Lista;
void Inicializa(Lista* lista);
void Inserir(Lista* lista,Voo voo);
Voo Remover(Lista* lista, Voo voo);
