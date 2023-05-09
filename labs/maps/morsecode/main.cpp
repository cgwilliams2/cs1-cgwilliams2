/*
Map Lab
Kattis - Morse Code Palindromes

Updatd By: Colton Williams
Date: 

Solution to Morse Code Palindromes Problem: https://open.kattis.com/problems/morsecodepalindromes
Algorithm steps:
1. Creae a map of char to morse code
2. Read in a string
3. Convert the string to morse code
   i. for each char in string, find its morse code in map
   ii. append morse code to a string if char key is found
4. Check if morse code is a palindrome
  i. compare first and last char
  ii. if they are the same, compare second and second last char
  iii. if they are the same, compare third and third last char
  iv. repeat until all chars are compared until mid index or a mismatch is found
5. Print 1 if morse code is a palindrome, 0 otherwise
*/

#include <iostream>
#include <cmath>
#include <cassert>
#include <map>
#include <string>
#include <cstring>

using namespace std;

// Algorithm step 1
map<char, string> morseCode = {
    {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."}, {'E', "."}, {'F', "..-."},
    {'G', "--."}, {'H', "...."}, {'I', ".."}, {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."},
    {'M', "--"}, {'N', "-."}, {'O', "---"}, {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."},
    {'S', "..."}, {'T', "-"}, {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"},
    {'Y', "-.--"}, {'Z', "--.."}, {'0', "-----"}, {'1', ".----"}, {'2', "..---"},
    {'3', "...--"}, {'4', "....-"}, {'5', "....."}, {'6', "-...."}, {'7', "--..."},
    {'8', "---.."}, {'9', "----."}, 
};

// function prototypes
string convertToMorse(const string&);
bool isPalindrome(const string&);
void testConvertToMorse();
void testIsPalindrome();
void solve();
void unittest();

int main(int argc, char* argv[]) {
    if (argc == 2 and string(argv[1]) == "test")
        unittest();
    else
        solve();
}

// solving the problem for kattis
void solve() {
    string phrase, morse;
    // string is a phrase: with space, puncuation, lower and uppercase letters
    // FIXME1 - step 2 FIXED
    // read english phrase into phrase variable
    getline(cin, phrase);
    // FIXME2 - step 3 FIXED
    // convert phrase to morse code
    morse = convertToMorse(phrase);
    // FIXME3 - step 4 FIXED
    // check if morse code is a palindrome calling isPalindrome function
    bool is_palindrome = isPalindrome(morse);
    // FIXME4 - step 5 FIXED
    // print 1 if it is a palindrome, 0 otherwise
    if(phrase.empty()){
        cout << "0" << endl; 
    }
    else{
    if(is_palindrome)
        cout << "1" << endl;
    else
        cout << "0" << endl;
    }
}

// function definitions
string convertToMorse(const string& phrase) {
    string morse = "";
    // convert phrase to morse code
    // for each char in phrase, convert char to uppercase, find its morse code in morseCode map
    // append morse code to a string if char key is found
    for (char c : phrase) {
        c = char(toupper(c));
        // FIXME5 - find morse code for char c in morseCode map and append it to morse string
        if (morseCode.find(c) != morseCode.end())
            morse += morseCode[c];
        else if (c == ' ')
            morse += "";
    }
    // Remove any extra spaces at the beginning or end of the morse code string
    size_t startpos = morse.find_first_not_of(" ");
    size_t endpos = morse.find_last_not_of(" ");
    if(startpos != string::npos && endpos != string::npos)
        morse = morse.substr(startpos, endpos-startpos+1);
    return morse;
}

bool isPalindrome(const string& morse) {
     // FIXME6 - check if morse code is a palindrome
     // return true if it is a palindrome, false otherwise
     // Algorithm step: 
        // compare first and last char
        // if they are the same, compare second and second last char
        // if they are the same, compare third and third last char
        // repeat until all chars are compared until mid index or a mismatch is found
        // NOTE: empty morse code is not a palindrome!
    bool r_val = true;

    if(morse == "")

        r_val = false;

    else

    {

        int mid_index = morse.size()/2;

        int end = morse.size()-1;

        for(int i=0;i<mid_index;i++)

        {

            if(morse[i] != morse[end-i])

                r_val = false;

        }

    }

    return r_val;
}


void testConvertToMorse() {
    assert(convertToMorse("A") == ".-");
	assert(convertToMorse("9") == "----.");
	assert(convertToMorse("Aa") == ".-.-");
	cerr << convertToMorse("AaBb") << endl;
	assert(convertToMorse("AaBb") == ".-.--...-...");
	assert(convertToMorse("Race car!") == ".-..--.-..-.-..-.-.");
	assert(convertToMorse("1881") == ".-------..---...----");
    assert(convertToMorse("Hello World!") == "......-...-..---.-----.-..-..-..");
    assert(convertToMorse("SOS") == "...---...");
    assert(convertToMorse("159")== ".----.....----."); 
    // FIXME7 - add 3 more test cases FIXED 
  
}

void testIsPalindrome() {
    string morse = convertToMorse("A");
	assert(isPalindrome(morse) == true);
	morse = convertToMorse("AaBb");
	assert(isPalindrome(morse) == false);
	morse = convertToMorse("Race car!");
	assert(isPalindrome(morse) == true);
	morse = convertToMorse("1881");
	assert(isPalindrome(morse) == true);
    morse = convertToMorse("madam");
    assert(isPalindrome(morse) == false);
    morse = convertToMorse("Hi");
    assert(isPalindrome(morse) == true);
    morse = convertToMorse("test");
    assert(isPalindrome(morse) == true);
    // FIXME8 - add 3 more test cases FIXED 
}

// unit testing all functions
void unittest() {
  // FIXME9 - call all unit test functions FIXED 
  testConvertToMorse();
  testIsPalindrome();
  cerr << "All unittests passed!\n";
}





