#include <iostream>
#include <iomanip>
#include "Deck.hpp"
#include "PlayingCard.hpp"

using namespace std;
//constructor
Deck::Deck() { 
    //automatically sets the default suit to clubs
    string suit = "clubs";
    //Uses a for loop to assign the 3 different kinds of variables to each card
    for(int i=0; i < 52; i++) {
        //Uses if else if statements to assign the suit that will be assigned to the cards
        if(i>12 && i < 26) {
            suit = "hearts";
        }

        else if(i > 25 && i < 39) {
            suit = "spades";
        }

        else if(i > 38 && i < 52) {
            suit = "diamonds";
        }
        //This is a long list of crappy if else if statements that assigns the 3 different variables
        //to each card with 52 different possibilities. It sucks, but hey it works
        // this one assigns the 1-10
        if((i%13) < 9) {
            PlayingCard NewCard(suit, ((i%13)+2), to_string((i%13) +2));
            Cards[i] = NewCard;//(suit,(i+2), to_string((i%13)+2));
        }
        //This assigns the jack
        else if((i%13) == 9) {
            PlayingCard NewCard(suit, 10, "Jack");
            Cards[i] = NewCard;
        }
        //queen
        else if((i%13) == 10) {
            PlayingCard NewCard(suit, 10, "Queen");
            Cards[i]= NewCard;
        }
        //king
        else if((i%13) == 11) {
            PlayingCard NewCard(suit, 10, "King");
            Cards[i]= NewCard;
        }
        //ace
        else if((i%13) == 12) {
            PlayingCard NewCard(suit, 11, "Ace");
            Cards[i] = NewCard;
        }
    }
}
    
void Deck::shuffle() {
    
    //seeds the time and uses a temp playing card to keep the value of the one being shuffled and then assigns it the random card
    
    srand(time(NULL));
    PlayingCard temp;
    int random;
    
    for(int i = 0; i < 52; i++) {
        temp = Cards[i];
        random = rand()%52;
        Cards[i] = Cards[random];
        Cards[random] = temp;
    }
}

PlayingCard Deck::draw() {
    //Uses a private variable cardnum to keep track of which number the draw pile is on
    //cardnum; also uses a temp int j so that card can be returned and the cardnum can be returned.
    //if it was done after return it would never add the number.
    int j;
    while(cardnum < 52) {
        j = cardnum;
        cardnum++;
        return Cards[j];
    }
}
//Prints all the cards that are left in the deck, keeps track of what cards it is on through teh cardnum variable.
void Deck::printDeck() {
    for(cardnum; cardnum < 52; cardnum++) {
        cout << Cards[cardnum].toString() << Cards[cardnum].getValue() << endl;
    }
}