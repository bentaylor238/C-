#include <iostream>
#include "Blackjack.hpp"
#include "PlayingCard.hpp"
//includes playingcard to make a temporary card object to use to add the 2 players' scores
using namespace std;

void Blackjack::playerTurn() {
    //sets choice to 'h' so the while loop will automatically run once
    //displays score and continues to ask if they would like to hit or stand until they choose stand
    char choice = 'h';
    
    cout << "Current player score: " << playerscore << endl;
    cout << "Hit(h) or stand(s): ";
    cin >> choice;
    
    PlayingCard drawcard;
    
    while(choice == 'h') {
        //draws a card and sets it as the temp card
        drawcard = playdeck.draw();
        
        cout << "Player draws a " << drawcard.toString() << endl;
        //adds teh value to the score
        playerscore +=drawcard.getValue();
        //if the player busts it breaks the while loop
        if(playerscore > 21) break;
        //Asks if they would like to hit or stand if they haven't busted
        cout << "Current player score: " << playerscore << endl;
        cout << "Hit(h) or stand(s): ";
        cin >> choice;
    }
}

void Blackjack::dealerTurn() {
    //Sets a temp card to set as the draw card so that values can be added to his score until he's at 17 or above
    PlayingCard drawcard;
    while(dealerscore < 17) {
        drawcard = playdeck.draw();
        dealerscore += drawcard.getValue();
    }
    
}

Blackjack::Blackjack() {
    //automatically sets teh scores to zero at teh beginning of being called and shuffles the deck object made
    playerscore = 0;
    dealerscore = 0;
    playdeck.shuffle();
}

void Blackjack::play() {
    //uses two temporary player cards for his draw cards to display and 2 temp dealer cards and displays one of those
        PlayingCard play1, play2;
        play1 = playdeck.draw();
        play2 = playdeck.draw();
        
        PlayingCard dealer1, dealer2;
        dealer1 = playdeck.draw();
        dealer2 = playdeck.draw();
        
        cout << "Player starts with the " << play1.toString() << " and " << play2.toString() << endl;
        cout << "Dealer is showing the " << dealer1.toString() << endl;
        //adds the values of the 2 drawn cards to the 2 players' scores
        playerscore = play1.getValue() + play2.getValue();
        dealerscore = dealer1.getValue() + dealer2.getValue();
        //series of if statements that determine whether whether to play the players' turns
        if(playerscore < 21) {
            playerTurn();
        }
        if(playerscore < 21) {
            dealerTurn();
        }
        //if the player busts, it lets them know
        if(playerscore > 21) {
            cout << "Player busted!!!!" << endl;
        }
        
        //series of if else if statements that determines the winner adn displays the results to the user
        cout << "Final score - Player: " << playerscore << ", Dealer: " << dealerscore << endl;
        if(playerscore > dealerscore && playerscore < 22) {
            cout << "Congratulations, you won!!!!!" << endl << endl;
        }
        
        else if(dealerscore > playerscore && dealerscore < 22) {
            cout << "Dealer wins, better luck next time!" << endl << endl;
        }
        
        else if(playerscore == dealerscore) {
            cout << "It's a push." << endl << endl;
        }
        
        else if(dealerscore > 21) {
            cout << "Dealer busted, you win!!!!" << endl << endl;
        }
        
        else if(playerscore > 21) {
            cout << "You busted, good try." << endl << endl;
        }
        
}