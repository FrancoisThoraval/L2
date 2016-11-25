all : bag.o set.o main.o
	g++ bag.o set.o main.o -o programme

main : main.o
	g++ -c main.c -Wall
bag : bag.o
	g++ -c bag.c -Wall

set : set.o
	g++ -c set.c -Wall
