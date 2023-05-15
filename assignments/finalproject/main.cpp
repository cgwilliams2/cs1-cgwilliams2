// main.cpp

#include "hangman.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
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

int main() {
    clean();
    initialize();
    cout << "Welcome to my Hangman game!" << endl; 
    cout << "This game picks a word based on the difficulty you select." << endl;
    cout << "There are three levels of difficulty 1, 2, and 3" << endl;
    cout << "1 is words with 4 or less letters" << endl;
    cout << "2 is words with 5-8 letters" << endl;
    cout << "3 is words with 9+" << endl;
    cout << "Defualt difficulty is 2." << endl; 
    cout << "The words are only words in the English Dictionary" << endl; 
    cout << "You will have 6 trys to guess the word. " << endl;
    cout << "Press Y/y then enter to play or just press enter to quit:" << endl; 
    string start;
    getline(cin, start);
    if(start != "Y" && start != "y"){
        cout << "Exiting Program|||" << endl;
        exit(EXIT_FAILURE);
    }
    else
    game();
    

    
    
    clean();
    printStats();

    
    return 0; 
}
