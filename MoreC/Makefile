# Makefile for the Week 4 assignment

CFLAGS = -Wall -g

.PHONY: all
all: qsim lltests

qsim: qsim.o llist.o
	$(CC) -o qsim $(CFLAGS) qsim.o llist.o $(LDFLAGS)

lltests: lltests.o llist.o
	$(CC) -o lltests $(CFLAGS) lltests.o llist.o $(LDFLAGS)

qsim.o: qsim.c llist.h

lltests.o: lltests.c llist.h

llist.o: llist.c llist.h

clean:
	rm -f lltests qsim *.o *~

