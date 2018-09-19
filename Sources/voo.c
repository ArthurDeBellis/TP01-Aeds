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
//Função Imprimir
/*void ImprimirVoo(TVoo Voo)
{
  printf("Vid: %d\n", Voo.vid);
  printf("Horario de Decolagem: %d:%d\n", Voo.horaDecolagem,Voo.minutosDecolagem);
  printf("Horario de Pouso: %d:%d\n", Voo.horaPouso,Voo.minutosPouso);
  printf("Aeroporto de Decolagem: %s\n", Voo.aeroportoDecolagem);
  printf("Aeroporto de Pouso: %s\n", Voo.aeroportoPouso);
  printf("Identificador de Pista: %d\n", Voo.identificadorPista);

}*/

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
  return (Voo.horaDecolagem);
}

//Função para ler os minutos da decolagem
int GetMinutosDecolagem(TVoo Voo)
{
  return (Voo.minutosDecolagem);
}

//Função para ler a hora do pouso
int GetHoraPouso(TVoo Voo)
{
  return (Voo.horaPouso);
}

//Função para ler o vid
int GetMinutosPouso(TVoo Voo)
{
  return (Voo.minutosPouso);
}

//Função para ler o aeroporto de decolagem
char* GetAeroportoDecolagem(TVoo Voo)
{
  char* p;
  p = Voo.aeroportoDecolagem;
  return p;
}

//Função para ler o aeroporto de pouso
char* GetAeroportoPouso(TVoo Voo)
{
  char* p;
  p = Voo.aeroportoPouso;
  return p;
}

//Função para ler o identificador da pista
int GetIdPista(TVoo Voo)
{
  return (Voo.identificadorPista);
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
void SetHrDecolagem(TVoo *Voo, int horaDecolagem)
{
  Voo -> horaDecolagem = horaDecolagem;
}

//Função para alterar os minutos de decolagem
void SetMinutosDecolagem(TVoo *Voo, int minutosDecolagem)
{
  Voo -> minutosDecolagem = minutosDecolagem;
}

//Função para alterar a hora de pouso
void SetHrPouso(TVoo *Voo, int horaPouso)
{
  Voo -> horaPouso = horaPouso;
}

//Função para alterar os minutos de pouso
void SetMinutosPouso(TVoo *Voo, int minutosPouso)
{
  Voo -> minutosPouso = minutosPouso;
}

//Função para alterar o aeroporto de pouso
void SetAeroportoPouso(TVoo *Voo, char *aeroportoPouso)
{
  strcpy(Voo -> aeroportoPouso, aeroportoPouso);
}

//Função para alterar o aeroporto de decolagem
void SetAeroportoDecolagem(TVoo *Voo, char *aeroportoDecolagem)
{
  strcpy(Voo -> aeroportoDecolagem, aeroportoDecolagem);
}

//Função para alterar o identificador da pista
void SetIdPista(TVoo *Voo, int identificadorPista)
{
  Voo -> identificadorPista = identificadorPista;
}
