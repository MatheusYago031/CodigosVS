#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define QTD_THREADS 5
pthread_mutex_t mutexfuel;
int fuel = 50;

void* routine(void* args){
    pthread_mutex_lock(&mutexfuel);
    pthread_mutex_lock(&mutexfuel);
    fuel += 50;
    printf("Incremented fuel to: [%d]\n",fuel);
    pthread_mutex_unlock(&mutexfuel);
    pthread_mutex_unlock(&mutexfuel);
}

int main( int argc, char* argv){
    int i;

    pthread_t th[QTD_THREADS];
    pthread_mutexattr_t RecursiveMutexAttributes;
    pthread_mutexattr_init(&RecursiveMutexAttributes);
    pthread_mutexattr_settype(&RecursiveMutexAttributes,PTHREAD_MUTEX_RECURSIVE);
    pthread_mutex_init(&mutexfuel,&RecursiveMutexAttributes);

    for( i = 0; i < QTD_THREADS; i++){
        if(pthread_create(&th[i],NULL,routine,NULL)!= 0){
            perror("THREAD_CREATE");
        }
    }

    for( i = 0; i < QTD_THREADS; i++){
        if(pthread_join(th[i],NULL)!= 0){
            perror("THREAD_JOIN");
        }
    }

    printf("Total fuel [%d]\n",fuel);
    pthread_mutex_destroy(&mutexfuel);
    pthread_mutexattr_destroy(&RecursiveMutexAttributes);


    exit(EXIT_SUCCESS);
}