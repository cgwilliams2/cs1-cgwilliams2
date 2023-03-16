//Colton Williams Kattis FizzBuzz
//03/16/2023
/*  input ints x y and n 1<=x<y<=n<=100
Print integers from 
 to 
 in order, each on its own line, replacing the ones divisible by x 
 with Fizz, the ones divisible by y
 with Buzz and ones divisible by both with FizzBuzz.*/

#include <iostream>
#include <cassert>
#include <string>

using namespace std; 

void out(int x, int y, int n);
void test();
string check = "";

int main(int argc, char* argv[]) {
    if(argc == 2 && string(argv[1]) == "test") {
        test();
        exit(EXIT_SUCCESS); // exit the program
    }




    int x, y, n; 
    cin >> x >> y >> n; 
    out(x, y, n);
    

    return 0; 
}


void out(int x, int y, int n){
    for(int i = 1; i <= n; i++){

        if(i % x == 0 && i % y != 0 ){
            cout << "Fizz" << endl;
            check += "1";
            }
             
        if(i % y == 0 && i % x != 0){
            cout << "Buzz" << endl;
            check += "2";
            }
             
        if(i % x == 0 && i % y == 0){
            cout << "FizzBuzz" << endl;
            check += "3";
            }
            
        if(i % x != 0 && i % y != 0){
            cout << i << endl;
            check +="4";
            }
             
        
    }

}

void test(){
    int x, y, n;
    x = 2;
    y = 3;
    n = 7;
    out(x, y, n);
    assert(check == "4121434");

    


    cerr << "All test cases passed!\n";
}