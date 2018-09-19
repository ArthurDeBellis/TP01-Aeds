#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../Libs/ItemMatriz.h"
#include "../Libs/ListadeVoos.h"
#include "../Libs/MatrizVoos.h"
#include "../Libs/voo.h"

int main(){
    int modo,parada = 0, intOperador;
    char op;
    while(parada ==0){
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("Digite o modo desejado:\n");
        printf("1 = Interativo\n");
        printf("2 = Arquivo\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        scanf("%d", &modo);
        if(modo == 1 || modo ==2){
            parada++;
        }
    }
    if(modo ==1){
        do{
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("Selecione a operação que deseja fazer(digite em minúsculo):\n");
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
            scanf("%c", &op);
            op = toupper(op);
            intOperador = op - 64;
            switch (intOperador) {
                case 1:

                    break;
                case 2:

                    break;
                case 3:

                    break;
                case 4:

                    break;
                case 5:

                    break;
                case 6:

                    break;
                case 7:

                    break;
                case 8:

                    break;
                case 9:

                    break;
                case 10:

                    break;
                case 11:

                    break;
                case 12:

                    break;
                case 13:

                    break;





            }
        }while(op != 's');
    }



    return 0;
}
