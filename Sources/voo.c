#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../Libs/voo.h"

//Função inicia
void Inicia(TVoo *aux)
{
  aux -> vid = 0;
  aux -> horaDecolagem = 0;
  aux -> minutosDecolagem = 0;
  aux -> horaPouso = 0;
  aux -> minutosPouso = 0;
  strcpy(aux -> aeroportoDecolagem, "");
  strcpy(aux -> aeroportoPouso, "");
  aux -> identificadorPista = 0;

}

/*--------------------------------------------------------------------------------------*/
                                    //Funções Get
/*--------------------------------------------------------------------------------------*/

//Função para ler o vid
int GetVid(TVoo aux)
{
  return (aux.vid);
}

//Função para ler a hora da decolagem
int GetHrDecolagem(TVoo aux)
{
  return aux.horaDecolagem;
}

//Função para ler os minutos da decolagem
int GetMinutosDecolagem(TVoo aux)
{
  return aux.minutosDecolagem;
}

//Função para ler a hora do pouso
int GetHoraPouso(TVoo aux)
{
  return aux.horaPouso);
}

//Função para ler o vid
int GetMinutosPouso(TVoo aux)
{
  return aux.minutosPouso);
}

//Função para ler o aeroporto de decolagem
char* GetAeroportoDecolagem(TVoo aux)
{
  return aux.aeroportoDecolagem);
}

//Função para ler o aeroporto de pouso
char* GetAeroportoPouso(TVoo aux)
{
  return aux.aeroportoPouso);
}

//Função para ler o identificador da pista
int GetIdPista(TVoo aux)
{
  return aux.identificadorPista);
}

/*--------------------------------------------------------------------------------------*/
                                //Funções Set:
/*--------------------------------------------------------------------------------------*/

//Função para alterar o vid
void SetVid(TVoo *aux)
{
  srand(time(NULL));
  aux -> vid = (rand()%1000);
}

//Função para alterar a hora de decolagem
void SetHrDecolagem(TVoo *aux, int NovaHr)
{
  aux -> horaDecolagem = NovaHr;
}

//Função para alterar os minutos de decolagem
void SetMinutosDecolagem(TVoo *aux, int NovosMnts)
{
  aux -> minutosDecolagem = NovosMnts;
}

//Função para alterar a hora de pouso
void SetHoraPouso(TVoo *aux, int NovaHr)
{
  aux -> horaPouso = NovaHr;
}

//Função para alterar os minutos de pouso
void SetMinutosPouso(TVoo *aux, int NovosMnts)
{
  aux -> minutosPouso = NovosMnts;
}

//Função para alterar o aeroporto de decolagem
void SetAeroportoDecolagem(TVoo *aux, char *NovoAeroporto)
{
  strcpy(aux -> aeroportoDecolagem, NovoAeroporto);
}

//Função para alterar o aeroporto de pouso
void SetAeroportoPouso(TVoo *aux, char *NovoAeroporto)
{
  strcpy(aux -> aeroportoPouso, NovoAeroporto);
}

//Função para alterar o identificador da pista
void SetIdPista(TVoo *aux, int NovaPista)
{
  aux -> identificadorPista = NovaPista;
}
