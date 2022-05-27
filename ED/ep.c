#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/wait.h>
#include <sys/types.h>


int main (int argc, char **argv) {
    int lebres;
    
    if (argc != 4) {
        printf("Modo de uso: ./main.out -p|-t numero_lebres tamanho_pista\n");
        exit(EXIT_FAILURE);
    }

    char *option = argv[1];
    char *c_numero_lebres = argv[2];
    char *c_tamanho_pista = argv[3];

    int numero_lebres = 0;
    sscanf(c_numero_lebres, "%d", &numero_lebres);
    printf("Numero lebres: %d\n", numero_lebres);

    int tamanho_pista = 0;
    sscanf(c_tamanho_pista, "%d", &tamanho_pista);
    printf("Tamanho pista: %d\n", tamanho_pista);

    // mais coisa

for (int i = 0; i < numero_lebres;i++){

    lebres = fork();



}

    exit(EXIT_SUCCESS);

}