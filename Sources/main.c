#include <stdio.h>
#include <stdlib.h>
#include "../Libs/ItemMatriz.h"
#include "../Libs/ListadeVoos.h"
#include "../Libs/MatrizVoos.h"
#include "../Libs/voo.h"

int main(){
    int modo, parada = 0;
    while(parada ==0){
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("Digite o modo desejado:\n");
        printf("1 = Interativo\n");
        printf("2 = Arquivo\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        scanf("%d", &modo);
        if(modo == 1 || modo ==2){
            parada++;
        }
    }
    if



    return 0;
}
