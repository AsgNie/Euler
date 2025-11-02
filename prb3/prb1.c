#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#define NUT ( 600851475143 ) // Number Under Test, approx 6*10^11

typedef struct node
{
    uint64_t factor;
    struct node* next;
} node_t;

// Returns pointer to new node. Ensures that node->next is always initialised to NULL.
// Asserts on out of memory return from malloc.
node_t* linkedListNewNode()
{
    node_t* new = malloc(sizeof(node_t));
    assert(new != NULL);
    new->next = NULL;

    return new;
}

// Adds factor to current node, and returns pointer to next node.
node_t* linkedListAdd(node_t* pNode, uint64_t factor)
{
    pNode->factor = factor;
    pNode->next = linkedListNewNode();
    return pNode->next;
}

void linkedListFree(node_t* node)
{
    while (node != NULL)
    {
        node_t* p = node;
        node = node->next;
        free(p);
    }
}

void linkedListPrint(const node_t* node)
{
    while (node->next != NULL)
    {
        printf("%ld, ", node->factor);
        node = node->next;
    }
    printf("\n");
}



int main(void)
{
    clock_t begin, end;
    begin = clock();

    uint64_t i_max = floor(sqrt(NUT));
    uint64_t n = NUT;

    node_t* pNodeFirst = linkedListNewNode();
    node_t* pNode = pNodeFirst;

    while (n%2 == 0) // Check if 2 is prime factor
    {
        pNode = linkedListAdd(pNode, 2);
        n = n/2;
    }

    // Check all odd integers less than or equal to sqrt(NUT)
    for( uint64_t i = 3; i <= i_max && n != 1; i += 2 )
    {
        if( n%i == 0) // Found a prime factor
        {
            while (n%i == 0) // Check how many times it factors
            {
                pNode = linkedListAdd(pNode, i);
                n = n/i;
            }
        }
    }

    // If a value remains larger than sqrt(NUT), that must be a prime factor.
    // Note that the value is NUT if NUT is a prime
    if (n != 1)
    {
        pNode = linkedListAdd(pNode, n);
    }

    end = clock();

    linkedListPrint(pNodeFirst);
    linkedListFree(pNodeFirst);

    printf("Clock = %ld\n", (end-begin));

    return 0;
}
