#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define QTD_THREADS 10
pthread_mutex_t mutex;


int Primes [10] = {2,3,5,7,11,13,17,19,23,29};//está sendo apontado por arg de routine

void* Routine(void* arg){//recebe os valores de Primes
    int index = *(int*)arg;
pthread_mutex_lock(&mutex);

    printf("%d\n",Primes[index]);
    free(arg);//ponteiro para i, ao qual "a" está recebendo seus valores

pthread_mutex_unlock(&mutex);


}


int main(int argc, char* argv[]){//recebe os valores de Prime, qur está sendo apontado por arg
 
int i;
pthread_t Th[QTD_THREADS];
pthread_mutex_init(&mutex, NULL);

for(i = 0; i < QTD_THREADS; i++){
    int *a = malloc(sizeof a);
        *a = i;
    if(pthread_create(&Th[i],NULL,Routine,a) != 0){//a vai apontar receber os elementos de cada posição na memoria da funcao Routine, que no caso está recebendo Primes atraves de *arg
       
        perror("Thread_CREATE");
        exit(EXIT_FAILURE);
    }
}


for(i = 0; i < QTD_THREADS; i++){
    if(  pthread_join(Th[i],NULL) != 0){
        perror("Thread_JOIN");
        exit(EXIT_FAILURE);
    };
    
}




pthread_mutex_destroy(&mutex);

exit(EXIT_SUCCESS);
}