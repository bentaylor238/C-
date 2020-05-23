#include <iostream>
using namespace std;

//These 3 functions will be called in main in while loops to play different rounds or display the menu
bool yahtzeeFourDice();
bool yahtzee();
int yahtzeeMenu(string yhtz1,string yhtz2);

const int numberOfRolls=7;

int main() {
    //This char will control the main while loop that the game is in, as long as the user wants to keep playing, it will continue.
    char playagain = 'y';
    
    //This is the main while loop that will display the beginning menu as long as the user wants to keep playing, even after winning
    while(playagain == 'y') {
        // decision is for the main menu response of the user while the bools are the returns from the rounds of each function.
        //They are all set to false because the user has not won any rounds yet and win will be changed once the user has completed
        //both rounds
    	int decision;
    	bool y1=false, y2=false, win=false;
    	
    	//These are the default strings until the user plays either round
    	string yhtz1 = "NOT_ATTEMPTED", yhtz2 = "NOT_ATTEMPTED";
        
        //Welcome to the game
    	cout << "Welcome to Yahtzee Extended Edition!!!!!" << endl << endl;
    	cout << "Complete all 4 rounds to Win! You will be allowed 7 rolls each round" << endl << endl;
    	
    	//This nested while loop is where the game begins since they have not won yet, the functions will be called
    	//within this loop.
    	while(!win){
    	    //decision determines which function we will call by calling the menu function and sending our strings to know if 
    	    //the rounds have been completed.
        	decision = yahtzeeMenu(yhtz1,yhtz2);
        	//If the user chooses the 1st we play normal yahtzee
        	if(decision==1) {
        	    //yahtzee() is a bool function, so we will receive a true or false
                y1 = yahtzee();
                //if true then we have won the round
                if(y1) {
                    yhtz1 = "COMPLETED";
                }
                //if false then we failed the round
                else{
                    yhtz1 = "FAILED";
                }
        	}
        	//If the user chooses 2 then we play yahtzee 4 of a kind and go through the same if else logic as the yahtzee previously.
        	else if(decision==2) {
                y2 = yahtzeeFourDice();
                if(y2) {
                    yhtz2 = "COMPLETED";
                }
                else {
                    yhtz2 = "FAILED";
                }
        	}
        	//In the menu function it checks for bad input so the only other option is 3, which is end the game.
    	    else {
    		    cout << "Thanks for playing!!!!" << endl;
    		    return 0;
    	    }
    	    //If the user doesn't end the game we test to see if they have won the game yet and congratulate them if so.
    	    //If they haven't won, the menu is repeatedly shown until they quit or win. When they win we ask if they would like
    	    //to continue playing and if not the while loop will end and the game is over.
    	    if(y1 && y2){
    	        win = true;
    	        cout << endl;
    	        cout << "Congrats, you won!!!! Would you like to play again? (y/n): ";
    	        cin >> playagain;
    	        while(playagain!='y' && playagain!='n') {
    	            cout << "You entered crap, please enter 'y' or 'n': ";
    	            cin >> playagain;
    	            cout << endl << endl;
    	        }
    	    }
    	}
    }
}



int yahtzeeMenu(string yhtz1,string yhtz2) {
	//display the game menu
	int choice;
	cout << "Please select a round to play: " << endl << endl;
	cout << "1. Yahtzee (all 5 dice the same number)........................." << yhtz1 << endl;
	cout << "2. 4 of a kind (4 dice of the same number)......................" << yhtz2 << endl;
	cout << "3. Quit Playing" << endl;
    //ask the user what they would like to do
	cin >> choice;
    //check for bad input and don't let them escape until they give good input
	while(choice < 1 or choice > 3) {
		cout << "You entered crap, please try again! (a number between 1 and 5): ";
		cin >> choice;
	}
    //returns their choice
	return choice;
}

//Yahtzee function
bool yahtzee() {
    //5 dice variables and choice to hold, starting with an impossible value in reference to our randomizer so it
    //will show all 5 dice
	int d1, d2, d3, d4, d5;
	int dicechoice=7;
	
	cout << "You have 7 rolls to get a Yahtzee." << endl << endl;
	//This loop limits the user to 7 rolls everytime they play.
	for(int i=0; i<numberOfRolls; i++) {
	    //shows the first roll
		srand(time(NULL));
		
		cout << "Here is your roll: " << endl;
		
        if(d1 != dicechoice) {
            d1 = rand()%6+1;
        }
        if(d2 != dicechoice) {
            d2 = rand()%6+1;
        }
        if(d3 != dicechoice) {
            d3 = rand()%6+1;
        }
        if(d4 != dicechoice) {
            d4 = rand()%6+1;
        }
        if(d5 != dicechoice) {
            d5 = rand()%6+1;
        }    

        cout << d1 << " " << d2 << " " << d3 << " " << d4 << " " << d5 << endl;
        //test to see if they're all equal
        if(d1 == d2 && d2 == d3 && d3 == d4 && d4 == d5) {
            //need to add to put in correct turn number, because 0 turns doesn't make sense
            i++;
            //congratulate user and end the function returning true, or resulting in completed.
            cout << "You got a Yahtzee!!! with the number " << d1 << " in " << i << " turns." << endl;
            return true;
        }  
        //This runs as long as i is less than 6 or whatever the variable is so that it doesn't ask the 
        //user what dice to hold after their last round
        else if(i<(numberOfRolls-1)) {
            cout << "Pick a number to hold(usually the number with the most dice): ";
            cin >> dicechoice;
            
        }
	}
    //if they lose it returns false, resulting in failed.
    cout << "Sorry you lost, try again." << endl;
    return false;
}

//Yahtzee four dice game
bool yahtzeeFourDice() {
    //uses the same logic as the last game, with only one variation that will be noted.
    int d1, d2, d3, d4, d5;
	int dicechoice=7;
    
    cout << "You have 7 rolls to get at least 4 dice the same." << endl << endl;
    
	for(int i=0; i<numberOfRolls; i++) {
        srand(time(NULL));
		
		cout << "Here is your roll: " << endl;
		
        if(d1 != dicechoice) {
            d1 = rand()%6+1;
        }
        if(d2 != dicechoice) {
            d2 = rand()%6+1;
        }
        if(d3 != dicechoice) {
            d3 = rand()%6+1;
        }
        if(d4 != dicechoice) {
            d4 = rand()%6+1;
        }
        if(d5 != dicechoice) {
            d5 = rand()%6+1;
        }    

        cout << d1 << " " << d2 << " " << d3 << " " << d4 << " " << d5 << endl;
        //This is the main difference, we test all the possible 4 of a kind to know if the user has won and congratulate
        //them and return true(complete).
        if((d1==d2 && d2==d3 && d3==d4) or (d1==d3 && d3==d4 && d4==d5) or (d2==d3 && d3==d4 && d4==d5) or 
        (d1==d2 && d2==d4 && d4==d5) or (d1==d2 && d2==d3 && d3==d5)) {
            cout << "You got 4 of a kind!!!" << endl;
            return true;
        }
        else if(i<(numberOfRolls-1)) {
            cout << "Pick a number to hold(usually the number with the most dice): ";
            cin >> dicechoice;
        }
	}
	
	cout << "Sorry you lost, try again. " << endl;
	return false;
}