// Colton Williams HW 6 Array
// Kattis Line Them Up

#include <iostream> 

using namespace std; 

void test();

int main(int argc, char* argv[]) {
    if(argc == 2 && string(argv[1]) == "test") {
        test();
        exit(EXIT_SUCCESS); // exit the program
    }




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


   return 0; 
}


void test(){
    
}