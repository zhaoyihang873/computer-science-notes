#
# Makefile that builds btest and other helper programs for the CS:APP data lab
# 
CC = gcc
# Keep the original tests on the native WSL ABI and preserve signed wraparound.
CFLAGS = -std=gnu99 -O0 -g -Wall -fwrapv -fno-strict-aliasing
LIBS = -lm

all: btest fshow ishow

btest: btest.c bits.c decl.c tests.c btest.h bits.h
	$(CC) $(CFLAGS) -o btest bits.c btest.c decl.c tests.c $(LIBS)

fshow: fshow.c
	$(CC) $(CFLAGS) -o fshow fshow.c

ishow: ishow.c
	$(CC) $(CFLAGS) -o ishow ishow.c

# Forces a recompile. Used by the driver program. 
btestexplicit:
	$(CC) $(CFLAGS) -o btest bits.c btest.c decl.c tests.c $(LIBS) 

clean:
	rm -f *.o btest fshow ishow *~


