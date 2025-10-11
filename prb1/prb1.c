#include <stdio.h>
#include <stdint.h>
#include <time.h>

// Naive solution using for-loops.

#define UPPER_BOUND (100000)


int main(void)
{
    clock_t begin, end;
    begin = clock();

    uint64_t sum = 0;
    for (size_t n = 3; n <= UPPER_BOUND; n+=3)
    {
        sum += n;
    }

    uint32_t cnt = 0;
    for (size_t n = 5; n <= UPPER_BOUND; n+=5)
    {
        // If value already counted in n=3 loop, skip to next itteration.
        cnt++;
        if (cnt >= 3)
        {
            cnt = 0;
            continue;
        }

        sum += n;
    }
    end = clock();


    printf("Sum = %ld, clocks = %ld\n", sum, (end-begin));

    return 0;
}