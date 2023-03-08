// Coltoon Williams Hw 03/08/2023

#include <iostream>
#include <cmath> 
#include <string>


using namespace std; 

double big5(double a, double b, double c, double d, double e);

double small5(double a, double b, double c, double d, double e);

string evenOdd(double a, double b, double c, double d, double e);



bool run();

void menu();

void clearScreen() {
    system("clear");
}

int main(){

 string name;
 cout << "Hello, please enter users name: "; 
 cin >> name;
 clearScreen();
 cout << "Welcome! " << name << ". This is a simple C++ program."<< endl;
 run();







    

    


    cin.ignore(100, '\n');
    cout << "Enter to quit the program.\n";
    cout << "Good bye..." << endl;
    cin.get();
    return 0; 

}






double big5(double a, double b, double c, double d, double e){

if((a > b || a == b) && (a > c || a == c) && (a > d || a == d) && (a > e || a == e))
    return a;
else if((b > a || b == a) && (b > c || b == c) && (b > d || b == d) && (b > e || b == e))
    return b;
else if((c > a || c == a) && (c > b || c == b) && (c > d || c == d) && (c > e || c == e))
    return c;
else if((d > a || d == a) && (d > b || d == b) && (d > c || d == c) && (d > e || d == e))
    return d;
else if((e > a || e == a) && (e > b || e == b) && (e > c || e == c) && (e > d || e == d))
    return e;
 
return 0.0;
}

double small5(double a, double b, double c, double d, double e){

if((a < b || a == b) && (a < c || a == c) && (a < d || a == d) && (a < e || a == e))
    return a;
else if((b < a || b == a) && (b < c || b == c) && (b < d || b == d) && (b < e || b == e))
    return b;
else if((c < a || c == a) && (c < b || c == b) && (c < d || c == d) && (c < e || c == e))
    return c;
else if((d < a || d == a) && (d < b || d == b) && (d < c || d == c) && (d < e || d == e))
    return d;
else if((e < a || e == a) && (e < b || e == b) && (e < c || e == c) && (e < d || e == d))
    return e;
    
return 0.0;
}

string evenOdd(double a, double b, double c, double d, double e){

    double sum = a + b + c + d + e; 
    sum = floor(sum);
    if(sum == 0)
        return "Zero";
    sum = fmod(sum, 2);
    if(sum == 0)
        return "Even";
    if(sum == 1)
        return "Odd";
    
    return "Error"; 
    


   
   
   
   
    
}


void menu(void){
    cout << "\nMenu options:\n";
    cout << "[1] Find largest of 5 numbers\n";
    cout << "[2] Find smallest of 5 numbers\n";
    cout << "[3] Find if sum of 5 numbers is even or odd\n";
    cout << "[8] Quit the program\n";
    cout << "Enter one of the menu options [1-8]: ";
}

bool run(){
    int select;
    bool loop = true; 
    double a, b, c, d, e;
   
    while(loop){
        menu();
        cin >> select;
        if(select < 1 || select > 10){
        clearScreen();
        cout << "invalid entry, please enter a value between 1 and 8."; 
        }

        if(select == 1){
            cout << "Enter five numbers seperated by a space: ";
            cin >> a >> b >> c >> d >> e;
            double ans = big5(a, b, c, d, e);
            printf("The largest number is: %.2f\n", ans);
            loop = true;
        }
        if(select ==2){
            cout << "Enter five numbers seperated by a space: ";
            cin >> a >> b >> c >> d >> e;
            double ans = small5(a, b, c, d, e);
            printf("The smallest number is: %.2f\n", ans);
            loop = true;
        }
        if(select == 3){
            cout << "Enter five numbers seperated by a space: ";
            cin >> a >> b >> c >> d >> e;
            cout << "\nThe sum of the numbers entered is: " << evenOdd(a, b, c, d, e);
        }

        if(select == 8)
            return false; 
    }
    



    

    return true;
}

