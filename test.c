#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    printf("pid do test: %d\n",getpid());
    sleep(100);
    return 0;
}