#include <stdio.h>
#include <stdlib.h>
#include "../Libs/ListadeVoos.h"
#include "../Libs/voo.h"

//Função inicializa dando à lista uma célula cabeça
void Inicializa(Lista *list){
  list->primeiro = (Ponteiro) malloc(sizeof(Celula));
  list->ultimo = list->primeiro;
  list->ultimo->prox = NULL;
}
//Aqui alocamos um novo espaço para a célula a ser inserida e também buscamos o lugar que
//ela ocupará na lista.
void Inserir(Lista *list){
  Ponteiro *novacelula = NULL, *auxiliar = NULL, *ultimomenor=NULL;
  Ponteiro *celulalista = (list->primeiro);
  int horario;
  novacelula = (Ponteiro) malloc(sizeof(Celula));
  if(!novacelula){
    printf("Erro ao alocar memória");
  }
  horario = (novacelula->voo->minutosDecolagem + (novacelula->voo->horaDecolagem * 60));
  //No loop while eu percorro pela lista parando apenas quando encontro horario igual ou
  //"mais tardio" que o horaio do voo que vai ser inserido, por isso com o ponteiro ultimomenor
  //eu aponto para a célula anterior à que está sendo analisada.

  while(horario < (celulalista->voo->minutosDecolagem+(celulalista->voo->horaDecolagem*60))){
    if (celulalista->prox == NULL){
      break;
    }
    else{
      ultimomenor = &celulalista;
      auxiliar = celulalista->prox;
      celulalista = auxiliar;
    }
  }
  novacelula->prox = ultimomenor->prox;
  ultimomenor->prox = novacelula;
  if(&ultimomenor==list->ultimo){
    list->ultimo = ultimomenor->prox;
  }
}
//Aqui busco o voo pelo identificador e a função retorna o ponteiro da célula que contém tal voo.
Celula *ProcuraVoo(Lista *list, int Id){
    Ponteiro *temp=NULL, *celulaatual=NULL;
    celulaatual=list->primeiro->prox;
    while(celulaatual->voo->vid != Id){
      if (celulalista->prox == NULL){
        printf("Voo não encontrado.\n");
        break;
      }
      else{
        temp = celulaatual->prox;
        celulaatual = temp;
      }
    }
  return celulaatual;
}
//Aqui fazemos o uso da função ProcuraVoo para encontrar o voo a ser removido e também buscamos o
//seu antecessor(que contém seu endereço), para pegar o endereço guardado na célula a ser
//removida no seu antecessor e depois liberar a memória ocupada pela célula removida.
int RemoverVoo(Lista *list, int Id){
  Ponteiro *CelulaaRemover= NULL, *antecessor = NULL, *auxiliar = NULL;
  CelulaaRemover = *ProcuraVoo(*list, Id);
  antecessor = list->primeiro->prox;
  while(antecessor->prox != CelulaaRemover){
    auxiliar = antecessor->prox;
    antecessor = auxiliar;
  }

  if(CelulaaRemover == list->ultimo){
    list->ultimo = antecessor->prox;
  }

  antecessor->prox=CelulaaRemover->prox;
  free(CelulaaRemover);
  return 0;
}
