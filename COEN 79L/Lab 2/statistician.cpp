//Name: Gagan Gupta
//Date: 01/17/20
//Assignment: Lab 2 Part 1 Class Implementation File
//Description: Implementation file for the statistician class

// FILE: statistician.cpp
// CLASS IMPLEMENTED: statistician (see stats.h for documentation)

#ifndef STATS2_H     // Prevent duplicate definition
#define STATS2_H
#include <cassert>   // Provides assert
#include <iostream> // Provides istream class
#include "statistician.h"  //Include the header file for the statistician class

using namespace std;

namespace coen79_lab2{      //Made sure to use scope resolution operator for all the member functions
    statistician::statistician(){   //Sets sum and length to 0
        sumSeq=0.0;
        len=0;
    }
    void statistician::next(double r){
        len++;          //Increment length
        if(len==1){     //If it is the first variable initilize the min and max
            sumSeq=r;
            min=r;
            max=r;
        }
        else{           //Sets the sum and checks the min and max values accordingly
            sumSeq+=r;
            if(r<min){
                min=r;
            }
            if(r>max){
                max=r;
            }
        }
    }
    void statistician::reset(){     //Resets all the values of the sequence
        len=0;
        sumSeq=0;
        max=0;
        min=0;
    }
    int statistician::length() const{       //Returns current length
        return len;
    }
    double statistician::sum() const{       //Returns current sum
        return sumSeq;
    }
    double statistician::mean() const{      //Retruns mean based on calculation with length and sum
        assert(len>0);                      //Assert there are elements in the sequence
        return sumSeq/((double)len);        //Have to typecast length to stop the mean from being an integer
    }
    double statistician::minimum() const{   //Returns current min
        assert(len>0);                      //Assert there are elements in the sequence
        return min;
    }
    double statistician::maximum() const{   //Returns current max
        assert(len>0);                      //Assert there are elements in the sequence
        return max;
    }
    statistician operator +(const statistician& s1, const statistician& s2){
        statistician temp;                          //Create temporary statistician to return later
        temp.len=s1.len+s2.len;                     //Set len and sum based on input statisticians
        temp.sumSeq=s1.sumSeq+s2.sumSeq;
        if(temp.len>0){                             //Check to see if there are elements in the temp
            if(s1.min>=s2.min) temp.min=s2.min;     //Set min
            else temp.min=s1.min;
            if(s1.max<=s2.max) temp.max=s2.max;     //Set max
            else temp.max=s1.max;
        }
        return temp;                                //Return temp statistician which is then destroyed after function call
    }
    statistician operator *(double scale, const statistician& s){
        statistician temp;                          //Create temporary statistician to return later
        temp.len=s.len;                             //Set len and sum based on input statistician and scale
        temp.sumSeq=s.sumSeq*scale;
        if(temp.len>0){                             //Check to see if there are elements in the temp
            if(scale>0){                            //Checks to see if scale is positive
                temp.min=s.min*scale;               //If it is set min and max normally
                temp.max=s.max*scale;
            }
            else{
                temp.min=s.max*scale;               //However if scale is negative the min and max will flip
                temp.max=s.min*scale;
            }
        }
        return temp;
    }
    bool operator ==(const statistician& s1, const statistician& s2){   //Check if two statisticians are equivalent
        if(s1.length()>0 && s2.length()>0 && s1.length()==s2.length()){ //Check if len>0 for both and if len is equivalent
            if(s1.sum()==s2.sum() && s1.minimum()==s2.minimum()
               && s1.maximum()==s2.maximum()) return true;              //Check to see if all other elements are equal, if so return true
            else return false;                                          //Otherwise false
        }
        else if(s1.length()!=s2.length()) return false;                 //If length is not equal return false
        else return true;                                               //Logically, If both have no elements return true
    }
}


#endif
