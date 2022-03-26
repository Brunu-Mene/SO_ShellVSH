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
    }else{
        waitpid(pid1, NULL, 0);
    }
    liberaVetorString(arrString, tamArr);
}

void criaProcessoBackground(char** listaComandos, int vetTam, Lista *listaProcessos){
    int pid1 = fork();

    if(pid1 == 0){
        destroiLista(listaProcessos);
        setsid();

        int pidN[5];
        int fd[vetTam-1][2];

        for(int i = 0; i < vetTam - 1; i++){
            if(pipe(fd[i]) == -1)
                exit(1);
        }

        for(int i = 0; i < vetTam ; i++){
            char **arrString = criaVetString(100);
            int tamArr = splitString(listaComandos[i], arrString, " ");
            arrString[tamArr] = NULL;
            
            pidN[i] = fork();

            if(pidN[i] == 0){
                for(int j = 0; j < vetTam - 1 ; j++){
                    if(j != i-1)
                        close(fd[j][0]);
                    else if(j != i)
                        close(fd[j][1]);
                }

                if(i > 0){
                    dup2(fd[i-1][0],STDIN_FILENO);
                }
                if(i < vetTam-1){
                    dup2(fd[i][1],STDOUT_FILENO);
                }

                int err = execvp(arrString[0], arrString);
                if(err < 0){
                    liberaVetorString(arrString, tamArr);
                    exit(2);
                }
                liberaVetorString(arrString, tamArr);

                close(fd[i][1]);
                if(i != 0)
                    close(fd[i-1][0]);
                
                exit(2);
            }
            liberaVetorString(arrString, tamArr);

        }
        int status;
        while(wait(&status) > 0){
            if(WIFSIGNALED(status)){
                if(WTERMSIG(status) == SIGUSR1 || WTERMSIG(status) == SIGUSR2){
                    killpg(getgid(), WTERMSIG(status));
                }
            }
        }
        exit(2);
    }

    else{
        insereLista(listaProcessos, pid1);
        usleep(200000);
    }
}

int verificaProcessoInterno(char *comando){
    if(strcmp(comando, "armageddon") == 0){
        return 1;
    }
    else if(strcmp(comando, "liberamoita") == 0){
        return 1;
    }
    return 0;
}

void processoInterno(char** comandos, Lista* listaProcessos){
    if(strcmp(comandos[0], "armageddon") == 0){
        while(1){

            int pid = retiraPrimeiroLista(listaProcessos);
            if(pid == -1)
                break;
        
            int status;
            waitpid(pid,&status, WNOHANG);
            if(!WIFEXITED(status))
                killpg(pid, SIGKILL);
        
        }
    
        printf("ARMAGEDDON\n");
        destroiLista(listaProcessos);
        liberaVetorString(comandos, 1);
        exit(2);
    }
    
    else if(strcmp(comandos[0], "liberamoita") == 0){
        printf("Liberando as moitas . . . \n");
        for(int i = 0; i < getTamanhoLista(listaProcessos); i++){
            int pid = retiraPrimeiroLista(listaProcessos);
            waitpid(pid, NULL, WNOHANG);  
            insereLista(listaProcessos, pid);
        }
    }
}