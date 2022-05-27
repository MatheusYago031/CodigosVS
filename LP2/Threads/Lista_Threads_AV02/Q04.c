/*Faça um programa em C/C++ onde 6 threads (além da principal) gerarão uma letra aleatória (caractere) cada. 
Estas letras deverão ser combinadas em uma palavra (uma string) na thread principal (função  main), que deverá exibi-la e também determinar se esta é um palíndromo ou não. 
Palíndromos são frases ou palavras quepodem ser lidas, indiferentemente,da esquerda para a direita, conforme o sentido habitual da leitura, ou da direitapara a esquerda, 
sem que haja mudança da sua significação (exemplos de palíndromos com 6 letras: “AAAAAA”,“ABAABA”, “ABCCBA”, “MUSSUM”). 
Repita este processo 10 vezes e use barreiras para sincronizar as threads.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

#define TAM_PALAVRAS 6

char palavra[TAM_PALAVRAS];
pthread_barrier_t barreira;

int contador;

void *checa_palindromo(char *str, int str_size){
    int i, j;
    printf("PALAVRA: %s\n", str);
    for( i = 0, j =str_size-1; i < j;i++,j--){
        if(str[i]  !=  str[j]){
            printf("NAO_PALINDROMO\n");
            return ;
        }
    }
    printf("PALINDROMO");
}

void* gera_letra(void *p){
    long idx = (long)p;

    while (contador < 10)
    {
        palavra[idx] = (rand()%26) + 'a';
        sleep(1);
        pthread_barrier_wait(&barreira);
    }
    
}


int main(void){
    pthread_t threads[TAM_PALAVRAS];

    pthread_barrier_init(&barreira,NULL, TAM_PALAVRAS +1);

    for(long i = 0; i < TAM_PALAVRAS; i++){
        pthread_create(&threads[i],NULL,gera_letra, (void*)i);
    }

    while(contador<10){
        pthread_barrier_wait(&barreira);
        checa_palindromo(palavra,TAM_PALAVRAS);
        contador++;
    }

    for (int i = 0; i < TAM_PALAVRAS; i++){
        pthread_join(threads[i],NULL);
    }

    printf("%s\n",palavra);
    return 0;
}