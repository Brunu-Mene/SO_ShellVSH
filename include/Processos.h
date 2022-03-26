#ifndef PROCESSOS_H
#define PROCESSOS_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "Util.h"
#include "Lista.h"

/**
* @brief: Cria um processo em foreground para executar o comando passado
* @param comando: Ponteiro para uma string contendo processo a ser executado
* @return: Nenhum
*/
void criaProcessoForeground(char* comando);

/**
* @brief: Cria um processo em background que ira criar uma session onde serao criados processos para executar os comandos passados
* @param listaComandos: Vetor de strings carregando o comando a ser executado
* @param vetTam: Inteiro com a quantidade de comandos no vetor de comandos
* @param listaProcessos: Ponteiro para a lista de processos
* @return: Nenhum
*/
void criaProcessoBackground(char** listaComandos, int vetTam, Lista *listaProcessos);

/**
* @brief: Funcao para verificar se string passada como comando corresponde a um processo interno
* @param comando: String carregando o conteudo a ser verificado
* @return: Inteiro para indicar caso o processo seja interno
*/
int verificaProcessoInterno(char *comando);

/**
* @brief: Funcao para realizar a execucao de um processo interno do shell
* @param listaComandos: Vetor de strings carregando o comando a ser executado
* @param listaProcessos: Ponteiro para a lista de processos
* @return: Nenhum
*/
void processoInterno(char** listaComandos, Lista *listaProcessos);

#endif