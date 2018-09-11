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
void SetHrDecolagem(TVoo *aux);

int GetMinutosDecolagem(TVoo aux);
void SetMinutosDecolagem(TVoo *aux);

int GetHrPouso(TVoo aux);
void SetHrPouso(TVoo *aux);

int GetMinutosPouso(TVoo aux);
void SetMinutosPouso(TVoo *aux);

char* GetAeroportoDecolagem(TVoo aux);
void SetAeroportoDecolagem(TVoo *aux);

char* GetAeroportoPouso(TVoo aux);
void SetAeroportoPouso(TVoo *aux);

int GetIdPista(TVoo aux);
void SetIdPista(TVoo *aux);
