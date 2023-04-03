// Colton Williams HW 6 Array
// Kattis Line Them Up

#include <iostream> 
#include <cassert>

using namespace std; 

void test();
void run();

int main(int argc, char* argv[]) {
    if(argc == 2 && string(argv[1]) == "test") {
        test();
        exit(EXIT_SUCCESS); // exit the program
    }

    run();




   return 0; 
}

void run(){
    int n; 
    cin >> n; 
    string nameIn; 
    cin >> nameIn; 

    n--; 


    bool increasing = true, decreasing = true; 

    while(n--){
        string name; 
        cin >> name; 


     if (nameIn.compare(name) < 0) {
         decreasing = false;
        } else if (nameIn.compare(name) > 0) {
         increasing = false;
         }

        nameIn = name;

        

    }

    if (increasing) {
     cout << "INCREASING" << endl;
    } else if (decreasing) {
      cout << "DECREASING" << endl;
    } else {
     cout << "NEITHER" << endl;
    }

}

void test(){

5
JOE
BOB
ANDY
AL
ADAM
run();

}