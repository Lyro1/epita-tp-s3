# Makefile

CC = gcc -fsanitize=address
CPPFLAGS = -MMD
CFLAGS = -Wall -Wextra -std=c99 -O0 -g
LDFLAGS =
LDLIBS =

OBJ = tree.o
DEP = ${OBJ:.o=.d}

all: tree

test: ${OBJ}

clean:
	rm -f ${OBJ} ${DEP} tree

-include ${DEP}

# END
