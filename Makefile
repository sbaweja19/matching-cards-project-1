#Makefile
CXX_FLAG = --std=c++11 -g

all: game testcards

game: main.o cards.o
	g++ $(CXX_FLAG) -o game main.o cards.o

testcards: testcards.o cards.o
	g++ $(CXX_FLAG) -o testcards testcards.o cards.o

cards.o: cards.cpp
	g++ -c $(CXX_FLAG) cards.cpp

main.o: main.cpp
	g++ -c $(CXX_FLAG) main.cpp

testcards.o: testcards.cpp
	g++ -c $(CXX_FLAG) testcards.cpp

clean:
	rm -f game main.o cards.o testcards testcards.o