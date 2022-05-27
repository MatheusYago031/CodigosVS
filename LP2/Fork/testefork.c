#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char*argv[]){
int id;
int valorPid=getpid();
    if (id<0){
        printf("erro, saindo...");
        exit;
    }
   
    if(valorPid=getpid){
        id=fork();

            if (id == 0 ){
                for (int i = 0; i < 10; i++)
                {
                    printf("Isso deve se repetir 10 vezes: %d\n",(i+1));
                     fflush(stdout);
                    }
                }


            if(id!=0){
            
                for(int i=0;i<3;i++){
                    wait();
                    printf("Hello world...\n");//teoricamente ele vai dar 3 hello world
                     fflush(stdout);
                }
            
                }


    return 0;
            }
}