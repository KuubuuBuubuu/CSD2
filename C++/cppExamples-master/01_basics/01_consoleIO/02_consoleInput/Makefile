CC = g++

all: makeASound

makeASound : main.o
	$(CC) -o $@ main.o

.cpp.o:
	$(CC) -c $<

clean:
	rm -f *.o
	rm -f makeASound
