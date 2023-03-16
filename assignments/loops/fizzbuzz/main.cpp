//Colton Williams Kattis FizzBuzz
//03/16/2023
/*  input ints x y and n 1<=x<y<=n<=100
Print integers from 
 to 
 in order, each on its own line, replacing the ones divisible by x 
 with Fizz, the ones divisible by y
 with Buzz and ones divisible by both with FizzBuzz.*/

#include <iostream>

using namespace std; 

void out(int x, int y, int n);

int main(){
    int x, y, n; 
    cin >> x >> y >> n; 
    out(x, y, n);

    return 0; 
}


void out(int x, int y, int n){
    for(int i = 1; i <= n; i++){
        if(i % x == 0 && i % y != 0 )
            cout << "Fizz" << endl; 
        if(i % y == 0 && i % x != 0)
            cout << "Buzz" << endl; 
        if(i % x == 0 && i % y == 0)
            cout << "FizzBuzz" << endl;
        if(i % x != 0 && i % y != 0)
            cout << i << endl; 
        
    }

}