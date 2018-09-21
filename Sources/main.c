#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "../Libs/ItemMatriz.h"
#include "../Libs/ListadeVoos.h"
#include "../Libs/MatrizVoos.h"
#include "../Libs/voo.h"
#include "../Libs/menu.h"

int main(){
  srand(time(NULL));
  TipoMatriz Principal;
  TVoo vooReserva;
  int aux = 10, intConfirma = 0, modo, intOperador = 0, vid, hrPouso, minPouso, hrDecolagem, minDecolagem;
  char op, confirma;

  printf("=================================================================\n");
  printf("|                      Seja Bem-vindo(a)!                       |\n");
  printf("=================================================================\n");
  printf("\n");

  while(aux != 0){
    menu_de_entradas();

    scanf("%d", &modo);

    if(modo == 0){
      menu_de_confirmacao();
      scanf(" %c", &confirma);
      printf("\n");
      confirma = toupper(confirma);
      intConfirma = confirma - 64;

      if(intConfirma == 19){
        menu_de_saida();
        aux = 0;
      }
    }
    else{
      aux = modo;
      if(modo ==1){
        while(intOperador != 19){

          menu_de_opcoes();

          scanf(" %c", &op);
          op = toupper(op);
          intOperador = op - 64;

          switch (intOperador){
            case 1:
              IniciaMatriz(&Principal);
              printf("\n");
              printf("A matriz foi inicializada!\n");
              break;

            case 2:
              IniciaVoo(&vooReserva);
              SetVid(&vooReserva);
              printf("Horário de Decolagem: (HH:MM)\n");
              scanf("%d:%d", &vooReserva.horaDecolagem, &vooReserva.minutosDecolagem);
              printf("Horário de Pouso:(HH:MM)\n");
              scanf("%d:%d", &vooReserva.horaPouso, &vooReserva.minutosPouso);
              printf("Aeroporto de decolagem:\n");
              scanf("%s", vooReserva.aeroportoDecolagem);
              printf("Aeroporto de pouso:\n");
              scanf("%s", vooReserva.aeroportoPouso);
              printf("Identificador de pista:\n");
              scanf("%d", &vooReserva.identificadorPista);
              InserirMVoo(&Principal, &vooReserva);
              printf("VID do voo cadastrado: %d\n", vooReserva.vid);
              break;

            case 3:
              printf("Digite o Vid do voo a ser removido: \n");
              scanf("%d", &vid);
              RemoverMVoo(&Principal, vid);
              break;

            case 4:
              printf("Digite o Vid do voo a ser pesquisado: \n");
              scanf("%d", &vid);
              ProcurarMVoo(&Principal, vid);
              break;

            case 5:
              printf("Digite a hora de decolagem: \n");
              scanf("%d:%d",&hrDecolagem, &minDecolagem);
              printf("Digite a hora de pouso: \n");
              scanf("%d:%d",&hrPouso, &minPouso);
              ImprimirVoo1(Principal, hrDecolagem, minDecolagem, hrPouso, minPouso);
              break;

            case 6:
              printf("Entre com o horário de decolagem: \n");
              scanf("%d:%d", &hrDecolagem, &minDecolagem);
              ImprimirVoo2(Principal, hrDecolagem, minDecolagem);
              break;

            case 7:
              printf("Entre com o horário de decolagem: \n");
              scanf("%d:%d", &hrDecolagem, &minDecolagem);
              ImprimirVoo2(Principal, hrDecolagem, minDecolagem);
              break;

            case 8:
              ImprimirMatriz(Principal);
              break;

            case 9:
              EncontrarMaiorHorario(&Principal);
              break;

            case 10:
              EncontrarMenorHorario(&Principal);
              break;

            case 11:
              EncontrarListaMaisRecente(&Principal);
              break;

            case 12:
              EncontrarListaMenosRecente(&Principal);
              break;

            case 13:
              MatrizEspaca(&Principal);
              break;

            case 19:
              printf("Você parou a execução do programa!\n\n");
              break;

            default:
              printf("Opção inválida\n");
          }
        }
      }
    }
  }
  return 0;
}
