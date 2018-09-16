#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "../Libs/voo.h"
#include "../Libs/ListadeVoos.h"
#include "../Libs/ItemMatriz.h"

void iniciar (ItemMatriz *Item){
    Item->Lista.pPrimeiro = NULL;
    Item->Lista.pUltimo = NULL;
    Item->NumeroVoos = 0;
    Item->HrLast = 0;
    Item->MntsLast = 0;
}

//Funções set
//Em SetNumVoo percorrerei a lista com loop while, assim ao final obtenho o tamanho da lista
//linear
void SetNumVoo(ItemMatriz *Item){
    TCelula *Contador = NULL, *Auxiliar = NULL;
    int tamanho = 0;
    Contador = Item->Lista.pPrimeiro;
    while(Contador->pProximo != NULL){
        tamanho++;
        Auxiliar = Contador->pProximo;
        Contador = Auxiliar;
    }
    Item->NumeroVoos = tamanho;
}

//Funções get
TLista GetLista(ItemMatriz Item){
    return Item.Lista;
}
int GetNumVoo(ItemMatriz Item){
    return Item.NumeroVint GetHrLast(ItemMatriz Item);oos;
}
int GetHrLast(ItemMatriz Item){
    return Item.HrLast;
}
int GetMntsLast(ItemMatriz Item){
    return Item.MntsLast;
}
