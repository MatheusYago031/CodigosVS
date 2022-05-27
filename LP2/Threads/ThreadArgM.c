//tentativa sozinha de fazer

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define QTD_THREADS 5
int Primes [5] = {2,3,5,7,11};
pthread_mutex_t mutex;

void* routine ( void *arg){
    int i=0;
    int index= *(int*)arg;

   pthread_mutex_lock(&mutex);  
   
  // while (i< QTD_THREADS)

   //{  
        printf("Thread [%d]: [%d]\n\n",i,Primes[index]);
    
        i++;
   //}
    free(arg);

    pthread_mutex_unlock(&mutex);
}


int main(int argc, char* argv[]){
    int i;
    
    pthread_t Th[QTD_THREADS];
    pthread_mutex_init(&mutex,NULL);
    
    for(i = 0; i < QTD_THREADS; i++){
        int *a = malloc(sizeof a);
        *a = i;
        if(pthread_create(&Th[i],NULL,routine,a) != 0 ){
            perror("Thread_Create");
            exit(EXIT_FAILURE);
        };
    }


    for(i  = 0; i < QTD_THREADS; i++){
        if(pthread_join(Th[i],NULL)!= 0){
            perror("Thread_JOIN");
            exit(EXIT_FAILURE);
        }
    }


    pthread_mutex_destroy(&mutex);
    exit(EXIT_SUCCESS);
}