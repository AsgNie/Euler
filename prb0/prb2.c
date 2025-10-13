#include <stdio.h>
#include <stdint.h>
#include <time.h>

// Optimised solution using finite sum of integers, and finite sum of squared integers.

#define NO_SQUARE_NUMBERS (946000) // The number of square numbers to evaluate
#define UPPER_BOUND ((NO_SQUARE_NUMBERS+1)/2) // Equivalent to ceil(NO_SQUARE_NUMBERS/2)


static inline uint64_t sumOfIntegers(uint64_t N)
{
    return N*(N+1)/2;
}

static inline uint64_t sumOfSquaredIntegers(uint64_t N)
{
    return N*(N+1)*(2*N+1)/6;
}

int main(void)
{
    clock_t begin, end;

    begin = clock();

    uint64_t sum =  4*sumOfSquaredIntegers(UPPER_BOUND) - 4*sumOfIntegers(UPPER_BOUND) + UPPER_BOUND;

    end = clock();

    printf("Sum = %ld, clocks = %ld\n", sum, (end-begin));

    return 0;
}
