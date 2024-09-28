all: firstfit bestfit

%: %.o
	g++ -Wall -Werror -Wno-deprecated -std=c++11 -O -lpthread $< -o $@

firstfit.o: firstfit.cpp memalloc.h
	g++ -Wall -Werror -Wno-deprecated -std=c++11 -O -c $< -o $@

bestfit.o: bestfit.cpp memalloc.h
	g++ -Wall -Werror -Wno-deprecated -std=c++11 -O -c $< -o $@

clean:
	rm *.o firstfit bestfit