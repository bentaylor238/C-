#include <iostream>
#include "PlayingCard.hpp"

using namespace std;
//default constructor
PlayingCard::PlayingCard() {
    value = 0;
    suit = "none";
    face = "0";
}
//constructor that assigns the object the parameters sent to it
PlayingCard::PlayingCard(string type, int num, string card) {
    value = num;
    suit = type;
    face = card;
}
//This returns the string of what face and suit the card is so it can be displayed
string PlayingCard::toString() {
    string card;
    card = face + " of " + suit;
    return card;
}
//This returns the value of the card that is assigned
int PlayingCard::getValue() {
    return value;
}