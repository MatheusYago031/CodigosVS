//Cria 2 threads, a primeira faz a soma do elemento 0 do array ate o elemento 4,
// A segunda faz a soma do elemento 5 ate o 9


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define QTD_THREADS 2
pthread_mutex_t mutex;
int primes[10] = {2,3,5,7,11,13,17,19,23,29};



void* routine(void *arg){
int index =  *(int*)arg;
int sum = 0;

for(int i = 0; i <= 5; i++){    
pthread_mutex_lock(&mutex);
sum += primes[index +i];
pthread_mutex_unlock(&mutex);
}
printf("Local sum = [%d]    ",sum);

*(int*)arg = sum;
return arg;    //assim conseguimos retornar o valor da soma
}



int main(int argc,char* argv[]){
    pthread_t th[QTD_THREADS];
    pthread_mutex_init(&mutex,NULL);
    long i;

    //-------------------Thread Create-------------------
    for(i = 0; i < QTD_THREADS; i++){
        int *a = malloc(sizeof a);
        *a= i * 5;
        if(pthread_create(&th[i],NULL,routine,a)!= 0){
            perror("Thread_CREATE_ERRO");
            exit(EXIT_FAILURE);
        }
    }

    //===================Thread Join=====================
    int GLOBAL_SUM = 0;
    for(i =  0; i< QTD_THREADS; i++){
        int* r;//ponteiro para o valor retornado
        if(pthread_join(th[i],(void**)&r)!= 0){
            perror("Thread_JOIN_ERROR");
            exit(EXIT_FAILURE);
        }
        GLOBAL_SUM += *r;
        free(r);
    }

pthread_mutex_destroy(&mutex);
printf("GLOBAL_SUM = [%d]    ",GLOBAL_SUM);
exit(EXIT_SUCCESS);
}
