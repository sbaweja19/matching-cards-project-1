//cards.cpp
//Authors: Your Partner's Name and Your Name
//Implementation of the classes defined in cards.h

#include <iostream>
#include <string>
#include <fstream>
#include "cards.h"
using namespace std;

bool Card::operator==(const Card& c){
    if(val == c.getVal())
        return true;
    else return false;
}
//constructor
Card::Card() {}

//constructor
Card::Card(string s){
    val = s;
}

//pre: value is a card value
//post: new Card is added to hand with val == value
void Hand::append(string value) {
    if (first == 0) { // empty list
        first = new Card;
        first->setVal(value);
        first->setNext(0);
    }
    else {
        Card *n = first;
        while (n->getNext()) // not last node yet
            n = n->getNext();
        n->setNext(new Card);
        n->getNext()->setVal(value);
        n->getNext()->setNext(0);
    }
}

//constructor
Hand::Hand() : first(0) {}
//destructor
Hand::~Hand(){
    Card* n = first;
    while(n != 0){
        Card* next = n->getNext();
        delete n;
        n = next;
    }
}
//copy constructor 
Hand::Hand(const Hand& source) : first(0) {
    Card* n = source.first;
    while (n) {
        append(n->getVal());
        n = n->getNext();
    }
}

//post: prints all vals of Hand on separate lines
void Hand::print() const{
    Card* n = first;
    while(n){
        cout << n->getVal() << endl;
        n = n->getNext();
    }
}

//pre: n is a pointer to a card
//post: n->next gets copied to n and gets deleted
void Hand::removeCard(Card* n){
    if (n==first){
        if (n->getNext() == 0){
            delete first;
            first = nullptr;
        }
        else{
            Card* temp = n->getNext();
            n->setVal(n->getNext()->getVal());
            n->setNext(n->getNext()->getNext());
            delete temp;
        }
    }
    else if(n->getNext() == 0){
        Card* secondLast = first;
        while(secondLast->getNext()->getNext() != 0)
            secondLast = secondLast->getNext();
        delete secondLast->getNext();
        secondLast->setNext(0);

    }
    else{
        Card* temp = n->getNext();
        n->setVal(n->getNext()->getVal());
        n->setNext(n->getNext()->getNext());
        delete temp;
    }
}
//pre: string s is a card value
//post: Card with val equal to s gets removed
void Hand::removeCardWithVal(string s){
    Card* n = first;
    while(n->getVal() != s){
        n=n->getNext();
    }
    this->removeCard(n);
}
//pre: c is a pointer to a Card
//post: if this Hand containts a Card equal to c, return true, else return false
bool Hand::contains(Card* c) const{
    Card* n = first;
    while(n){
        if (*n == *c)
            return true;
        n=n->getNext();
    }
    return false;
}

/*bool operator==(const Card* c1, const Card* c2){
    if(c1.getVal() == c2.getVal())
        return true;

    else return false;
}*/

/*Card::~Card(Card* prev, Card* first){
    if(prev){
        prev.getNext() = next;
        delete this;
    }
    else{
        first = next;
        delete this;
    }
}*/

//overloaded << operator for Hand
ostream& operator<<(ostream& os, const Hand& h) {
    Card* n = h.first;
    while(n){
        os << n->getVal() << endl;
        n=n->getNext();
    }
    return os;
}



