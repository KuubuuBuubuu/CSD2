CC = g++
CFLAGS = -I/usr/local/include -Wall -std=c++1z
LDFLAGS= -ljack

all: example

example : synth.o sine.o oscillator.o simpleSynth.o jack_module.o main.o
	$(CC) -o $@ $(CFLAGS) synth.o sine.o oscillator.o simpleSynth.o jack_module.o main.o $(LDFLAGS)

.cpp.o:
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f example
