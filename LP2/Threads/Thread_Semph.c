#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

#define QTD_THREADS 4
sem_t semaphore;

void* routine(void* args){
    sem_wait(&semaphore);
    sleep(1);
    int index = *(int*)args;
    printf("HELLO FROM THREAD[%d]\n",index);
    sem_post(&semaphore);
    free(args);

}

int main( int argc, char* argv ){
    int i;
    pthread_t th[QTD_THREADS];
    sem_init(&semaphore, 0, 1);//o ultimo parametro determina quantas threads executarao ao mesmo tempo...
    //isso por que em semaforos, o segundo parametro é basicamente uma especie de marcação para o Wait, e só qndo chega no ultimo,ele printa ex::
    /*
               inicia     processa     executa
    threads      
        1         1   -1->   0     +1->    1   ->     (retorna para a proxima thread) 
        2         1   -1->   0     +1->    1   ->     (retorna para a proxima thread)
        3         1   -1->   0     +1->    1   ->     (retorna para a proxima thread)
        4         1   -1->   0     +1->    1   ->     (retorna para a proxima thread)
    -------------------No exemplo acima, apenas uma thread será executada por vez--------------------------
   
        Se o semaforo, tivesse um valor de execução de dois por exemplo, aconteceria assim:
 
                   inicia     processa     executa
    threads      
        1           2     -1 -> 1     +1->    1    
        2           2     -1 -> 0     +1->    2  ->     (retorna para a proxima thread)
        3           2     -1 -> 1     +1->    1   
        4           2     -1 -> 0     +1->    2   ->    (retorna para a proxima thread)

        ---------------Ou seja, a cada duas threads, sera feita os 3 processos, isso por que ao decrementar a primeira vez,
         ele "percebe" que ainda pode decrementar,ai a segunda thread 
         entra simultâneamente e decrementa também, até chegar em 0
        o processo de execução é o contrário, incrementa-se até chegar em 2-----------------------


        caso o valor fosse 3, ocorreria o mesmo processo em 3 threads simultâneas, e assim por diante.

    */

    for( i = 0; i < QTD_THREADS; i++){
        int *a = malloc(sizeof a);
        *a = i;
        if(pthread_create(&th[i],NULL,&routine,a) != 0){
            perror("THREAD_CREATE");
        }
    }

    for( i = 0; i < QTD_THREADS; i++){
        if(pthread_join(th[i],NULL) != 0){
            perror("THREAD_JOIN");
        }
    }

sem_destroy(&semaphore);
exit(EXIT_SUCCESS);
}