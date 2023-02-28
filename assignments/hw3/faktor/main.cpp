// Colton Williams Faktor kattis problem 
//02/28/2023
// Citations div by Articles round up 

#include <iostream> 
#include <cmath>

using namespace std;




int main(){

double cit, art, impc; 

cin >> art >> impc;

cit = (art * (impc-1)) + 1;

cit = ceil(cit);

cout << cit; 

return 0; 







}