#ifndef DECK_H
#define DECK_H
#include "Card.h"
#include <string>
using namespace std;

class Deck
{
  private:
    Card deck[52];
    int topCard;

  public:
    Deck();
    void refreshDeck();
    Card deal();
    void shuffle();
    int cardsLeft();
    void showDeck();
};
#endif