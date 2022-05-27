#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>


#define QTD_THREADS 10
pthread_barrier_t barrier;

void *routine(void* argc){
    while(1){
        printf("ESPERANDO NA BARREIRA\n");
        sleep(1);
        pthread_barrier_wait(&barrier);
        printf("PASSEI DA BARREIRA\n");
        sleep(1);
    }

}

int main(int argc, char* argv[]){
    int i;

    pthread_t th[QTD_THREADS];
    pthread_barrier_init(&barrier,NULL,7);

    for(i = 0; i < QTD_THREADS; i++){
         if(pthread_create(&th[i],NULL,&routine,NULL)!= 0){
             perror("THREAD_CREATE");
         }
    }

    for(i = 0; i < QTD_THREADS; i++){
        if(pthread_join(th[i],NULL)!= 0){
            perror("THREAD_JOIN");
        }
    }

pthread_barrier_destroy(&barrier);
exit(EXIT_SUCCESS);
}