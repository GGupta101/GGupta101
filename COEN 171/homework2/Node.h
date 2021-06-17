//File: Node.h
//Name: Gagan Gupta
//Date: 10/25/20
//Assignment: COEN 171 Homework 2 Part 1

# ifndef NODE_H
# define NODE_H

#include <cstdlib>  
#include <cassert>
#include <stdio.h>
#include <iomanip>
#include <vector>
#include <iostream>

template <class Item>
class Node{
	Item data_field; // data field of a Node
	Node *left_field;  // pointer to the left sub-tree
	Node *right_field; // pointer to the right sub-tree
public:
	// CONSTRUCTOR
	Node( const Item& init_data = Item(),Node* init_left = NULL, Node* init_right = NULL){
		data_field = init_data;
		Node* left_field = init_left;
		Node* right_field = init_right;
	}
	
	static bool insert(Node<Item>* root_ptr, const Item& entry){
        if (root_ptr == NULL){
            root_ptr = new Node<Item>(entry);
            return false;
        }
		
		if (entry <= root_ptr->data_field){   
			if(root_ptr->left_field==NULL){
				root_ptr->left_field=new Node<Item>(entry);
			}
			else{
				insert(root_ptr->left_field, entry);
			}
		}
		if (entry > root_ptr->data_field){    
			if(root_ptr->right_field==NULL){
				root_ptr->right_field=new Node<Item>(entry);
			}
			else{
				insert(root_ptr->right_field, entry);
			}
		}
		return true;
    }
	
	static bool member(Node<Item>* root_ptr, const Item& target){
		//If less than go left, if more than go right, and if equal return true
		if (root_ptr == NULL){
			return false;
		}
		if (target < root_ptr->data_field){   
			return member(root_ptr->left_field, target);
		}
		if (target > root_ptr->data_field){   
			return member(root_ptr->right_field, target);
		}
		if (root_ptr->left_field == NULL){  
			return true;
		}
		return true;
	}
};

#endif