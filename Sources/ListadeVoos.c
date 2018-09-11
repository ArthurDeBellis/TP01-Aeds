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
//Aqui alocamos um novo espaço para a célula a ser inserida e também buscamos o lugar que ela ocupará na lista.
void inserir(Lista *list){

  Ponteiro *celulalista = (list->primeiro);
  Ponteiro novacelula = (Ponteiro) malloc(sizeof(Celula));
}

void SetVid(TVoo *aux, int NovoVid){
  int horario = (voo->minutosDecolagem + (voo->horaDecolagem * 60));
  while(horario < (celulalista->voo->minutosDecolagem+(celulalista->voo->horaDecolagem*60))){
    if (celulalista->prox == NULL){
      break
    }
    else{
      celulalista = celulalista->prox;
    }
  }
}
