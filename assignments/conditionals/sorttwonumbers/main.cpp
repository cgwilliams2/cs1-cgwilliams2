//Colton Williams Kattis Sort Two Numbers

#include<iostream> 

using namespace std; 

int main(){
    
    int a, b; 
    cin >> a >> b; 

    if(a > b)
        cout << b << " " << a; 
    if(b > a) 
        cout << a << " " << b; 
    else if(a == b)
    cout << a << " " << b; 



 return 0; 

}