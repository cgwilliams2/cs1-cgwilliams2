/*  
    Lab 1 = ASCII Art and Standard IO
    
    By: Colton Williams 
    CSCI 111
    Date: 01/26/2023

    This program produces an ASCII art on the console. 

    Algorithm steps: Write a series of cout statements 
    to print
    the art to the console. 

*/

#include <iostream> 
#include <string> 

using namespace std; 

int main()
{



    string name;  //#FIXED#

    cout << "Hi there, what's your full name? ";

    getline(cin, name);  //#FIXED#

    cout << "Nice meeting you, " << name << "!" << endl;  //#FIXED#

    cout << "hope you'll like my ASCII art...\n" << endl;



    string line0 = "  |\\_/|   ********************    (\\_/)"; //#FIXED#
    string line1 = " / @ @ \\  *     ASCII Lab    *   (=\'.\'=)";  //#FIXED#
    string line2 = "( > 0 < ) *  Colton Williams *   (\")_(\")";  //#FIXED#
    string line3 = "  >>x<<   *       2023       * ";  //#FIXED#
    string line4 = " /  O  \\  *     CSCI 111     *";  //#FIXED#
    string line5 = "          ********************";  //#FIXED#
    

    cout << line0 << endl;  //#FIXED#
    cout << line1 << endl;   //#FIXED#
    cout << line2 << endl;   //#FIXED#
    cout << line3 << endl;   //#FIXED#
    cout << line4 << endl;   //#FIXED#
    cout << line5 << endl;   //#FIXED#


    cout << "\nGood Bye... Press enter to exit the program: " << "\n";  //#FIXED#
    cin.get();   //#FIXED#


return 0; 

}