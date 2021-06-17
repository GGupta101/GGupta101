//FILE: node.cpp
//Name: Gagan Gupta
//Date: 02/14/20
//Assignment: Lab 6 Node Implmentation File

//
// IMPLEMENTS: The functions of the node class and the
// linked list toolkit (see node1.h for documentation).
//
// INVARIANT for the node class:
//   The data of a node is stored in data()
//   and the link to the next node is stored in link().

#ifndef COEN_79_NODE_CPP
#define COEN_79_NODE_CPP

#include "node.h"
#include <cassert>    // Provides assert
#include <cstdlib>    // Provides NULL and size_t
#include <iostream>

using namespace std;

namespace coen79_lab6
{
    size_t list_length(const node* head_ptr)
    // Library facilities used: cstdlib
    {
	const node *cursor;
	size_t answer;

	answer = 0;
	for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
	    ++answer;

	return answer;
    }

    void list_head_insert(node*& head_ptr, const node::value_type& entry)
    {
    	head_ptr = new node(entry, head_ptr);
    }

    void list_insert(node* previous_ptr, const node::value_type& entry)
    {
    	node *insert_ptr;

    	insert_ptr = new node(entry, previous_ptr->link( ));
    	previous_ptr->set_link(insert_ptr);
    }

    node* list_search(node* head_ptr, const node::value_type& target)
    // Library facilities used: cstdlib
    {
    	node *cursor;

    	for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
    	    if (target == cursor->data( ))
        		return cursor;

    	return NULL;
    }

    const node* list_search(const node* head_ptr, const node::value_type& target)
    // Library facilities used: cstdlib
    {
    	const node *cursor;

    	for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
    	    if (target == cursor->data( ))
        		return cursor;

    	return NULL;
    }

    node* list_locate(node* head_ptr, size_t position)
    // Library facilities used: cassert, cstdlib
    {
    	node *cursor;
    	size_t i;

    	assert (0 < position);
    	cursor = head_ptr;
    	for (i = 1; (i < position) && (cursor != NULL); i++)
    	    cursor = cursor->link( );

    	return cursor;
    }

    const node* list_locate(const node* head_ptr, size_t position)
    // Library facilities used: cassert, cstdlib
    {
    	const node *cursor;
    	size_t i;

    	assert (0 < position);
    	cursor = head_ptr;
    	for (i = 1; (i < position) && (cursor != NULL); i++)
    	    cursor = cursor->link( );

    	return cursor;
    }

    void list_head_remove(node*& head_ptr)
    {
    	node *remove_ptr;

    	remove_ptr = head_ptr;
    	head_ptr = head_ptr->link( );
    	delete remove_ptr;
    }

    void list_remove(node* previous_ptr)
    {
    	node *remove_ptr;

    	remove_ptr = previous_ptr->link( );
    	previous_ptr->set_link( remove_ptr->link( ) );
    	delete remove_ptr;
    }

    void list_clear(node*& head_ptr)
    // Library facilities used: cstdlib
    {
    	while (head_ptr != NULL)
    	    list_head_remove(head_ptr);
    }

    void list_copy(const node* source_ptr, node*& head_ptr, node*& tail_ptr)
    // Library facilities used: cstdlib
    {
    	head_ptr = NULL;
    	tail_ptr = NULL;

    	// Handle the case of the empty list.
    	if (source_ptr == NULL)
    	    return;

    	// Make the head node for the newly created list, and put data in it.
    	list_head_insert(head_ptr, source_ptr->data( ));
    	tail_ptr = head_ptr;

    	// Copy the rest of the nodes one at a time, adding at the tail of new list.
    	source_ptr = source_ptr->link( );
    	while (source_ptr != NULL)
    	{
    	    list_insert(tail_ptr, source_ptr->data( ));
    	    tail_ptr = tail_ptr->link( );
    	    source_ptr = source_ptr->link( );
    	}
    }

    void list_piece(node* start_ptr, node* end_ptr, node*& head_ptr, node*& tail_ptr){
		//Allocate new array with the data from start_ptr to end_ptr and set head_ptr and tail_ptr to the head and the tail of the newly allocated array
        if(start_ptr==NULL || start_ptr==end_ptr){
            head_ptr=NULL;
            return;
        }
        node* newHead=new node(start_ptr->data());
        head_ptr=newHead;
        node* temp=newHead;
        node* mover=start_ptr->link();
        while(mover!=end_ptr){
            list_insert(temp,mover->data());
            temp=temp->link();
            mover=mover->link();
        }
        tail_ptr=temp;
    }
    size_t list_occurrences(node* head_ptr, const node::value_type& target){
		//Counts the number of occurrences of target in the linked list and returns it
        node* temp=head_ptr;
        size_t count=0;
        while(temp!=NULL){
            if(temp->data()==target){
                count++;
            }
            temp=temp->link();
        }
        return count;
    }
    void list_insert_at(node*& head_ptr, const node::value_type& entry, size_t position){
		//Inserts entry at the given position given that head_ptr is position=1
		if(position==1){
			list_head_insert(head_ptr, entry);
		}
		else if (position==list_length(head_ptr)+1){
			list_insert(list_locate(head_ptr, list_length(head_ptr)), entry);
		}
		else{
			list_insert(list_locate(head_ptr, position-1), entry);
		}
    }
    node::value_type list_remove_at(node*& head_ptr, size_t position){
		//Removes the node at position given that head_ptr is position=1
        node::value_type value=list_locate(head_ptr, position)->data();
		if(position==1){
			temp=head_ptr->data();
			list_head_remove(head_ptr);
		}
		else{
			list_remove(list_locate(head_ptr, position-1));
		}
        return temp;
    }
    node* list_copy_segment(node* head_ptr, size_t start, size_t finish){
		//Create copy of the whole linked list using the previously defined list_piece
		node* newHead, newTail;
        node* start_ptr=list_locate(head_ptr,start);
        node* end_ptr=list_locate(head_ptr,finish+1);
		list_piece(start_ptr, end_ptr, newHead, newTail);
        return newHead;
    }
    void list_print (const node* head_ptr){
		//Print out the Linked List
        if(head_ptr==NULL){
            cout<<endl;
            return;
        }
        while(head_ptr->link()!=NULL){
            cout<<head_ptr->data()<<", ";
            head_ptr=head_ptr->link();
        }
        cout<<head_ptr->data()<<endl;
    }
    void list_remove_dups(node* head_ptr){
		//Removes all the duplicates in the linked list
		node* ptr1, ptr2, tmep;
		ptr1 = head_ptr;
		while(ptr1 != NULL && ptr1->link()!= NULL){
			ptr2 = ptr1;
			while(ptr2->link() != NULL){
				if(ptr1->data() == ptr2->link()->data()){
					temp = ptr2->link();
					ptr2->set_link(ptr2->link()->link());
					delete temp;
				}
				else{
				  ptr2 = ptr2->link();
				}
				ptr1 = ptr1->link();
			}
		}
		return;
    }
    node* list_detect_loop (node* head_ptr){
		//Implementation of Floyd's Loop Detection Algorithm
        node* sr=head_ptr;
        node* fr=head_ptr;
        int k=1;
        while(fr!=NULL && fr->link()!=NULL && fr!=sr){
            k++;
            fr=fr->link()->link();
            sr=sr->link();
        }
        if((fr==NULL)||(fr->link()==NULL)){
            return NULL;
        }
		for(int i=0;i<k;i++){
			sr=sr->link();
		}
        return sr;
    }
    
}

#endif
