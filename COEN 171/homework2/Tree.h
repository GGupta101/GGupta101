//File: Tree.h
//Name: Gagan Gupta
//Date: 10/25/20
//Assignment: COEN 171 Homework 2 Part 1

# ifndef TREE_H
# define TREE_H

#include <stdio.h>

template <class anObject>
class Node{
	anObject value; // data field of a Node
	Node *left;  // pointer to the left sub-tree
	Node *right; // pointer to the right sub-tree
public:
	// CONSTRUCTOR
	Node( const anObject& init_data = anObject(),Node* init_left = NULL, Node* init_right = NULL){
		value = init_data;
		Node* left = init_left;
		Node* right = init_right;
	}
	
	static bool insert(Node<anObject>* root_ptr, const anObject& entry){
        if (root_ptr == NULL){
            root_ptr = new Node<anObject>(entry);
            return false;
        }
		
		if (entry <= root_ptr->value){   
			if(root_ptr->left==NULL){
				root_ptr->left=new Node<anObject>(entry);
			}
			else{
				insert(root_ptr->left, entry);
			}
		}
		if (entry > root_ptr->value){    
			if(root_ptr->right==NULL){
				root_ptr->right=new Node<anObject>(entry);
			}
			else{
				insert(root_ptr->right, entry);
			}
		}
		return true;
    }
	
	static bool member(Node<anObject>* root_ptr, const anObject& target){
		//If less than go left, if more than go right, and if equal return true
		if (root_ptr == NULL){
			return false;
		}
		if (target < root_ptr->value){   
			return member(root_ptr->left, target);
		}
		if (target > root_ptr->value){   
			return member(root_ptr->right, target);
		}
		if (root_ptr->left == NULL){  
			return true;
		}
		return true;
	}
};

template <class anObject>
class Tree{
	Node<anObject>* root_ptr;  // pointer to root Node
public:
	// CONSTRUCTOR
	Tree(Node<anObject>* init_root = NULL){
		root_ptr = init_root;
	}
	
	// CONST MEMBER FUNCTIONS
	const Node<anObject>* root() const{
		return root_ptr;
	}
	
	bool insert(const anObject& entry){
		if (root_ptr == NULL){   
			root_ptr=new Node<anObject>(entry);
		}
		else{
			Node<anObject>::insert(root_ptr, entry);
		}
    }
	
	bool member(const anObject& target){
		if (root_ptr == NULL){   
		// Empty tree
			return false;
		}
		else{
			Node<anObject>::member(root_ptr, target);
		}
	}
};

#endif