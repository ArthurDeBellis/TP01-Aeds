#ifndef MATRIZVOOS_H
#define MATRIZVOOS_H

#include "ItemMatriz.h"

/*--------------------------------------------------------------------------------------*/
                                       //Funções
/*--------------------------------------------------------------------------------------*/

void IniciaMatriz(TipoMatriz *Matriz); //Inicializa a estrutura de dados do TAD
void AtualizaMatriz(TipoMatriz *Matriz);//Salva a hora e data da última atualização na matriz
void InserirMVoo(TipoMatriz *Matriz, TVoo *voo); //Insere informações de um voo na matriz
void RemoverMVoo(TipoMatriz *Matriz, int vid); //Remove um voo a partir do indentificador de voo
int ProcurarMVoo(TipoMatriz *Matriz, int vid); //Procura um voo a partir do identificador de voo
void ImprimirVooHrDecolagemHrPouso(TipoMatriz Matriz, int horaDecolagem, int minutosDecolagem, int horaPouso, int minutosPouso); // Imprimir voos a partir do horario de decolagem e horario de pouso previsto
void ImprimirVooHrDecolagem(TipoMatriz Matriz, int horaDecolagem, int minutosDecolagem); // Imprimir voos a partir do horario de decolagem
void ImprimirVooHrPouso(TipoMatriz Matriz, int horaPouso, int minutosPouso); // Imprimir voos a partir do horario de pouso
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
//Verificar se matriz é esparça
void MatrizEsparca(TipoMatriz *Matriz);

#endif
