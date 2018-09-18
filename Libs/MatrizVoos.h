#include "../Libs/voo.h"
#include "../Libs/ListadeVoos.h"
#include "../Libs/ItemMatriz.h"

#ifndef MATRIZVOOS_H
#define MATRIZVOOS_H

//Criando a struct do tipo matriz

/*typedef struct
{
  ItemMatriz Item;
  TVoo Voo;
}TMatriz;
*/
typedef struct
{
  ItemMatriz Matriz[24][24];
  int TotalDeVoos;
  int Data;
  int HoradaUltimaAtualizaao;
}TipoMatriz;


//Criando as funções

void Inicializar(ItemMatriz *Matriz); //Inicializa a estrutura de dados do TAD
void InserirVoo(ItemMatriz *Matriz, int vid, int horaDecolagem, int minutosDecolagem, int horaPouso, int minutosPouso, char* aeroportoDecolagem, char* aeroportoPouso, int identificadorPista); //Insere informações de um voo na matriz
void RemoverVoo(ItemMatriz *Matriz, int vid); //Remove um voo a partir do indentificador de voo
void ProcurarVoo(ItemMatriz *Matriz, int vid); //Procura um voo a partir do identificador de voo
void ImprimirVoo1(ItemMatriz Matriz, int horaDecolagem, int minutosDecolagem, int horaPouso, int minutosPouso); // Imprimir voos a partir do horario de decolagem e horario de pouso previsto
void ImprimirVoo2(ItemMatriz Matriz, int horaDecolagem, int minutosDecolagem); // Imprimir voos a partir do horario de decolagem
void ImprimirVoo3(ItemMatriz Matriz, int horaPouso, int minutosPouso); // Imprimir voos a partir do horario de pouso
void ImprimirMatriz(ItemMatriz Matriz); // Imprimir todos os voos cadastrados na matriz
/*Encontrar faixa de horário de decolagem e previsão de pouso com maior número de voos cadastrados.
Mostra indices i e j da posição encontrada e quantidade de voos.*/
void EncontrarMaiorHorario(ItemMatriz Matriz);
/*Encontrar faixa de horário de decolagem e previsão de pouso com menor número de voos cadastrados.
Mostra indices i e j da posição encontrada e quantidade de voos.*/
void EncontrarMenorHorario(ItemMatriz Matriz);
//Encontrar lista de voos mais recentemente alterada. Mostra indices i e j da posição encontrada e horário da última alteração.
void EncontrarListaMaisRecente(ItemMatriz Matriz);
//Encontrar lista de voos menos recentemente alterada. Mostra indices i e j da posição encontrada e horário da última alteração.
void EncontrarListaMenosRecente(ItemMatriz Matriz);
void MatrizEspaca(ItemMatriz Matriz); //Verificar se matriz é esparça

#endif
