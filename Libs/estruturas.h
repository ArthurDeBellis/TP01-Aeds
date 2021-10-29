#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

typedef struct{
  int vid;
  int horaDecolagem;
  int minutosDecolagem;
  int horaPouso;
  int minutosPouso;
  char aeroportoDecolagem[5];
  char aeroportoPouso[5];
  int identificadorPista;
}TVoo; //As horas e minutos foram separadas as para facilitar a execução do programa

//Aqui eu criei a estrutura de como será cada Celula da lista, com a estrutura do vôo mais o endereço do próximo item.
typedef struct Celula{
  TVoo Voo;
  struct Celula* pProximo;
}TCelula;

//Aqui criei a lista, que irá conter apenas os ponteiros da primeira e última célula.
typedef struct {
  TCelula* pPrimeiro;
  TCelula* pUltimo;
}TLista;

typedef struct {
  TLista Lista; //Lista do tipo TLista, definido no TAD Lista_de_Voos
  int NumeroVoos; //Numero total de voos na lista
  int HrLast; //Hora da ultima atualização
  int MntsLast; //Minutos da ultima atualização
}ItemMatriz;


typedef struct
{
  ItemMatriz Matriz[24][24];
  int TotalDeVoos;
  int dia, mes, ano;
  int HoradaUltimaAtualizacao, MinutosUltimaAtualizacao;
}TipoMatriz;

#endif
