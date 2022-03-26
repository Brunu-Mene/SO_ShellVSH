#include "../include/Sinais.h"

void setHandles(){
    signal(SIGTSTP,&ignoreSignalHandler);
    signal(SIGINT, &ignoreSignalHandler);
    signal(SIGQUIT,&ignoreSignalHandler);

    signal(SIGUSR1,&SIGUSRVacineHandler);
    signal(SIGUSR2,&SIGUSRVacineHandler);
}

void ignoreSignalHandler(int sig){
    switch(sig){
        case SIGINT:
            printf("\nO sinal de Ctrl^C nao funciona em mim, estou vacinado\n");
            break;

        case SIGQUIT:
            printf("\nO sinal de Ctrl^\\ nao funciona em mim, estou vacinado\n");
            break;

        case SIGTSTP:
            printf("\nO sinal de Ctrl^Z nao funciona em mim, estou vacinado\n");
            break;
    }
}

void SIGUSRVacineHandler(int sig){
    printf("         _  _    \n");
    printf("        (0)(0)-.  .-'^^'^^'^^'^^'^^'--.\n");
    printf("(.(.)----'`     ^^'               /^   ^^-._\n");
    printf("(     `               \\          |         ^^-.\n");
    printf("VvvvvvvVv~~__,/.._> /:/:/:/:/:/:/:/\\ (_..,______^^-.\n");
    printf(" `^^^^^^^^/  /    /   /^^^^^^^^^>^^>^>  >        _`)  )\n");
    printf("         (((`     (((`         (((` (((`        `'--'^\n");
    printf("I feel weird...\n");
}