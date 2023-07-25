CC= g++
CFLAGS= -Wall -Werror -ansi -pedantic
SFMLFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

all:
	make PhotoMagic

PhotoMagic: PhotoMagic.o FibLFSR.o
	$(CC) PhotoMagic.o FibLFSR.o -o PhotoMagic $(SFMLFLAGS)

PhotoMagic.o: PhotoMagic.cpp FibLFSR.h
	$(CC) $(CFLAGS) -c PhotoMagic.cpp FibLFSR.h

FibLFSR.o: FibLFSR.cpp FibLFSR.h
	$(CC) -c FibLFSR.cpp 

clean:
	$(RM) *.o
	$(RM) PhotoMagic
