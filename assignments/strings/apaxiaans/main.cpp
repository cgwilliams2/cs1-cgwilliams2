// Colton Williams HW 7 strings kattis apaxianns
// Read through a string and remove any repeated letters right next to each other ie rooobert = robert

#include <iostream>
#include <string> 
#include <cassert>

using namespace std; 

void test();
string run(string); 

int main(int argc, char* argv[]) {
    if(argc == 2 && string(argv[1]) == "test") {
        test();
        exit(EXIT_SUCCESS); // exit the program
    }
    string name; 
    cin >> name; 

    cout << run(name) << endl; 

  return 0; 
}

string run(string name){
    char prev;
    string newName; 
    for(int i = 0; i < name.size(); i++){
        if(name[i] != prev){
            newName += name[i];
        }
        prev = name[i];
    }

    return newName; 
}

void test(){
    string t; 
    t = "roobert"; 
    assert(run(t).compare("robert") == 0);
    t = "robert";
    assert(run(t).compare("robert") == 0);
    t = "ttteeesssttt";
    assert(run(t).compare("test") == 0);
    t = "rruunniinngg";
    assert(run(t).compare("runing") == 0);

    cerr << "All unit tests passed!" << endl;
}