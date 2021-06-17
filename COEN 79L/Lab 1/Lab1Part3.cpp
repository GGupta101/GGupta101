//
//  Lab1Part3.cpp
//  Lab 1
//
//  Created by ggupta on 1/10/20.
//

#include "Lab1Part3.hpp"
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, const char* argv[]){
    //Checks if your give one and only one input (one txt file)
    assert(argc==2);
    
    //Take in the input from the command line
    string filename(argv[1]);
    ifstream in_file;
    
    //Open the txt file for interating through
    in_file.open(filename);
    string tempstring;
    
    while(!in_file.eof()){
        //Load a word into the tempstring
        in_file>>tempstring;
        
        //Parse through the word
        for(int i=0;i<tempstring.length();i++){
            //Checks if it is an Alphabet and if so makes it uppercase
            if(isalpha(tempstring[i])) {
                tempstring[i]=toupper(tempstring[i]);
            }
            
            //It is is not an Alphabet then it erases the char
            else {
                tempstring.erase(i,1);
                i--;
            }
        }
        //If the Uppercase word is 10 letters or longer, it will print it out
        if(tempstring.length()>=10){
            cout<<tempstring<<"\n";
        }
    }
    return 0;
}
