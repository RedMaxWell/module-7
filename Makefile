main: container.o main.o
	g++ -g -o main container.o main.o
	
container.o: container.cpp
	g++ -c -g container.cpp
	
main.o: main.cpp
	g++ -c -g main.cpp
