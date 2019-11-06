#include <iostream>
#include <fstream>
#include <string>
#include "cards.h"

using namespace std;

int main(int argv, char** argc){
  if(argv != 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }
  
  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);
  string line;

  if (cardFile1.fail()){
    cout << "Could not open file " << argc[1];
    return 1;
  }

  if (cardFile2.fail()){
    cout << "Could not open file " << argc[2];
    return 1;
  }

  // Create two objects of the class you defined 
  // to contain two sets of cards in two input files
  Hand hand1;
  Hand hand2;

  // Read each file and store cards in hand1 and hand2
  
  while (getline (cardFile1, line) && (line.length() > 0)){
    hand1.append(line);
  }
  cardFile1.close();

  while (getline (cardFile2, line) && (line.length() > 0)){
    hand2.append(line);
  }
  cardFile2.close();

  // Start the game

  Card* a = hand1.getFirst();;
  int turn = 0;
 
  while (a != nullptr){
    if (turn%2==0){
      if (hand2.contains(a)){
        cout << "Alice picked matching card " << a->getVal() << endl;
        hand2.removeCardWithVal(a->getVal());
        hand1.removeCard(a);
        turn++;
        a = hand2.getFirst();
      }
      else{
        a=a->getNext();
      }
    }
    else if (turn%2==1){
      if (hand1.contains(a)){
        cout << "Bob picked matching card " << a->getVal() << endl;
        hand1.removeCardWithVal(a->getVal());
        hand2.removeCard(a);
        turn++;
        a = hand1.getFirst();
      }
      else{
        a=a->getNext();
      }
    }
  } 


  cout << "\n" << "Alice's cards:\n" << hand1 << endl;
  cout << "Bob's cards:\n" << hand2;

  return 0;
}
