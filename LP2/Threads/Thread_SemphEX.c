#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <semaphore.h>

#define QTD_THREADS 16
sem_t semaphore;

void* routine(void* args){
    int index = *(int*)args;
    printf("[%d] Waiting in a queue...\n",index);
    
    sem_wait(&semaphore);
    
    
    printf("[%d] Logged in\n",index);
    sleep((rand()%5) +1);
    printf("[%d] Logged out\n",index);
    
    
    sem_post(&semaphore);
    free(args);
}


int main(int argc, char* argv[]){
    int i;
    pthread_t th[QTD_THREADS];
    sem_init(&semaphore,0,12);
        for(i = 0; i < QTD_THREADS; i++){
            int *a = malloc(sizeof a);
            *a = i;
            if(pthread_create(&th[i],NULL,&routine,a)!=0){
                perror("THREAD_CREATE");
            }
        }

        for(i = 0; i< QTD_THREADS; i++){
            if(pthread_join(th[i],NULL)!= 0){
                perror("THREAD_JOIN");
            }
        }

    sem_destroy(&semaphore);
    exit(EXIT_SUCCESS);
}