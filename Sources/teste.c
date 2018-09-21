#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "../Libs/ItemMatriz.h"
#include "../Libs/ListadeVoos.h"
#include "../Libs/MatrizVoos.h"
#include "../Libs/voo.h"

int main() {
  srand(time(NULL));

  TVoo voo;

  IniciaVoo(&voo);
  SetVid(&voo);
  SetHrDecolagem(&voo, 15);
  SetMinutosDecolagem(&voo, 35);
  SetHrPouso(&voo, 18);
  SetMinutosPouso(&voo, 30);
  SetAeroportoDecolagem(&voo, "AAA");
  SetAeroportoPouso(&voo, "JIU");
  SetIdPista(&voo, 15);

  TVoo voo2;

  IniciaVoo(&voo2);
  SetVid(&voo2);
  SetHrDecolagem(&voo2, 14);
  SetMinutosDecolagem(&voo2, 40);
  SetHrPouso(&voo2, 18);
  SetMinutosPouso(&voo2, 30);
  SetAeroportoDecolagem(&voo2, "BBB");
  SetAeroportoPouso(&voo2, "dsa");
  SetIdPista(&voo2, 17);

  TVoo voo3;

  IniciaVoo(&voo3);
  SetVid(&voo3);
  SetHrDecolagem(&voo3, 14);
  SetMinutosDecolagem(&voo3, 15);
  SetHrPouso(&voo3, 18);
  SetMinutosPouso(&voo3, 30);
  SetAeroportoDecolagem(&voo3, "CCC");
  SetAeroportoPouso(&voo3, "dsa");
  SetIdPista(&voo3, 17);

  TVoo voo4;

  IniciaVoo(&voo4);
  SetVid(&voo4);
  SetHrDecolagem(&voo4, 14);
  SetMinutosDecolagem(&voo4, 00);
  SetHrPouso(&voo4, 18);
  SetMinutosPouso(&voo4, 30);
  SetAeroportoDecolagem(&voo4, "DDD");
  SetAeroportoPouso(&voo4, "dsa");
  SetIdPista(&voo4, 17);

  TVoo voo5;

  IniciaVoo(&voo5);
  SetVid(&voo5);
  SetHrDecolagem(&voo5, 14);
  SetMinutosDecolagem(&voo5, 39);
  SetHrPouso(&voo5, 18);
  SetMinutosPouso(&voo5, 30);
  SetAeroportoDecolagem(&voo5, "EEE");
  SetAeroportoPouso(&voo5, "dsa");
  SetIdPista(&voo5, 17);

  //ImprimirTVoo(voo);

  TLista lista1;
  IniciaLista(&lista1);

  InserirNovo(&lista1, voo);
  InserirNovo(&lista1, voo2);
  InserirNovo(&lista1, voo3);
  InserirNovo(&lista1, voo4);
  InserirNovo(&lista1, voo5);

  //TCelula *busca = ProcurarVoo(&lista1, 123);
  ImprimirLVoos(lista1);

  printf("\n\n============================================\n\n" );

  //ImprimirTVoo(busca->Voo);
  //RemoverVoo(&lista1, GetVid(voo4));

  ImprimirLVoos(lista1);

  ItemMatriz Matriz1;
  IniciaItem(&Matriz1);
  SetLista(&Matriz1);
  SetNumVoo(&Matriz1);
  SetHreMntsLast(&Matriz1);
  ImprimirItem(Matriz1);

  return 0;
}
