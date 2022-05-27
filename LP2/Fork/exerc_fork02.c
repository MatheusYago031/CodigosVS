#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char* argv){
int id = fork();
int n;

        if(id<0){
            printf("ERROR");
            return 1;
        }

        if(id==0){
            n=1;


        
        }else{

            n=201;
            wait();

        }

int i;

            for(i=n;i<n+200;i++){
                printf("%d  ",i);
                fflush(stdout);
            }





    return 0;
}