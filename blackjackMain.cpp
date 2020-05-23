#include <iostream>
#include "Blackjack.hpp"
#include "Deck.hpp"
#include "PlayingCard.hpp"

using namespace std;

int main() {
    //Creates a blackjack game object and plays
    Blackjack game;
    
    game.play();
    //used for user input on whether to play again
    char selection;
    //Runs once after one game play and if they say 'n' then it don't play no more
    do {
        cout << "Would you like to play again? (y/n): ";
        cin >> selection;
        if(selection == 'y') game.play();
    } while(selection == 'y');
    
    
    return 0;
}