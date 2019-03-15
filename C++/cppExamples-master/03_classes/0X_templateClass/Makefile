CC = g++ -g

all: point

point: main.o
	$(CC) -o $@ main.o

.cpp.o:
	$(CC) -c $<

clean:
	rm -f *.o
	rm -f point
