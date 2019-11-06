//cards.h
//Authors: Your Partner's Name and Your Name
//All class declarations go here
#include <string>
#ifndef CARDS_H
#define CARDS_H

#endif
using namespace std;
// Use this file to define all your classes and public functions
// You should design your program with OOP prinicples using classes
// An example of class design would be having Card, CardList and Player as Classes.
// Card represent Node in your LinkedList which has some data in it
// CardList can be your LinkedList Class which has operations such as append, remove etc
// Player class represents your game player
// Think about the public functions that should be part of each class. (All public function need to be tested in unit testing)
// One of the important functions is search / find which is essential for players to find cars in their opponent's "hand"
// Make sure you overload the desired operators
// This is not the fixed design. We are not expecting exactly 3 classes. You can do with less or more.
// Important thing to consider is abstraction.

class Card{
private:
	string val;
	Card* next;
public:
	Card(string s);
	Card();
	string getVal() const {return val;};
	Card* getNext() const {return next;};
	void setVal(string s) {val = s;};
	void setNext(Card* n) {next = n;};
	bool operator==(const Card& c);
};

class Hand {
public:
	Hand();
	~Hand();
	Hand(const Hand& source);
	void print() const;
	void append(string val);
	//void removeNextCard(Card* prevN);
	void removeCard (Card* n);
	Card* getFirst() const {return first;};
	bool contains(Card* c) const;
	void removeCardWithVal(string s);
	friend std::ostream& operator<<(std::ostream& os, const Hand& h);
private:
	Card* first;
};