#include <stdio.h>
#include <semaphore.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define QTD_THREADS 6

float saldo_cliente = 0;

int number = 1;
int next = 1;
int turn[QTD_THREADS] = {0};

void *prod(void *param)
{
    long idx = (long)param;

    turn[idx] = __sync_fetch_and_add(&number, 1);

    while (turn[idx] != next) usleep(10321);

    int valor_op = rand() % 500;

    saldo_cliente += valor_op;

    puts("..");

    printf("[%ld] Saldo: %.2f\n", idx, saldo_cliente);
    sleep(1);

    next++;
}

int main(void)
{   
    srand(time(NULL));
    pthread_t threads[QTD_THREADS];

    for (long i = 0; i < QTD_THREADS; i++)
    {
        pthread_create(&threads[i], NULL, prod, (void *)i);
    }

    for (long i = 0; i < QTD_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }
}

