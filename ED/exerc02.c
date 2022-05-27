#include <stdio.h>

int main(void){
int n;

    printf("Digite um numero: ");
    scanf("%d",&n);

    if(n%2>=1){
        printf("O numero: %d, e impar\n",n);
    }
        else{
            printf("O numero: %d, e par\n",n);
        }

return(0);

}