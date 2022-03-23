#include "../include/Menu.h"
#include "../include/Util.h"
#include "../include/Processos.h"

void startShell(){
    printf("vsh> ");
    char* entrada = getEntrada();

    char **vetString = criaVetString(5);
    int vetTam = splitString(entrada,vetString,"|");
    
    if(vetTam == 1){
        if(processoInterno(vetString[0]))
            criaProcessoForeground(vetString[0]);
    }
    else{
        criaProcessoBackground(vetString, vetTam);
    }

    free(entrada);
    liberaVetorString(vetString, vetTam);
}