all: memalloc

%: %.o
	g++ -Wall -std=c++11 -O $< -o $@

memalloc.o: main.cpp main.h
	g++ -Wall -std=c++11 -O -c $< -o $@

clean:
	rm *.o memalloc