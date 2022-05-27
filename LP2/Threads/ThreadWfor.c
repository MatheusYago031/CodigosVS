//cria N threads utilizando laço de repetição
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex;
int mails = 0;

void* rotine(){
for(int i = 0; i < 100000000; i++){

pthread_mutex_lock(&mutex);
mails++;
pthread_mutex_unlock(&mutex);

    }
}


int main(int argc, char * argv[]){
    int N;

    pthread_t t[N];

    printf("Digite o valor de N: ");
    scanf("%d",&N);
    pthread_mutex_init(&mutex, NULL);
    
    for(int i = 0; i < N; i++){
    if(pthread_create(&t[i],NULL,rotine,NULL)!= 0){
        printf("thread_create_t%d",i);
        exit(EXIT_FAILURE);
        }
        printf("Thread %d foi criada\n",i);
    }

    for(int i = 0; i < N ; i++){
    if(pthread_join(t[i],NULL)!=0){
        printf("thread_join_t%d",i);
        exit(EXIT_FAILURE);
    }
    printf("Thread %d terminou sua execucao\n",i);
    }

    pthread_mutex_destroy(&mutex);

    printf("Number of mails: %d\n",mails);
    exit(EXIT_SUCCESS); 
}