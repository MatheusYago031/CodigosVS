#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/syscall.h>


#define QTD_THREADS 2

void * routine(void* args){

    pthread_t th = pthread_self();
    printf("%ul\n",th);//printa o valor de identificação das threads que foram atribuidos por pthread_t
    printf("%d\n",(pid_t) syscall(SYS_gettid));//printa o pid das threads, atribuidos pelo sistema
    //gettid so pode ser usado no linux.
}

int main(int argv,char* argc[]){
    int i;
    pthread_t th[QTD_THREADS];

    for(i = 0; i < QTD_THREADS; i++){
        if(pthread_create(&th[i],NULL,routine,NULL)!= 0){
            perror("THREAD_CREATE");
        }
    }
    for(i = 0; i < QTD_THREADS; i++){
        if(pthread_join(th[i],NULL)!= 0){
            perror("THREAD_JOIN");
        }
    }

exit(EXIT_SUCCESS);
}