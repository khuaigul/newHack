.PHONY: clean
main: parse.o main.o
	g++ -Wall -ansi -std=gnu++11 -DLOCAL -o main.exe parse.o main.o
parse.o: parse.cpp
	g++ -Wall -ansi -c -std=gnu++11 -DLOCAL -o parse.o parse.cpp
main.o: main.cpp
	g++ -Wall -ansi -c -std=gnu++11 -DLOCAL -o main.o main.cpp
clean:
	rm *.o
