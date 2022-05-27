/*Ponteiros: um ponnteiro sempre irá "apontar" para o endereço de memória de outra variável.... sempre que quisermos chamar um ponteiro há uma diferença para exibir ou trabalhar com seu valor e/ou seu endereço de memória, 
para exibir valor utilizamos: %d,c,f(a depender do tipo) e * ou ** (a depender do caso) + nomeDoPonteiro, já para  o endereço de memória utilizamos %x(exibe um número hexadecimal) &nomeDoPonteiro, 
devemos sempre lembrar que o código é lido pelo sistema de forma linear de cima para baixo,isso implica que a medida que eu altero o valor de um ponteiro, 
todas as variáveis que são apontadas ou que apontam para ele, também são alteradas*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char* argv){
    int g;
    int *p;
    int **pp;
    srand(time(NULL));
    g=rand()%30;
    printf("valor de g: %d\n",g);
    p = &g;
    *p=*p+30;
    printf("valor de p: %d\n",*p);

    pp = &p; 
    **pp= **pp+6;
    printf("valor de pp: %d\n",**pp);
  // printf("valor do endereço de g: %d\n",g);
  

   printf(" endereço de g: %x\n endereço apontado por p: %x\n endereço apontado por  pp: %x\n", &g,p,pp);
  //p aponta para o endereço de g e pp aponta para o endereço de p
    
        }
    
     
    
