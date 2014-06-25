/****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/

#include <stdbool.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

#include "dictionary.h"
#define HT_SIZE 143091

// prototype
int hash(const char *word);

// global word varialbes
char word[LENGTH + 1];
int word_count = 0;

typedef struct node 
{
    char *word;
    struct node *next;
} node;

node *hasht[HT_SIZE];

/**
 * Returns true if word is in dictionarmakey else false.
 */
bool check(const char *word)
{
    node *nnode = malloc(sizeof(nnode));
    int hashv = hash(word);
    nnode = hasht[hashv];
    
    while(nnode != NULL) 
    {
        if (strcasecmp(word, nnode->word) == 0)
        {
	        return true;
        }
        nnode = nnode->next;
    }
    return false;
}


/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    FILE *fp = NULL;
    int hh;
 
    for (int i = 0; i < HT_SIZE; i++) 
    {
        hasht[i] = NULL;
    }

    if (!(fp = fopen(dictionary, "r")))
    {
        return false;
    }
  

    while (fscanf(fp,"%s\n",word) != EOF)
    {
        node *nodep = malloc(sizeof(node));
        nodep->word = malloc(strlen(word) +1);
        strcpy(nodep->word,word);
    
        hh = hash(word);
  
        word_count++;
    
    if(hasht[hh] == NULL)
    {
    	hasht[hh] = nodep;
	    nodep->next = NULL;
    }
    else 
    {
	    nodep->next = hasht[hh];
	    hasht[hh] = nodep;
    }
  }
  
  return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
     return word_count;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    node *nextnode,*node;
    
    for (int i = 0; i<HT_SIZE; i++)
    {
        node = hasht[i];
        while (node)
        {
	        free(node->word);
	        nextnode  = node->next;
	        free(node);
	        node = nextnode;
        }   
        hasht[i] = NULL;
    }
  
  return true;
}

int hash(const char *word) 
{
    int length = strlen(word);
    int hash = 0;

    for(int i = 0; i < length; i++)
    {
        int x = word[i];
        if (x > 64 && x < 91)
        {
            hash += word[i] + 32;
        }
        else
        {
            hash += word[i];
        }
    }
    
    return hash % HT_SIZE; 
}
