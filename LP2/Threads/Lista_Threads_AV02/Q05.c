#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include <string.h>
#include <time.h>

int buffer[10];
int count = 0;
int Num ;

#define QTD_THREADS 2
sem_t semEmpty;
sem_t semFULL;
pthread_mutex_t MutexBuffer;

void* producer(void* args)
{
    int i = 0;
    while(i < 100){
   
        //produce
        
        //sleep(1); por conta dos seméforos, podemos permitir a criação "descontrolada" de numeros randomicos, e mesmo assim só será printado 1 por vez
        sem_wait(&semEmpty);
        //add to buffer
       
        pthread_mutex_lock(&MutexBuffer);
            
            while(count < 10){
                int x = rand()%256;
                buffer[count] = x;
                printf("[PROD]: [%d]\n",x);
                count++;
                 i+=1;
             }
        pthread_mutex_unlock(&MutexBuffer);
        sem_post(&semFULL);
        
       }
}

void* consumer(void* args)
{   
    int i = 0;
    while(i < 100){//ira Consumir 100X 
   
        int y;
        //De forma semelhante, também não é mais preciso setar o valor de y
        
        sem_wait(&semFULL);
        //remove from the buffer
        
        pthread_mutex_lock(&MutexBuffer);
        
        // if(count > 0)como nosso sem_wait irá sempre checar se é maior que 0, não é mais necessário verificar o contador
           while (count > 0)
           {
                y = buffer[count - 1];
                printf("[CONS] Got [%d]\n",y);
                count --;
                i+=1;
                            }
           
           
          
       pthread_mutex_unlock(&MutexBuffer);
       sem_post(&semEmpty);
      //consuming
        
    }
}

int main(int argc, char* argv){
    int i;
    srand(time(NULL));
    pthread_t th[QTD_THREADS];
    pthread_mutex_init(&MutexBuffer,NULL);
    sem_init(&semEmpty,0,10);
    sem_init(&semFULL,0,0);

    for( i = 0; i < QTD_THREADS; i++ ){
        if(i % 2 == 0){
        
           if(pthread_create(&th[i],NULL,&producer,NULL)!=0){
                perror("THREAD_CREATE");
        
            }
           
            }else{
                    
                    if(pthread_create(&th[i],NULL,&consumer,NULL)!=0){
                         perror("THREAD_CREATE");            
                    
                    }
                 }
    }


    for( i = 0; i < QTD_THREADS; i++){
        if(pthread_join(th[i],NULL)){
            perror("THREAD_JOIN");
        }
    }

sem_destroy(&semEmpty);
sem_destroy(&semFULL);

pthread_mutex_destroy(&MutexBuffer);
exit(EXIT_SUCCESS);

}