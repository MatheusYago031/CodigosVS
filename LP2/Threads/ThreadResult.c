//cria N threads que sorteiam os numeros de um dado

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

pthread_mutex_t mutex;

void * rola_dado(){
    
    pthread_mutex_lock(&mutex);
    int value = (rand()%6)+1;
    int *Pvalue;
    Pvalue = malloc(sizeof Pvalue);
    *Pvalue = value;
    pthread_mutex_unlock(&mutex);

    return (void*) Pvalue;
    
}

int main(int argc, char* argv){
    srand(time(NULL));
    int N;
    int *res;
    pthread_t Th[N];
    pthread_mutex_init(&mutex,NULL);
    

    printf("Digite o Numero de Threads Desejadas....");
    scanf("%d",&N);

    for(int i = 0; i < N; i++){
        if(pthread_create(&Th[i],NULL,&rola_dado, NULL)!= 0){
            perror("Thread_CREATE");
            exit (EXIT_FAILURE);
        }
        printf("Thread[%d] INICIADA\n",i);
    }

    for( int i = 0; i < N; i++){
        
        if(pthread_join(Th[i],(void*) &res)!= 0 ){
            perror("Thread_JOIN");
            exit (EXIT_FAILURE);
        }
        printf("\nThread[%d] FINALIZADA\n",i);
        printf("RESULTADO[%d]\n\n",*res);
    }


    //printf("RESULTADO[%d]",*res);


    free(res);
pthread_mutex_destroy(&mutex);
exit (EXIT_SUCCESS);
}