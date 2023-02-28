// Colton Williams HW3 Calculator 
//02/27/2023

#include <iostream> 
#include <cmath>
#include <string>
#include <cstdlib>

using namespace std;


double add (double one, double two) {

        return one + two; 
        
        
}

double sub (double one, double two) {
    
    return one - two;


}

double multi (double one, double two) {

    return one * two;
    
}

double div (double one, double two) {


    return one / two; 
    
}

double dif (double one, double two) {

 return abs(two - one);


}

double divr (int one, int two) {

return one % two; 


}

double power (double one, double two) {

    return pow(one, two); 
}

double root (double one) {
    return sqrt(one);
}

double test(){
 return rand() % 100 + 1; 
}

void tester(){
double tone = test();
double ttwo = test();


 cout << "Testing Calculator code with two test numbers: " << tone << ", " << ttwo << endl; 

    cout << tone << " + " << ttwo << " = " << add (tone , ttwo) << endl; 
    cout << tone << " - " << ttwo << " = " << sub (tone , ttwo) << endl; 
    cout << tone << " * " << ttwo << " = " << multi (tone , ttwo) << endl; 
    cout << tone << " / " << ttwo << " = " << div (tone , ttwo) << endl; 
    cout << "The difference between " << tone << " and " << ttwo << " is " << dif (tone, ttwo)<< endl; 
    cout << tone << " % " << ttwo << " = " << divr(tone, ttwo) << endl;
    cout << tone << " ^ " << ttwo << " = " << power(tone, ttwo) << endl; 
    cout << "The square root of " << tone << " is " << root(tone) << "\n" << endl; 



}



int main (){

   

   
    double main1, main2;
    cout << "Enter a number \n" << endl; 
    cin >> main1; 
    cout << "Enter another number \n" << endl; 
    cin >> main2;

    cout << main1 << " + " << main2 << " = " << add (main1 , main2) << endl; 
    cout << main1 << " - " << main2 << " = " << sub (main1 , main2) << endl; 
    cout << main1 << " * " << main2 << " = " << multi (main1 , main2) << endl; 
    cout << main1 << " / " << main2 << " = " << div (main1 , main2) << endl; 
    cout << "The difference between " << main1 << " and " << main2 << " is " << dif (main1, main2)<< endl; 
    cout << main1 << " % " << main2 << " = " << divr(main1, main2) << endl;
    cout << main1 << " ^ " << main2 << " = " << power(main1, main2) << endl; 
    cout << "The square root of " << main1 << " is " << root(main1) << endl; 

    cout << "\n\n" << endl; 
    tester();
    tester();





 
 return 0; 
}

