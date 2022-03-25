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

void criaProcessoForeground(char* comando);

void criaProcessoBackground(char** listaComandos, int vetTam, Lista *listaProcessos);

int verificaProcessoInterno(char *comando);
void processoInterno(char** comandos, Lista *listaProcessos);

void armageddon(char** comandos, Lista* listaProcessos);

#endif