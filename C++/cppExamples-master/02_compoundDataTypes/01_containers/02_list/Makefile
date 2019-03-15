CC = g++ -g
CFLAGS = -Wall -std=c++1z

all: list

list: main.o
	$(CC) -o $@ $(CFLAGS) main.o

.cpp.o:
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f list
