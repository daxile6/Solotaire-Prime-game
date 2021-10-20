// Name : Steven Nguyen
//Class (CECS 282-01)
//Project Name (Prog 1 – Solitaire Prime)
// Due Date (09/13/2021)
// //I certify that this program is my own original work. I did not copy any part of this program from any other source. I further certify that I typed each and every line of code in this program
#include <iostream>
#include "Card.h"
#include "Deck.h"
using namespace std;

bool isPrime(int number){
    if (number <= 1)
        return false;
    for (int i = 2; i < number/2; i++)
        if (number % i == 0)
            return false;
    return true;
}

void play_solotaire(Deck the_deck){
  int pile = 0;
  int sum =0;
  int tracker = 0;
  while(the_deck.cardsLeft() != 0)
  {
    Card card = the_deck.deal();
    card.showCard();
    sum += card.getValue();
    tracker = sum;
    if (isPrime(sum)==true){
      pile += 1;
      cout<<", Prime : "<<sum<<endl;
			sum = 0;
    } 
    else{
      cout<<",";
    }
  
  }
  if(the_deck.cardsLeft()==0){
    if(isPrime(tracker)==true){
      cout << "Winner in " << pile << " piles! " << endl;
    }
    else if(isPrime(tracker) == false){
       cout << "loser " << endl;
    }
  }
  

}

int main() {
  int option;
	Deck the_deck;
  cout << "Welcome to Solitaire Prime! " <<endl;
  do
    {   
      cout << "1) New Deck" << endl;
      cout << "2) Display Deck" << endl;
      cout << "3) Shuffle Deck" << endl;
      cout << "4) Play Solotaire Prime" << endl;
      cout << "5) Exit" << endl;
      option = 0;
      cin >> option;
      if (option ==1)
      {
        cout << "You have refreshed your deck " <<endl;
        the_deck.refreshDeck();
      }
      else if(option==2)
      {
       the_deck.showDeck();
      }
      else if(option ==3)
      {
      cout << "You have shuffled the deck " <<endl;
      the_deck.shuffle();
       }
      else if(option ==4)
      {
      play_solotaire(the_deck);
      }
      else if(option ==5)
      {
      cout << "You have exit the game " <<endl;
      }
      else{
      cout << "Please choose the options available  " <<endl;
      }
       
    } while (option != 5);
return 0;
}

