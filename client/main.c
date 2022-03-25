#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"
#include "Processos.h"

void handleSignals(int sig){
    printf("Signal ignored %d\n",sig);
}

void handleSIGUSRpai(int sig){
    printf("         _  _    \n");
    printf("        (0)(0)-.  .-'^^'^^'^^'^^'^^'--.\n");
    printf("(.(.)----'        ^^'             /^   ^^-._\n");
    printf("(                     \\          |         ^^-.\n");
    printf("VvvvvvvVv~~__,/.._> /:/:/:/:/:/:/:/\\ (_..,______^^-.\n");
    printf("  ^^^^^^^^/  /    /   /^^^^^^^^^>^^>^>  >          _) )\n");
    printf("            (((    (((           (((  (((         `'--'^\n");
    printf("I feel weird...\n");
}

int main(int argc, char **argv){
    Lista *listaProcessos = iniciaLista();

    signal(SIGTSTP, &handleSignals);
    signal(SIGINT, &handleSignals);
    signal(SIGQUIT, &handleSignals);
    //trata o sinal se enviar SIGUSR para o terminal
    signal(SIGUSR1,&handleSIGUSRpai);
    signal(SIGUSR2,&handleSIGUSRpai);

    while(1){
        printf("vsh> ");
        char* entrada = getEntrada();

        char **vetString = criaVetString(5);
        int vetTam = splitString(entrada,vetString,"|");
        free(entrada);

        if(vetTam == 1){
            if(verificaProcessoInterno(vetString[0])){
                processoInterno(vetString,listaProcessos);
            }
            else{
                criaProcessoForeground(vetString[0]);
            }
        }
        else{
            criaProcessoBackground(vetString, vetTam, listaProcessos);
        }
        
        liberaVetorString(vetString, vetTam);
    }

    return 0;
}

