all: compile link run

delete:
	del *.o

compile:
	g++ -c main.cpp src/*.cpp

link:
	g++ *.o -o main 

run:
	./main.exe
