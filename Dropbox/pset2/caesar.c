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
    
 
  
  string sen=GetString();
  int k=atoi(argv[1]);
    
    for(int i=0;i<strlen(sen);i++)
    {
        
            if(isupper(sen[i]))
            {
                int chr=sen[i];
                int position=chr-65;
                int newposi=(position+k)%26;
                sen[i]=(char) (newposi+65);
            }
            else if(islower(sen[i]))
            {
             int chr=sen[i];
                int position=chr-97;
                int newposi=(position+k)%26;
                sen[i]=(char)(newposi+97);
            }
        	
        
    }
    printf("%s\n",sen);
    return 0;
}
