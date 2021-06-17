//File: Tree.h
//Name: Gagan Gupta
//Date: 10/25/20
//Assignment: COEN 171 Homework 2 Part 1

# ifndef TREE_H
# define TREE_H

#include <cstdlib>  
#include <cassert>
#include <stdio.h>
#include <iomanip>
#include <vector>
#include <iostream>
#include "Node.h"

template <class Item>
class Tree{
protected:
	Node<Item>* root_ptr;  // pointer to root Node
	
public:
	// CONSTRUCTOR
	Tree(Node<Item>* init_root = NULL){
		root_ptr = init_root;
	}
	
	// CONST MEMBER FUNCTIONS
	const Node<Item>* root() const{
		return root_ptr;
	}
	
	bool insert(const Item& entry){
		if (root_ptr == NULL){   
			root_ptr=new Node<Item>(entry);
		}
		else{
			Node<Item>::insert(root_ptr, entry);
		}
    }
	
	bool member(const Item& target){
		if (root_ptr == NULL){   
		// Empty tree
			return false;
		}
		else{
			Node<Item>::member(root_ptr, target);
		}
	}
};

#endif