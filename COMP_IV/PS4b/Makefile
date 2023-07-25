CC= g++
CFLAGS= -g -Wall -Werror -std=c++0x -pedantic
SFLAGS= -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
BOOST= -lboost_unit_test_framework


all: KSGuitarSim SStest SSLite

KSGuitarSim: KSGuitarSim.o StringSound.o CircularBuffer.o
	$(CC) KSGuitarSim.o StringSound.o CircularBuffer.o -o KSGuitarSim $(SFLAGS)

SSLite:	SSLite.o StringSound.o CircularBuffer.o
	$(CC) SSLite.o StringSound.o CircularBuffer.o -o SSLite $(SFLAGS)

SStest:	SStest.o StringSound.o CircularBuffer.o
	$(CC) SStest.o StringSound.o CircularBuffer.o -o SStest $(BOOST)

KSGuitarSim.o: KSGuitarSim.cpp StringSound.hpp
	$(CC) -c KSGuitarSim.cpp StringSound.hpp $(CFLAGS)

SSLite.o: SSLite.cpp StringSound.hpp
	$(CC) -c SSLite.cpp StringSound.hpp $(CFLAGS)

StringSound.o: StringSound.cpp StringSound.hpp
	$(CC) -c StringSound.cpp StringSound.hpp $(CFLAGS)

CircularBuffer.o: CircularBuffer.cpp CircularBuffer.hpp
	$(CC) -c CircularBuffer.cpp CircularBuffer.hpp $(CFLAGS)

SStest.o: SStest.cpp
	$(CC) -c SStest.cpp $(Boost)

clean:
	rm *.o
	rm *.gch
	rm KSGuitarSim
	rm SStest
	rm SSLite

