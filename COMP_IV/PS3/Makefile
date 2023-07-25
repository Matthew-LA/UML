C= g++
CFLAGS= -Wall -Werror -ansi -pedantic
GFLAGS= -lsfml-graphics -lsfml-window -lsfml-system
c17 = -std=c++17

all: TFractal

TFractal: TFractal.o Triangle.o
	$(C) TFractal.o Triangle.o -o TFractal $(GFLAGS)

TFractal.o: TFractal.cpp
	$(C) -c TFractal.cpp -o TFractal.o $(CFLAGS) $(c17)

Triangle.o: Triangle.cpp Triangle.hpp
	$(C) -c Triangle.cpp -o Triangle.o $(CFLAGS) $(c17)

clean:
	rm *.o *TFractal
