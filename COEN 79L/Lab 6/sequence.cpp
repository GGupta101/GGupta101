//FILE: sequence.cpp
//CLASS IMPLEMENTED: sequence (see sequence.h for documentation)
//Name: Gagan Gupta
//Date: 02/14/20
//Assignment: Lab 6 Sequence Implmentation File

//INVARIANT for the sequence class
//  1. The number of items in the sequence is stored in the member variable "many_nodes"
//
//  2. For an empty sequence, we do not care what is stored in any of data and head_ptr
//      and tail_ptr point to NULL; for a non-empty sequence, the items stored in the
//      sequence can be accessed using head_ptr and tail_ptr and we don't care what is
//      stored in the rest of the data.
//
//  3. If there is a current item, then it lies in *cursor; if there is no
//     current item, then cursor* equals NULL.
//
//  4. If there is a previous item, then it lies in precursor*.  If there is no previous
//       item, then precursor equals NULL.


#include <iostream>
#include <algorithm> //provides copy function
#include <cassert> //for assert function
#include "sequence.h" //header file for class
#include "node.h" // provides node class

using namespace std; //For copy function

namespace coen79_lab6
{
    // Default private member variable initialization function.
    void sequence::init()
    {
        //Initializing pointers to NULL
        head_ptr = NULL;
        tail_ptr = NULL;
        cursor = NULL;
        precursor = NULL;
        //Initializiing many_nodes (or our counter) to 0
        many_nodes = 0;
    }

    //CONSTRUCTOR IMPLEMENTATION for default constructor
    sequence :: sequence ()
    {
        init();
    }

    //Copy Constructor
    sequence :: sequence(const sequence& source)
    {
        init();
        *this = source;
    }
    
    //Destructor
    ~sequence( ){
        
    }
    
    // MODIFICATION MEMBER FUNCTIONS
    void start( ){
        if(many_nodes!=0){
            cursor=head_ptr;
            precursor=NULL;
        }
        else{
            cursor=NULL;
            precursor=NULL;
        }
    }
    void end(){
        if(many_nodes!=0){
            cursor=tail_ptr;
            
        }
        else{
            cursor=NULL;
            precursor=NULL;
        }
    }
    void advance( ){
		//Move the cursor ahead one position. if at end then set to NULL
        if(cursor==tail_ptr){
			cursor=NULL;
		}
		else{
			precursor=cursor;
			cursor= cursor->link();
		}
    }
    void insert(const value_type& entry){
		//Insert entry depending on where cursor is positioned and increment many_nodes
		if(head_ptr == NULL){
			list_head_insert(head_ptr, entry);
			tail_ptr = head_ptr;
			cursor = head_ptr;
			precursor = NULL;
		}
		else if(is_item() && cursor == head_ptr){
			list_head_insert(head_ptr, entry);
			cursor = head_ptr;
			precursor = NULL;
		}
		else if(is_item() && cursor != head_ptr){
			list_insert(precursor, entry);
			cursor = precursor -> link();
		}
		else if(!is_item()){
			list_head_insert(head_ptr, entry);
			tail_ptr = precursor->link();
			cursor = head_ptr;
			precursor = NULL;
		}
		many_nodes++;
		return;
    }
    void attach(const value_type& entry){
		//Attach the given entry to the Linked List. If empty make it head
		if(head_ptr == NULL){
			list_head_insert(head_ptr, entry);
			cursor = head_ptr;
			precursor = NULL;
			tail_ptr = head_ptr;
		}
		else if(many_nodes == 1){
			list_insert(head_ptr, entry);
			precursor = head_ptr;
			tail_ptr = precursor->link();
			cursor = tail_ptr;
		}
		else if(many_nodes > 1 && cursor == head_ptr){
			list_insert(head_ptr, entry);
			precursor = head_ptr;
			cursor = precursor->link();
		}
		else if(cursor != head_ptr){
			if(cursor != tail_ptr){
				list_insert(cursor, entry);
				advance();
			}
			else{//tail
				list_insert(tail_ptr, entry);
				tail_ptr = cursor->link();
				precursor = cursor;
				cursor = tail_ptr;
			}
		}
		else if(!is_item()&&many_nodes > 0){
			list_insert(tail_ptr, entry);
			precursor = tail_ptr;
			cursor = precursor->link();
			tail_ptr = cursor;
		}
		many_nodes++;
		return;
	}
    void operator =(const sequence& source){
		//Overload the = ooperator. If the addresses are the same return
		if(this == &source){
			return;
		}
		list_clear(head_ptr);
		many_nodes = 0;
		node* tmp_tail;
		list_copy(source.head_ptr, head_ptr,tmp_tail);
		cursor = head_ptr;
		tail_ptr = tmp_tail;
		node* tmp = source.head_ptr;
		precursor = head_ptr;
		if(source.cursor == NULL){
			cursor = NULL;
			precursor = tail_ptr;
		}
		else{
			while(tmp != source.precursor){
				tmp = tmp->link();
				precursor = precursor->link();
			}
			if(precursor != NULL){
				cursor = precursor->link();
			}
		}
		many_nodes = source.many_nodes;   
    }
    void remove_current( ){
		//Remove the element the cursor is pointing to
		if(head_ptr->link() == NULL){
			delete cursor;
			head_ptr = NULL;
			tail_ptr = NULL;
			precursor = NULL;
			cursor = NULL;
		}
		else if(cursor == head_ptr && head_ptr ->link() !=NULL){
			cursor = head_ptr->link();
			list_head_remove(head_ptr);
			precursor = NULL;
		}
		else if(cursor != head_ptr && cursor != tail_ptr){
			precursor->set_link(cursor->link());
			delete cursor;
			cursor = precursor->link();
		}
		else if (cursor == tail_ptr && many_nodes > 1){
			tail_ptr = precursor;
			delete cursor;
			cursor = NULL;
			tail_ptr->set_link(NULL);
		}
		many_nodes--;
    }
    
    // CONSTANT MEMBER FUNCTIONS
	sequence::size_type sequence::size( ) const{
		return many_nodes;
	}

	bool sequence::is_item( ) const{
		if(cursor == NULL){
			return false;
		}
		return true;]
	}

	sequence::value_type sequence::current( ) const{
		return cursor->data();
	}
}
