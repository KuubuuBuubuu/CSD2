CC = g++
CFLAGS = -I/usr/local/include -Wall -std=c++1z
LDFLAGS= -L/usr/local/lib -lbear-audio

all: simpleSine

simpleSine : main.o
	$(CC) -o $@ $(CFLAGS) main.o $(LDFLAGS)

.cpp.o:
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f simpleSine
