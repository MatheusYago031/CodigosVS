//criando processos, que vao representar numeros, que serao printados no terminal

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int main(int argc, char* argv[]){
    int n;
    int id = fork();


    if( id <0){
        return 1;
    }
    
    if (id==0)
    {
        n=1;
    }else
    {
        wait();
        n=11;
      
    }

    /*if (id!=0){
        wait();
    }*/
    int i;
    for(i = n; i < n+ 10; i++){
        printf("%d ",i);
        fflush(stdout);
    }
if (id!=0){
    printf("\n");
    return 0;
}
}