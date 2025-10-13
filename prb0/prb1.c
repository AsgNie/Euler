#include<stdio.h>
#include<stdint.h>
#include <time.h>

// Naive solution using for-loops.

#define NO_SQUARE_NUMBERS (946000) // The number of square numbers to evaluate
#define UPPER_BOUND ((NO_SQUARE_NUMBERS+1)/2) // Equivalent to ceil(NO_SQUARE_NUMBERS/2)

int main(void)
{
    clock_t begin, end;
    begin = clock();

    uint64_t sum = 0;
    for(size_t n = 1; n <= UPPER_BOUND; n++)
    {
        sum += (2*n-1)*(2*n-1);
    }

    end = clock();


    printf("Sum = %ld, clocks = %ld\n", sum, (end-begin));

    return 0;
}
