CC = g++
CFLAGS = -I/usr/local/include -Wall

all: variableSizes

variableSizes : main.o
	$(CC) -o $@ $(CFLAGS) main.o

.cpp.o:
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f `find . -perm +111 -type f`
