## Problem
[Problem 0](https://projecteuler.net/register):
A number is a perfect square, or a square number, if it is the square of a positive integer.
For example, 25 is a square number because 5^2 = 5 * 5 = 25; it is also an odd square.

The first 5 square numbers are:
1, 4, 9, 16, 25, and the sum of the odd squares is 1+9+25 = 35.

Among the first X square numbers, what is the sum of all the odd squares?

Note: The value of X is randomised.

## Considerations

* If we were to find the sum of the first 10 square numbers it could be put as sum_{n=1}^{N=10}{ n^2 }.
* The odd numbers can be singled out, by replacing n with (2*n-1) and changing the upper bound to N_{new} = N/2.
* One X value asked for the first 547 thousand, i.e. 547'000, square numbers to be evaluated. This will be computationally expensive with a naive solution.

## Naive solution
prb1.c

Carry out the computation `sum_{n=1}^{N/2}{ (2*n-1)^2 }` using a for-loop.

## Smart solution
prb2.c

Expand `(2*n-1)^2` to get three simpler sums (multiplied by some constants) of `sum{n^2}`, `sum{n}`, and `sum{1}`.
Each of these can be evaluated as a close-form expression instead of itteratively:
* `sum_{n=1}^{N}{ n^2 } = N(N+1)(2N+1)/6`
* `sum_{n=1}^{N}{ n }   = N(N+1)/2`
* `sum_{n=1}^{N}{ 1 }   = N`

A proof of the two first can be found at [Brilliant](https://brilliant.org/wiki/sum-of-n-n2-or-n3/), while the third is simply to take add one N times, giving a final sum of N.
