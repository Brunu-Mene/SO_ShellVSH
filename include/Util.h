#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/**
* @brief: Função que lê uma entrada passada no terminal
* @return: String com a entrada lida
*/
char *getEntrada();

/**
* @brief: Funcao que remove os espacos extras no comeco e fim de uma string
* @param str: Uma string
* @return: A string sem espacos extras
*/
char* trim(char* str);

/**
* @brief: Funcao que aloca na memoria um vetor de strings vazio
* @param tam: Inteiro com o tamanho a ser alocado
* @return: O vetor de strings alocado e vazio
*/
char **criaVetString(int tam);

/**
* @brief: Funcao para realizar a divisao de uma string em um conjunto de substrings separadas por um determinado caracter
* @param string: String com o conteudo a ser dividido
* @param vetString: Vetor de strings a ser preenchido pelas substrings resultantes da divisao
* @param cSplit: Ponteiro para um conjunto de caracteres a determinar a divisao
* @return: Inteiro com a quantidade de elementos criados a partir da divisao da string maior
*/
int splitString(char *string, char **vetString, char *cSplit);

/**
* @brief: Funcao para liberar da memoria um vetor de strings previamente alocado
* @param vetString: Ponteiro inicial para a sequencia de strings
* @param tam: Quantidade de strings pertencentes ao vetor
* @return: Nenhum
*/
void liberaVetorString(char **vetString, int tam);

#endif