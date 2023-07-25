CC= g++
CFLAGS= -g -Wall -Werror -std=c++0x -pedantic
Boost= -lboost_unit_test_framework

all:	ps4a main.out

ps4a:	test.o CircularBuffer.o
	$(CC) test.o CircularBuffer.o -o ps4a $(Boost)

main.out: main.o CircularBuffer.o
	$(CC) main.o CircularBuffer.o -o main.out

RingBuffer.o: CircularBuffer.cpp CircularBuffer.hpp
	$(CC) -c CircularBuffer.cpp CircularBuffer.hpp $(CFLAGS)

test.o: test.cpp CircularBuffer.hpp
	$(CC) -c test.cpp CircularBuffer.hpp $(CFLAGS)

main.o:	main.cpp CircularBuffer.hpp
	$(CC) -c main.cpp CircularBuffer.hpp $(CFLAGS)

clean:
	rm *.o
	rm *.gch
	rm ps4a
	rm *.out
