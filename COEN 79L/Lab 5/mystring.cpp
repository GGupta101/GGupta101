//FILE: mystring.cpp
//Name: Gagan Gupta
//Date: 02/07/20
//Assignment: Lab 5 String Implementation File

#ifndef COEN79_LAB5_STRING_CPP
#define COEN79_LAB5_STRING_CPP

#include "mystring.h"
#include <cctype>
#include <cassert>
#include <string.h>
#include <iostream>

namespace coen79_lab5{
	
  //CONSTRUCTOR, COPY CONSTRUCTOR, and DESTRUCTOR
  string::string(const char str[ ]){
	//Constructor for the string object when contains char array
    used = strlen(str);
    allocated = used + 1;
    chars = new char[allocated];
    strncpy(chars, str, allocated);
  }
  string::string(char c){
	//Constructor for the string object when contains char
    used = 1;
    allocated = used + 1;
    chars = new char[allocated];
    chars[0] = c;
    chars[1] = '\0';
  }
  string::string(const string& source){
	//Constructor for the string object when contains normal string
    chars = new char[source.used];
    strncpy(chars, source.chars, source.used);
    used = source.used;
    allocated = source.allocated;
  }
  string::~string( ){
	//Destructor for the string objects. Called automatically at the end of the main or when free/delete is called on the object
    delete [] chars;
    used = 0;
    allocated = 0;
  }



  //MODIFICATION MEMBER FUNCTIONS
  void string::operator +=(const string& addend){
	//+= operator for a string addend
    size_t addLen = addend.used;
    size_t finalLen = used + addLen;
    allocated = finalLen + 1;
    reserve(allocated);
    strncat(chars, addend.chars, addLen);
    used = finalLen;
    return;
  }
  void string::operator +=(const char addend[ ]){
	//+= operator for a char array addend
    size_t addLen = strlen(addend);
    size_t finalLen = used + addLen;
    allocated = finalLen + 1;
    reserve(allocated);
    strncat(chars, addend, addLen);
    used = finalLen;
    return;
  }
  void string::operator +=(char addend){
	//+= operator for a char addend
    size_t finalLen = used + 1;
    allocated = finalLen + 1;
    reserve(allocated);
    chars[used] = addend;
    used = finalLen;
    return;
  }
  void string::reserve(size_t n){
	//When we fill the bag we allocate more memory in the heap for the bag and transfer over the data and free the old memory
    char* new_chars = new char[n];
    if(chars != NULL){
      strncpy(new_chars, chars, used);
      delete []chars;
    }
    chars = new_chars;
    return;
  }
  string& string::operator =(const string& source){
	//Implementing valid value semantics for the char dynamic bag
    this->dlt(0, used);
    if(used != source.used){
      allocated = source.allocated;
      reserve(allocated);
    }
    strncpy(chars, source.chars, source.used);
    used = source.used;
    return *this;
  }
  void string::insert(const string& source, unsigned int position){
	//Insert source at given position
    assert(position <= length());
    char* temp1 = new char[used + source.used + 1];
    if(position > 0){
      strncpy(temp1, chars, position);
    }
    char* temp2 = new char[allocated - position];
    for(int i = position, j = 0; i <= used; i++, j++){
      temp2[j] = chars[i];
    }
    delete[] chars;
    strncat(temp1, source.chars, source.used);
    strncat(temp1, temp2, strlen(temp2));
    chars = temp1;
    used += source.used;
    allocated = used + 1;
    return;
  }
  void string::dlt(unsigned int position, unsigned int num){
	//All num chars are deleted from the sequence starting at position
    assert((position + num) <= length());
    for(int i = position; i < length(); i++){
      chars[i] = chars[i + num];
    }
    used -= num;
    return;
  }
  void string::replace(char c, unsigned int position){
	//Replace char at position with c
    assert(position < length());
    chars[position] = c;
    return;
  }
  void string::replace(const string& source, unsigned int position){
	//Chars  in string at position are replaced with the ones in source
    assert((position + source.used) <= used);
    int j = 0;
    for(int i = position; i < (position + source.length()); i++){
	*(chars + i) = source[j++];
    }
    return;
  }



  //CONSTANT MEMBER FUNCTIONS 
  char string::operator [ ](size_t position) const{
	//Random access operator implementation for the char bag
    assert(position < length());
    return chars[position];
  }
  int string::search(char c) const{
	//Simple search function for a char in a string
    int index = -1;
    for(int i = 0; i < length(); i++){
      if(c == chars[i]){
	index = i;
	break;
      }
    }
    return index;
  }
  int string::search(const string& substring) const{
    int index = -1;
	//strstr searchs for the specific substring in the given string and returns a pointer to its location if found
    char* tmp = strstr(chars, substring.chars);
	//If the strstr funciton doesn't return null it is valid and subtracts the address of it and the char array to get its index
    if(tmp != NULL){
      index = *tmp - *chars;
    }
    return index;
  }
  unsigned int string::count(char c) const{
    unsigned int count = 0;
    for(int i = 0; i < length(); i++){
      if(c == chars[i]){
		count++;
      }
    }
    return count;
  }



  //FRIEND FUNCTIONS
  std::ostream& operator <<(std::ostream& outs, const string& source){
	//Simple implementation for when cout is called on the char bag aka a string
    outs << source.chars;
    return outs;
  }
  //All of the basic comparators for the char bag aka a string
  bool operator ==(const string& s1, const string& s2){
    return (strcmp(s1.chars, s2.chars) == 0);
  }
  bool operator !=(const string& s1, const string& s2){
    return (strcmp(s1.chars, s2.chars) != 0);
  }
  bool operator > (const string& s1, const string& s2){
    return (strcmp(s1.chars, s2.chars) > 0);
  }
  bool operator < (const string& s1, const string& s2){
    return (strcmp(s1.chars, s2.chars) < 0);
  }
  bool operator >=(const string& s1, const string& s2){
    return ((s1 > s2) || (s1 == s2));
  }
  bool operator <=(const string& s1, const string& s2){
    return ((s1 < s2) || (s1 == s2));
  }



  //NON-MEMBER FUNCTIONS for the string class 
  string operator +(const string& s1, const string& s2){
	//Use a temp and the public += operator to implement the + operator for 2 strings
    string temp;
    temp.reserve(s1.length() + s2.length() + 1);
    temp += s1;
    temp += s2;
    return temp;
  }
  string operator +(const string& s1, const char addend[ ]){
	//Use a temp and the public += operator to implement the + operator for a string and a char array
    string temp;
    temp.reserve(s1.length() + strlen(addend) + 1);
    temp += s1;
    temp += addend;
    return temp;
  }
  std::istream& operator >> (std::istream& ins, string& target){
	//istream::peek() extracts the next char in the istream and ignore discards them after we extract them
    while(ins && isspace(ins.peek())){
      ins.ignore();
    }
    char* input = new char[500];
    ins >> input;
    target = string(input);
    return ins;
  }
}

#endif