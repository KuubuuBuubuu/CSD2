CXX=g++
CXXFLAGS= -Ic:/Program\ Files\ \(x86\)/Jack/includes -Wall -std=c++14
LDFLAGS= -Lc:/Program\ Files\ \(x86\)/Jack/lib -llibjack
SOURCE= jack_module.o MelodyGenerator.o main.o

example: $(SOURCE)
	$(CXX) -o $@ $(SOURCE) $(LDFLAGS)
	rm -f *.gch *.o

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $<
clean:
	rm -f *.gch *.o
