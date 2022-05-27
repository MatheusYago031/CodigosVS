//alocação dinâmica
#include <stdio.h>
#include <stdlib.h>
#include <math.h>





//pot por parametros
int pot(int x, int n){
    x=pow( x, n);
    return(x);
}
//pot por ponteiros
void potP(int *p, int *z){

    *p= pow( *p,*z);
    return;
}

int main(void){
    int numero;
    int exp;
  
    
    printf("DIGITE O NUMERO: ");
    scanf("%d",&numero);
    printf("DIGITE O SEGUNDO NUMERO: ");
    scanf("%d",&exp);
    
//chamando por ponteiros
    potP(&numero,&exp);
    printf("O resultado de sua multiplicacao é: %.d\n",numero);
    
// chamando por retorno
//    numero =  pot(numero,exp);

 //   printf("O resultado de sua multiplicacao é: %.1f\n",numero);


    

    return 0;

}