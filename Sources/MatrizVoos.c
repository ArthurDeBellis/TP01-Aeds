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
  Inserir(&Matriz->Matriz[i][j].Lista, voo);
  SetHreMntsLast(&Matriz->Matriz[i][j]);
}
void RemoverMVoo(TipoMatriz *Matriz, int vid){
  int i,j;
  for(i = 0; i < 24; i++){
    for(j = 0; j < 24; j++){
      while(Matriz->Matriz[i][j].Lista.pPrimeiro->pProximo != NULL){
        if(Matriz->Matriz[i][j].Lista.pPrimeiro->Voo.vid == vid){
          RemoverVoo(&Matriz->Matriz[i][j].Lista, vid);
          SetHreMntsLast(&Matriz->Matriz[i][j]);
        }
      }
    }
  }
}
void ProcurarVoo(TipoMatriz *Matriz, int vid){
  int i, j;
  for (i = 0; i < 24; i++){
    for(j = 0; j < 24; j++){
      ProcurarVoo(&Matriz->Matriz[i][j].Lista, vid);
    }
  }
}
void ImprimirVoo1(TipoMatriz Matriz, int horaDecolagem, int minutosDecolagem, int horaPouso, int minutosPouso){

}
void ImprimirVoo2(TipoMatriz Matriz, int horaDecolagem, int minutosDecolagem){

}
void ImprimirVoo3(TipoMatriz Matriz, int horaPouso, int minutosPouso){

}
void ImprimirMatriz(TipoMatriz Matriz){

}
void EncontrarMaiorHorario(TipoMatriz *Matriz){
    int linha, coluna,i,j,comparador =0,contador, maior =0;
    Celula *pAtual, *pAuxiliar;
    for(linha=0; linha<24; linha++){
      contador = 0;
      for(coluna =0; coluna<24; coluna++){
          pAtual = Matriz->Matriz[linha][coluna].Lista.pPrimeiro;
          while (pAtual->pProximo != NULL){
              contador++;
              pAuxiliar = pAtual->pProximo;
              pAtual = pAuxiliar;
          }
          if (contador>=maior){
              i = linha;
              j = coluna;
              maior = contador;
          }
    printf("i = %d e j = %d e quantidade de voos = %d\n", i, j, contador);

      }
    }


}
void EncontrarMenorHorario(TipoMatriz *Matriz){
    int linha, coluna,i,j,comparador =0,contador, menor =10000, maior;
    Celula *pAtual, *pAuxiliar;
    for(linha=0; linha<24; linha++){
        contador = 0;
        for(coluna =0; coluna<24; coluna++){
            pAtual = Matriz->Matriz[linha][coluna].Lista.pPrimeiro;
            while (pAtual->pProximo != NULL){
                contador++;
                pAuxiliar = pAtual->pProximo;
                pAtual = pAuxiliar;
            }
            if (contador<=maior){
                i = linha;
                j = coluna;
                menor = contador;
            }
    printf("i = %d e j = %d e quantidade de voos = %d\n", i, j, contador);

      }
    }

}
void EncontrarListaMaisRecente(TipoMatriz *Matriz){
    int horas, minutos, minutoMaisRecente, horaMaisRecente, contador = 0, linha, coluna, i, j;
    ItemMatriz *pAtual;
    for(linha=0; linha<24; linha++){
        for(coluna =0; coluna<24; coluna++){
            pAtual = &(Matriz->Matriz[linha][coluna]);
            horas = (pAtual->HrLast)*60;
            minutos = (pAtual->MntsLast);
            if (contador ==0){
                contador++;
                horaMaisRecente = horas;
                minutoMaisRecente = minutos;
                i = 0;
                j = 0;
            }else{
                if ((horas+minutos)>=(horaMaisRecente+minutoMaisRecente)){
                    horaMaisRecente = horas/60;
                    minutoMaisRecente = minutos;
                    i = linha;
                    j = coluna;
            }
        }
    }
    printf("i = %d, j = %d, horario = %d:%d\n", i,j,horaMaisRecente,minutoMaisRecente);
}
}
void EncontrarListaMenosRecente(TipoMatriz *Matriz){
    int horas, minutos, minutoMenosRecente, horaMenosRecente, contador = 0, linha, coluna, i, j;
    ItemMatriz *pAtual;
    for(linha=0; linha<24; linha++){
        for(coluna =0; coluna<24; coluna++){
            pAtual = &(Matriz->Matriz[linha][coluna]);
            horas = (pAtual->HrLast)*60;
            minutos = (pAtual->MntsLast);
            if (contador ==0){
                contador++;
                horaMenosRecente = horas;
                minutoMenosRecente = minutos;
                i = 0;
                j = 0;
            }else{
                if ((horas+minutos)<=(horaMenosRecente+minutoMenosRecente)){
                    horaMenosRecente = horas/60;
                    minutoMenosRecente = minutos;
                    i = linha;
                    j = coluna;
                }
            }
        }
    printf("i = %d, j = %d, horario = %d:%d\n", i,j,horaMenosRecente,minutoMenosRecente);
  }
}
void MatrizEspaca(TipoMatriz *Matriz){
    int contador =0, linha, coluna;
    Celula *pAtual, *pAuxiliar;
    for(linha=0; linha<24; linha++){
        for(coluna =0; coluna<24; coluna++){
            pAtual = Matriz->Matriz[linha][coluna].Lista.pPrimeiro;
            if(pAtual->pProximo == NULL){
                contador++;
            }
        }
    }
    if(contador>=384){
      printf("É esparça.\n");
    }else{
      printf("Não é esparça.\n");
    }
}
