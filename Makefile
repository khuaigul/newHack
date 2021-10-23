.PHONY: clean
main: parse.o main.o cost.o
	g++ -Wall -ansi -std=gnu++11 -DLOCAL -o main.exe parse.o main.o cost.o
parse.o: parse.cpp classes.h
	g++ -Wall -ansi -c -std=gnu++11 -DLOCAL -o parse.o parse.cpp
main.o: main.cpp classes.h
	g++ -Wall -ansi -c -std=gnu++11 -DLOCAL -o main.o main.cpp
cost.o: cost.cpp classes.h 
	g++ -Wall -ansi -c -std=gnu++11 -DLOCAL -o cost.o cost.cpp
clean: 
	rm *.o