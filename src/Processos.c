#include "../include/Processos.h"
#include "../include/Util.h"


void criaProcessoForeground(char* comando){
    char **arrString = criaVetString(100);
    int tamArr = splitString(comando, arrString, " ");
    arrString[tamArr] = NULL;

    int pid1 = fork();

    if(pid1 == 0){
        int err = execvp(arrString[0], arrString);
        if(err < 0){
            waitpid(pid1, NULL, 0);
            exit(1);
        }
        exit(1);
    }
    waitpid(pid1, NULL, 0);
    liberaVetorString(arrString, tamArr);
}

void criaProcessoBackground(char** listaComandos, int vetTam){
    int pid1 = fork();

    if(pid1 == 0){
        setsid();

        int pidN[5];
        int fd[vetTam-1][2];

        for(int i = 0; i < vetTam - 1; i++){
            if(pipe(fd[i]) == -1)
                return 1;
        }

        for(int i = 0; i < vetTam ; i++){
            char **arrString = criaVetString(100);
            int tamArr = splitString(listaComandos[i], arrString, " ");
            arrString[tamArr] = NULL;
            
            pidN[i] = fork();

            if(pidN[i] == 0){
                
                int err = execvp(arrString[0], arrString);
                if(err < 0){
                    liberaVetorString(arrString, tamArr);
                    exit(1);
                }
                liberaVetorString(arrString, tamArr);
                exit(1);
            }
            liberaVetorString(arrString, tamArr);
        }

        exit(1);
    }
    waitpid(pid1, NULL, 0);
}

int processoInterno(char* comando){
    if(strcmp(comando, "armageddon") == 0){
        printf("armageddon\n");
        return 0;
    }
    else if(strcmp(comando, "liberamoita") == 0){
        printf("liberamoita\n");
        return 0;
    }

    return 1;
}