CC= g++
CFLAGS= -g -Wall -std=c++0x -pedantic
Boost= -lboost_unit_test_framework

all:
	make TextWriter TestWriter

TextWriter:  RandWriter.o TextWriter.o
	$(CC) -o TextWriter TextWriter.o RandWriter.o $(CFLAGS)
	
TestWriter: RandWriter.o Test.o
	$(CC) -o TestWriter RandWriter.o Test.o $(Boost)

Test.o: RandWriter.h Test.cpp 
	$(CC) -c Test.cpp $(CFLAGS)
	
TextWriter.o: RandWriter.h TextWriter.cpp
	$(CC) -c TextWriter.cpp $(CFLAGS)

RandWriter.o: RandWriter.h RandWriter.cpp
	$(CC) -c RandWriter.cpp $(CFLAGS)

clean:
	rm -f *.o *~ TextWriter TestWriter