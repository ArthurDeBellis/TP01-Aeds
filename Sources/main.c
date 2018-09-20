#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../Libs/ItemMatriz.h"
#include "../Libs/ListadeVoos.h"
#include "../Libs/MatrizVoos.h"
#include "../Libs/voo.h"

int main(){
    TipoMatriz Principal;
    TVoo vooReserva;
    int modo,parada = 0, intOperador = 0, vid, hrPouso, minPouso, hrDecolagem, minDecolagem;
    char op;
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("Digite o modo desejado:\n");
        printf("1 = Interativo\n");
        printf("2 = Arquivo\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        scanf("%d", &modo);
        if(modo == 1 || modo ==2){
            parada++;
    }
    if(modo ==1){
        while(intOperador != 19){
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("Selecione a operação que deseja fazer:\n");
            printf("a = Inicializar\n");
            printf("b = Inserir voo\n");
            printf("c = Remover voo\n");
            printf("d = Procurar voo\n");
            printf("e = Imprimir voos - entre com horários de decolagem e pouso\n");
            printf("f = Imprimir voos - entre apenas com o horário de decolagem\n");
            printf("g = Imprimir voos - entre apenas com o horário de pouso\n");
            printf("h = Imprimir todos os voos da matriz\n");
            printf("i = Encontrar faixa de horário mais movimentada\n");
            printf("j = Encontrar faixa de horário menos movimentada\n");
            printf("k = Encontrar a lista com atualização mais recente\n");
            printf("l = Encontrar a lista com atualização mais antiga\n");
            printf("m = Verificar se a matriz é esparça\n");
            printf("s = Sair\n");
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            scanf(" %c", &op);
            op = toupper(op);
            intOperador = op - 64;
            switch (intOperador) {
                case 1:
                    IniciaMatriz(&Principal);
                    printf("Matriz Inicializada\n");
                    break;
                case 2:
                    IniciaVoo(&vooReserva);
                    SetVid(&vooReserva);
                    printf("Horário de Decolagem:\n");
                    scanf("%d:%d", &vooReserva.horaDecolagem, &vooReserva.minutosDecolagem);
                    printf("Horário de Pouso:\n");
                    scanf("%d:%d", &vooReserva.horaPouso, &vooReserva.minutosPouso);
                    printf("Aeroporto de decolagem:\n");
                    scanf("%s", vooReserva.aeroportoDecolagem);
                    printf("Aeroporto de pouso:\n");
                    scanf("%s", vooReserva.aeroportoPouso);
                    printf("Identificador de pista:\n");
                    scanf("%d", &vooReserva.identificadorPista);
                    InserirMVoo(&Principal, &vooReserva);
                    printf("Voo cadastrado com o VID %d\n", vooReserva.vid);
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
                default:
                    printf("Opção inválida\n");
            }
        }
    }



    return 0;
}
