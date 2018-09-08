#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "voo.h"

//Função inicial para receber os dados do voo
void Inicia(TVoo *aux, int horaDecolagem, int minutosDecolagem, int horaPouso, int minutosPouso, char *aeroportoDecolagem, char *aeroportoPouso, int identificadorPista)
{

  aux -> vid = (rand()%999);
  aux -> horaDecolagem = horaDecolagem;
  aux -> minutosDecolagem = minutosDecolagem;
  aux -> horaPouso = horaPouso;
  aux -> minutosPouso = minutosPouso;
  strcpy(aux -> aeroportoDecolagem, aeroportoDecolagem);
  strcpy(aux -> aeroportoPouso, aeroportoPouso);
  aux -> identificadorPista = identificadorPista;

}

//Funções para ler e alterar o Vid
int GetVid(TVoo aux)
{
  printf("Vid: %d\n", aux.vid);
}
void SetVid(TVoo *aux, int NovoVid)
{
  aux -> vid = NovoVid;
}

//Funções para ler e alterar a hora da Decolagem
int GetHrDecolagem(TVoo aux)
{
  printf("Hora Decolagem: %d\n", aux.horaDecolagem);
}
void SetHrDecolagem(TVoo *aux, int NovaHr)
{
  aux -> horaDecolagem = NovaHr;
}

//Funções para ler e alterar os minutos da decolagem
int GetMinutosDecolagem(TVoo aux)
{
  printf("Minutos Decolagem: %d\n", aux.minutosDecolagem);
}
void SetMinutosDecolagem(TVoo *aux, int NovosMnts)
{
  aux -> minutosDecolagem = NovosMnts;
}

//Funções para ler e alterar a hora do pouso
int GetHoraPouso(TVoo aux)
{
  printf("Hora do Pouso: %d\n", aux.horaPouso);
}
void SetHoraPouso(TVoo *aux, int NovaHr)
{
  aux -> horaPouso = NovaHr;
}

//Funções para ler e alterar os minutos do pouso
int GetMinutosPouso(TVoo aux)
{
  printf("Minutos Pouso: %d\n", aux.minutosPouso);
}
void SetMinutosPouso(TVoo *aux, int NovosMnts)
{
  aux -> minutosPouso = NovosMnts;
}

//Funções para ler e alterar o nome do aeroporto de decolagem
char* GetAeroportoDecolagem(TVoo aux)
{
  printf("Aeroporto de Decolagem: %s\n", aux.aeroportoDecolagem);
}
void SetAeroportoDecolagem(TVoo *aux, char *NovoAeroporto)
{
  strcpy(aux -> aeroportoDecolagem, NovoAeroporto);
}

//Funções para ler e alterar o nome do aeroporto de pouso
char* GetAeroportoPouso(TVoo aux)
{
  printf("Aeroporto de Pouso: %s\n", aux.aeroportoPouso);
}
void SetAeroportoPouso(TVoo *aux, char *NovoAeroporto)
{
  strcpy(aux -> aeroportoPouso, NovoAeroporto);
}

//Funções para ler e alterar o identificador da pista de decolagem
int GetIdPista(TVoo aux)
{
  printf("Identificador da Pista de Decolagem: %d\n", aux.identificadorPista);
}
void SetIdPista(TVoo *aux, int NovaPista)
{
  aux -> identificadorPista = NovaPista;
}
