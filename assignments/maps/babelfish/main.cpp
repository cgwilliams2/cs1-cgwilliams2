// Colton Williams
// Kattis BabelFish
// takes in an english word followed by its translation then builds a map 
// outputs the english word for the forgien word entered 


#include <iostream>
#include <unordered_map>
#include <cassert>

using namespace std; 


string out(unordered_map<string, string>&words, string word);
void test();


int main(int argc, char* argv[]) {
    if (argc == 2 and string(argv[1]) == "test"){
        test();
        return 0;

    }
        

    unordered_map<string, string> words;
    string in; 

    while(getline(cin, in) && in != ""){
        string english, foreign; 
        int space = in.find(' ');
        english = in.substr(0, space);
        foreign = in.substr(space+1);
        words[foreign] = english; 
    }

    string word;
    while(cin >> word){
        cout << out(words, word) << endl; 
    }
    


    return 0; 
}



string out(unordered_map<string, string>&words, string word){
    string rt = (words.count(word) ? words[word] : "eh");
    return rt;
}

void test(){
    unordered_map<string, string> tests = {
        {"hund", "dog"},
        {"katze", "cat"},
        {"vogel", "bird"},
        {"pferd", "horse"},
        {"kuh", "cow"},
        {"schaf", "sheep"}
    };

   
    assert(out(tests, "hund") == "dog");
    assert(out(tests, "katze") == "cat");
    assert(out(tests, "vogel") == "bird");
    assert(out(tests, "pferd") == "horse");
    assert(out(tests, "kuh") == "cow");
    assert(out(tests, "schaf") == "sheep");
    assert(out(tests, "lion") == "eh");

cerr << "All test cases passed!\n";
}