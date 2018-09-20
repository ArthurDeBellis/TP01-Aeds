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

  if(Vazia((*Lista))==1){
    InserirUltimo(Lista, Voo);
    return;
  }

  if(((Voo.horaDecolagem * 60 )+Voo.minutosDecolagem) >= ((Lista->pUltimo->Voo.horaDecolagem *60 )+ Lista->pUltimo->Voo.minutosDecolagem) ){
      InserirUltimo(Lista, Voo);
      return;
  }
  


}


void Inserir(TLista *pLista, TVoo *Voo){
  TCelula *novacelula = NULL, *auxiliar = NULL, *ultimomenor=NULL;
  TCelula *celulalista = (pLista -> pPrimeiro);
  int horario;
  novacelula = (TCelula*) malloc(sizeof(TCelula));
  if(!novacelula){
    printf("Erro ao alocar memória");
  }

  //Aqui eu pego o conteúdo do voo inserido e passo para a memoria alocada
  novacelula->Voo.vid = Voo->vid;
  novacelula->Voo.horaDecolagem = Voo->horaDecolagem;
  novacelula->Voo.minutosDecolagem = Voo->minutosDecolagem;
  novacelula->Voo.horaPouso = Voo->horaPouso;
  novacelula->Voo.minutosPouso = Voo->minutosPouso;
  strcpy(novacelula->Voo.aeroportoDecolagem,Voo->aeroportoDecolagem);
  strcpy(novacelula->Voo.aeroportoPouso,Voo->aeroportoPouso);
  novacelula->Voo.identificadorPista = Voo->identificadorPista;

  horario = (novacelula -> Voo.minutosDecolagem + (novacelula -> Voo.horaDecolagem * 60));
  //No loop while eu percorro pela lista parando apenas quando encontro horario igual ou
  //"mais tardio" que o horaio do voo que vai ser inserido, por isso com o ponteiro ultimomenor
  //eu aponto para a célula anterior à que está sendo analisada.
  while(horario < (celulalista -> Voo.minutosDecolagem + (celulalista -> Voo.horaDecolagem*60))){
    if (celulalista -> pProximo == NULL){
      break;
    }
    else{
      ultimomenor = celulalista;
      auxiliar = celulalista -> pProximo;
      celulalista = auxiliar;
    }
  }
  novacelula -> pProximo = ultimomenor -> pProximo;
  ultimomenor -> pProximo = novacelula;
  if(ultimomenor == pLista -> pUltimo){
    pLista -> pUltimo = ultimomenor -> pProximo;
  }
}
//Aqui busco o voo pelo identificador e a função retorna o ponteiro da célula que contém tal voo
TCelula *ProcurarVoo(TLista *pLista, int Id){
    TCelula *temp = NULL, *celulaatual = NULL;
    celulaatual = pLista -> pPrimeiro -> pProximo;
    while(celulaatual -> Voo.vid != Id){
      if (celulaatual -> pProximo == NULL){
        break;
      }
      else{
        temp = celulaatual -> pProximo;
        celulaatual = temp;
      }
    }
  return celulaatual;
}
//Aqui fazemos o uso da função ProcuraVoo para encontrar o voo a ser removido e também buscamos o
//seu antecessor(que contém seu endereço), para pegar o endereço guardado na célula a ser
//removida no seu antecessor e depois liberar a memória ocupada pela célula removida.
int RemoverVoo(TLista *pLista, int Id){
  TCelula *CelulaaRemover= NULL, *antecessor = NULL, *auxiliar = NULL;
  CelulaaRemover = ProcurarVoo(pLista, Id);
  antecessor = pLista -> pPrimeiro -> pProximo;
  while(antecessor -> pProximo != CelulaaRemover){
    auxiliar = antecessor -> pProximo;
    antecessor = auxiliar;
  }

  if(CelulaaRemover == pLista -> pUltimo){
    pLista -> pUltimo = antecessor -> pProximo;
  }

  antecessor -> pProximo = CelulaaRemover -> pProximo;
  free(CelulaaRemover);
  return 0;
}
