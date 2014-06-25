#include <cs50.h>
#include <stdio.h>

int main(void)
{ 
    printf("C: ");
    float c=GetFloat();
    float f=(c*9/5)+(32); 
    printf("Equilent F value is : %0.1f\n", f); 
    return 0;
}
