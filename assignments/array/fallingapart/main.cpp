// Colton Williams
// Kattis FallingApart 
// Takes in number of pieces and values then adds the highest to alternating numbers 

#include <iostream>
#include <cassert>

void test();
void run();
void solve();


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

