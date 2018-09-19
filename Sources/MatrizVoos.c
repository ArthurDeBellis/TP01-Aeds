#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../Libs/MatrizVoos.h"
#include "../Libs/ItemMatriz.h"
#include "../Libs/ListadeVoos.h"
#include "../Libs/voo.h"

void Inicializar(TipoMatriz *Matriz){
  int i, j;
  for(i = 0; i < 24; i++){
    for(j = 0; j < 24; j++){
      iniciar(&Matriz -> Matriz[i][j]);
      Inicializa(&Matriz -> Matriz[i][j].Lista);
    }
  }
  Matriz -> dia = 0;
  Matriz -> mes = 0;
  Matriz -> ano = 0;

  Matriz -> HoradaUltimaAtualizacao = 0;
  Matriz -> MinutosUltimaAtualizacao = 0;
}
void InserirVoo(TipoMatriz *Matriz, TVoo *voo){
  int i, j;
  i = voo->horaDecolagem;
  j = voo->horaPouso + 1;
  Inserir(&Matriz->Matriz[i][j]->Lista, &voo)
}
void RemoverVoo(TipoMatriz *Matriz, int vid){
  int i,j;
  for(i = 0; i < 24; i++){
    for(j = 0; j < 24; j++){
      while(Matriz->Matriz[i][j].Lista->pPrimeiro->pProximo != NULL){
        if(Matriz->Matriz[i][j].Lista->pPrimeiro.Voo.vid == vid){
          RemoverVoo(&Matriz->Matriz[i][j].Lista, vid);
        }
      }
    }
  }
}
void ProcurarVoo(TipoMatriz *Matriz, int vid){

}
void ImprimirVoo1(TipoMatriz Matriz, int horaDecolagem, int minutosDecolagem, int horaPouso, int minutosPouso){

}
void ImprimirVoo2(TipoMatriz Matriz, int horaDecolagem, int minutosDecolagem){

}
void ImprimirVoo3(TipoMatriz Matriz, int horaPouso, int minutosPouso){

}
void ImprimirMatriz(TipoMatriz Matriz){

}
void EncontrarMaiorHorario(TipoMatriz Matriz){

}
void EncontrarMenorHorario(TipoMatriz Matriz){

}
void EncontrarListaMaisRecente(TipoMatriz Matriz){

}
void EncontrarListaMenosRecente(TipoMatriz Matriz){

}
void MatrizEspaca(TipoMatriz Matriz){

}
