# Makefile
 
CC = gcc -fsanitize=address
CPPFLAGS = -MMD
CFLAGS = -Wall -Wextra -std=c99 -O0 -g
LDFLAGS =
LDLIBS =
 
OBJ = ../hash_table.o tests.o
DEP = ${OBJ:.o=.d}
 
all: tests
 
tests: ${OBJ}
 
.PHONY: clean
 
clean:
	${RM} ${OBJ} ${DEP} tests
 
-include ${DEP}
 
# END
