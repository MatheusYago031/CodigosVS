#include <stdio.h>
 
int main(void){
    int x, y, *p;y = 0;
        p = &y;
        x = *p;
        x = 4;
    (*p)++;
    --x;
    (*p) += x;

    printf("os valores sao, p = %d\n x = %d\n y = %d\n",*p,x,y );

}