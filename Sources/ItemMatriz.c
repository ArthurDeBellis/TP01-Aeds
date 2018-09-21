#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "../Libs/voo.h"
#include "../Libs/ListadeVoos.h"
#include "../Libs/ItemMatriz.h"

void IniciaItem (ItemMatriz *Item){
    Item->Lista.pPrimeiro = NULL;
    Item->Lista.pUltimo = NULL;
    Item->NumeroVoos = 0;
    Item->HrLast = 0;
    Item->MntsLast = 0;
    SetLista(Item);
}

void ImprimirItem(ItemMatriz Item){
  printf("Numero de Voos: %d\n", Item.NumeroVoos);
  printf("Horario da Ultima Atualização: %d:%d\n", Item.HrLast, Item.MntsLast);
}

//Funções set
//Em SetNumVoo percorrerei a lista com loop while, assim ao final obtenho o tamanho da lista
//linear
void SetLista(ItemMatriz *Item){
    IniciaLista(&Item->Lista);
}
void SetNumVoo(ItemMatriz *Item){
    TCelula *Contador = NULL;
    int tamanho = 0;
    Contador = Item->Lista.pPrimeiro;
    while(Contador->pProximo != NULL){
        tamanho++;
        Contador = Contador->pProximo;
    }
    Item->NumeroVoos = tamanho;
}
//nessa função eu uso a estrutura tm para pegar a hora e minutos da última alteração na lista
void SetHreMntsLast(ItemMatriz *Item){
    struct tm *horarioatual;
    time_t momentoatual;
    momentoatual= time(NULL);
    horarioatual=localtime(&momentoatual);

    Item->HrLast = horarioatual->tm_hour;
    Item->MntsLast = horarioatual->tm_min;

}

//Funções get
TLista GetLista(ItemMatriz Item){
    return Item.Lista;
}
int GetNumVoo(ItemMatriz Item){
    return Item.NumeroVoos;
}
int GetHrLast(ItemMatriz Item){
    return Item.HrLast;
}
int GetMntsLast(ItemMatriz Item){
    return Item.MntsLast;
}
