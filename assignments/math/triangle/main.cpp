// Triangle HW coded by Colton Williams finds area of a triangle
//02/21/2023


//get side lengths then do some math and return the area

#include <iostream>
#include <cmath>

using namespace std;

int main(){

 double a, b, c, s, area, peri;
 

 cout << "Enter the three side lengths of a triangle and the area will be calculated." << endl; 
 cout << "Enter the first side length: " << endl; 
 cin >> a;
 cout << "Side one has a length of: "<< a << "\n Enter the secound side length: " << endl;
 cin >> b;
 cout << "Side two has a length of: "<< b << "\n Enter the third side length: " << endl;
 cin >> c;
 cout << "The side lengths entered are: " << a << ", " << b << ", " << c << "." << endl; 

 // doing maths 

 if((a+b) > c && (b+c) > a && (a+c) > b){
     peri = a + b + c;
     s = (a+b+c)/2;

     area = s * (s-a) * (s-b) * (s-c);
     area = sqrt(area);
     cout << "\nThe area of a traingle with side lengths of: " << a << ", " << b << ", " << c << " is: " << area << "\nand the pereimeter of the triangle is: " << peri << endl; 
     }

 else{
        cout << "\nThe side lengths entered do not form a triangle...\n" << endl; 
     }
 
 
 cin.ignore(1000, '\n');
 cout << "Enter to quit the program: ";
 cin.get();
 cout << "Good bye..." << endl;






   return 0;
}
