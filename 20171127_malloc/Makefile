# Makefile for malloc
 
CC=gcc
CFLAGS= -Wall -Wextra -std=c99 -g -fPIC -D_DEFAULT_SOURCE
LDFLAGS=
LDLIBS=

SRC= test.c
OBJ= ${SRC:.c=.o}
DEP= ${SRC:.c=.d}
 
test: ${OBJ}

libmalloc.so: malloc.o
	${CC} -shared -o libmalloc.so malloc.o
 
clean:
	rm -f *~ *.o
	rm -f libmalloc.so
