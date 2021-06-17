//
//  Lab1Part2.cpp
//  Lab 1
//
//  Created by ggupta on 1/10/20.
//

#include "Lab1Part2.hpp"
#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, const char* argv[]){
    //Based on the given example there is a pattern for finding the gaps to feed in and this for loop uses those values
    for(int i=14;i<24;i+=2){
        //When using setw to add spaces make sure to add the length of the phrase to the input to setw
        cout<<setw(i)<<"0123456789"<<setw(i+7)<<"9876543210\n";
    }
    return 0;
}
