CXX=g++
CXXFLAGS= -lwinmm
LDFLAGS= -lwinmm
SOURCE= CSD_SYNTH.o MelodyGenerator.o pch.o olcNoiseMaker.o Oscillator.o  Saw.o Sine.o Square.o Triangle.o

example: $(SOURCE)
	$(CXX) -o $@ $(SOURCE) $(LDFLAGS)
	rm -f *.gch *.o

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $<
clean:
	rm -f *.gch *.o
