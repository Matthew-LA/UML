C= g++
CFLAGS= -Wall -Werror -ansi -pedantic
GFLAGS= -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
c11 = -std=c++11

all:	
	make NBody

NBody: CelestialBody.o main.o
	$(C) CelestialBody.o main.o -o NBody $(GFLAGS) $(c11)

CelestialBody.o: CelestialBody.cpp CelestialBody.hpp 
	$(C) -c CelestialBody.cpp -o CelestialBody.o $(CFLAGS) $(c11)

main.o: main.cpp CelestialBody.hpp
	$(C) -c main.cpp -o main.o $(CFLAGS) $(c11)

clean:
	rm *.o *NBody