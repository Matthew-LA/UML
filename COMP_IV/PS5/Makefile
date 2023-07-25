all:
	make EDistance

EDistance: main.o EDistance.o
	g++ -o EDistance -g main.o EDistance.o -lsfml-system

main.o: EDistance.cpp main.cpp
	g++ -c -g main.cpp -ansi -pedantic -Wall -Werror

EDistance.o: EDistance.hpp EDistance.cpp
	g++ -c -g -O2 EDistance.cpp -ansi -pedantic

clean:
	rm -f *.o *~ EDistance 
