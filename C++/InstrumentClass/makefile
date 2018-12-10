SOURCE = instrumentClass.o main.o

instrument: $(SOURCE)
	g++ -o $@ $^

.cpp.o: instrumentClass.cpp main.cpp
	g++ -c $<

clean:
	rm -f ./*.o
