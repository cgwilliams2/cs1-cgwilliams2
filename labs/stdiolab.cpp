/*  
    Lab 1 = ASCII Art and Standard IO
    
    By: Colton Williams 
    CSCI 111
    Date: 01/26/2023

    This program produces an ASCII art on the console. 

    Algorithm steps: Write a series of cout statements to print
    the art to the console. 

*/

#include <iostream> 
#include <string> 

using namespace std; 

int main()
{



    string name;

    cout << "Hi there, what's your full name? ";

    getline(cin, name);

    cout << "Nice meeting you, " << name << "!" << endl;

    cout << "hope you'll like my ASCII art...\n" << endl;



return 0; 

}