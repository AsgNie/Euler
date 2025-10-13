CC = gcc
CFLAGS = -Wall -O2

all: build

build: prb1.out prb2.out

prb1.out: prb1.c
	$(CC) -o $@ prb1.c $(CFLAGS)

prb2.out: prb2.c
	$(CC) -o $@ prb2.c $(CFLAGS)

run: build
	./prb1.out
	./prb2.out

clean:
	rm -rvf *.out
