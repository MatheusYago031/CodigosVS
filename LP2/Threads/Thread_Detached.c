#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void * routine(void* args){
    printf("Finished execution\n");
}

int main(int argc,char* argv []){
    pthread_t th [2];
    pthread_attr_t detachedThread; //cria uma thread que está desvinculada da thread principal
    pthread_attr_init(&detachedThread);
    pthread_attr_setdetachstate(&detachedThread,PTHREAD_CREATE_DETACHED);//o segundo parametro nos diz como sera setado o estado da thread, no caso desvinculada,
    //mas também pode ser joinable

    for(int i = 0; i < 2; i++){
        if(pthread_create(&th[i],&detachedThread,&routine,NULL)!=0){
            perror("THREAD_CREATE");
        }
    }
//como ela está desvinculada, não é necessário o join

    pthread_attr_destroy(&detachedThread);//tudo que se cria,é necessario destruir
    pthread_exit(0);
}