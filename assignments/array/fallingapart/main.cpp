// Colton Williams
// Kattis FallingApart 
// Takes in number of pieces and values then adds the highest to alternating numbers 

#include <iostream>
#include <cassert>
#include <cstdlib>
#include <cstdio>

void test();
void run();
string solve(int[]);

using namespace std; 


int main(int argc, char* argv[]) {
    if(argc == 2 && string(argv[1]) == "test") {
        test();
        exit(EXIT_SUCCESS); // exit the program
    }

    

  return 0; 
}

void run(){
int n;
cin >> n;
int pieces[n];
for(int i = 0; i < n; i++){
    cin >> pieces[i];
}

cout << solve(pieces) << endl; 


}


string solve(int pieces[]){
    int b, a; 
    bool alice = true;
    bool bob = false;
    bool done = false; 
    do {
        if(alice){
            for(int i = 0; i < pieces.size())

        }
        else if(bob){

        }
        else
            done = true;
    }
    while(!done); 

    return " ";
}

