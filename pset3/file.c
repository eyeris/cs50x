#include <stdio.h>

#define SIZE 8

void sort(int array[], int size)
{
    for(int i=0;i<size;i++)
    {
    int min=i;
        for(int j=i+1;j<size;j++)
        {
            if(array[min]>array[j])
            {
             min=j;
        	}
            
        }
        if(min!=i)
        {
        	int temp=array[i];
        	array[i]=array[min];
        	array[min]=temp;
        }
    
    }
}

int main(void)
{
    int numbers[SIZE] = { 4, 15, 16, 50, 8, 23, 42, 108 };
    for (int i = 0; i < SIZE; i++)
        printf("%d ", numbers[i]);
    printf("\n");
    sort(numbers, SIZE);
    for (int i = 0; i < SIZE; i++)
        printf("%d ", numbers[i]);
    printf("\n");
    return 0;
}