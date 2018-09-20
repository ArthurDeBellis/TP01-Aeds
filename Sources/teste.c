#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../Libs/ItemMatriz.h"
#include "../Libs/ListadeVoos.h"
#include "../Libs/MatrizVoos.h"
#include "../Libs/voo.h"

int main() {

  TVoo voo;

  IniciaVoo(&voo);
  SetVid(&voo);
  SetHrDecolagem(&voo, 13);
  SetMinutosDecolagem(&voo, 35);
  SetHrPouso(&voo, 18);
  SetMinutosPouso(&voo, 30);
  SetAeroportoDecolagem(&voo, "BHD");
  SetAeroportoPouso(&voo, "JIU");
  SetIdPista(&voo, 15);

  TVoo voo2;

  IniciaVoo(&voo2);
  SetVid(&voo2);
  SetHrDecolagem(&voo2, 14);
  SetMinutosDecolagem(&voo2, 40);
  SetHrPouso(&voo2, 18);
  SetMinutosPouso(&voo2, 30);
  SetAeroportoDecolagem(&voo2, "asd");
  SetAeroportoPouso(&voo2, "dsa");
  SetIdPista(&voo2, 17);

  ImprimirTVoo(voo);

  TLista lista1;
  IniciaLista(&lista1);


  InserirNovo(&lista1, voo);
  InserirNovo(&lista1, voo2);

  printf("%s\n", lista1.pPrimeiro->pProximo->pProximo->Voo.aeroportoDecolagem);


  return 0;
}
