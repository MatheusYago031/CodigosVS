#include <stdio.h>

int main(void){
float n1,n2,n3,n4;
float media;
    printf("Digite suas 3 primeiras notas: ");
        scanf("%f",&n1);
        scanf("%f",&n2);
        scanf("%f",&n3);
            
            
            media = (n1+n2+n3)/3;

            if (media >= 7)
            {
                printf("Aluno aprovado\n");
            }

            if(media < 7)
            {
                n4 = 28-(n1+n2+n3);
                   
                    if(10>n4)
                    {
                        printf("Aluno em recuperação,nota necessária: ");
                        printf("%.1f\n",n4);
                    }
                    
                    else printf("Aluno reprovado,nota necessária: ");
                            printf("%.1f\n ",n4);

            
                return(0);


            }
            



}