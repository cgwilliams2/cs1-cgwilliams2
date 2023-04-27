// Colton Williams
// Kattis FallingApart 
// Takes in number of pieces and values then adds the highest to alternating numbers 

#include <iostream>
#include <cassert>
#include <cstdlib>
#include <cstdio>

void test();
void run();
string solve(int, int[]);

using namespace std; 


int main(int argc, char* argv[]) {
    if(argc == 2 && string(argv[1]) == "test") {
        test();
        exit(EXIT_SUCCESS); // exit the program
    }

    

  return 0; 
}

void run(){
int n = 0; 
cin >> n;
int pieces[n];
 

for(int i = 0; i < n; i++){
    cin >> pieces[i];
}

cout << solve(n, pieces) << endl; 


}


string solve(int n, int* pieces[]){
    int a = 0;
    int b = 0; 
    bool alice = true;
    bool bob = false;
    bool done = false; 
    do {
        if(alice){
            int* p = pieces[0];
            int count; 
            for(int i = 0; i < n; i++){
                if(pieces[i] > p){
                    p  = pieces[i];
                    count = i;
                }
                else if(p == 0)
                    done = true; 
                    
                }
            a = a + int(pieces[count]);
            pieces[count] = 0;
            alice = false; 
            bob = true; 

        
        }
        else if(bob){
            int* p = pieces[0];
            int count; 
            for(int i = 0; i < n; i++){
                if(pieces[i] > p){
                    p  = pieces[i];
                    count = i;
                }
                else if(p == 0)
                    done = true; 
                    
                }
            b = b + int(pieces[count]);
            pieces[count] = 0;
            bob = false; 
            alice = true;  

        }
        else
            done = true;
    }
    while(!done); 

    return a + " " + b;
}

