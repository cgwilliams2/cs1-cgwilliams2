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
void gameRun();
void printMenu();
void printStats();
void sortWords(vector<string>& words, vector<string>& word1, vector<string>& word2, vector<string>& word3);
void printStats();
void gameStart();
void changeDifficulty();
string word(int difficulty);

// varibles and word vectors
vector<string> words;
vector<string> words1;
vector<string> words2;
vector<string> words3;
int difficulty = 2; 
string gameWord, repGameWord;


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
    cout << "Defualt difficulty is 2." << endl; 
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
 
}








void game(){
    cout << "Game Started" << endl;
    
    
    int menu;
    
    while(menu != 2){
        printMenu();
        cin >> menu;
        if(menu == 1 ){
            changeDifficulty();

        }
        if(menu == 0){
            gameRun();

        }

    }
    
}

void gameStart(){
   gameWord = word(difficulty);
   for(int i = 0; i < gameWord.length(); i++){ //makes string of _ _ _ representing unguessed letters
        repGameWord+="_";
        }

}

void gameRun(){
    gameStart();
    int numwg = 0;
    int numcg = 0; 
    string letters, wrngLetters, letter, lettersEnt;
    bool guess = false; 
   

    while(numwg < 6){
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
        if(numwg == 6)
            cout << game6 << endl;

        cout << "Letters not in the word: " << wrngLetters << endl;
        cout << repGameWord << endl;

        cout << "Guess a letter then press enter: ";
        cin >> letter;

        while(letter.length() > 1){
             cout << "only enter one letter" << endl;
            cout << "Guess a letter then press enter: ";
            cin >> letter;
            for(int i = 0; i < lettersEnt.length(); i++){
                if(letter[0] == lettersEnt[i]){
                    cout << "Letter alredy used. Try a difffernt letter" << endl; 
                    letter = "  ";
                }
            }
        }

        lettersEnt += letter; 


        for(int i = 0; i < gameWord.length(); i++){
            if(letter[0] == gameWord[i]){
                numcg++;
                repGameWord[i] = letter[0];
                guess = true; 

            }
        }

        if(!guess){
            numwg++;
            wrngLetters = letter + " " + wrngLetters; 
        }


       

       

     
     
        guess = false; 
    }

}



void changeDifficulty(){
    cout << "There are three levels of difficulty 1, 2, and 3" << endl;
    cout << "1 is words with 4 or less letters" << endl;
    cout << "2 is words with 5-10 letters" << endl;
    cout << "3 is words with 11+" << endl;
    cout << "Type 1, 2, or 3 then press enter to change difficutly" << endl; 
    cin >> difficulty; 


}

void initialize(){
    readFile(words);
    sortWords(words, words1, words2, words3);
}

string word(int difficulty){
    if(difficulty == 1){
        int randomIndex = rand() % words1.size();
        return words[randomIndex];
    }

    if(difficulty == 2){
        int randomIndex = rand() % words2.size();
        return words[randomIndex];

    }

    if(difficulty == 3){
        int randomIndex = rand() % words3.size();
        return words[randomIndex];

    }

    return "";
}

void printStats(){
    cout << "         All stats calculted for this game session\n" << endl; 
    cout << "Correct words guessed: " << "temp" << endl;
    cout << "Correct guesses: " << "temp" << endl;
    cout << "Correct words guessed: " << "temp" << endl;
    cout << "Words not guessed: " << "temp" << endl;
    cout << "Incorrect gusses: " << "temp" << endl;
    
    
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

