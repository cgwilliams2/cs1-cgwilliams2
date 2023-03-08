// Coltoon Williams Hw 03/08/2023

#include <iostream>
#include <cmath> 
#include <string>


using namespace std; 

double big5(double a, double b, double c, double d, double e);





int main(){
    double a, b, c, d, e;
 cout << " enter 5 #'s: \n"; 
 cin >> a >> b >> c >> d >> e; 
 

 cout << "\n" << big5(a, b, c, d, e); 


    



    return 0; 

}

/*bool run(){
    double a, b, c, d, e;

    while(true){

    }

    


}
*/


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