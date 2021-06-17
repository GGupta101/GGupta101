// FILE: keyed_bag.h
// CLASS PROVIDED: keyed_bag (part of the namespace coen79_lab4)
//
//
//  COEN 79
//  --- Behnam Dezfouli, COEN, SCU ---

#ifndef COEN79_KEYBAG_CPP
#define COEN79_KEYBAG_CPP

#include <cstdlib>  // Provides size_t
#include <string>
#include "keyed_bag.h"

using namespace std;

namespace coen79_lab4
{
	//CONSTRUCTOR for the keyed_bag class:
    keyed_bag::keyed_bag( ){
        //Sets used to 0
        used=0;
    }

	//MODIFICATION MEMBER FUNCTIONS for the keyed_bag class:
    void keyed_bag::erase(){
        //Set used to 0
        used=0;
    }
    bool keyed_bag::erase(const key_type& key){
        //Erase the given key from the bag if it exists and shift the arrays over accordingly
        if(has_key(key)){
            int i,j;
            for(i=0;i<used;i++){
                if(keys[i]==key){
                    for(j=i+1;j<used;j++){
                        data[j-1]=data[j];
                        keys[j-1]=keys[j];
                    }
                    used--;
                    return true;
                }
            }
        }
        return false;
    }
    void keyed_bag::insert(const value_type& entry, const key_type& key){
        //Insert the given entry with the given key into the bag
        data[used]=entry;
        keys[used]=key;
        used++;
    }
    void keyed_bag::operator +=(const keyed_bag& addend){
        //+= operator for the keyed bag class
        for(int i=0;i<addend.used;i++){
            //Simply use the insert to add all the new elements to the end of the bag
            insert(addend.data[i],addend.keys[i]);
        }
    }

	//CONSTANT MEMBER FUNCTIONS for the keyed_bag class:
    bool keyed_bag::has_key(const key_type& key) const{
        //Check if the bag has an element with the given key, if so return true, if not return false
        int i;
        for(i=0;i<used;i++){
            if(keys[i]==key){
                return true;
            }
        }
        return false;
    }
    keyed_bag::value_type keyed_bag::get(const key_type& key) const{
        //Return the element with the given key if it exists
        int i;
        for(i=0;i<used;i++){
            if(keys[i]==key){
                return data[i];
            }
        }
        return 0;
    }
    keyed_bag::size_type keyed_bag::size( ) const{
        //Return size of the bag
        return (size_type)used;
    }
    keyed_bag::size_type keyed_bag::count(const value_type& target) const{
        //Count the number of elements with the vlaue of target in the bag and return
        int i,count;
        count=0;
        for(i=0;i<used;i++){
            if(data[i]==target){
                count++;
            }
        }
        return (size_type)count;
    }
    bool keyed_bag::hasDuplicateKey(const keyed_bag& otherBag) const{
        //If there are 2 identical key return true. else false
        int i;
        for(i=0;i<used;i++){
            if(otherBag.has_key(keys[i])){
                return true;
            }
        }
        return false;
    }

    // NONMEMBER FUNCTIONS for the keyed_bag class
    keyed_bag operator +(const keyed_bag& b1, const keyed_bag& b2){
        //+ operator for the bag class. It ia a nonmember so we use the member operator += to calculate and return combined value of b1 and b2
        keyed_bag temp;
        temp+=b1;
        temp+=b2;
        return temp;
    }
}

#endif
