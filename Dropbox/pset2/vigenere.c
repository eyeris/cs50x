#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
 {
    if(argc !=2)
    {
    printf("Wrong and Try again\n");
    return 1;
    }
 
    for(int j=0;j<strlen(argv[1]);j++)
    {
    
        if(isdigit(argv[1][j]))
        {
        printf("Keyword must contain only characters\n");
        return 1;
        }
    
    }
    


  string sen=GetString();
 
  int incremeter=0;
  //int upshiftchar=incremeter % strlen(argv[1]);
  
    
    for(int i=0;i<strlen(sen);i++)
    {
        
        
            if(isupper(sen[i]))
            {
                int chr=sen[i];
                int position=chr-65;
                int newposi=(position+( int)(tolower(argv[1][incremeter % strlen(argv[1])]))-97 )%26;
                sen[i]=(char) (newposi+65);
                incremeter+=1;
            }
            else if(islower(sen[i]))
            {
             int chr=sen[i];
                int position=chr-97;
                int newposi=(position+( int)(tolower(argv[1][incremeter % strlen(argv[1])]))-97 )%26;
                sen[i]=(char)(newposi+97);
                incremeter+=1;
            }
        	
            
    }
    printf("%s\n",sen);
    return 0;
}
