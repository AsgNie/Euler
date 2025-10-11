## Problem
[Problem 1](https://projecteuler.net/problem=1):
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
Find the sum of all the multiples of 3 or 5 below 1000.

## Considerations

* Multiplication tables of 3 and 5 overlap, (15, 30, 45, ...) do not sum those entries twice.
* Checking if some multiple of X is also a multiples of Y wo. further knowledge requires a division and check of the remainder, i.e. check (N*X)%Y == 0 to find a multiple of both X and Y.
* Multiplications and especially divisions are typically expensive operations for a processor. Try to replace them with additions/substrations if possible.

## Naive solution
prb1.c

Make two for-loops. One that starts at n=3 and increments by n+=3, and another that starts at n=5 and increments by n+=5.
Keep track of not summing common multiples of 3 and 5 twice. A simple implementation would be to have a counter in the n+=5 loop, and use an if-statement to skip every third value of the 5-table (15, 30, 45,...).

A possible optimisation of the above code could be to replace the if-statement with logic that does not rely on branching to avoid the processor having to stall on mistaken branch predictions.

## Smart solution
prb2.c

Realise that sum(x n) can be re-written as x*sum(n).
Next, realise that the finite sum of integers can be expressed as sum_{n=1}^{N}(n) = (N*(N+1))/2. There is an elegant proof of this, but for our purpose simply refer to either of these Wikipedia articles:
[1 + 2 + 3 + 4 + ⋯](https://pages.github.com/)
[Triangular number](https://pages.github.com/)

Using this we will only have to evaluate one expression for each sum, rather than looping through the multiplication tables.
In order to remove the duplicate multiples of 3 and 5 we can substract the sum of the multiplication table of 15:
sum = sum(3n) + sum(5n) - sum(15n).

## Execute code
To build and execute both programs call the makefile as `make run`.
Notice that the `UPPER_BOUND` has been set to `100000` rather than `1000` to take up enough CPU cycles to make the difference visible.