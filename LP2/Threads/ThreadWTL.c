//Pratical example with trylock
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
//chefs = threads
//stove = shared data


#define QTD_THREADS 10
int stove_fuel [4] = {100,100,100,100};
pthread_mutex_t   stove_Mutex[4];

void * routine(void *arg){
    for(int i = 0; i < 4; i++){
   
        if(pthread_mutex_trylock(&stove_Mutex[i]) == 0){
            int fuelNeeded = (rand()%30);
            

            if(stove_fuel[i] - fuelNeeded < 0) {
                printf("No more fuel...\n");
            }
                else{
                    stove_fuel[i] -= fuelNeeded;
                    usleep(50000);
                    printf("Fuel left [%d]\n",stove_fuel[i]);
                }



                pthread_mutex_unlock(&stove_Mutex[i]);
                break;
        }
           
           
            else{
                if (i == 3){   
                    printf("No stove available, waiting...\n");
                    usleep(300000);
                    i = 0;
                }
             }

    }
}



int main(int argc, char* argv[]){
    srand(time(NULL));


    for(int i = 0; i < 4 ; i++){
    pthread_mutex_init(&stove_Mutex[i],NULL);
    }


    pthread_t th[QTD_THREADS];


    for(int i = 0; i < QTD_THREADS; i++){
        if(pthread_create(&th[i],NULL,routine,NULL)!= 0){
            perror("THREAD_CREATE");
            exit(EXIT_FAILURE);
        }
    }



    for(int i = 0; i < QTD_THREADS; i++){
        if(pthread_join(th[i],NULL)!= 0){
            perror("THREAD_JOIN");
            exit(EXIT_FAILURE);
        }
    }



for(int i = 0; i < 4; i++){
pthread_mutex_destroy(&stove_Mutex[i]);
}

exit(EXIT_SUCCESS);
}
