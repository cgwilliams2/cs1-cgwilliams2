// hangman.cpp

#include "hangman.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cctype>

using namespace std;

#ifdef _WIN32
#define clean() system("cls")
#else
#define clean() system("clear")
#endif


vector<string> words1;
vector<string> words2;
vector<string> words3;
int difficulty = 2; 
string gameWord, repGameWord; 
int timesWon = 0; 
int timesLost = 0;
int totalGuesses = 0;
int totalWrong = 0;
int totalRight = 0; 

// gamestates
string game0 = "     |------------\n     |/       |\n     |\n     |\n     |\n     |\n     |\n===========\n";
string game1 = "     |------------\n     |/       |\n     |        O\n     |\n     |\n     |\n     |\n===========\n";
string game2 = "     |------------\n     |/       |\n     |        O\n     |        |\n     |\n     |\n     |\n===========\n";
string game3 = "     |------------\n     |/       |\n     |        O\n     |       /|\n     |\n     |\n     |\n===========\n";
string game4 = "     |------------\n     |/       |\n     |        O\n     |       /|\\ \n     |\n     |\n     |\n===========\n";
string game5 = "     |------------\n     |/       |\n     |        O\n     |       /|\\ \n     |       /\n     |\n     |\n===========\n";
string game6 = "     |------------\n     |/       |\n     |        O\n     |       /|\\ \n     |       / \\\n     |\n     |\n===========\n";





void game(){
    cout << "Game Started" << endl;
    
    
    int menu = -1; 
   
    
    while( menu == -1){
        
        cout << "Difficulty is: " << difficulty << endl; 
        printMenu();
        cin >> menu;
        if(cin.fail()){
            cout << "Invalid input." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            menu = -1; 
        }
        if(menu == 1 ){
            changeDifficulty();
            menu = -1; 
            

        }
        if(menu == 0){
            gameRun();
            menu = -1; 
           

        }
        if(menu == 1234){
            debug();
            menu = -1; 
            

        }
            
        
    }
    
}

void gameStart(){
   gameWord = word(difficulty);
   repGameWord = "";
   for(int i = 0; i < gameWord.length(); i++){ //makes string of _ _ _ representing unguessed letters
        repGameWord+="_";
        }

}

void gameRun(){
    gameStart();
    int numwg = 0;
    int numcg = 0; 
    string wrngLetters, letter, lettersEnt;
    bool guess = false;
    bool stop = false;
    int loopCheck = 0; 
    
   

    while(!stop){
        bool newlet = false;
        
        
        clean();
        if(numwg == 0)
            cout << game0 << endl;
        if(numwg == 1)
            cout << game1 << endl;
        if(numwg == 2)
            cout << game2 << endl;
        if(numwg == 3)
            cout << game3 << endl;
        if(numwg == 4)
            cout << game4 << endl;
        if(numwg == 5)
            cout << game5 << endl;
        
        cout << "Letters not in the word: " << wrngLetters << endl;
        for(int i = 0; i < repGameWord.length(); i++){
            cout << repGameWord[i] << " "; 
        }
        cout << endl; 
        if(guess)
            cout << "You guessed a correct letter!" << endl;
        else if(numwg != 0)
            cout << "You guessed incorrectly" << endl; 
        guess = false; 

        cout << "Guess a letter then press Enter: " << endl;
        cin >> letter;
        letter = tolower(letter[0]);
        

        while(letter.length() > 1 && !stop){
             cout << "only enter one letter" << endl;
            cout << "Guess a letter then press Enter: ";
            cin >> letter;
            letter = tolower(letter[0]);
            for(int i = 0; i < lettersEnt.length(); i++){
                if(letter[0] == lettersEnt[i]){
                    cout << "Letter alredy used. Try a difffernt letter" << endl; 
                    letter = "  ";
                    loopCheck++;
                    if(loopCheck > 999){
                        stop = true;
                       

                    }
                }
            }
        }

        for(int i = 0; i < lettersEnt.length(); i++){
                if(letter[0] == lettersEnt[i]){
                  newlet = true;
                    }
            }

        while(newlet && !stop){
            for(int i = 0; i < lettersEnt.length(); i++){
                if(letter[0] == lettersEnt[i]){
                    cout << "Letter alredy used. Try a difffernt letter" << endl;
                    cin >> letter;
                    letter = tolower(letter[0]);
                    loopCheck++;
                    if(loopCheck > 999){
                        stop = true; 

                    }
                    
                    
                }
                newlet = false; 
                for(int i = 0; i < lettersEnt.length(); i++){
                if(letter[0] == lettersEnt[i]){
                  newlet = true;
                    }
                
            }

            }
        }

        lettersEnt += letter; 


        for(int i = 0; i < gameWord.length(); i++){
            if(letter[0] == gameWord[i]){
                numcg++;
                totalRight++;
                repGameWord[i] = letter[0];
                guess = true; 

            }
        }

        if(!guess){
            numwg++;
            totalWrong++;
            wrngLetters = letter + " " + wrngLetters;
            
        }

        if(numwg == 6){
            stop = true; 
            clean();
            cout << game6 << endl;
            cout << "  You  Lost :(" << endl;
            cout << "The word was: " << gameWord << endl;
            cout << "Press Enter to continue" << endl;
            timesLost++; 
            int total = numcg + numwg;
            totalGuesses += total;        
            cin.ignore();
            if(cin.get() == '\n')
            stop = true; 
            
        
        }

        if(numcg == gameWord.length()){
            stop = true; 
            clean();
            cout << "   You Won!!" << endl;
            cout << "The word was: " << gameWord << endl;
            int total = numwg + numcg;
            totalGuesses += total; 
            timesWon++; 
            cout << "It took you " << total << " trys to guess the word." << endl; 
            cout << "Press Enter to coninue" << endl; 
            cin.ignore();
            if(cin.get() == '\n')
            stop = true; 

            
        }
     
    }       


}

void changeDifficulty(){
    cout << "There are three levels of difficulty 1, 2, and 3" << endl;
    cout << "1 is words with 4 or less letters" << endl;
    cout << "2 is words with 5-8 letters" << endl;
    cout << "3 is words with 9+" << endl;
    cout << "Type 1, 2, or 3 then press enter to change difficutly" << endl; 
    cin >> difficulty;
    cout << "Difficulty is now: " << difficulty << endl;
    cout << "Press Enter to continue" << endl; 
    cin.ignore();
    cin.get();
    


}

void initialize(){
    srand(time(0));
    readFile();
}

string word(int difficulty){

    vector<string>* selectedWords = nullptr;

     if (difficulty == 1) {
        selectedWords = &words1;
    }
    else if (difficulty == 2) {
        selectedWords = &words2;
    }
    else if (difficulty == 3) {
        selectedWords = &words3;
    }
    else {
        cout << "Exiting Program ||| No word selected in 'word()' function." << endl;
        exit(EXIT_FAILURE);
    }

    if (selectedWords->empty()) {
        cout << "No more words available for the selected difficulty." << endl;
        exit(EXIT_FAILURE);
    }

    int randomIndex = rand() % selectedWords->size();
    string selectedWord = (*selectedWords)[randomIndex];
    selectedWords->erase(selectedWords->begin() + randomIndex);

    return selectedWord;
}

void printStats(){
    double percentCorrect = (static_cast<double>(totalRight) / totalGuesses) * 100; 
    double percentWrong = (static_cast<double>(totalWrong) / totalGuesses) * 100;
    int totalGames = timesLost + timesWon;
    double percentWon = (static_cast<double>(timesWon) / totalGames) * 100; 
    double percentLost = (static_cast<double>(timesLost) / totalGames) * 100;
    cout << "\n\n\n\n---->All stats calculated for this game session<----\n" << endl; 
    cout << "You Won " << timesWon << " times!" << endl;
    cout << "You lost " << timesLost << " times." << endl;
    cout << "Correct guesses: " << totalRight << endl;
    cout << "Incorrect guesses: " << totalWrong << endl;
    cout << "Total guesses: " << totalGuesses << endl;
    cout << "You guessed correctly " << round(percentCorrect) << "% of the time." << endl;
    cout << "You guessed wrong " << round(percentWrong) << "% of the time." << endl;
    cout << "You won " << round(percentWon) << "% of the time." << endl;
    cout << "You lost " << round(percentLost) << "% of the time." << endl;
    cout << "\n\n\n\n" << endl; 
}

void printMenu(){
    cout << "Type [0] then press enter to play" << endl;
    cout << "Type [1] then press enter to change difficulty" << endl;
    cout << "Type [2] then press enter to exit and display stats" << endl;

}

void readFile()
{
    ifstream inputFile("words.txt");

    if (!inputFile)
    {
        cout << "Exiting Program||| Could not open file words.txt" << endl;
        exit(EXIT_FAILURE);
    }

    string word;
    while (inputFile >> word)
    {
        for (char& c : word){
            c = tolower(c);
        }

        if(word.length() < 5)
        {
            words1.push_back(word);
        }
        if((word.length() > 5 && word.length() < 8)) 
        {
            words2.push_back(word);
        }
        if(word.length() >= 8)
        {
            words3.push_back(word);
        }

       
    }

    inputFile.close();
}

void debug(){
    cout << "DEBUG Selected Printing all info... PRESS ENTER" << endl; 
    cin.ignore();
    cin.get();
    cout << "\nALL WORDS IN WORDS1 VECTOR: \n" << endl; 
    for(const auto& word : words1)
        cout << word << " ";
    cout << "\nPress Enter to show all words in words2 vector." << endl; 
    cin.ignore();
    cin.get();
    cout << "\nALL WORDS IN WORDS2 VECTOR: \n" << endl; 
    for(const auto& word : words2)
        cout << word << " ";
    cout << "\nPress Enter to show all words in words3 vector." << endl; 
    cin.ignore();
    cin.get();
     cout << "\nALL WORDS IN WORDS3 VECTOR: \n" << endl; 
    for(const auto& word : words3)
        cout << word << " ";
    cout << "\nPress Enter" << endl; 
    cin.ignore();
    cin.get();
    




}
