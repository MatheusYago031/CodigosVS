#include <stdio.h>
#include <stdlib.h>


#define MAX_TAM_FRASE 100



int main(void){
    char frase[MAX_TAM_FRASE];
    int i=0;
   char trocarLetra(char letra);
   // Letra=&letra;
    //char *f;
       // *f=&frase;
    
    printf("Digite a frase a ser codificada: ");
    fgets(frase,MAX_TAM_FRASE,stdin);

    
    while (frase[i]!='\0')
    {
        frase[i]=trocarLetra(frase[i]);
        i++;
    }
    
    printf("A frase com as letras trocadas é: %s",frase);
    printf("\n\n");
    return 0;
}


  char trocarLetra(char letra ) {
      char nova_letra;
      /* char vogal[4];
       vogal['a','e','i','o','u'];
       letra = &vogal;*/
    
    switch (letra)
    {
            case 'a': nova_letra = 'u';
                break;
            case 'e': nova_letra = 'o';
                break;
            case 'i': nova_letra = 'u';
                break;
            case 'o': nova_letra = 'a';
                break;
            case 'u': nova_letra = 'i';
                
                break;
    
    default:
        nova_letra=letra;
        break;
    }
   return nova_letra; 
   
  }
