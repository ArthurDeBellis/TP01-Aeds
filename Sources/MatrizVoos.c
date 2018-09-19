#include <stdio.h>
#include <stdlib.h>
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
  /*Matriz -> Data = 0;
  Matriz -> HoradaUltimaAtualizacao = 0;*/
}
void InserirVoo(TipoMatriz *Matriz, int horaDecolagem, int minutosDecolagem, int horaPouso, int minutosPouso, char* aeroportoDecolagem, char* aeroportoPouso, int identificadorPista){

}
void RemoverVoo(TipoMatriz *Matriz, int vid){

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
