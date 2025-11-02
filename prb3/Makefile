CC = gcc
CFLAGS = -Wall -O2

all: build

build: prb1.out genPrimes.out

prb1.out: prb1.c
	$(CC) -o $@ prb1.c $(CFLAGS)

prb2.out: prb2.c
	$(CC) -o $@ prb2.c $(CFLAGS)

genPrimes.out: genPrimes.c
	$(CC) -o $@ genPrimes.c $(CFLAGS)

run: build
	./prb1.out

clean:
	rm -rvf *.out
