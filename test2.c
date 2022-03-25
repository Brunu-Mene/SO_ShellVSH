#include <stdio.h>
#include <unistd.h>

int main(){
    char buffer[1000];
    read(STDIN_FILENO, buffer, 1000);
    printf("%s\n",buffer);
    return 0;
}