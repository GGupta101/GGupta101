//File: Test.cpp
//Name: Gagan Gupta
//Date: 10/25/20
//Assignment: COEN 171 Homework 2 Part 1

# ifndef TEST_MAIN
# define TEST_MAIN

#include <stdio.h>
#include <iostream>
#include "Tree.h"

int main(){
    Tree<int>* t = new Tree<int>();
	t->insert(15);
	t->insert(10);
	t->insert(20);
	t->insert(5);
	t->insert(30);
	t->insert(25);

	std::cout<<t->member(15)<<std::endl;
	std::cout<<t->member(5)<<std::endl;
	std::cout<<t->member(25)<<std::endl;
	std::cout<<t->member(7)<<std::endl;
	std::cout<<t->member(11)<<std::endl;
	std::cout<<t->member(44)<<std::endl;
}

# endif
