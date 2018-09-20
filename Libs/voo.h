#ifndef VOO_H
#define VOO_H

typedef struct{
  int vid;
  int horaDecolagem;
  int minutosDecolagem;
  int horaPouso;
  int minutosPouso;
  char aeroportoDecolagem[5];
  char aeroportoPouso[5];
  int identificadorPista;
}TVoo;

/*As horas e minutos foram separadas as para facilitar a execução do programa*/

// Todos os valores serão iniciados com 0
void IniciaVoo(TVoo *Voo);
void ImprimirTVoo(TVoo Voo);

/*--------------------------------------------------------------------------------------*/
                                    //Funções Get
/*--------------------------------------------------------------------------------------*/

int GetVid(TVoo Voo);

int GetHrDecolagem(TVoo Voo);

int GetMinutosDecolagem(TVoo Voo);

int GetHoraPouso(TVoo Voo);

int GetMinutosPouso(TVoo Voo);

char* GetAeroportoDecolagem(TVoo Voo);

char* GetAeroportoPouso(TVoo Voo);

int GetIdPista(TVoo Voo);

/*--------------------------------------------------------------------------------------*/
                                //Funções Set:
/*--------------------------------------------------------------------------------------*/

void SetVid(TVoo *Voo);

void SetHrDecolagem(TVoo *Voo, int horaDecolagem);

void SetMinutosDecolagem(TVoo *Voo, int minutosDecolagem);

void SetHrPouso(TVoo *Voo, int horaPouso);

void SetMinutosPouso(TVoo *Voo, int minutosPouso);

void SetAeroportoPouso(TVoo *Voo, char *aeroportoPouso);

void SetAeroportoDecolagem(TVoo *Voo, char *aeroportoDecolagem);

void SetIdPista(TVoo *Voo, int identificadorPista);

#endif
