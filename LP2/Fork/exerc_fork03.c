#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>


int main (int argc, char* argv[]){
    int id1 = fork();
    int id2 = fork();

            if(id1==0){
                if(id2==0){
                    printf("somos os processos filhos de id2\n");
                }else{
                    printf("somos os processos de id2\n");
                   
                }}else{
                    if(id2==0){
                     printf("somos os processos filhos de id1\n");
            }else{
                printf("somos os processos de id1.\n");
            }
 }
           
    while (wait(NULL)!= -1 || errno != ECHILD){
        printf("Esperando os filhos terminarem a execucao....\n");
    }
            
    return 0;
}

