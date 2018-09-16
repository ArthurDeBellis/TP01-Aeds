#include "../Libs/voo.h"
#include "../Libs/ListadeVoos.h"
#ifndef ITEMMATRIZ_H
#define ITEMMATRIZ_H

//Definido a struct
typedef struct {
  //Lista do tipo TLista, definido no TAD Lista_de_Voos
  TLista Lista;
  //Numero total de voos na lista
  int NumeroVoos;
  //Hora da ultima atualização
  int HrLast;
  //Minutos da ultima atualização
  int MntsLast;
}ItemMatriz;

void iniciar (ItemMatriz *Item);

/*Funções SET*/

void SetLista(ItemMatriz *Item);
void SetNumVoo(ItemMatriz *Item);
void SetHreMntsLast(ItemMatriz *Item);

/*Funções GET*/

TLista GetLista(ItemMatriz Item);
int GetNumVoo(ItemMatriz Item);
int GetHrLast(ItemMatriz Item);
int GetMntsLast(ItemMatriz Item);

#endif
