// Colton Williams HW 6 Array
// Kattis Line Them Up

#include <iostream> 
#include <string>
#include <cassert>

using namespace std; 

void test();
void run();
string ans(int, string[]);


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
    string names[n];
    for(int i = 0; i < n; i++){
        cin >> names[i];
    }

    cout << ans(n, names) << endl;


}

string ans(int n, string* names){

    string nameC; 
    bool increasing = true, decreasing = true; 

    for(int i = 1; i < n; i++){
         
        if(names[i].compare(names[i-1]) > 0)
            decreasing = false;
        else if(names[i].compare(names[i-1]) < 0)
            increasing = false;

    }

    if (increasing) {
     return "INCREASING";
    } else if (decreasing) {
      return "DECREASING";
    } else {
     return "NEITHER";
    }
    
    
}



void test(){
    int n = 5;
    string names[n];
    names[0] = "JOE";
    names[1] = "BOB";
    names[2] = "ANDY";
    names[3] = "AL";
    names[4] = "ADAM";
    assert(ans(n, names).compare("DECREASING") == 0);
    n = 11;
    string names2[n];
    names2[0] = "HOPE";
    names2[1] = "ALI";
    names2[2] = "BECKY";
    names2[3] = "JULIE";
    names2[4] = "MEGHAN";
    names2[5] = "LAUREN";
    names2[6] = "MORGAN";
    names2[7] = "CARLI";
    names2[8] = "MEGAN";
    names2[9] = "ALEX";
    names2[10] = "TOBIN"; 
    assert(ans(n, names2).compare("NEITHER") == 0); 
    /*names[0] = "JOE";
    names[1] = "BOB";
    names[2] = "ANDY";
    names[3] = "AL";
    names[4] = "ADAM";
    assert(ans(n, names).compare("DECREASING") == 0); 
    names[0] = "JOE";
    names[1] = "BOB";
    names[2] = "ANDY";
    names[3] = "AL";
    names[4] = "ADAM";
    assert(ans(n, names).compare("DECREASING") == 0); 
    */
    cerr << "All unit tests passed!" << endl;


}










