// Colton Williams HW 9 maps 
// Kattis a new alphabet 

#include <iostream>
#include <cmath>
#include <cassert>
#include <map>
#include <string>
#include <cstring>

using namespace std; 

void unittest();
string run(string);



map<char, string> newAlpha = {{'a', "@"},       {'b', "8"},      {'c', "("},      {'d', "|)"},
      {'e', "3"},       {'f', "#"},      {'g', "6"},      {'h', "[-]"},
      {'i', "|"},       {'j', "_|"},     {'k', "|<"},     {'l', "1"},
      {'m', "[]\\/[]"}, {'n', "[]\\[]"}, {'o', "0"},      {'p', "|D"},
      {'q', "(,)"},     {'r', "|Z"},     {'s', "$"},      {'t', "']['"},
      {'u', "|_|"},     {'v', "\\/"},    {'w', "\\/\\/"}, {'x', "}{"},
      {'y', "`/"},      {'z', "2"},};




int main(int argc, char* argv[]) {
	if (argc == 2 and string(argv[1]) == "test")
		unittest();
	else{
     string in;
     getline(cin, in);

		cout << run(in) << endl; 
    }
 

 return 0; 
}

string run(string line) {
  string out;
  for (char c : line) {
    string translated = newAlpha[tolower(c)];
    if (translated.empty()) {
      out += c;
    } else {
      out += translated;
    }
  }
  return out; 
}

void unittest(){


}