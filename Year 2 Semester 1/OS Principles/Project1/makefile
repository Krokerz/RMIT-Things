all: mmcopier mscopier

%: %.o
	g++ -Wall -Werror -std=c++11 -O -lpthread $< -o $@

mmcopier.o: task1.cpp task1.h
	g++ -Wall -Werror -std=c++11 -O -c $< -o $@

mscopier.o: task2.cpp task2.h
	g++ -Wall -Werror -std=c++11 -O -c $< -o $@

clean:
	rm *.o mmcopier mscopier