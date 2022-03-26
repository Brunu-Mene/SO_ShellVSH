#include "../include/Processos.h"
#include "../include/Util.h"


void criaProcessoForeground(char* comando){
    //Separa em um vetor de strings o comando e seus argumentos
    char **arrString = criaVetString(100);
    int tamArr = splitString(comando, arrString, " ");
    arrString[tamArr] = NULL;

    int pid1 = fork();

    if(pid1 == 0){
        //Executa o vetor de comando a partir da primeira string;
        int err = execvp(arrString[0], arrString);
        if(err < 0){
            exit(1);
        }
        exit(2);
    }
    else{
        //Esperando o termino do processo filho;
        waitpid(pid1, NULL, 0);
    }

    liberaVetorString(arrString, tamArr);
}

void criaProcessoBackground(char** listaComandos, int vetTam, Lista *listaProcessos){
    int pid1 = fork();

    if(pid1 == 0){
        destroiLista(listaProcessos);
        
        //cria uma session
        setsid();

        int pidN[5];
        int fd[vetTam-1][2];

        //abre os pipes
        for(int i = 0; i < vetTam - 1; i++){
            if(pipe(fd[i]) == -1)
                exit(1);
        }

        for(int i = 0; i < vetTam ; i++){
            //Separa em um vetor de strings o comando e seus argumentos
            char **arrString = criaVetString(100);
            int tamArr = splitString(listaComandos[i], arrString, " ");
            arrString[tamArr] = NULL;
            
            pidN[i] = fork();

            if(pidN[i] == 0){
                //fecha os pipes que nao serao usados
                for(int j = 0; j < vetTam - 1 ; j++){
                    if(j != i-1)
                        close(fd[j][0]);
                    else if(j != i)
                        close(fd[j][1]);
                }

                //redireciona a STDIN e STDOUT para os pipes
                if(i > 0)
                    dup2(fd[i-1][0],STDIN_FILENO);
                
                if(i < vetTam-1)
                    dup2(fd[i][1],STDOUT_FILENO);
                
                //executa o comando
                int err = execvp(arrString[0], arrString);
                if(err < 0){
                    liberaVetorString(arrString, tamArr);
                    exit(2);
                }
                liberaVetorString(arrString, tamArr);

                //fecha os pipes usados
                if(i != vetTam - 1)
                    close(fd[i][1]);
                if(i != 0)
                    close(fd[i-1][0]);
                
                exit(2);
            }
            liberaVetorString(arrString, tamArr);

        }
        //Espera o final dos processos da session e verifica caso tenham sido terminados por sinais SIGUSR1 ou SIGUSR2
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
    //Se o comando for armageddon ou liberamoita, entao e um processo interno
    if(strcmp(comando, "armageddon") == 0)
        return 1;
    
    else if(strcmp(comando, "liberamoita") == 0)
        return 1;
    
    return 0;
}

void processoInterno(char** listaComandos, Lista* listaProcessos){
    //Processo armageddon:
    if(strcmp(listaComandos[0], "armageddon") == 0){
        while(1){
            //Retira processo da lista de processos
            int pid = retiraPrimeiroLista(listaProcessos);
            if(pid == -1)
                break;

            //Verifica o status do processo
            int status;
            waitpid(pid,&status,WNOHANG);
            // Caso o processo nao tenha terminado ele mata o grupo de processos desse pai
            if(!WIFEXITED(status))
                killpg(pid, SIGKILL);
        
        }
    
        printf("ARMAGEDDON\n");
        destroiLista(listaProcessos);
        liberaVetorString(listaComandos, 1);
        exit(2);
    }
    
    //Processo liberamoita:
    else if(strcmp(listaComandos[0], "liberamoita") == 0){
        printf("Liberando as moitas . . . \n");
        //Percorre todos processos na lista de processos dando waitpid, caso tenha um zumbi a funcao ira termina-lo
        for(int i = 0; i < getTamanhoLista(listaProcessos); i++){
            int pid = retiraPrimeiroLista(listaProcessos);
            waitpid(pid, NULL, WNOHANG);
            // insere o processo novamente na lista de processos 
            insereLista(listaProcessos, pid);
        }
    }
}