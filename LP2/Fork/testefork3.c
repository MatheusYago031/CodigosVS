#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
int main(int argc,char *argv[]){
int id = fork();
if(id == 0){
    sleep(3);
}

printf("Processo atual: %d, Processo pai:%d\n",getpid(), getppid());


    wait(NULL);



int i;
return 0;



}