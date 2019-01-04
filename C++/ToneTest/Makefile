CXX=g++
CXXFLAGS= -Ic:/Program\ Files\ \(x86\)/Jack/includes -Wall -std=c++14
LDFLAGS= -Lc:/Program\ Files\ \(x86\)/Jack/lib -llibjack
SOURCE= jack_module.o sine.o square.o saw.o oscillator.o main.o

example: $(SOURCE)
	$(CXX) -o $@ $(SOURCE) $(LDFLAGS)

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $<
clean:
	rm -f *.gch *.o
