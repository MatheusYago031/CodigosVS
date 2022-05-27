//A barrier init, diferentemente de cond e de mutex,possui um terceiro parâmetro, este seria a quantidade de threads que deve-se esperar, 
//se por algum acaso a quantidade de thread for menor que o esperado, o programa nunca irá parar a execução,pelo fato de nunca chegar ao "final"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

#define QTD_THREADS 10
pthread_barrier_t barrier;


void* routine(void* args){
    while (1)
    {
        
        printf("Esperando na barreira....\n");
        sleep(1);
        pthread_barrier_wait(&barrier);
   
        printf("Passamos da barreira\n");
        sleep(1);
    }
}

int main(int argc, char* argv[]){
    int i;
    pthread_t th [QTD_THREADS];
    pthread_barrier_init(&barrier, NULL, 10);

    for( i  = 0; i < QTD_THREADS; i++){
        if(pthread_create(&th[i],NULL,&routine,NULL) != 0){
            perror("THREAD_CREATE");
            exit(EXIT_FAILURE);
        }
    }

    for( i  = 0; i < QTD_THREADS; i++){
        if(pthread_join(th[i],NULL) != 0){
            perror("THREAD_JOIN");
            exit(EXIT_FAILURE);
        }

    }

pthread_barrier_destroy(&barrier);
    
exit(EXIT_SUCCESS);
}
