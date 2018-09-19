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
  int dia, mes, ano;
  int HoradaUltimaAtualizacao, MinutosUltimaAtualizacao;
}TipoMatriz;


//Criando as funções

void IniciaMatriz(TipoMatriz *Matriz); //Inicializa a estrutura de dados do TAD

void InserirVoo(TipoMatriz *Matriz, TVoo *voo); //Insere informações de um voo na matriz
void RemoverMVoo(TipoMatriz *Matriz, int vid); //Remove um voo a partir do indentificador de voo
void ProcurarVoo(TipoMatriz *Matriz, int vid); //Procura um voo a partir do identificador de voo
void ImprimirVoo1(TipoMatriz Matriz, int horaDecolagem, int minutosDecolagem, int horaPouso, int minutosPouso); // Imprimir voos a partir do horario de decolagem e horario de pouso previsto
void ImprimirVoo2(TipoMatriz Matriz, int horaDecolagem, int minutosDecolagem); // Imprimir voos a partir do horario de decolagem
void ImprimirVoo3(TipoMatriz Matriz, int horaPouso, int minutosPouso); // Imprimir voos a partir do horario de pouso
void ImprimirMatriz(TipoMatriz Matriz); // Imprimir todos os voos cadastrados na matriz

/*Encontrar faixa de horário de decolagem e previsão de pouso com maior número de voos cadastrados.
Mostra indices i e j da posição encontrada e quantidade de voos.*/

void EncontrarMaiorHorario(TipoMatriz *Matriz);

/*Encontrar faixa de horário de decolagem e previsão de pouso com menor número de voos cadastrados.
Mostra indices i e j da posição encontrada e quantidade de voos.*/

void EncontrarMenorHorario(TipoMatriz *Matriz);

//Encontrar lista de voos mais recentemente alterada. Mostra indices i e j da posição encontrada e horário da última alteração.

void EncontrarListaMaisRecente(TipoMatriz *Matriz);

//Encontrar lista de voos menos recentemente alterada. Mostra indices i e j da posição encontrada e horário da última alteração.

void EncontrarListaMenosRecente(TipoMatriz *Matriz);

void MatrizEspaca(TipoMatriz *Matriz); //Verificar se matriz é esparça

#endif
