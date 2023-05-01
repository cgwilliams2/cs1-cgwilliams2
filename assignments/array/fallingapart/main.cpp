// Colton Williams
// Kattis FallingApart 
// Takes in number of pieces and values then adds the highest to alternating numbers 

#include <iostream>
#include <cassert>
#include <string>

using namespace std; 

void test();
void run();
string solve(int, int[], int[]);



int main(int argc, char* argv[]) {
    if(argc == 2 && string(argv[1]) == "test") {
        test();
        exit(EXIT_SUCCESS); // exit the program
    }
    run();
    cout << endl; 
    

  return 0; 
}

void run(){
int n = 0; 
cin >> n;
int pieces[n];
int ab[2];
ab[0] = 0; 
ab[1] = 0; 
 

for(int i = 0; i < n; i++){
    cin >> pieces[i];
}

cout << solve(n, pieces, ab); 


}


string solve(int n, int pieces[], int ab[]){
    bool alice = true;
    bool bob = false;
    bool run = true;
    //cout << pieces[0] << " " << pieces[1] << " " << pieces[2] << " " << ab[0] << " " << ab[1] << endl; 
    do {
        if(alice){
            //cout << "Alice start " << pieces[0] << " " << pieces[1] << " " << pieces[2] << " " << ab[0] << " " << ab[1] << endl;
            int p = pieces[0];
            int count = 0; 
            for(int i = 0; i < n; i++){
                if(pieces[i] > p){
                   // cout << i << endl; 
                    p  = pieces[i];
                    count = i;
                }
                }
            if(p == 0){
                    run = false; 
                    //cout << "P = 0" << endl;
                } 
                    
                
            ab[0] = ab[0] + pieces[count];
            pieces[count] = 0;
            alice = false; 
            bob = true;
            //cout << "Alice end " << pieces[0] << " " << pieces[1] << " " << pieces[2] << " " << ab[0] << " " << ab[1] << endl;
            

        
        }
        else if(bob){
            //cout << "Bob start " << pieces[0] << " " << pieces[1] << " " << pieces[2] << " " << ab[0] << " " << ab[1] << endl;
            int p = pieces[0];
            int count = 0;
            for(int i = 0; i < n; i++){
                if(pieces[i] > p){
                   // cout << i << endl; 
                    p  = pieces[i];
                    count = i;
                }
            }
            if(p == 0){
                    run = false;
                    //cout << "P = 0" << endl; 
                }
                    
                
            ab[1] = ab[1] + pieces[count];
            pieces[count] = 0;
            bob = false; 
            alice = true;
            //cout << "Bob end " << pieces[0] << " " << pieces[1] << " " << pieces[2] << " " << ab[0] << " " << ab[1] << endl;  

        }
        
        
    }
    while(run);
    string ans = to_string(ab[0]) + " " + to_string(ab[1]);
    
    return ans;
    
}

void test(){
    int n = 3; 
    int pieces[n];
    int ab[2];
    ab[0] = 0;
    ab[1] = 0; 
    pieces[0] = 3; 
    pieces[1] = 1;
    pieces[2] = 2;
    assert(solve(n, pieces, ab).compare("4 2") == 0);
    n = 3;
    ab[0] = 0;
    ab[1] = 0; 
    pieces[0] = 5; 
    pieces[1] = 10;
    pieces[2] = 8;
    assert(solve(n, pieces, ab).compare("15 8") == 0);
    n = 4;
    ab[0] = 0;
    ab[1] = 0; 
    pieces[0] = 1; 
    pieces[1] = 2;
    pieces[2] = 2;
    pieces[3] = 1;
    assert(solve(n, pieces, ab).compare("3 3") == 0);
    n = 6;
    ab[0] = 0;
    ab[1] = 0; 
    pieces[0] = 1; 
    pieces[1] = 8;
    pieces[2] = 20;
    pieces[3] = 22;
    pieces[4] = 90;
    pieces[5] = 6;
    assert(solve(n, pieces, ab).compare("116 31") == 0);
    
    
 cerr << "All unit tests passed!" << endl;
}
