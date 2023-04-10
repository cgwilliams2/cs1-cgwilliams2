/*
Kattis - Hissing Microphone Problem

Updated By: Colton Williams
Date: 04/10/2023

Problem Statement: https://open.kattis.com/problems/hissingmicrophone
Algorithm steps:
1. Read a string
2. Search for "ss" substring in the string
    i. if found, print "hiss"
    ii. otherwise, print "no hiss"
*/

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

// function prototypes
string answer(const string &line);
void testAnswer();
void solve();

int main(int argc, char* argv[]) {
    if (argc == 2 and string(argv[1]) == "test")
        testAnswer();
    else
        solve();
}

string answer(const string &line) {
    // FIXME3 - implement algorithm step 2; return "hiss" or "no hiss"  FIXED
    if(line.find("ss") == string::npos)
        return "no hiss";
    return "hiss";
}

// unit testing answer()
void testAnswer() {
    // FIXME4 - write at least two test cases to test answer()  FIXED 
    string test = "test";
    assert(answer(test) == "no hiss");
    test = "hiss"; 
    assert(answer(test) == "hiss");


    cerr << "All test cases passed!\n";
}

// solving the problem for kattis
void solve() {
    string line;
    // Note: string consists of only lowercase letters (no spaces) upto 30 chars
    // FIXME5 - read string into line  FIXED 
    cin >> line;
    cout << answer(line) << endl;
}