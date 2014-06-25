#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float change;
    do 
        {
        printf("O hai! How much change is owed? ");
        change =GetFloat();
        }
    while(change<0);
    int ch=round(change*100);
    int counter=0;
    
    while(ch%25>=0 && ch>=25)
        {
        ch-=25;
        counter++;
        }
    while(ch%10>=0 && ch>=10)
        {
        ch-=10;
        counter++;  
        }
    while(ch%5>=0 && ch>=5)
    {
        ch-=5;
        counter++;   
    }
   
    printf("%d\n",counter+ch);
    return 0;
    

}
