#include <stdio.h>

int main(void)
{
float r;
float A;
    printf("Digite o tamanho do raio: ");
        scanf("%f",&r);

        if(r < 0){
            r = r * (-1);
        }
            A = 3.14 * (r*r);

                printf("o tamanho da area do circulo é: %.2f\n",A);
    return (0);
}