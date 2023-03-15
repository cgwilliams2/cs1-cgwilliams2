// Colton Williams 03/15/2023 
//Guess Number Program -- has user guess a random number between 1 and 20






#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <string>

using namespace std;

void game(string name);
int randomNumber();
int readNumber();
int checkGuess(int gNum, int uNum);
bool win(int gNum, int uNum);
bool lower(int gNum, int uNum);
bool higher(int gNum, int uNum);
void clearScreen();
void test();

int timesPlayed = 0, timesWon = 0, timesLost = 0;
double percentLost, percentWon;


int main(int argc, char* argv[]) {
  if (argc == 2 and string(argv[1]) == string("test")) {
    // FIXME1: call testDistance function
    test(); 
  }
  else {

    



    clearScreen();
    cout << "Welcome to --Guess The Number-- game! \nWhat is your name?" << endl;
    string name;
    cin >> name; 
    cout << "Hello, " << name << ". I am thinking of a number between 1 and 20." << endl; 

    game(name);

    percentLost = ((double)timesLost / (double)timesPlayed) * 100;
    percentWon = ((double)timesWon / (double)timesPlayed) * 100;
    cout << "You played " << timesPlayed << " times, you won " << percentWon << "% of games played, and lost " << percentLost << "% of games played." << endl; 

    



    return 0; 
  }

}


void game(string name){
    int uNum, numG, gNum, c; 
    bool won = false, quit = false; 
    
    

    
    while(!quit){
        timesPlayed++;
        won = false;
        numG = 0;
        gNum = randomNumber();
        cout << "You get 6 tries to guess the number." << endl;
        while(numG <= 6 && !won){
            if(numG >= 6){
            cout << "Sorry, " << name << " You lose..." << endl;
            timesLost++;
            break; 
            }

            cout << "Take a guess." << endl; 
            uNum = readNumber();
            numG++;
            c = checkGuess(gNum, uNum);
            if(c == 0){
                cout << "Congratulations, " << name <<"! You WIN!! You guessed my number in " << numG << " guesses." << endl; 
                won = true; 
                timesWon++;
            }
            if(c == 1)
                cout << "Your guess is too low." << endl;
            if(c == 2)
                cout << "Your guess is too high." << endl; 
            if(c == -1)
                cout << "\n***ERROR has occured(checkGuess)***\n" << endl; 
            



        }
         
        

        cout << "Would you like to play again? Enter [y/Y], anything else to quit." << endl;

        cin.ignore(100, '\n');
        int q = getchar();
        
        if((q != 'y' && q != 'Y') || q == '\n')
            quit = true;
        else 
        clearScreen();


     
    }


}

int randomNumber(){
    return rand() % 20 + 1; 
}

int readNumber(){
    int num; 
    cin >> num; 
    return num;
}

int checkGuess(int gNum, int uNum){
    if(win(gNum, uNum))
    return 0;
    if(lower(gNum, uNum))
    return 1;
    if(higher(gNum, uNum))
    return 2;

  return -1; 

}

bool win(int gNum, int uNum){
    if(gNum == uNum)
    return true;
    
    return false; 
}

bool lower(int gNum, int uNum){
    if(gNum > uNum)
    return true;

    return false; 
}

bool higher(int gNum, int uNum){
    if(gNum < uNum)
    return true; 

    return false; 
}


void clearScreen() {
    system("clear");
}

void test(){
    assert(checkGuess(0, 0) == 0);
    assert(checkGuess(10, 5) == 1);
    assert(checkGuess(5, 10) == 2);
    printf("%s\n", "all test cases passed...\n");
    
}

