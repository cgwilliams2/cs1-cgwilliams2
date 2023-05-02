// Colton Williams Strings Homework Kattis Avion
// Take in strings and search for FBI. output strings with FBI or if non found output he got away

#include <iostream>
#include <string> 
#include <cassert>

using namespace std; 

string run(string[]);
void test();

int main(int argc, char* argv[]) {
    if(argc == 2 && string(argv[1]) == "test") {
        test();
        exit(EXIT_SUCCESS); // exit the program
    }
   
    string blimps[5];
    for(int i = 0; i < 5; i++){
        cin >> blimps[i];
    }
    
    cout << run(blimps) << endl; 
    

  return 0; 
}


string run(string blimps[]){
    bool cia = false; 
    string out = "";
    for(int i = 0; i < 5; i++){
        
        
        if (blimps[i].find("FBI") != string::npos){
            out += to_string(i+1) + " ";
            cia = true; 
            }   
    
        
    }
    if(!cia){
        return "HE GOT AWAY!";
    }


    return out; 
}

void test(){
    string blimps[5] = {"N-FBI1", "9A-USKOK", "I-NTERPOL", "G-MI6", "RF-KGB1" }; 
    assert(run(blimps).compare("1 ") == 0);
    string blimps1[5] = {"N321-CIA", "F3-B12I", "F-BI-12", "OVO-JE-CIA", "KRIJUMCAR1" };
    assert(run(blimps1).compare("HE GOT AWAY!") == 0);
    string blimps2[5] = {"47-FBI", "BOND-007", "RF-FBI18", "MARICA-13", "13A-FBILL" };
    assert(run(blimps2).compare("1 3 5 ") == 0);
    string blimps3[5] = {"1T-TEST", "1E-EXPER", "1-FBI11", "NF-GOLF3", "N-A9FBI" };
    assert(run(blimps3).compare("3 5 ") == 0);

 cerr << "All unit tests passed!" << endl;
}
