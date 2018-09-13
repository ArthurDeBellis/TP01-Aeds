#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../Libs/voo.h"

//Função inicia
void Inicia(TVoo *Voo)
{
  Voo -> vid = 0;
  Voo -> horaDecolagem = 0;
  Voo -> minutosDecolagem = 0;
  Voo -> horaPouso = 0;
  Voo -> minutosPouso = 0;
  strcpy(Voo -> aeroportoDecolagem, "");
  strcpy(Voo -> aeroportoPouso, "");
  Voo -> identificadorPista = 0;

}

/*--------------------------------------------------------------------------------------*/
                                    //Funções Get
/*--------------------------------------------------------------------------------------*/

//Função para ler o vid
int GetVid(TVoo Voo)
{
  return (Voo.vid);
}

//Função para ler a hora da decolagem
int GetHrDecolagem(TVoo Voo)
{
  return Voo.horaDecolagem;
}

//Função para ler os minutos da decolagem
int GetMinutosDecolagem(TVoo Voo)
{
  return Voo.minutosDecolagem;
}

//Função para ler a hora do pouso
int GetHoraPouso(TVoo Voo)
{
  return Voo.horaPouso);
}

//Função para ler o vid
int GetMinutosPouso(TVoo Voo)
{
  return Voo.minutosPouso);
}

//Função para ler o aeroporto de decolagem
char* GetAeroportoDecolagem(TVoo Voo)
{
  return Voo.aeroportoDecolagem);
}

//Função para ler o aeroporto de pouso
char* GetAeroportoPouso(TVoo Voo)
{
  return Voo.aeroportoPouso);
}

//Função para ler o identificador da pista
int GetIdPista(TVoo Voo)
{
  return Voo.identificadorPista);
}

/*--------------------------------------------------------------------------------------*/
                                //Funções Set:
/*--------------------------------------------------------------------------------------*/

//Função para alterar o vid
void SetVid(TVoo *Voo)
{
  srand(time(NULL));
  Voo -> vid = (rand()%1000);
}

//Função para alterar a hora de decolagem
void SetHrDecolagem(TVoo *Voo)
{
  scanf("%d", &Voo -> horaDecolagem);
}

//Função para alterar os minutos de decolagem
void SetMinutosDecolagem(TVoo *Voo)
{
  scanf("%d", &Voo -> minutosDecolagem);
}

//Função para alterar a hora de pouso
void SetHoraPouso(TVoo *Voo)
{
  scanf("%d", &Voo -> horaPouso);
}

//Função para alterar os minutos de pouso
void SetMinutosPouso(TVoo *Voo)
{
  scanf("%d", &Voo -> minutosPouso);
}

//Função para alterar o aeroporto de decolagem
void SetAeroportoDecolagem(TVoo *Voo)
{
  scanf("%s", Voo -> aeroportoDecolagem);
}

//Função para alterar o aeroporto de pouso
void SetAeroportoPouso(TVoo *Voo)
{
  scanf("%s", Voo -> aeroportoPouso);
}

//Função para alterar o identificador da pista
void SetIdPista(TVoo *Voo)
{
  scanf("%d", &Voo -> identificadorPista);
}
