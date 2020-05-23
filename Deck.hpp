#ifndef DECK_HPP
#define DECK_HPP
#include "PlayingCard.hpp"

using namespace std;

class Deck {
    private:
    //playing card array for 52 cards in a deck, and cardnum to keep track of where the drawpile is at
        PlayingCard Cards[52];
        int cardnum = 0;
    public:
        Deck();
        void shuffle();
        PlayingCard draw();
        void printDeck();
};

#endif