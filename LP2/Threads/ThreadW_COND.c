//Pratical example with mutex_cond
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>


pthread_mutex_t mutex_fuel;

pthread_cond_t cond_fuel;
int fuel = 0;

void* fuel_filling(void *arg){
    for(int i = 0; i < 5; i++){
    pthread_mutex_lock(&mutex_fuel);
    fuel += 30;
    printf("Filled fuel... [%d]\n",fuel);
    pthread_mutex_unlock(&mutex_fuel);
    
   // pthread_cond_signal(&cond_fuel);apenas para 1 thread
    
    pthread_cond_broadcast(&cond_fuel);//manda o sinal para todas as threads que estão aguardando
    
    sleep(1);
    }
}

void* car(void *arg){
    pthread_mutex_lock(&mutex_fuel);
    while (fuel<40)
    {  
         printf("Isn't fuel enought\n");
         pthread_cond_wait(&cond_fuel,&mutex_fuel);
         //equivalent to: pthread_mutex_unlock(&mutex_fuel);
         //wait signal on cond_fuel
         //pthread_mutex_lock(&mutex_fuel);
    }
    
    fuel -= 40;
    printf("Got fuel. Now left [%d]\n",fuel);
    pthread_mutex_unlock(&mutex_fuel);
    
}



int main(int argc, char const *argv[])
{
    pthread_mutex_init(&mutex_fuel,NULL);

    pthread_cond_init(&cond_fuel,NULL);

    pthread_t th[6];
    
    
    for(int i =0 ; i < 6; i++){
        if(i == 4 || i == 5){
            if(pthread_create(&th[i],NULL,&fuel_filling,NULL)!=0){
                perror("THREAD_CREATE_ERRO");
                exit(EXIT_FAILURE);
            }
        }else{

            if(pthread_create(&th[i],NULL,&car,NULL)!=0){
                perror("THREAD_CREATE_ERRO");
                exit(EXIT_FAILURE);
              }    
        }
    }
    
    for(int i = 0; i < 6 ; i++){

            if (pthread_join(th[i],NULL)!=0)
            {
                perror("THREAD_JOIN_ERRO");
                exit(EXIT_FAILURE);
            }
            
    }

    
pthread_cond_destroy(&cond_fuel);
pthread_mutex_destroy(&mutex_fuel);

exit(EXIT_SUCCESS);
}
