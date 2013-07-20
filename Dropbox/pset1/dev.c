#include <cs50.h>
#include <stdio.h>

int main(void)
{   float nn ;
    printf("non-negative numerator: ");
    nn=GetFloat();
    while(nn<0)
    {
        printf("Non-negative numerator: ");
        nn=GetFloat();
          
    }
    float kk ;
    printf("Positive denominator: ");
    kk=GetFloat();
    while(kk<=0)
    {
        printf("Positive denominator: ");
        kk=GetFloat();
          
    }
    float ss=nn/kk*100;
    
    printf("%0.2f%%\n",ss);
    
    return 0;
}
