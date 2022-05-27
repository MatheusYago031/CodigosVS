#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <time.h>

#define Tam_Palavra 6

char Palavra[Tam_Palavra];
pthread_barrier_t barrier;

int contador = 0;


void* checa_palindromo(char* str, int str_size){
    int i,j;
    printf("PALAVRA: %s \n",str);
    for(i=0,j=0;j=str_size-1,i<j;i++,j--){
        if(str[i] != str[j]){
            printf("NAO_PALINDROMO\n");
            return;
        }
    }
printf("PALINDROMO  ");
}


void*gera_letra(void *p){
    long idx=(long)p;
    while (contador<10)
    {
   Palavra[idx] = (rand()%26) + 'a';
   sleep(1);
   pthread_barrier_wait(&barrier);
    }

}


int main(void){
    srand(time(NULL));
    pthread_t th[Tam_Palavra];
    pthread_barrier_init(&barrier,NULL,Tam_Palavra+1);

    for(long i = 0; i < Tam_Palavra; i++){
        if(pthread_create(&th[i],NULL,gera_letra,(void*)i)!=0){
            perror("THREAD_CREATE");
        }
    }
    while (contador < 10)
    {
        pthread_barrier_wait(&barrier);

        checa_palindromo(Palavra,Tam_Palavra);
        
        contador++;
    }
    
     for(long i = 0; i < Tam_Palavra; i++){
        if(pthread_join(th[i],NULL)!=0){
            perror("THREAD_JOIN");
        }
    }

printf("%s\n",Palavra);
return 0;
}
