#include <cs50.h>
#include <stdio.h>

int main(void)
{   float nn;
    do{
    printf("non-negative numerator: ");
    nn=GetFloat();
    }
    while(nn<0);

    float kk;
    do{
    printf("Positive denominator: ");
    kk=GetFloat();
    }
    while(kk<=0);

    float ss=nn/kk*100;
    
    printf("%0.2f%%\n",ss);
    
    return 0;
}
