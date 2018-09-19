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
  int i, j;
  i = horaDecolagem;
  j = horaPouso + 1;
  TCelula *pAtual = Matriz.Matriz[i][j].Lista.pPrimeiro->pProximo, *pAuxiliar;
  if(Matriz.Matriz[i][j].NumeroVoos != 0){
    while (pAtual != NULL){
      printf("=======================================================\n");
      printf("Vid: %d\n", pAtual->Voo.vid);
      printf("Horario de Decolagem: %d:%d\n", pAtual->Voo.horaDecolagem,pAtual->Voo.minutosDecolagem);
      printf("Horario de Pouso: %d:%d\n", pAtual->Voo.horaPouso, pAtual->Voo.minutosPouso);
      printf("Aeroporto de Decolagem: %s\n", pAtual->Voo.aeroportoDecolagem);
      printf("Aeroporto de Pouso: %s\n", pAtual->Voo.aeroportoPouso);
      printf("Identificador de Pista: %d\n", pAtual->Voo.identificadorPista);
      printf("=======================================================\n");

      pAuxiliar = pAtual -> pProximo;
      pAtual = pAuxiliar;
    }
  }
  else{
    printf("==========================================================\n");
    printf("\n    >>>Nao existe voos cadastrados nesse horario <<<\n");
    printf("==========================================================\n");
  }
}
void ImprimirVoo2(TipoMatriz Matriz, int horaDecolagem, int minutosDecolagem){
  int i, j;
  i = horaDecolagem;
  TCelula *pAtual, *pAuxiliar;
  for(j = 0; j < 24; j++)
  {
    if(Matriz.Matriz[i][j].NumeroVoos != 0){
      pAtual = Matriz.Matriz[i][j].Lista.pPrimeiro->pProximo;
      while (pAtual != NULL){
        printf("=======================================================\n");
        printf("Vid: %d\n", pAtual->Voo.vid);
        printf("Horario de Decolagem: %d:%d\n", pAtual->Voo.horaDecolagem,pAtual->Voo.minutosDecolagem);
        printf("Horario de Pouso: %d:%d\n", pAtual->Voo.horaPouso, pAtual->Voo.minutosPouso);
        printf("Aeroporto de Decolagem: %s\n", pAtual->Voo.aeroportoDecolagem);
        printf("Aeroporto de Pouso: %s\n", pAtual->Voo.aeroportoPouso);
        printf("Identificador de Pista: %d\n", pAtual->Voo.identificadorPista);
        printf("=======================================================\n");

        pAuxiliar = pAtual->pProximo;
        pAtual = pAuxiliar;

      }
    }
  }
}
void ImprimirVoo3(TipoMatriz Matriz, int horaPouso, int minutosPouso){
  int i, j;
  j = horaPouso + 1;
  TCelula *pAtual, *pAuxiliar;
  for(i = 0; i < 24; i++)
  {
    if(Matriz.Matriz[i][j].NumeroVoos != 0){
      pAtual = Matriz.Matriz[i][j].Lista.pPrimeiro->pProximo;
      while (pAtual != NULL){
        printf("=======================================================\n");
        printf("Vid: %d\n", pAtual->Voo.vid);
        printf("Horario de Decolagem: %d:%d\n", pAtual->Voo.horaDecolagem,pAtual->Voo.minutosDecolagem);
        printf("Horario de Pouso: %d:%d\n", pAtual->Voo.horaPouso, pAtual->Voo.minutosPouso);
        printf("Aeroporto de Decolagem: %s\n", pAtual->Voo.aeroportoDecolagem);
        printf("Aeroporto de Pouso: %s\n", pAtual->Voo.aeroportoPouso);
        printf("Identificador de Pista: %d\n", pAtual->Voo.identificadorPista);
        printf("=======================================================\n");

        pAuxiliar = pAtual->pProximo;
        pAtual = pAuxiliar;
      }
    }
  }
}
void ImprimirMatriz(TipoMatriz Matriz){
  int i, j;
  TCelula *pAtual, *pAuxiliar;
  for(i = 0; i < 24; i ++)
  {
    for (j = 0; j < 24; j++)
    {
      if(Matriz.Matriz[i][j].NumeroVoos != 0){
        pAtual = Matriz.Matriz[i][j].Lista.pPrimeiro->pProximo;
        while (pAtual != NULL){
          printf("=======================================================\n");
          printf("Vid: %d\n", pAtual->Voo.vid);
          printf("Horario de Decolagem: %d:%d\n", pAtual->Voo.horaDecolagem,pAtual->Voo.minutosDecolagem);
          printf("Horario de Pouso: %d:%d\n", pAtual->Voo.horaPouso, pAtual->Voo.minutosPouso);
          printf("Aeroporto de Decolagem: %s\n", pAtual->Voo.aeroportoDecolagem);
          printf("Aeroporto de Pouso: %s\n", pAtual->Voo.aeroportoPouso);
          printf("Identificador de Pista: %d\n", pAtual->Voo.identificadorPista);
          printf("=======================================================\n");

          pAuxiliar = pAtual->pProximo;
          pAtual = pAuxiliar;
        }
      }
    }
  }
}
void EncontrarMaiorHorario(TipoMatriz *Matriz){
    int linha, coluna,i,j,comparador =0,contador, maior =0;
    TCelula *pAtual, *pAuxiliar;
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
    TCelula *pAtual, *pAuxiliar;
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
    TCelula *pAtual, *pAuxiliar;
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
