#include <stdio.h>
#include <stdlib.h>
#include "voo.h"

int main()
{
  TVoo DOG;

  Inicia(&DOG, 12, 30, 18, 50, "Florestal", "Betim", 13);

  GetVid(DOG);
  SetVid(&DOG,351);
  GetVid(DOG);

  GetMinutosPouso(DOG);
  SetMinutosPouso(&DOG, 23);
  GetMinutosPouso(DOG);

  return 0;
}
