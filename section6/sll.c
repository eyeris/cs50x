/*************************************************************************
 * sll.c
 *
 * Implements a simple singly-linked list structure for ints.
 ************************************************************************/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// the size of our test list: feel free to adjust as you wish!
#define TEST_SIZE 10

typedef struct node
{
    // the value to store in this node
    int i;

    // the link to the next node in the list
    struct node* next;
}
node;

// declare the first node of our list (as a global variable)
node* first = NULL;

/**
 * Returns the length of the list.
 */
int length(void)
{
    int counter = 0;
    node* nn = first;
    while (nn != NULL)
    {
        nn = nn->next;
        counter=counter+1;
    }
    return counter;
}

/**
 * Returns true if a node in the list contains the value i and false
 * otherwise.
 */
bool contains(int i)
{
    node* nn = first;
    while (nn != NULL)
    {
        if (nn->i == i)
        {
            return true;
        }
        nn = nn->next;
    }
    return false;
}
/**
 * Puts a new node containing i at the front (head) of the list.
 */
void prepend(int i)
{
    node* nn = newnode(i);
    if (first == NULL)
    {
        first = nn;
    }
    else
    {
        nn->next = first;
        first = nn;
    }
    return;
}

/**
 * Puts a new node containing i at the end (tail) of the list.
 */
void append(int i)
{
    node* nn = newnode(i);
    if (first == NULL)
        first = nn;
    node* mm = first;
    while (mm != NULL)
    {
        mm = mm->next;
        if (mm->next == NULL)
        {
            mm->next = nn;
            return;
        }
    }
    return;
}


/**
 * Puts a new node containing i at the appropriate position in a list
 * sorted in ascending order.
 */
void insert_sorted(int i)
{
    node* nn = newnode(i);
    node * mm = first;
    if (first == NULL)
    {
        first = nn;
    }
    while (mm != NULL)
    {
        if (mm->next->i > nn->i)
        {
            nn->next = mm->next;
            mm->next = nn;
            return;
        }
        mm = mm->next;
    }
    return;
}
    

/**
 * Implements some simple test code for our singly-linked list.
 */
int main(void)
{
    printf("Prepending ints 0-%d onto the list...", TEST_SIZE);
    for (int i = 0; i < TEST_SIZE; i++)
    {
        prepend(i);
    }
    printf("done!\n");

    printf("Making sure that the list length is indeed %d...", TEST_SIZE);
    assert(length() == TEST_SIZE);
    printf("good!\n");

    printf("Making sure that values are arranged in descending order...");
    node* n = first;
    for (int i = 0; i < TEST_SIZE; i++)
    {
        assert(n != NULL);
        assert(n->i == TEST_SIZE - i - 1);
        n = n->next;
    }
    printf("good!\n");

    printf("Freeing the list...");
    while (first != NULL)
    {
        node* next = first->next;
        free(first);
        first = next;
    }
    printf("done!\n");

    printf("Appending ints 0-%d to the list...", TEST_SIZE);
    for (int i = 0; i < TEST_SIZE; i++)
    {
        append(i);
    }
    printf("done!\n");

    printf("Making sure that the list length is indeed %d...", TEST_SIZE);
    assert(length() == TEST_SIZE);
    printf("good!\n");

    printf("Making sure that values are arranged in ascending order...");
    n = first;
    for (int i = 0; i < TEST_SIZE; i++)
    {
        assert(n != NULL);
        assert(n->i == i);
        n = n->next;
    }
    printf("good!\n");

    printf("Freeing the list...");
    while (first != NULL)
    {
        node* next = first->next;
        free(first);
        first = next;
    }
    printf("done!\n");

    printf("Inserting %d random ints to the list...", TEST_SIZE);
    for (int i = 0; i < TEST_SIZE; i++)
    {
        insert_sorted(rand() % TEST_SIZE);
    }
    printf("done!\n");

    printf("Making sure that the list length is indeed %d...", TEST_SIZE);
    assert(length() == TEST_SIZE);
    printf("good!\n");

    printf("Making sure that values are arranged in sorted order...");
    n = first;
    int prev = 0;
    for (int i = 0; i < TEST_SIZE; i++)
    {
        assert(n != NULL);
        assert(n->i >= prev);
        prev = n->i;
        n = n->next;
    }
    printf("good!\n");

    printf("Freeing the list...");
    while (first != NULL)
    {
        node* next = first->next;
        free(first);
        first = next;
    }
    printf("done!\n");

    printf("\n********\nSuccess!\n********\n");

    return 0;
}
