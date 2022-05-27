#include <stdio.h>
#include <math.h>

int main(){
    int a;
    int b;
    int c;
    int bb;

    int delta;
    
    float x1,x2;

        printf("Informe o valor de A: ");
        scanf("%d",&a);

        printf("Informe o valor de B: ");
        scanf("%d",&b);

        printf("Informe o valor de C: ");
        scanf("%d",&c);
            
            bb=pow(b,2);
            
            delta = (bb)-4*a*c;
                printf("O valor de delta é :%d\n",delta);
                    if (delta<0)
                 {
                    printf("Impossível continuar o cálculo");
                    }
                else
                    x1= ((-b)+ sqrt(delta))/2;
                    x2= ((-b)- sqrt(delta))/2;
                        
                        printf("%.2f\n",x1);
                        printf("%.2f\n",x2);
                        
        return(0);
}