CC = g++ -g

all: aPointer

aPointer: main.o
	$(CC) -o $@ main.o

.cpp.o:
	$(CC) -c $<

clean:
	rm -f *.o
	rm -f aPointer
