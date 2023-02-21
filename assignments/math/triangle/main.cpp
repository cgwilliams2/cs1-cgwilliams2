// Triangle HW coded by Colton Williams finds area of a triangle
//02/21/2023


//get side lengths then do some math and return the area

#include <iostream>
#include <cmath>

using namespace std;

int main(){

 double a, b, c, s, area;

 cout << "Enter the three side lengths of a triangle and the area will be calculated." << endl; 
 cout << "Enter the first side length: " << endl; 
 cin >> a;
 cout << "Side one has a length of: "<< a << "\n Enter the secound side length: " << endl;
 cin >> b;
 cout << "Side two has a length of: "<< b << "\n Enter the third side length: " << endl;
 cin >> c;
 cout << "The side lengths entered are: " << a << ", " << b << ", " << c << "." << endl; 

 // doing maths 
 
 s = (a+b+c)/2;

 area = s * (s-a) * (s-b) * (s-c);
 area = sqrt(area);

 cout << "The area of a traingle with side lengths of: " << a << ", " << b << ", " << c << " is: " << area << endl; 

 cin.ignore(1000, '\n');
 cout << "Enter to quit the program: ";
 cin.get();
 cout << "Good bye..." << endl;






   return 0;
}
