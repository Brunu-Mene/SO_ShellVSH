#include "../include/Sinais.h"

void setHandles(){
    signal(SIGTSTP,&ignoreSignal);
    signal(SIGINT,&ignoreSignal);
    signal(SIGQUIT,&ignoreSignal);
    signal(SIGUSR1,&handleSIGUSRVacine);
    signal(SIGUSR2,&handleSIGUSRVacine);
}

void ignoreSignal(int sig){
    switch(sig){
        case SIGINT:
            printf("\nO sinal de Ctrl^C nao funciona em mim, estou vacinado!\n");
            break;
        case SIGQUIT:
            printf("\nO sinal de Ctrl^\\ nao funciona em mim, estou vacinado!\n");
            break;
        case SIGTSTP:
            printf("\nO sinal de Ctrl^Z nao funciona em mim, estou vacinado!\n");
            break;
    }
}

void handleSIGUSRVacine(int sig){
    printf("         _  _    \n");
    printf("        (0)(0)-.  .-'^^'^^'^^'^^'^^'--.\n");
    printf("(.(.)----'`     ^^'               /^   ^^-._\n");
    printf("(     `               \\          |         ^^-.\n");
    printf("VvvvvvvVv~~__,/.._> /:/:/:/:/:/:/:/\\ (_..,______^^-.\n");
    printf(" `^^^^^^^^/  /    /   /^^^^^^^^^>^^>^>  >        _`)  )\n");
    printf("         (((`     (((`         (((` (((`        `'--'^\n");
    printf("I feel weird...\n");
}