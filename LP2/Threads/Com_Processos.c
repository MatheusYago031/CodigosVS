#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>



#define QTD_THREADS 5

int running =1;

sem_t garfos[QTD_THREADS];

int eat(long i){
    printf("[%ld] Comendo....\n",i);
    sleep ((int)i);
}

int think(long i){
    printf("[%ld] Pensando....\n",i);
    sleep ((int) i);
}


void* filosofo( void* p){
    long idx = (long)p;
    if(idx == 4){
         while (running)
        {   
            sem_wait(&garfos[0]);
            
            sem_wait(&garfos[QTD_THREADS-1]);
            
            eat(idx);
            
            sem_post(&garfos[0]);
            
            think(idx);
            
            sem_post(&garfos[QTD_THREADS-1]);
        }
        }else{
                while (running)
                 {
            
                    sem_wait(&garfos[idx]);
            
                    sem_wait(&garfos[idx +1]);
            
                    eat(idx);
            
                    sem_post(&garfos[idx]);
            
                    sem_post(&garfos[idx+1]);

                    think(idx);
                }
        }   
}





int main( int argc, char* argv[]){

        pthread_t th[QTD_THREADS];
       

        for(int i = 0; i < QTD_THREADS; i++){
        sem_init(&garfos[i],0,1);
        }


        for(long i = 0; i < QTD_THREADS; i++){
            pthread_create(&th[i],NULL,filosofo,(void*)i);
        }



        for(long i = 0; i < QTD_THREADS; i++){
            pthread_join(th[i],NULL);
        }

        for (int i = 0; i < QTD_THREADS; i++)
        {
            sem_destroy(&garfos[i]);
        }
        
}