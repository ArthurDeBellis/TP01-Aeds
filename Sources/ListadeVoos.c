#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Libs/voo.h"
#include "../Libs/ListadeVoos.h"


//Função inicializa dando à lista uma célula cabeça
void IniciaLista(TLista *pLista){
  pLista -> pPrimeiro = (TCelula*) malloc(sizeof(TCelula));
  pLista -> pUltimo = pLista -> pPrimeiro;
  pLista -> pUltimo -> pProximo = NULL;
}
//Aqui alocamos um novo espaço para a célula a ser inserida e também buscamos o lugar que
//ela ocupará na lista.

void InserirUltimo(TLista *Lista, TVoo Voo)
{

  Lista -> pUltimo -> pProximo = (TCelula *) malloc(sizeof(TCelula));
  Lista -> pUltimo = Lista -> pUltimo -> pProximo;
  Lista -> pUltimo -> Voo = Voo;
  Lista -> pUltimo -> pProximo = NULL;

}

int Vazia(TLista Lista)
{
  return (Lista.pPrimeiro == Lista.pUltimo);
}


void InserirNovo(TLista *Lista, TVoo Voo){
  if(Vazia((*Lista))==1 || ((Voo.horaDecolagem * 60 )+Voo.minutosDecolagem) >= ((Lista->pUltimo->Voo.horaDecolagem *60 )+ Lista->pUltimo->Voo.minutosDecolagem)){
    InserirUltimo(Lista, Voo);
    return;
  }

  else{
    TCelula *novacelula = (TCelula*) malloc(sizeof(TCelula));
    TCelula *antecessor = (Lista -> pPrimeiro);
    int horario;
    novacelula->Voo.vid = Voo.vid;
    novacelula->Voo.horaDecolagem = Voo.horaDecolagem;
    novacelula->Voo.minutosDecolagem = Voo.minutosDecolagem;
    novacelula->Voo.horaPouso = Voo.horaPouso;
    novacelula->Voo.minutosPouso = Voo.minutosPouso;
    strcpy(novacelula->Voo.aeroportoDecolagem,Voo.aeroportoDecolagem);
    strcpy(novacelula->Voo.aeroportoPouso,Voo.aeroportoPouso);
    novacelula->Voo.identificadorPista = Voo.identificadorPista;

    horario = (novacelula -> Voo.minutosDecolagem + (novacelula -> Voo.horaDecolagem * 60));
    while(horario > (antecessor -> pProximo -> Voo.minutosDecolagem + (antecessor -> pProximo -> Voo.horaDecolagem*60))){
        antecessor = antecessor -> pProximo;
    }
    novacelula -> pProximo = antecessor -> pProximo;
    antecessor -> pProximo = novacelula;
    return;
  }
}



//Aqui busco o voo pelo identificador e a função retorna o ponteiro da célula que contém tal voo
TCelula *ProcurarVoo(TLista *pLista, int Id){
    TCelula *retorno = pLista -> pPrimeiro -> pProximo;

    while(retorno -> Voo.vid != Id){
      if (retorno->pProximo==NULL){
        return NULL;
      }
      retorno = retorno->pProximo;
      }
  return retorno;
}
//Aqui fazemos o uso da função ProcuraVoo para encontrar o voo a ser removido e também buscamos o
//seu antecessor(que contém seu endereço), para pegar o endereço guardado na célula a ser
//removida no seu antecessor e depois liberar a memória ocupada pela célula removida.
int RemoverVoo(TLista *pLista, int Id){
  TCelula *CelulaaRemover= NULL, *Antecessor = NULL;
  CelulaaRemover = ProcurarVoo(pLista, Id);
  if(CelulaaRemover!= NULL){
    Antecessor = pLista -> pPrimeiro -> pProximo;
    while(Antecessor -> pProximo != CelulaaRemover){
      Antecessor = Antecessor -> pProximo;
    }

    if(CelulaaRemover == pLista -> pUltimo){
      pLista -> pUltimo = Antecessor;
    }

    Antecessor -> pProximo = CelulaaRemover -> pProximo;
    free(CelulaaRemover);
  }
  else{
    printf("Voo não encontrado :(\n");
  }
  return 0;
}
void ImprimirLVoos(TLista Lista) {
  TCelula* Aux; Aux = Lista.pPrimeiro -> pProximo;
   while (Aux != NULL) {
     //printf("%d\n", Aux -> Item.Chave);
     printf("Vid: %d\n", Aux -> Voo.vid);
     printf("Horario de Decolagem: %d:%d\n", Aux -> Voo.horaDecolagem, Aux -> Voo.minutosDecolagem);
     printf("Horario de Pouso: %d:%d\n", Aux -> Voo.horaPouso, Aux -> Voo.minutosPouso);
     printf("Aeroporto de Decolagem: %s\n", Aux -> Voo.aeroportoDecolagem);
     printf("Aeroporto de Pouso: %s\n", Aux -> Voo.aeroportoPouso);
     printf("Identificador de Pista: %d\n\n", Aux ->Voo.identificadorPista);

     Aux = Aux -> pProximo; } }
