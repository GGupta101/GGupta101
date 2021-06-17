//Name: Gagan Gupta
//Date: 01/24/20
//Assignment: Lab 3 Implementation File
//Description: Implementation file for the sequence Class

// FILE: sequence1.c
//  Sequence Class
//
//  COEN 79
//  --- Behnam Dezfouli, COEN, SCU ---

//Macroguard for the Implementation File
#ifndef COEN79_SEQUENCE2_H
#define COEN79_SEQUENCE2_H

//Include iostream, cmath, and the corresponding header file
#include <iostream>
#include <cmath>
#include "sequence1.h"

namespace coen79_lab3 {
    // TYPEDEF and MEMBER CONSTANTS
    typedef double value_type;
    typedef std::size_t size_type;
    static const size_type CAPACITY = 30;
    
    //Default constructor zeroing out the iterator and the items variables
    sequence::sequence(){
        iterator=0;
        items=0;
    }
    
    //Reset the iterator to 0
    void sequence::start(){
        iterator=0;
    }
    //Set iterator to the last element
    void sequence::end(){
        iterator=items-1;
    }
    //Set iterator to the last position in the double array sequence
    void sequence::last(){
        iterator=CAPACITY-1;
    }
    //Increment iterator by 1
    void sequence::advance(){
        if(iterator<CAPACITY-1){
            iterator++;
        }
    }
    //Decrement iterator by 1
    void sequence::retreat(){
        if(iterator>0){
            iterator--;
        }
    }
    
    //Insert double in the position behind the iterator
    void sequence::insert(const value_type& entry){
        //If there aren't any items add it to the first position
        if(items==0)seq[0]=entry;
        //Else shift everything down one place (including iterator position) and add the element in
        else{
            for(int i=items;i>iterator-1;i--){
                seq[i]=seq[i-1];
            }
            seq[iterator]=entry;
        }
        //Increment item but not iterator
        items++;
    }
    //Insert double in the position after the iterator
    void sequence::attach(const value_type& entry){
        //If there aren't any items add it to the first position
        if(items==0)seq[0]=entry;
        //If the iterator is at the last positon just add the element after it
        else if(iterator==items-1)seq[items]=entry;
        //Else shift everything down one place (NOT including iterator position) and add the element in
        else{
            for(int i=items;i>iterator;i--){
                seq[i]=seq[i-1];
            }
            seq[iterator]=entry;
        }
        //Increment item and iterator as this new element is after the old iterator position
        items++;
        iterator++;
    }
    //Remove the element at the position of the iterator
    void sequence::remove_current(){
        //If one item just set it to zero
        if(items==1){
            seq[0]=0.0;
        }
        //Write over the postion of the iterator and then set the old last element to zero
        else{
            for(int i=iterator+1;i<items;i++){
                seq[i-1]=seq[i];
            }
            seq[items-1]=0.0;
        }
        //Decrement items
        items--;
    }
    //Insert element in the front of the sequence
    void sequence::insert_front(const value_type& entry){
        start();
        insert(entry);
    }
    //Attach element at the end of the sequence
    void sequence::attach_back(const value_type& entry){
        end();
        attach(entry);
    }
    //Remove the first element
    void sequence::remove_front(){
        start();
        remove_current();
    }
    //When += is called attach_back all the elements of rhs to lhs
    void sequence::operator +=(const sequence& rhs){
        for(int i=0;i<rhs.size();i++){
            attach_back(rhs.seq[i]);
        }
    }
    
    //Return items
    size_type sequence::size() const{
        return items;
    }
    //Returns a bool to whether the iterator is at a valid element
    bool sequence::is_item( ) const{
        if(iterator<items)return true;
        return false;
    }
    //Return the elementa at the iterator position
    value_type sequence::current() const{
        return seq[iterator];
    }
    //Return the element in the sequence at position index
    value_type sequence::operator[](int index) const{
        return seq[index];
    }
    //Returns the mean by calculating the sum and then dividing it by the typecasted items
    double sequence::mean() const{
       value_type sum1=0.0;
        for(int i=0;i<items;i++){
            sum1+=seq[i];
        }
        return sum1/((double)items);
    }
    //Retuns the Standard Deviation using the mean, the element, and fuctions from cmath
    double sequence::standardDeviation() const{
        double mean1=mean();
        double sum1=0.0;
        for(int i=0;i<items;i++){
            sum1+=pow((seq[i]-mean1),2);
        }
        return sqrt(sum1/((double)(items)));
    }
    //When + is called create a temporary sequence and += the lhs and += the rhs and then return the temporary (This is a non-member non-friend function)
    sequence operator+(const sequence& lhs, const sequence& rhs){
        sequence temp;
        temp+=lhs;
        temp+=rhs;
        return temp;
    }
    //Returns the sum as a non-member non-friend function. This means we make a copy of the sequence to be able to use the mmber fuction on it.
    value_type summation(const sequence &s){
        sequence s1=s;
        sequence::value_type sum1=0.0;
        s1.start();
        for(size_t i=0;i<s1.size();i++){
            sum1+=s1.current();
            s1.advance();
        }
        return sum1;
    }
}

#endif
