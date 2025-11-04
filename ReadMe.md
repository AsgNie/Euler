# Euler
This repository consist of my toughts and solutions to problems presented by [Project Euler](https://projecteuler.net/). The problems are of a mathematical nature, and often requires a short program to solve them. Typically the problems are of a form where a good idea will reduce the program runtime significantly.

To each problem I attempt to present two solutions. A naive solution, that solves the problem by brute force, and a smart solution that makes use of an insight or good idea to solve the problem more efficiently.

> [!WARNING]
> I have become aware that while allowed it is discouraged to publicly shared solutions to Problem 0 to 100.
> Sharing solutions to Problem 101 and above publicly is against the rules of Project Euler.

The argument for the above rules is that the project wishes to encourage people to explore the problems and gain insights of their own. Once a problem have been solved, access is granted to the official forum where it can be discussed.

In respect of the above, I will limit my solutions to the problems 0 to 5.

## Constraints
My solutions will be in the form of small programs. The programs are written in C, compiled with GCC (currently version 13.3.0), with makefiles presented for GNU make. The setup is developed and tested on a Linux system, but should translate to Windows with little effort.

## Repository organisation
Each problem will have its own subfolder with a sepperate ReadMe-file that introduces the problem, considerations to take into account, and present the solution(s).

A make-file is included in each sub-folder, with the targets `build`, `run`, `clean` to easily compile and execute the programs.
