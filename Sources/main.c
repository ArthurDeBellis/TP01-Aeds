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

  FILE *arq;
  //Declaração dos Tipos Abstratos de Dados (TADs).
  TipoMatriz Principal;
  TVoo vooReserva;

  //Declaração das variáveis básicas.
  int modo, vid, hrPouso, minPouso, hrDecolagem, minDecolagem;

  //Variáveis auxiliares para a interrupção dos whiles.
  int operadorAuxiliar = 1, modoAuxiliar = 1;

  //Caracteres que recebem as operações e confirmação de saída.
  char op, confirma;

  //Variáveis para receber o valor numérico dos caracteres setados.
  int intConfirma = 0, intOperador = 0;

  char nomeArquivo[50];

  printf("=================================================================\n");
  printf("|                      Seja Bem-vindo(a)!                       |\n");
  printf("=================================================================\n");
  printf("\n");

  while(modoAuxiliar != 0){
    menu_de_entradas();
    scanf(" %d", &modo);

    if(modo == 0){
      menu_de_confirmacao();
      /*
      O scanf a seguir identifica o caracter digitado pelo usuário e então
      usando a função toupper o caracter é convertido para maiúsculo, após
      este processo, ele é convertido para int e decrescido 64 unidades, o que
      no final faz com que todos sejam "iguais" a caracteres minúsculos.

      Ao fim é conferido se o intConfirma == 19, o que significaria que a pessoa
      digitou 'S' ou 's', indicando que ela realmente quer parar a execução
      do programa
      */
      scanf(" %c", &confirma);
      printf("\n");
      confirma = toupper(confirma);
      intConfirma = confirma - 64;

      if(intConfirma == 19){
        menu_de_saida();
        modoAuxiliar = 0;
      }
    }
    else if(modo ==1){
      /*
      Confirmando que o operadorAuxiliar = 1 antes de iniciar o programa, para
      caso o usuário alguma hora interrompa o modo interativo e queira retornar
      a usá-lo.
      */
      operadorAuxiliar = 1;

      printf("=================================================================\n");
      printf("                       MODO INTERATIVO\n");
      while(operadorAuxiliar != 0){
        menu_de_opcoes();
        /*
        O processo a seguir se assemelha muito ao já usado anteriormente, agora
        ele verifica cada um dos casos.

        a -> 1
        b -> 2
        .
        .
        .
        m -> 13
        E finalmente:
        s -> 19, que por fim indica que se deseja parar a execução do programa.
        */
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

            printf("Horário de Decolagem no formato HH:MM - ");
            scanf("%d:%d", &vooReserva.horaDecolagem, &vooReserva.minutosDecolagem);

            if(vooReserva.horaDecolagem > 23 || vooReserva.minutosDecolagem > 59){
              printf("Formato inválido!\n");
              break;
            }

            printf("Horário de Pouso no formato HH:MM - ");
            scanf("%d:%d", &vooReserva.horaPouso, &vooReserva.minutosPouso);

            if(vooReserva.horaPouso > 23 || vooReserva.minutosPouso > 59){
              printf("Formato inválido!\n");
              break;
            }

            printf("Aeroporto de decolagem: ");
            scanf("%s", vooReserva.aeroportoDecolagem);

            printf("Aeroporto de pouso: ");
            scanf("%s", vooReserva.aeroportoPouso);

            printf("Identificador da pista: ");
            scanf("%d", &vooReserva.identificadorPista);

            InserirMVoo(&Principal, &vooReserva);
            break;

          case 3:
            printf("Digite o Vid do voo a ser removido: ");
            scanf("%d", &vid);
            printf("\n");
            RemoverMVoo(&Principal, vid);
            break;

          case 4:
            printf("Digite o Vid do voo a ser pesquisado: ");
            scanf("%d", &vid);
            printf("\n");
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
            printf("Você parou a execução do programa!\n");
            /*
            Caso o usuário resolva para o programa, o operadorAuxiliar recebe
            0, o que condiz com a condição de parada do while, ao voltar o modo
            para 1, o operadorAuxiliar volta a valer 1, fazendo assim com que
            o programa volte ao modo interativo.
            */
            operadorAuxiliar = 0;
            break;

          default:
            //Caso o usuário coloque um uma opção inválida
            printf("Opção inválida\n");
            break;
        }
      }
    }
    else if(modo == 2){
      menu_arquivo();
      scanf("%s", nomeArquivo);
      printf("\n");
      arq = fopen(nomeArquivo, "r");
      if(!arq){
        printf("O arquivo digitado não foi encontrado.\n");
      }
      /*
      TODO a leitura do arquivo e procedimento das funções
      */
      fclose(arq);
    }
  }
  return 0;
}
