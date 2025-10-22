#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <math.h>

// Smart solution using closed-form rounding expressions for finding index of largest Fibonacci number,
// and similarly to calculate a Fibonacci number. Sum of evens is found by a modified sum identity.

#define UPPER_BOUND (4000000)               // 4M
#define PHI         (1.6180339887498949 )   // ( 1 + sqrt(5) ) / 2
#define LOG_PHI     (0.48121182505960663)   // ln( PHI )

int main(void)
{
    clock_t begin, end;
    begin = clock();

    uint32_t N_upper = floor(  log(sqrt(5)*UPPER_BOUND+0.5)/LOG_PHI  ); // Index of highest Fibonacci number smaller than UPPER_BOUND
    uint32_t N_even_p2 = N_upper - ( N_upper % 3 ) + 2;                 // Index of highest even Fibonacci number plus 2

    uint64_t fib_even_p2 = round( pow(PHI,N_even_p2)/sqrt(5) );         // Fibonacci number by rounding expression
    uint64_t sum = (fib_even_p2 - 1) / 2;                               // Sum of even Fib numbers by modified sum identity.

    end = clock();

    printf("Sum = %ld, N_even = %d, clock = %ld\n", sum, (N_even_p2-2), (end-begin));

    return 0;
}
