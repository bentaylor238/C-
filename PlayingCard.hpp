#ifndef PLAYINGCARD_HPP
#define PLAYINGCARD_HPP

using namespace std;

class PlayingCard {
    private:
        string suit;
        int value;
        string face;
        
    public:
    //default constructor
        PlayingCard();
        //constructor with parameters sent to it
        PlayingCard(string, int, string);
        string toString();
        int getValue();
};

#endif