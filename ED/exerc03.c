#include <stdio.h>

int main(void){
float n1,n2,n3,n4;
float Sf;
float media;
float Sn;

printf("Digite suas notas: ");
scanf("%f %f %f",&n1,&n2,&n3);

Sn = n1+n2+n3;
media = (n1+n2+n3)/3;
Sf = 28 - Sn;

if (media>=7)
{
    printf("Aluno aprovado.");
}
if(18<=Sn && Sn<=20){
    printf("Aluno em recuperação\n");
    
    printf("O aluno precisa de: %.2f para passar\n",Sf);

}
if(Sn<18){
    printf("O aluno precisa de: %.2f para passar\n",Sf);
    printf("Aluno reprovado\n");
}
    return(0);

}