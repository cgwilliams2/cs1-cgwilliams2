// Colton Williams
// Hangman Game

#include <iostream>
#include <string>




using namespace std;

int main(){

    string name;             // varibles being used
    string gameWord = "";
    string charEnt = "";
    string letter = "";
    string word = "";
    string wrngLetters = "";
    int wrongGuesses = 0;
    int correctGuesses = 0;
    bool guessedWrong = true;
    bool gameWon = false;


    for(int i = 0; i < 50; i++){   // clears the users terminal
        cout << "\n\n"; 

    }

    

    cout << "Hello, what is your're name?\n" << endl; 
    getline(cin, name); 
    cout << "Hey, " << name << "!\n Have someone enter a word or two that you will try to guess before\n your charater gets hung!\n Enter a word:";
    getline(cin, gameWord);

        
    for(int i = 0; i < 50; i++){   // clears the users terminal
        cout << "\n\n"; 

    }
  
       
    string str = gameWord;
   
        
    int count = 0;              //removes any spaces from the string and saves them into the varible str
    for(int i = 0; i <= str.length(); i++)
        if(str[i] != ' ')
            str[count++] = str[i];
    str[count] = '\0';

    //string strt = str; 
         // random code not used right not
    
    

    //for (int x=0; x<strt.length(); x++)
        //strt[x] = to_lower(strt[x]); 

    
    

    int winCon = str.length();


    //building output graphics
       string game = "     |------------\n     |/       |\n     |\n     |\n     |\n     |\n     |\n===========\n";
     string game1 = "     |------------\n     |/       |\n     |        O\n     |\n     |\n     |\n     |\n===========\n";
    string game2 = "     |------------\n     |/       |\n     |        O\n     |        |\n     |\n     |\n     |\n===========\n";
    string game3 = "     |------------\n     |/       |\n     |        O\n     |       /|\n     |\n     |\n     |\n===========\n";
    string game4 = "     |------------\n     |/       |\n     |        O\n     |       /|\\ \n     |\n     |\n     |\n===========\n";
    string game5 = "     |------------\n     |/       |\n     |        O\n     |       /|\\ \n     |       /\n     |\n     |\n===========\n";
    string game6 = "     |------------\n     |/       |\n     |        O\n     |       /|\\ \n     |       / \\\n     |\n     |\n===========\n";

    
    cout << "Guess a letter.\n";

    for(int i = 0; i < gameWord.length(); i++){ //makes string of _ _ _ representing unguessed letters
        if(gameWord[i] == ' ')
            word+=" ";
         else if(gameWord[i] != ' ')
            word+="_";
    
    }




   // game while statement 
    while(!gameWon){
        for(int i = 0; i < 50; i++){ //clears the users screen again
        cout << "\n\n"; 
     }                           //fiqures out what stage of hanging the player is at then displays it
        if(wrongGuesses == 0)
        cout << game;
        if(wrongGuesses == 1)
        cout << game1;
        if(wrongGuesses == 2)
        cout << game2;
        if(wrongGuesses == 3)
        cout << game3;
        if(wrongGuesses == 4)
        cout << game4;
        if(wrongGuesses == 5)
        cout << game5;
        if(wrongGuesses == 6)
        cout << game6;


        cout << "\nThese letters are not in the word: " << wrngLetters << "\n"; //prints letters the user has alredy guessed that are not in the word
        cout << "\n" << word << "\n\n";


        guessedWrong = true; //resets the boolean varible that tracks the current guess 
        cout << "type a letter then press enter:\n"; //askes for input for varible "letter"
        cin >> letter;


        if(letter.length() > 1){ //makes sure the user only entered one letter
         cout << "only enter one letter\n";
         cin >> letter;
        }


        for(int i=0; i <= charEnt.length(); i++){ //checks to make sure that the letter entered has not alredy been used
            if(letter[0] == charEnt[i]){
                cout << "Letter alredy used. Try a difffernt letter\n";
                cin >> letter;
            }

        }


        for(int t=0; t <= str.length(); t++){ //checks to see if the user guessed a correct letter
            if(letter[0] == str[t]){
              
                word[t] = gameWord[t];
                guessedWrong = false;
                correctGuesses++;
               }
        }

        if(guessedWrong){ //keeps track of useres wrong guesses and adds wrong letters to a string
            wrongGuesses++;
            wrngLetters = letter + " " + wrngLetters;
            

        }

        charEnt += letter;

        if(wrongGuesses >= 6){ //when the user is out of guess this ends the game
            for(int i = 0; i < 50; i++){
         cout << "\n\n"; 
         }
            cout << game6 << "\nyou lost :( The word was: " << gameWord << " " << str << "\n Press enter to exit\n";
            cin.ignore();
            if(cin.get() == '\n')
            return 0;

        }

        if(winCon == correctGuesses){ //if the user wins this prints the last stage of the game
            for(int i = 0; i < 50; i++){
         cout << "\n\n"; 
         }
         if(wrongGuesses == 0)
         cout << game;
         else if(wrongGuesses == 1)
         cout << game1;
         else if(wrongGuesses == 2)
         cout << game2;
         else if(wrongGuesses == 3)
         cout << game3;
         else if(wrongGuesses == 4)
         cout << game4;
         else if(wrongGuesses == 5)
         cout << game5;

         
            cout << "\n !You Won! The word was: " << gameWord << " " << str << "\n";
            cout << "\n\n     press enter to exit";
            cin.ignore();
            if(cin.get() == '\n')
            return 0;
        
            }









    }
    

 cout << "\n\n press enter to exit"; //random exit code if for some reason code dosent exit as it should 
 cin.ignore();
 if(cin.get() == '\n')
 return 0;



 return 0; 

}