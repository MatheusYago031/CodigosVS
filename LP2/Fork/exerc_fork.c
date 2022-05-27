/*Criando processos(pais e filhos) e exibindo seus "pids"*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>



int main(int argc, char* argv[]){
    int id;
    pid_t ProcessoPid = getpid();
    


        if(id<0){
            printf("ERRO, RETORNANDO");
           return 1; 
        }
        if(ProcessoPid=getpid()){
        id=fork();
        if(id==0){
            for (int i = 0; i <5 ; i++)
            {
                
                printf(" Pid do processo pai: %d\n \n Pid do processo filho: %d\n \n", getppid(),getpid());
                 fflush(stdout);
          
               
            }
       
        }
        }

    return 0;
}