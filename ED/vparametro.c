#include<stdio.h>

#include<stdlib.h>








float media ( int n, float *notas);




int main(void)
{

    float notas[10];
   
    float mediaN;
   
    int i;
   
   
   
   
   
        for( i=0;i<10;i++)
        {
            printf("Digite a nota: ");

            scanf("%f",&notas[i]);
       
        }


	mediaN = media(10, notas);

    printf("\nMedia: %.1f",mediaN);


    system("pause");

	return 0;


}

//calcular a media

float media(int n, float *notas){
    int i;
    float m, soma=0;
   
    for(i=0;i<n;i++){
        soma= soma + notas[i];
    }

    m = soma/n;

return m;
}