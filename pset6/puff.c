
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "forest.h"
#include "huffile.h"
#include "tree.h"


Tree* join(Tree* a, Tree* b);


Tree* root = NULL;

int main(int argc, char* argv[])
{

    if (argc != 3)
    {
        printf("Usage: %s input output\n", argv[0]);
        return 1;
    }

   
    Huffile* in = hfopen(argv[1], "r");
    if (in == NULL)
    {
        printf("Could not open %s for reading.\n", argv[1]);
        return 1;
    }

   
    FILE* out = fopen(argv[2], "w");
    
  
    Huffeader header;
    if (hread(&header, in) == false)
    {
        hfclose(in);
        printf("Could not read header.\n");
        return 1;
    }

  
    if (header.magic != MAGIC)
    {
        hfclose(in);
        printf("File was not huffed.\n");
        return 1;
    }

  
    int checksum = header.checksum;
    for (int i = 0; i < SYMBOLS; i++)
    {
        checksum -= header.frequencies[i];
    }
    if (checksum != 0)
    {
        hfclose(in);
        printf("File was not huffed.\n");
        return 1;
    }
    
    
    Forest* forest = mkforest();
    
    
    for (int i = 0; i < SYMBOLS; i++)
    {
       
        if (header.frequencies[i] >= 1)
            {
                Tree* newTree = mktree();
                newTree->frequency = header.frequencies[i];
                newTree->symbol = i;
                newTree->left = NULL;
                newTree->right = NULL;
                plant(forest, newTree);
            }
    }
    
  
    bool done = false;
    while (!done)
    {
 
        Tree* small1 = pick(forest);
        
     
        Tree* small2 = pick(forest);
        
      
        if (small2 == NULL)
        {
            done = true;
            root = small1;
        }
        
    
        else
        {

            Tree* combinedTree = join(small1, small2);
            
            
            plant(forest, combinedTree);
        }

    }

  
    int bit;
    Tree* point = root;
    while ((bit = bread(in)) != EOF)	
	{	
	    
	   
	    if (bit == 0)
	    {
	        point = point->left;
	    }
	
	   
	    else if (bit == 1)
	    {
	       point = point->right;
	    }
	    
	    
	    if ((point->right == NULL) && (point->left == NULL))
	    {
	        
	        fprintf(out, "%c", point->symbol);
	        
	    
	        point = root;
	    }
	}
    
  
    rmtree(root);
    
  
    rmforest(forest);
    
   
    hfclose(in);
    
   
    fclose(out);

   
    return 0;
}


Tree* join(Tree* a, Tree* b)
{
   
    Tree* combinedTree = mktree();
    
   
    combinedTree->frequency = (a->frequency + b->frequency);
    

    combinedTree->left = a;
    

    combinedTree->right = b;
    

    return combinedTree;
}

