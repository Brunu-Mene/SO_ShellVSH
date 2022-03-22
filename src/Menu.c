#include "../include/Menu.h"
#include "../include/Util.h"

void startShell(){
    printf("vsh> ");
    char* entrada = getEntrada();
    char* token = strtok(entrada, "|");

    int qtdIn = 0;
    char* arr[5];
    
    while(token != NULL){
        token = trim(token);
        arr[qtdIn] = token;
        printf("%s\n", arr[qtdIn]);
        qtdIn++;
        token = strtok(NULL, "|\n");
    }
    
    if(qtdIn == 1){
        system(arr[0]);
    }
    else{
        for(int i = 0; i < qtdIn; i++){
        }
    }

    free(entrada);
}