all:
	make ps1a

ps1a: FibLFSR.o test.o
	g++ FibLFSR.o test.o -o ps1a -l boost_unit_test_framework

test.o: FibLFSR.h FibLFSR.cpp test.cpp
	g++ -c FibLFSR.cpp test.cpp -l boost_unit_test_framework

FibLFSR.o: FibLFSR.h FibLFSR.cpp
	g++ -c FibLFSR.cpp 

clean:
	rm -f *.o *~ ps1a
