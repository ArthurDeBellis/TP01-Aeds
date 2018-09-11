typedef struct {
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
void Inicia(TVoo *aux); /*Função para iniciar a execução*/

/*Funções para acessar e alterar as informações*/
int GetVid(TVoo aux);
void SetVid(TVoo *aux);

int GetHrDecolagem(TVoo aux);
void SetHrDecolagem(TVoo *aux, int NovaHr);

int GetMinutosDecolagem(TVoo aux);
void SetMinutosDecolagem(TVoo *aux, int NovoMinuto);

int GetHrPouso(TVoo aux);
void SetHrPouso(TVoo *aux, int NovaHr);

int GetMinutosPouso(TVoo aux);
void SetMinutosPouso(TVoo *aux, int NovoMinuto);

char* GetAeroportoDecolagem(TVoo aux);
void SetAeroportoDecolagem(TVoo *aux, char *NovoAeroporto);

char* GetAeroportoPouso(TVoo aux);
void SetAeroportoPouso(TVoo *aux, char *NovoAeroporto);

int GetIdPista(TVoo aux);
void SetIdPista(TVoo *aux, int NovaPista);
