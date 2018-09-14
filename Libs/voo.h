#ifndef VOO_H
#define VOO_H

typedef struct{
  int vid;
  int horaDecolagem;
  int minutosDecolagem;
  int horaPouso;
  int minutosPouso;
  char aeroportoDecolagem[50];
  char aeroportoPouso[50];
  int identificadorPista;
}TVoo;

/*As horas e minutos foram separadas as para facilitar a execução do programa*/

// Todos os valores serão iniciados com 0
void Inicia(TVoo *Voo); /*Função para iniciar a execução*/
//void ImprimirVoo(TVoo Voo);
/*Funções para acessar e alterar as informações*/
int GetVid(TVoo Voo);
void SetVid(TVoo *Voo);

int GetHrDecolagem(TVoo Voo);
void SetHrDecolagem(TVoo *Voo);

int GetMinutosDecolagem(TVoo Voo);
void SetMinutosDecolagem(TVoo *Voo);

int GetHrPouso(TVoo Voo);
void SetHrPouso(TVoo *Voo);

int GetMinutosPouso(TVoo Voo);
void SetMinutosPouso(TVoo *Voo);

char* GetAeroportoDecolagem(TVoo Voo);
void SetAeroportoDecolagem(TVoo *Voo);

char* GetAeroportoPouso(TVoo Voo);
void SetAeroportoPouso(TVoo *Voo);

int GetIdPista(TVoo Voo);
void SetIdPista(TVoo *Voo);
#endif
