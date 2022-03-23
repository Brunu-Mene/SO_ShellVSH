#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char *getEntrada();
char* trim(char* str);
char **criaVetString(int tam);
int splitString(char *string, char **vetString, char *cSplit);
void liberaVetorString(char **vetString, int tam);

#endif