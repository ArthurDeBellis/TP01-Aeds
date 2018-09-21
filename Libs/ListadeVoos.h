#include "../Libs/voo.h"
#ifndef LISTADEVOOS_H
#define LISTADEVOOS_H

//Aqui eu criei a estrutura de como será cada Celula da lista, com a estrutura do vôo mais o endereço do próximo item.
typedef struct Celula{
  TVoo Voo;
  struct Celula* pProximo;
}TCelula;

//Aqui criei a lista, que irá conter apenas os endereços da primeira e última célula.
typedef struct {
  TCelula* pPrimeiro;
  TCelula* pUltimo;
}TLista;

//Função inicializa, que irá dar a célula cabeça para a lista.
void IniciaLista(TLista *pLista);

//Função para ver se a lista é vazia
int Vazia(TLista Lista);

//Função inserir
void Inserir(TLista *pLista, TVoo *Voo);

//Função Inserir(em Andamento)
void InserirNovo(TLista *Lista, TVoo Voo);

//Função para inserir na ultima posição da lista
void InserirUltimo(TLista *Lista, TVoo Voo);

//Busca o vôo pelo identificador, remove da lista e retorna.
int RemoverVoo(TLista *pLista, int Id);

//Busca o vôo pelo identificador e não o remove.
TCelula *ProcurarVoo (TLista *pLista, int Id);

//Função para imprimir a lista de voos
void ImprimirLVoos(TLista Lista);

#endif
