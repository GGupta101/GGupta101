//
//  Lab1Part1.cpp
//  Lab 1
//
//  Created by ggupta on 1/10/20.
//

#include "Lab1Part1.hpp"
#include <iostream>
using namespace std;

int main(int argc, const char* argv[]){
    //Store the word input from the user using getline (in case there is a space in the phrase)
    string word;
    cout<<"Please type something: ";
    getline(cin,word);
    
    //Intilize and set the varibles for the counts of the types of chars
    int alnum=0;
    int nonAlnum=0;
    //Iterate through the whole word input
    for(int i=0;i<word.length();i++){
        //Check to ignore spaces
        if(word[i]!=' '){
            if(isalnum(word[i])) nonAlnum++;
            else alpha++;
        }
    }
    //Print Phrase stating all the information about the counts
    cout<<"\""<<word<<"\""<<" has "<<alnum<<" alphanumeric characters and "<<alpha<<" non-alphanumeric characters.\n";
    return 0;
}
