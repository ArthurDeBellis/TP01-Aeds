#include <stdio.h>
#include <stdlib.h>
#include <../Libs/MatrizVoos.h>

void Inicializar(ItemMatriz *Matriz){
  int i, j;
  for(i = 0; i < 24; i++){
    for(j = 0; j < 24; j++){
      Matriz -> Matriz[i][j] = iniciar;
    }
  }
  Matriz -> Data = 0;
  Matriz -> HoradaUltimaAtualizacao = 0;
}
void InserirVoo(ItemMatriz *Matriz, int vid, int horaDecolagem, int minutosDecolagem, int horaPouso, int minutosPouso, char* aeroportoDecolagem, char* aeroportoPouso, int identificadorPista){

}
void RemoverVoo(ItemMatriz *Matriz, int vid){

}
void ProcurarVoo(ItemMatriz *Matriz, int vid){

}
void ImprimirVoo1(ItemMatriz Matriz, int horaDecolagem, int minutosDecolagem, int horaPouso, int minutosPouso){

}
void ImprimirVoo2(ItemMatriz Matriz, int horaDecolagem, int minutosDecolagem){

}
void ImprimirVoo3(ItemMatriz Matriz, int horaPouso, int minutosPouso){

}
void ImprimirMatriz(ItemMatriz Matriz){

}
void EncontrarMaiorHorario(ItemMatriz Matriz){

}
void EncontrarMenorHorario(ItemMatriz Matriz){

}
void EncontrarListaMaisRecente(ItemMatriz Matriz){

}
void EncontrarListaMenosRecente(ItemMatriz Matriz){

}
void MatrizEspaca(ItemMatriz Matriz){

}
