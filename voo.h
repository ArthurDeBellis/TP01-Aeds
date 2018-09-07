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

// O VID não é um dos parâmetros pois ele é escolhido aleatoriamente
void Inicia(TVoo *aux, int horaDecolagem, int minutosDecolagem, int horaPouso, int minutosPouso, char *aeroportoDecolagem, char *aeroportoPouso, int identificadorPista); /*Função para iniciar a execução*/
void imprime(TVoo aux);

/*Funções para acessar e alterar as informações*/
int GetVid(TVoo aux);
void SetVid(TVoo *aux, int NovoVid);

int GetHrDecolagem(TVoo aux);
void SetHrDecolagem(TVoo *aux, int NovaHr);

int GetMinutosDecolagem(TVoo aux);
void SetMinutosDecolagem(TVoo *aux, int NovosMnts);

int GetHoraPouso(TVoo aux);
void SetHoraPouso(TVoo *aux, int NovaHr);

int GetMinutosPouso(TVoo aux);
void SetMinutosPouso(TVoo *aux, int NovosMnts);

char* GetAeroportoDecolagem(TVoo aux);
void SetAeroportoDecolagem(TVoo *aux, char *NovoAeroporto);

char* GetAeroportoPouso(TVoo aux);
void SetAeroportoPouso(TVoo *aux, char *NovoAeroporto);

int GetIdPista(TVoo aux);
void SetIdPista(TVoo *aux, int NovaPista);
