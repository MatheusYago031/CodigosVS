//comunicação entre processos utilizando pipes

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int argc, char* argv){
int fd[2];
// fd[0]== read
// fd[1]== write

    if(pipe(fd)==-1){
        printf("ERROR");
        return 1;
    }
    int id = fork();
    if(id<0){
        printf("ocorreu um erro");
        return 4;
    }

    if(id==0){
        int x;
        close (fd[0]);
        printf("Digite um número: ");
        scanf("%d",&x);
        if(write(fd[1], &x, sizeof(int))==-1){
            printf("Ocorreu um erro");
            return 2;
        } 
        close(fd[1]);
    }
    else{
        close (fd[1]);
        int y;
       if(read(fd[0],&y,sizeof(int))==-1){
           printf("Ocorreu um erro");
           return 3; 
       }
        y= y*10;
        close (fd[0]);
        printf("Número conseguido atraves do processo filho: %d\n",y);
     


    }




    return 0;
}