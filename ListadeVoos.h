//Aqui eu criei a estrutura de como será cada Celula da lista, com a estrutura do vôo mais o endereço do próximo item.
typedef struct {
  TVoo voo;
  Ponteiro prox;
} Celula;

//Aqui criei um ponteiro para o tipo ItemLista.
typedef struct Celula *Ponteiro;

//Aqui criei a lista, que irá conter apenas os endereços da primeira e última célula.
typedef struct {
  Ponteiro primeiro, ultimo;
} Lista;

//Função inicializa, que irá dar a célula cabeça para a lista.
void Inicializa(Lista *list);

//função inserir
void Inserir(Lista *list,TVoo voo);

//Busca o vôo pelo identificador e o retorna.
int ProcuraVoo(Lista *list, int Id);
