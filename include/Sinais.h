#ifndef SINAIS_H
#define SINAIS_H

#include <stdio.h>
#include <signal.h>

/**
* @brief: associa os sinais as suas determinadas funcoes handler
* @return: Nenhum
*/
void setHandles();

/**
* @brief: handler para sinais que devem ser ignorados
* @param sig: O sinal recebido
* @return: Nenhum
*/
void ignoreSignalHandler(int sig);

/**
* @brief: handler para SIGUSR1 e SIGUSR2 quando vacinado
* @param sig: O sinal recebido
* @return: Nenhum
*/
void SIGUSRVacineHandler(int sig);

#endif