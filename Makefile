.PHONY: clean

CC=gcc #could be clang if it's faster
CFLAGS = -std=c11 -I. -os -Wall -Wextra -Wfloat-equal
OBJS = assembler.o

proiect: $(OBJS)
	$(CC) $(CFLAGS) -o proiect $(OBJS)

assembler.o: assembler.h

clean:
	rm proiect *.o