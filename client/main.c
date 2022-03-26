#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"
#include "Processos.h"
#include "Sinais.h"

int main(int argc, char **argv){
    Lista *listaProcessos = iniciaLista();

    setHandles();

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

