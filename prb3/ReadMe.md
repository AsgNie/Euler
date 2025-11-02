## Problem
[Problem 3 - Largest Prime Factor](https://projecteuler.net/problem=3):

The prime factors of 13195 are 5, 7, 13 and 29.
What is the largest prime factor of the number 600851475143? (approximately 6*10^11)

## Considerations
* See [Wikipedia](https://en.wikipedia.org/wiki/Prime_number), or [Wolfram](https://mathworld.wolfram.com/PrimeNumber.html) for an introduction to prime numbers
* A simple, put comptationally heavy, solution to finding prime factors is to do trial divisions. Dividide the number under test x by all numbers in the interval [2, sqrt(x)]. If the division has a remainder of 0, a prime factor has been discovered.
* The upper bound of sqrt(x) comes from the observation, that if x is not prime, it can be factored as x=a*b. If either a or b is larger than sqrt(x), the other must be smaller. Thus if no prime factor can be found equal or less than sqrt(x), x itself is a prime.
* When running in the interval [2, sqrt(x)] one should remember to check the remainder of x divided with all the found prime factors. If it is not 1, the remainder itself is a primefactor.
* It is advantageous to start a prime search algorithm from below, and then divide the original number with any prime factor found. If the original number reaches 1 after such a division, all prime factors have been found and the search can stop early.
* For factors above 2, only odd values have to be searched.

## Naive solution

With x being the number under test, make a for-loop that searches all odd numbers in the interval [2, sqrt(x)] and do trial division using the considerations described above.
For my personal enjoyment I have implemented a solutions that adds any primefactor found to a linked list, which is then printed at the end of the search. 

## Smart solution

Due to the usage of large primes in cryptography, alot of research has gone into designing efficient prime-search algorithms. For any serious application I recommend looking into their pros and cons, and choosing one (or more likely a combination) of these algorithms [Wikipedia: Computational methods](https://en.wikipedia.org/wiki/Prime_number#Computational_methods). As an interesting observation, the faster algorithm are typically probabilistic, and does not guarentee that all "hits" are actually primes. They are then often paired with slow but deterministic algorithm to re-check all the candidates values found.

Idea for a smart solution:
Pre-compute a large list of prime numbers, store them in an array, and implement a for-loop that only searches through these existing primes and check if they are factors with trivial division.
This solution represents a trade-off. It achieves fast run-time execution by having done a heavy pre-computation once, and by having a large array kept in program memory. I judge that for most applications this is a sensible trade-off, but it should be evaluated per use case. An example where it does not pay off is if only a few factorisations have to be done.

If the list runs out without the number under test beeing completely factored one can continue with another search algorithm, e.g. the one used in the Naive solution.

I am yet to have implemented this solution. I have, however, written a small CLI-program for generating the first N primes as presented below. The first 1000 are given in the file `1000_first_primes.csv` as an output example.

## genPrimes program
Usage: `genPrimes.out [-v] [-n <number of primes to generate>] [-o <outputfile>] [-h]`
Warning: I have not implemented an upper bound on the number of primes that can be requested.
TODO: Gracefully release ressources before calling `exit()`. Currently the program relies on the exit call to release ressources (open file or malloc'ed memory) if an error is encountered. While this works just fine I consider it bad practise as it is prone to cause bugs if the program is expanded later.

This program combines a bit of both solutions to find a user specified amount of primes starting from the prime number `2` and up.
The program runs a while loop that searches for primes, untill the requested amount have been found. The loop searches for primes
by itterating through all the odd numbers, and checking if they can be factored by any of the previously found primes. If yes, the number is not a prime, if no, it must be a prime and is added to the list.
