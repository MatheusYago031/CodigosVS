//Criará 8 threads, cada uma sorteará um numero nos dados, nos dirá quem venceu, no caso, quem sorteou um numero maior
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

#define QTD_THREADS 8

pthread_barrier_t barrier_dice_rolled;//vai servir para fazer com que o programa espere até que todas as threads sorteiem um "dado"
pthread_barrier_t calculate_winner;//para garantir que so ira mudar o status apos tudo ser executado

int DICE_VALUES[QTD_THREADS];
int status[QTD_THREADS] = {0};//basicamente é quem diz quem é o vencedor



void* rolling(void* args){

int index = *(int*)args;
    while (1)
    {
        DICE_VALUES[index] = (rand() % 6)+1;

        pthread_barrier_wait(&barrier_dice_rolled);
        pthread_barrier_wait(&calculate_winner);
        
        if(status[index] == 1){
            printf ("(%d rolled %d)I WON\n",index,DICE_VALUES[index]);
        }else{
            printf ("(%d rolled %d)I LOST\n",index,DICE_VALUES[index]);
            }
    }
free(args);
}

int main(int argc, char* argv[]){
    
    srand(time(NULL));

    int i;
    
    pthread_t th[QTD_THREADS];
    pthread_barrier_init(&barrier_dice_rolled, NULL, QTD_THREADS + 1);
    pthread_barrier_init(&calculate_winner,NULL,QTD_THREADS + 1);

    for( i = 0; i < QTD_THREADS; i++ ){
        int *a = malloc(sizeof a);
        *a = i;
        
        if(pthread_create(&th[i],NULL,&rolling,a)!= 0){
            perror("THREAD_CREATE");
        }
    }

    while(1){
        int max = 0;
        pthread_barrier_wait(&barrier_dice_rolled);
        for( i = 0; i < QTD_THREADS; i++ ){
            if(DICE_VALUES[i] > max){
                max = DICE_VALUES[i];
             }
        }
        
        for( i = 0; i < QTD_THREADS; i++ ){
            if(DICE_VALUES[i] == max){
                status[i] = 1;
            }else{
            status[i] = 0;
                }
        }
        sleep(1);
        printf("-----NEW ROUND-----\n");
        pthread_barrier_wait(&calculate_winner);    
    }


    for( i = 0; i < QTD_THREADS; i++ ){
        if(pthread_join(th[i],NULL) != 0 ){
            perror("THREAD_JOIN");
        }
    }


pthread_barrier_destroy(&barrier_dice_rolled);
pthread_barrier_destroy(&calculate_winner);
exit(EXIT_SUCCESS);
}