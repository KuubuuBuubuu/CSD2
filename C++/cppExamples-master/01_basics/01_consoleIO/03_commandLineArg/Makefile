CC = g++ -g

all: commandLineArg

commandLineArg: commandLineArg.o
	$(CC) -o $@ commandLineArg.o

.cpp.o:
	$(CC) -c $<

clean:
	rm -f *.o
	rm -f commandLineArg
