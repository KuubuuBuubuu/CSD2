
CC = g++ -g
CFLAGS = -Wall


all: union

union: union.o
	$(CC) -o $@ $(CFLAGS) union.o -llo

.cpp.o:
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f `find . -perm +111 -type f`
