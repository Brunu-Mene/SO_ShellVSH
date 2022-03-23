#include "../include/Util.h"

char *getEntrada(){
    char in[500];
    scanf("%[^\n]",in);
    getchar();
    return strdup(in);
}

char **criaVetString(int tam){
    return malloc(sizeof(char *)*tam);
}

int splitString(char *string, char **vetString, char *cSplit){
    char *token = strtok(string, cSplit);
    int tamArr = 0;

    while(token != NULL){
        token = trim(token);
        vetString[tamArr] = strdup(token);
        tamArr++;
        token = strtok(NULL, cSplit);
    }
        
    return tamArr;
}

char* trim(char* str) {
    while (isspace(*str)) str++;
    
    char* end = str + strlen(str) - 1;
    while (end > str && isspace(*end)) end--;
    *(end+1) = '\0';

    return str;
}

void liberaVetorString(char **vetString, int tam){
    for(int i=0; i<tam ;i++)
        free(vetString[i]);
    
    free(vetString);
}