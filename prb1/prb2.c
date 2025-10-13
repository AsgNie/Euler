#include <stdio.h>
#include <stdint.h>
#include <time.h>


// Optimised solution using finite sum of integers

// Upper bound.
#define UPPER_BOUND (1000)
// Upper bounds of sums. Problem specifies multiplicants BELOW the upper bound, thus the minus 1.
#define N3_MAX  ((UPPER_BOUND-1)/ 3)
#define N5_MAX  ((UPPER_BOUND-1)/ 5)
#define N15_MAX ((UPPER_BOUND-1)/15)


int main(void)
{
    clock_t begin = clock();
    uint64_t sum =  (uint64_t)  3*((N3_MAX  * (N3_MAX+1)) /2)
                  + (uint64_t)  5*((N5_MAX  * (N5_MAX+1)) /2)
                  - (uint64_t) 15*((N15_MAX * (N15_MAX+1))/2);
    clock_t end = clock();

    printf("Sum = %ld, clocks = %ld\n", sum, (end-begin));

    return 0;
}