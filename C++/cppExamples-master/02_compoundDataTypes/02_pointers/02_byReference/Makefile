CC = g++ -g

all: byReference

byReference: main.o
	$(CC) -o $@ main.o

.cpp.o:
	$(CC) -c $<

clean:
	rm -f *.o
	rm -f byReference
