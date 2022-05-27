/*UNIVERSIDADE FEDERAL DA PARAÍBA – CENTRO DE INFORMÁTICA
LPII - Programação Concorrente - 2021.2
Prof. Carlos Eduardo Batista
Pontuação: vale 3,0 pontos 

* Entrega por e-mail (bidu @ ci ufpb br). 

* Horário limite: 09h59 de 25/04/2022.

* O   título   do   e-mail   deve   conter:   
“[LPII-20211-E002]   NOME   DO  ALUNO   –   MATRICULA”. 

* Arquivo de entrega deve anexar todos os códigos fonte em C/C++ dentro de um 
diretório nomeado “MATRICULA_ALUNO-LPII-20211-E001” o  qual   deve   ser 
comprimido   em   um   arquivo   ZIP (“MATRICULA_ALUNO-LPII-20211-E001”).

* O arquivo ZIP deve conter obrigatoriamente um arquivo   de   texto   chamado
README.txt contemplando   todas   as   instruções   de   compilação e execução,
além de qualquer observação que se fizer necessária para correção. 

* O NÃO ATENDIMENTO ÀS INSTRUÇÕES ACIMA IMPLICARÁ NA NÃO CORREÇÃO DO EXERCÍCIO

* TRABALHO INDIVIDUAL - plágio será punido com a não correção do exercício.

-------------------------------------------------------------------------------

Faça um programa em C/C++ que simula uma corrida de lebres, usando threads e 
processos. O programa deverá receber 3 parâmetros na sua execução: 
- se usará processos ou threads; 
- quantas instâncias (lebres) serão criadas para a corrida;
- e um valor inteiro, que representa o tamanho da pista da corrida em metros.

Exemplo de execução:

	$ ./corrida -t 5 1000 (5 lebres/threads, pista de 1000m)
	lebre 0 saltou 30cm (total: 30)
	lebre 2 saltou 42cm (total: 42)
	...
	lebre 2 saltou 31cm (total: 1002)
	lebre 2 venceu! 

	$ ./corrida -p 10 500 (10 lebres/processos, pista de 500m)
	lebre 1 saltou 20cm (total: 20)
	lebre 0 saltou 43cm (total: 43)
	...
	lebre 3 saltou 44cm (total: 520)
	lebre 3 venceu!

Os processos / threads executarão a função que representa as lebres nessa 
corrida fictícia; a função que receberá dois parâmetros: um valor inteiro que
identifique a lebre (seu índice) e um valor inteiro que represente a distância
máxima do salto dessa lebre em cm. A função então simulará a corrida de uma 
lebre através de um loop onde cada iteração é um 'salto', que acontece a partir
da geração de um valor aleatório entre 10 e o valor do salto máximo definido
para aquela instância de "lebre" (considerando valores expressos em cm).

Faça as lebres "correrem" nessa "pista" com o tamanho definido na execução do
programa. Para cada vez que a função de cada processo/thread (lebre) executar
a geração de valores aleatórios uma soma de todos os saltos deverá ser 
armazenada em uma variável com o quanto a lebre já percorreu da pista (uma 
variável int no escopo da função da lebre). A função permanece no loop, 
"saltando", até que o valor acumulado seja igual ou superior ao tamanho da 
pista.

A cada "salto" (iteração realizada pela função associada ao processo ou a 
thread), deverá ser exibida uma mensagem contendo a distância do salto 
efetuado e qual distância total percorrida (dormindo 1s - função sleep - até 
que dê outro salto). A primeira 'lebre' (thread ou processo) que finalizar sua
função (ou seja, tenha a variável que represente o quanto a lebre já percorreu
com valor maior ou igual ao tamanho da pista) deverá exibir uma mensagem onde 
se declara vencedora e o programa deverá ser finalizado. */





#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>

bool Processo_F = false;
//-------------------------funcao dos processos-----------------------
int funcao_P(int indice, int salto_M, int tam_P ){
    int distPer= 0;
    while (distPer < tam_P)
    {
        int  salto = (rand() % salto_M - 10) + 10;
        distPer = distPer + salto;

    }
    return indice;
}
//--------------------------Threads----------------------------------------
   typedef struct  inf 
{
    int indice;
    int pulo_M;
    int tm_pista;
}Info;

void *funcao_T(void *arg){
    inf *lebre = (inf *) arg;

    int dist_P = 0;
    while(dist_P < lebre -> tam_P){
        int salto = (rand() % coelho -> pulo_M -10) +10;
        dist_P = dist_P + salto;
        printf("lebre %d pulou %d, totalizando %d", lebre -> indice, salto, dist_P);
        sleep(1);
    }
    return lebre ->indice;
}


pthread_t thread;
    


}
//------------------------------Main--------------------------------------
int main (int qt_arg, char* lt_arg[]){ 
    char *Escolha = lt_arg[1];
    int *qt_lebres = atoi(lt_arg[2]);
    int *tm_pista= atoi(lt_arg[3]);

    int return_F;

    pid_t processoPID = getpid();
    // getpid() = pega o Pid do processo atual

    int valorFlork;




//--------------------------Processos------------------------------



    if(strcmp(Escolha, "-p") == 0){
      if(processoPID=getpid()){
      //criando filhos
      for (int i = 1; i <= qt_lebres;i++){

          valorFlork = fork();
      //TRABALHANDO COM PROCESSOS FILHOS
            if(valorFlork == 0){
                srand(time(NULL));
                int salto_M = rand() % 40 +10;
                int indice = i;
                int tm_pista = atoi(lt_arg[3]);
                return_F=funcao_P();
            }
        }
      }
      //RETORNANDO O VALOR DO 
    if(processoPID != getpid()){
        if(processo_F == false){
            processo_F = true;
           
            return return_F;
          
        }
        
    }
    //FAZENDO O PROCESSO PAI ESPERAR OS FILHOS PARA SE INICIAR
    if(processoPID == getpid()){
        int status;
        //RECEBE OS STATUS DO PROCESSO FILHO, O PRIMEIRO QUE ACABAR VAI SEGUIR
        wait(&status);
        printf("A lebre ganhadora é a : %d\n", WEXITSTATUS(status));
    }
    }


//--------------------------------Threads-------------------------------------------



if(strcmp(Escolha, "-t") == 0)

{
    void *funcao_T(void *arg);
    for(int i = 0;i<qt_lebres;i++){
           
            lebre.indice= i;
            lebre.pulo_M = (rand() % 40  + 10 );
            lebre.tm_pista= atoi(lt_arg[3]);
            pthread_create(&thread,NULL,f,(void*) lebre);
            
            
}
    
    return 0;
}

