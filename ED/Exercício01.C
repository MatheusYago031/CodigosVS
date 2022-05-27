#include <stdio.h>
    int main(void)
    {
        float r;
        float Ac;
            
            printf("Digite o valor do raio: ");
            scanf("%f", &r);
        
                if(r<0){
            r=r*(-1);
                }

        Ac=3.14*(r*r);

    printf ("Valor da área do círculo = %.2f\n",Ac);
        
    
        
        return(0);
        
    }
