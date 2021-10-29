
#ifndef LISTADEVOOS_H
#define LISTADEVOOS_H

#include "voo.h"

/*--------------------------------------------------------------------------------------*/
                                       //Funções
/*--------------------------------------------------------------------------------------*/

void IniciaLista(TLista *pLista); //Função inicializa, que irá dar a célula cabeça para a lista.

int ListaVazia(TLista Lista); //Função para ver se a lista é vazia

void InserirNovo(TLista *Lista, TVoo Voo); //Função para inserir a celula na posição correta

void InserirUltimo(TLista *Lista, TVoo Voo); //Função para inserir na ultima posição da lista

int RemoverVoo(TLista *pLista, int Id); //Função para buscar o vôo pelo identificador, remover da lista e o retornar.

TCelula *ProcurarVoo (TLista *pLista, int Id); //Busca o vôo pelo identificador e não o remove.

void ImprimirLVoos(TLista Lista); //Função para imprimir a lista de voos

#endif
