// Colton Williams Hangman Game final project 
// Takes a list of words from a txt file selects one and has the user guess what the word is. 

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>


using namespace std;

#ifdef _WIN32
#define clear() system("cls")
#else
#define clear() system("clear")
#endif

//functions
void initialize();
void readFile(vector<string>& words);
void game();
bool checkGuess();
void printMenu();
void printStats();
void sortWords(vector<string>& words, vector<string>& word1, vector<string>& word2, vector<string>& word3);
void printStats();

// varibles 
vector<string> words;
vector<string> words1;
vector<string> words2;
vector<string> words3;


// gamestates
string game0 = "     |------------\n     |/       |\n     |\n     |\n     |\n     |\n     |\n===========\n";
string game1 = "     |------------\n     |/       |\n     |        O\n     |\n     |\n     |\n     |\n===========\n";
string game2 = "     |------------\n     |/       |\n     |        O\n     |        |\n     |\n     |\n     |\n===========\n";
string game3 = "     |------------\n     |/       |\n     |        O\n     |       /|\n     |\n     |\n     |\n===========\n";
string game4 = "     |------------\n     |/       |\n     |        O\n     |       /|\\ \n     |\n     |\n     |\n===========\n";
string game5 = "     |------------\n     |/       |\n     |        O\n     |       /|\\ \n     |       /\n     |\n     |\n===========\n";
string game6 = "     |------------\n     |/       |\n     |        O\n     |       /|\\ \n     |       / \\\n     |\n     |\n===========\n";


int main(){
    clear();
    initialize();
    cout << "Welcome to my Hangman game!" << endl; 
    cout << "This game picks a word based on the difficulty you select." << endl;
    cout << "There are three levels of difficulty 1, 2, and 3" << endl;
    cout << "1 is words with 4 or less letters" << endl;
    cout << "2 is words with 5-10 letters" << endl;
    cout << "3 is words with 11+" << endl;
    cout << "The words are only words in the English Dictionary" << endl; 
    cout << "You will have 6 trys to guess the word. " << endl;
    cout << "Press Y/y then enter to play or just press enter to quit:" << endl; 
    string start;
    getline(cin, start);
    if(start != "Y" && start != "y"){
        cout << "exiting..." << endl;
        abort();
    }
    else
    game();
    

    
    
    
    printStats();
 return 0;
}

void initialize(){
    readFile(words);
    sortWords(words, words1, words2, words3);
}


void readFile(vector<string>& words)
{
    ifstream inputFile("words.txt");

    if (!inputFile)
    {
        cout << "Error opening file." << endl;
        abort();
    }

    string word;
    while (inputFile >> word)
    {
        words.push_back(word);
       
    }

    inputFile.close();
}

void printMenu(){
    cout << "Type [0] then press enter to play" << endl;
    cout << "Type [1] then press enter to change difficulty" << endl;
    cout << "Type [2] then press enter to exit and display stats" << endl;

}

void sortWords(vector<string>& words, vector<string>& word1, vector<string>& word2, vector<string>& word3){
    for (const auto& word : words)
    {
        if (word.size() <= 4)
        {
            word1.push_back(word);
        }
        else if (word.size() <= 10)
        {
            word2.push_back(word);
        }
        else
        {
            word3.push_back(word);
        }
    }


}

void game(){
    cout << "Game Started" << endl;
    bool run = true;

    while(run){

     printMenu();
     run = false;

    }
    

}

void printStats(){
    cout << "         All stats calculted for this game session\n" << endl; 
    cout << "Correct words guessed: " << "temp" << endl;
    cout << "Correct guesses: " << "temp" << endl;
    cout << "Correct words guessed: " << "temp" << endl;
    cout << "Words not guessed: " << "temp" << endl;
    cout << "Incorrect gusses: " << "temp" << endl;
    
    
}

/*
cout << "Type Y/y to play or N/n to exit." << endl;
    string start;
    getline(cin, start);
    if(start != "Y" || start != "y" || start != "N" || start != "n" ){
        cout << "Invalid input." << endl; 
        cout << "Type Y/y to play or N/n to exit." << endl;
        getline(cin, start);
        if(start != "Y" || start != "y" || start != "N" || start != "n" ){
            cout << "Invalid input Exiting Program..." << endl; 
            abort();

        }
        
        else if(start == "Y" || start == "y")
            game();

    }
    else if(start == "Y" || start == "y")
            game();
        
*/