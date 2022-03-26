#ifndef SINAIS_H
#define SINAIS_H

#include <stdio.h>
#include <signal.h>

void setHandles();
void ignoreSignal(int sig);
void handleSIGUSRVacine(int sig);

#endif