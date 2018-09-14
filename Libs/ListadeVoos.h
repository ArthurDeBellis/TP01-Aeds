//Aqui eu criei a estrutura de como será cada Celula da lista, com a estrutura do vôo mais o endereço do próximo item.
typedef struct tcelula{
  TVoo voo;
  struct *tcelula prox;
} Celula;

//Aqui criei um ponteiro para o tipo ItemLista.
typedef struct Celula *Ponteiro;

//Aqui criei a lista, que irá conter apenas os endereços da primeira e última célula.
typedef struct {
  Ponteiro primeiro, ultimo;
} Lista;

//Função inicializa, que irá dar a célula cabeça para a lista.
void Inicializa(Lista *list);

//Função inserir
void Inserir(Lista *list);

//Busca o vôo pelo identificador, remove da lista e retorna.
int RemoverVoo(Lista *list, int Id);

//Busca o vôo pelo identificador e não o remove.
Celula *ProcuraVoo (Lista *list, int Id);
