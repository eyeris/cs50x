cd p#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h ;
    printf("Height: ");
    h=GetInt();
    while(h<0||h>23)
    {
        printf("Height: ");
        h=GetFloat();
          
    }
    
     for(int i=0;i<h;i++)
     {
        int n=h-i;
        int j=0;
        int k=0;
     
        while(j<=n-2)
        {
            printf(" ");
            j++;
        }
        while(k<h+2-n)
        {
            printf("#");
            k++;
        }
     
     printf("\n");
     }
     return 0;
}
