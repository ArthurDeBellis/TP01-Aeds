#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../Libs/MatrizVoos.h"
#include "../Libs/ItemMatriz.h"
#include "../Libs/ListadeVoos.h"
#include "../Libs/voo.h"

void IniciaMatriz(TipoMatriz *Matriz){
  TipoMatriz **pMatriz;
  pMatriz = &Matriz;
  int i, j;
  pMatriz = (TipoMatriz **)malloc(24*sizeof(TipoMatriz *));
  for(i = 0; i < 24; i++){
    pMatriz[i] = (TipoMatriz *)malloc(24*sizeof(TipoMatriz));
    for(j = 0; j < 24; j++){
      IniciaItem(&(Matriz) -> Matriz[i][j]);
    }
  }
  Matriz -> dia = 0;
  Matriz -> mes = 0;
  Matriz -> ano = 0;

  Matriz -> HoradaUltimaAtualizacao = 0;
  Matriz -> MinutosUltimaAtualizacao = 0;
}
void InserirMVoo(TipoMatriz *Matriz, TVoo *voo){
  int i, j;
  i = voo->horaDecolagem;
  j = voo->horaPouso;
  InserirNovo(&Matriz->Matriz[i][j].Lista, *voo);
  SetNumVoo(&Matriz->Matriz[i][j]);
  SetHreMntsLast(&Matriz->Matriz[i][j]);
}
void RemoverMVoo(TipoMatriz *Matriz, int vid){
  int i,j;
  for(i = 0; i < 24; i++){
    for(j = 0; j < 24; j++){
      while(Matriz->Matriz[i][j].Lista.pPrimeiro->pProximo != NULL){
        if(Matriz->Matriz[i][j].Lista.pUltimo->Voo.vid == vid){
          RemoverVoo(&Matriz->Matriz[i][j].Lista, vid);
          SetHreMntsLast(&Matriz->Matriz[i][j]);

        }
        }
      }
    }
}

void ProcurarMVoo(TipoMatriz *Matriz, int vid){
  int i, j;
  int contador = 0;
  for (i = 0; i < 24; i++){
    for(j = 0; j < 24; j++){
      while(Matriz->Matriz[i][j].Lista.pPrimeiro->pProximo != NULL){
        if(Matriz->Matriz[i][j].Lista.pUltimo->Voo.vid == vid){
          printf("O voo informado está cadastrado!\n");
          break;
        }
        else{
          contador++;
          if(contador == 1){
            printf("O voo não foi encontrado...\nVerifique se o VID informado está correto e tente novamente!\n");
            break;
          }
        }
      }
    }
  }
}
void ImprimirVoo1(TipoMatriz Matriz, int horaDecolagem, int minutosDecolagem, int horaPouso, int minutosPouso){
  int i, j;
  i = horaDecolagem;
  j = horaPouso + 1;
  TCelula *pAtual = Matriz.Matriz[i][j].Lista.pPrimeiro->pProximo;
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

      pAtual = pAtual -> pProximo;
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
  TCelula *pAtual;
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

        pAtual = pAtual->pProximo;

      }
    }
  }
}
void ImprimirVoo3(TipoMatriz Matriz, int horaPouso, int minutosPouso){
  int i, j;
  j = horaPouso + 1;
  TCelula *pAtual;
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

        pAtual = pAtual->pProximo;
      }
    }
  }
}
void ImprimirMatriz(TipoMatriz Matriz){
  int i, j,cont = 0;
  TCelula *pAtual;
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

          pAtual = pAtual->pProximo;
          cont++;
        }
      }
    }
  }
  if(cont==0){
    printf("A matriz está vazia.\n");
  }
}
void EncontrarMaiorHorario(TipoMatriz *Matriz){
  int linha=0, coluna=0, numerodevoos, maior;
  for(linha=0; linha<24; linha++){
      for(coluna =0; coluna<24; coluna++){
          numerodevoos = Matriz->Matriz[linha][coluna].NumeroVoos;
          if ((linha+coluna)==0) {
            maior = numerodevoos;
          }
          else{
            if(numerodevoos>maior ){
              maior = numerodevoos;
            }
          }
        }
      }
  if(maior!=0){
    for(linha=0; linha<24; linha++){
      for(coluna =0; coluna<24; coluna++){
        numerodevoos = Matriz->Matriz[linha][coluna].NumeroVoos;
        if(maior==numerodevoos){
            printf("Item com maior quantidade de voos: i = %d e j = %d e quantidade = %d\n", linha, coluna, maior);
        }
      }
    }
  }
  else{
    printf("A matriz está vazia\n" );
  }
}
void EncontrarMenorHorario(TipoMatriz *Matriz){
    int linha=0, coluna=0, numerodevoos, menor =10000;
    for(linha=0; linha<24; linha++){
        for(coluna =0; coluna<24; coluna++){
            numerodevoos = Matriz->Matriz[linha][coluna].NumeroVoos;
            if ((linha+coluna)==0 && numerodevoos != 0) {
              menor = numerodevoos;
            }
            else{
              if(numerodevoos<menor && numerodevoos != 0){
                menor = numerodevoos;
              }
            }
          }
        }
    if(menor!=10000){
      for(linha=0; linha<24; linha++){
          for(coluna =0; coluna<24; coluna++){
            numerodevoos = Matriz->Matriz[linha][coluna].NumeroVoos;
              if(menor==numerodevoos){
                  printf("Item com menor quantidade de voos: i = %d e j = %d e quantidade = %d\n", linha, coluna, menor);
              }
          }
      }
    }
    else{
      printf("A matriz está vazia\n" );
    }
}
void EncontrarListaMaisRecente(TipoMatriz *Matriz){
  int horas= 0, minutos = 0, minutoMaisRecente =0, horaMaisRecente=0, linha, coluna;
  for(linha=0; linha<24; linha++){
      for(coluna =0; coluna<24; coluna++){
          horas = Matriz->Matriz[linha][coluna].HrLast*60;
          minutos = Matriz->Matriz[linha][coluna].MntsLast;
          if (horas+minutos != 0){
            if((horas+minutos)>=((horaMaisRecente*60)+minutoMaisRecente)){
              horaMaisRecente = horas;
              minutoMaisRecente = minutos;
            }
          }
      }
    }
    if(horaMaisRecente!=0){
      for(linha=0; linha<24; linha++){
          for(coluna =0; coluna<24; coluna++){
            horas = Matriz->Matriz[linha][coluna].HrLast*60;
            minutos = Matriz->Matriz[linha][coluna].MntsLast;
            if((horas+minutos)==(horaMaisRecente+minutoMaisRecente)){
              printf("Mais recente: i = %d, j = %d, horario = %d:%d\n", linha, coluna, (horaMaisRecente/60), minutoMaisRecente);
            }
          }
      }
    }
    else{
      printf("A matriz está vazia.\n");
    }
}
void EncontrarListaMenosRecente(TipoMatriz *Matriz){
    int horas= 0, minutos = 0, minutoMenosRecente =59, horaMenosRecente=23, linha, coluna;
    for(linha=0; linha<24; linha++){
        for(coluna =0; coluna<24; coluna++){
            horas = Matriz->Matriz[linha][coluna].HrLast*60;
            minutos = Matriz->Matriz[linha][coluna].MntsLast;
            if (horas+minutos != 0){
              if((horas+minutos)<=((horaMenosRecente*60)+minutoMenosRecente)){
                horaMenosRecente = horas;
                minutoMenosRecente = minutos;
              }
            }
        }
      }
      if(horaMenosRecente!=23){
        for(linha=0; linha<24; linha++){
            for(coluna =0; coluna<24; coluna++){
              horas = Matriz->Matriz[linha][coluna].HrLast*60;
              minutos = Matriz->Matriz[linha][coluna].MntsLast;
              if((horas+minutos)==(horaMenosRecente+minutoMenosRecente)){
                printf("Menos recente: i = %d, j = %d, horario = %d:%d\n", linha, coluna, (horaMenosRecente/60), minutoMenosRecente);

              }
            }
        }
      }
      else{
        printf("A matriz está vazia.\n");
      }
}
void MatrizEsparca(TipoMatriz *Matriz){
    int contador =0, linha, coluna;
    TCelula *pAtual;
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
