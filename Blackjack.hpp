#ifndef BLACKJACK_HPP
#define BLACKJACK_HPP
#include "Deck.hpp"
//includes the deck to make a deck class
using namespace std;
//Header class with a deck object that will be used to play, score keepers, and functions to play for the 2 players.
//public functions are for the constructor and play function that will call all the private stuff.
class Blackjack {
    private:
        Deck playdeck;
        int playerscore;
        int dealerscore;
        void playerTurn();
        void dealerTurn();
    public:
        Blackjack();
        void play();
};

#endif