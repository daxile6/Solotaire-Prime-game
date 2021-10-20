#include "Deck.h"
#include "Card.h"
#include <iostream>
using namespace std;

Deck::Deck()
{
refreshDeck();
}




void Deck::refreshDeck()
{
topCard = 0;
char the_rank[] = {'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
char the_suit[] = {'S', 'H', 'D', 'C'};
for(int i =0; i < 52; i ++){
  deck[i] = Card(the_rank[i %13],the_suit[i/13]);
}
}



Card Deck::deal()
{
    return deck[topCard++];   
}

void Deck::shuffle()
{
  srand(time(NULL));
  for(int i = 0;i<100;i++)
  {
    int x = rand() % 52;
    int y = rand() % 52;

   Card temp = deck[x];
   deck[x] =deck[y];
   deck[y] = temp;
  }
  
}

int Deck::cardsLeft() 
{
  return 52-topCard;
}
void Deck::showDeck()
{
  int count = 0;
  for(int i = 0;i<52;i++){
    deck[i].showCard();
    count ++;
    if(count ==13){
      cout << endl;
      count =0;
    }
  }


}