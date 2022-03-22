#include "../include/Util.h"

char *getEntrada(){
    char in[500];
    scanf("%[^\n]",in);

    return strdup(in);
}


char* trim(char* str) {
    while (isspace(*str)) str++;
    
    char* end = str + strlen(str) - 1;
    while (end > str && isspace(*end)) end--;
    *(end+1) = '\0';

    return str;
}