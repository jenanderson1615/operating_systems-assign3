#  Jen Anderson
#  anderjen@onid.oregonstate.edu
#  CS311-400
#  Homework3
#  Makefile	
 
CC=gcc
DEBUG=-g
CFLAGS=$(DEBUG) -Wall
PROGS=homework3


all: $(PROGS)

homework3: homework3.o
	$(CC) $(CFLAGS) -o homework3 homework3.o

homework3.o: homework3.c
	$(CC) $(CFLAGS) -c homework3.c

clean:
	rm -f $(PROGS) *.o *~

