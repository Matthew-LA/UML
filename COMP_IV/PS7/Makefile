CC = g++
CFLAGS = -std=c++11 -c -g -O1 -Wall -Werror -pedantic
BOOST = -lboost_regex -lboost_date_time

all: ps7

ps7: main.o
	$(CC) -o ps7 main.o $(BOOST)
main.o: main.cpp 
	$(CC) -c main.cpp $(CFLAGS)

clean:
	rm -f *.o ps7 *~
