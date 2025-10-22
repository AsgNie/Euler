#include <stdio.h>
#include <stdint.h>
#include <time.h>

// Naive solution using while-loop
// I elected to construct a very barebone circular buffer, and encapsule the complexity in short function calls.

#define UPPER_BOUND     (4000000)
#define FUNC_SUCCESS    (0)
#define FUNC_ERROR      (-1)

typedef struct
{
    uint64_t buffer[2]; // Holds two last Fib values
    uint8_t idx;        // Points to next write location

} fib_buf_t;


// Innit buffer. Checks that a <= b, returns FUNC_SUCCESS on success, or FUNC_ERROR on failure.
int8_t fib_buf_init(fib_buf_t * f, uint64_t a, uint64_t b)
{
    if(a > b)
    {
        return FUNC_ERROR;
    }

    f->buffer[0] = a;
    f->buffer[1] = b;
    f->idx = 0;

    return FUNC_SUCCESS;
}


// Push a value to buffer overwritting the oldest
void fib_buf_push(fib_buf_t * f, uint64_t val)
{
    f->buffer[f->idx++] = val;
    if(f->idx > 1)
    {
        f->idx = 0;
    }
}


// Generate next Fibonnaci Number, push it to buffer, and return number
uint64_t fib_generate(fib_buf_t * f)
{
    uint64_t next = f->buffer[0] + f->buffer[1];
    fib_buf_push(f, next);
    return next;
}



int main(void)
{
    clock_t begin, end;
    begin = clock();

    uint64_t sum = 0;
    fib_buf_t fs;
    fib_buf_t* fp = &fs;

    // Init first Fibonacci Numbers to two 1, and check that init succeded.
    if (fib_buf_init(fp, 1, 1) != FUNC_SUCCESS)
    {
        return FUNC_ERROR;
    }

    uint64_t fibEven = fib_generate(fp); // fibEven = 2
    uint32_t n = 0;
    while (fibEven <= UPPER_BOUND )
    {
        n += 3;
        sum += fibEven;
        fib_generate(fp);
        fib_generate(fp);
        fibEven = fib_generate(fp);
    }

    end = clock();

    printf("Sum = %ld, N_even = %d, clock = %ld\n", sum, n, (end-begin));

    return FUNC_SUCCESS;
}
