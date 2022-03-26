#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"
#include "Processos.h"
#include "Sinais.h"

int main(int argc, char **argv){
    // Lista do pid dos processos que criam as sessions dos processos em background
    Lista *listaProcessos = iniciaLista();

    setHandles();

    while(1){
        printf("vsh> ");

        //Le uma linha digitada no vsh
        char* entrada = getEntrada();

        //Separa cada comando passado na linha em um vetor de strings
        char **vetString = criaVetString(5);
        int vetTam = splitString(entrada, vetString, "|");
        free(entrada);

        //Se um unico comando foi passado na linha
        if(vetTam == 1){
            //Se for um processo interno (armageddon ou liberamoita)
            if(verificaProcessoInterno(vetString[0])){
                processoInterno(vetString,listaProcessos);
            }
            
            else{
                criaProcessoForeground(vetString[0]);
            }
        }

        //Se mais de um processo foi passado na mesma linha
        else{
            criaProcessoBackground(vetString, vetTam, listaProcessos);
        }
        
        liberaVetorString(vetString, vetTam);
    }

    return 0;
}

