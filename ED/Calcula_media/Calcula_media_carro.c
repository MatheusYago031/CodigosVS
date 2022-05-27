//calcula a média /litro que o carro faz

#include <stdio.h>
#include <stdlib.h>


typedef struct 
{
  float km;//field km
  float l;//field litro(l)
  float mkm;//field media
}media_kl;

//FUNÇÃO PARA EXIBIR RESULTADO
void imprime_media(media_kl mk)
{
  printf("A media foi de: %.2f km/l\n",mk.mkm);
}

//AQUI ULTILIZAMOS A PASSAGEM POR REFERÊNCIA
float set_economia(media_kl *M,float k_p,float l_g,float m_p_l)
{ 
    M->km = k_p;
    M->l = l_g;
    M->mkm = m_p_l;

    m_p_l=k_p/l_g;

    return m_p_l;
   
}


int main(void)
{
    float q_p;
    float q_a;
    float media;

    printf("Digite a quilometragem: ");
      scanf ("%f",&q_p);

    printf("Digite a quantidade abastecida: ");
      scanf("%f",&q_a);

      media_kl carro;

      media = q_p/q_a;

      
//"FUNÇÃO "CRIA" A ECONOMIA DE "CARRO"
set_economia(&carro,q_p,q_a,media);

//CHAMAMOS A FUNÇÃO QUE EXIBE A ECONOMIA
imprime_media(carro);


	return 0;

}



