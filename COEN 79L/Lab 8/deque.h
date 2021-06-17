//FILE: deque.h
//Name: Eason Liu and Gagan Gupta
//Date: 02/2/20
//Assignment: Lab 8 Deque Header and Implementation File

// TEMPLATE PARAMETER, TYPEDEFS and MEMBER CONSTANTS for the deque<Item> class:
//   The template parameter, Item, is the data type of the items in the deque,
//   also defined as deque<Item>::value_type. It may be any of the C++ built-in
//   types (int, char, etc.), or a class with a default constructor, a copy
//   constructor, and an assignment operator. The definition
//   deque<Item>::size_type is the data type of any variable that keeps track of
//   how many items are in a deque.
//
//   static const size_t BLOCK_SIZE = ____
//     deque::BLOCK_SIZE is the number of enteries in each data block
//
//   static const size_t BLOCKPOINTER_ARRAY_SIZE = ____
//     deque::BLOCKPOINTER_ARRAY_SIZE is the number of enteries in the array of block pointers
//
//   typedef ____ Item
//     sequence::Item is the data type of the items in the deque. It may be any of
//     the C++ built-in types (int, char, etc.), or a class with a default
//     constructor, an assignment operator, and a copy constructor.
//
//
// CONSTRUCTOR for the deque<Item> class:
//   deque(szie_type init_bp_array_size = BLOCKPOINTER_ARRAY_SIZE,
//         size_type initi_block_size = BLOCK_SIZE);
//     Postcondition: The deque contains an array of block pointers with BLOCKPOINTER_ARRAY_SIZE entries
//     NOTE: The default value for the init_bp_array_size is BLOCKPOINTER_ARRAY_SIZE.
//     The default value for the initi_block_size is BLOCK_SIZE.
//
//
//
// CONST MEMBER FUNCTIONS for the deque<Item> class:
//
//   bool isEmpty()
//     Postcondition: Returns false if the deque is empty.
//     Otherwise returns true.
//
//   value_type front()
//    Precondition: isItem() must return true.
//    Postcondition: Returns a copy of the front item.
//
//   value_type back()
//    Precondition: isItem() must return true.
//    Postcondition: Returns a copy of the back item.
//
//
// MEMBER FUNCTIONS for the deque<Item> class:
//   void clear()
//     Postcondition: All the entries of the deque are deleted.
//
//   void print()
//     Postcondition: Prints all the entries of the deque.
//
//   void reserve()
//    Postcondition: Increases the capacity of the deque by 20 x BLOCK_SIZE
//
//   void push_front(const value_type& entry)
//    Postcondition: Adds entry to the front of the deque
//
//   void push_back(const value_type& entry)
//    Postcondition: Adds entry to the back of the deque
//
//   void pop_front()
//    Precondition: isItem() must return true
//    Postcondition: Removes the front item of the deque
//
//   void pop_back()
//    Precondition: isItem() must return true
//    Postcondition: Removes the back item of the deque
//
//
// VALUE SEMANTICS for the deque<Item> class:
//    Assignments and the copy constructor may be used with deque objects.
//
//
// STANDARD ITERATOR MEMBER FUNCTIONS (provide a forward iterator):
//   iterator begin( )
//   iterator end( )

#ifndef COEN79_DEQUE
#define COEN79_DEQUE

//#define USEDEBUG
#ifdef USEDEBUG
#define Debug( x ) std::cout << x
#else
#define Debug( x )
#endif

#include <stdio.h>
#include <cstdlib>
#include <math.h>
#include <cassert>
#include <memory>
#include "deque_iterator.h" 

namespace coen79_lab8{
    template <class Item>
    class deque {
		public:
			static const size_t BLOCK_SIZE = 5;
			static const size_t BLOCKPOINTER_ARRAY_SIZE = 5; 
			typedef std::size_t size_type;
			typedef Item value_type; 
			typedef deque_iterator<Item> iterator; 
			
			deque(size_type init_bp_array_size = BLOCKPOINTER_ARRAY_SIZE, size_type initi_block_size = BLOCK_SIZE);
			deque(const deque& source);
			~deque();
			
			bool isEmpty();
			value_type front();
			value_type back();
			
			iterator begin();
			iterator end();
			
			void operator=(const deque& source);
			void clear();
			void reserve();
			void push_front(const value_type& entry);
			void push_back(const value_type& entry);
			void pop_back();
			void pop_front();
			
		private:
			value_type** block_pointers;     
			value_type**  block_pointers_end;
			
			value_type**  first_bp; 
			value_type**  last_bp;   
			
			value_type* front_ptr;   
			value_type* back_ptr;    
			
			size_type bp_array_size; 
			size_type block_size;    
    };
	
    template <class Item>
    deque<Item>::deque (size_type init_bp_array_size, size_type init_block_size){
		//Implements the constructor for the deque<Item> class which takes in array size and block size as inputs
        bp_array_size = init_bp_array_size;
        block_size = init_block_size;
        block_pointers = new value_type* [bp_array_size];
		
		//Init all the block pointers for deque<Item> class
        for (size_type index = 0; index < bp_array_size; ++index){
            block_pointers[index] = NULL;
        }
        
        block_pointers_end = block_pointers + (bp_array_size - 1);
        first_bp = last_bp = NULL;
        front_ptr = back_ptr = NULL;
    }
    
    
    template <class Item>
    deque<Item>::deque (const deque<Item>& source){
		//Implements the copy constructor for the deque<Item> class
        first_bp = last_bp = NULL;
        front_ptr = back_ptr = NULL;
        block_pointers = block_pointers_end = NULL;
        *this = source;
    }
    
    
    template <class Item>
    void deque<Item>::operator=(const deque<Item>& source) {
		//Implements the == operator for the deque<Item> class which makes sure all the elements in this are equal to the elements in source
        if(first_bp!=NULL) clear();
        delete [] block_pointers;
		
        block_pointers = NULL;
        block_pointers_end = NULL;
        bp_array_size = source.bp_array_size;
        block_size = source.block_size;
        block_pointers = new value_type* [bp_array_size];
		
        for(size_type bp_array_index = 0; bp_array_index < source.bp_array_size; ++bp_array_index){
            if (source.block_pointers[bp_array_index] == NULL){
                block_pointers[bp_array_index] = NULL;
            }
            else{
                if((source.block_pointers + bp_array_index) == source.first_bp){
                    first_bp = block_pointers + bp_array_index;
				}
                if((source.block_pointers + bp_array_index) == source.last_bp){
                    last_bp = block_pointers + bp_array_index;
                }
                block_pointers[bp_array_index] = new value_type [block_size];
                for (size_type block_item_index = 0; block_item_index < block_size; ++block_item_index){
                    value_type val = source.block_pointers[bp_array_index][block_item_index];
                    block_pointers[bp_array_index][block_item_index] = val;
                    if((source.block_pointers[bp_array_index] + block_item_index) == source.front_ptr){
                        front_ptr = block_pointers[bp_array_index] + block_item_index;
					}
                    if((source.block_pointers[bp_array_index] + block_item_index) == source.back_ptr){
                        back_ptr = block_pointers[bp_array_index] + block_item_index;
					}
                }
            }
        }
    }
    
    template <class Item>
    deque<Item>::~deque () {
		//Implements the destructor for the deque<Item> class which initially calls the clear() function before deleting the block pointers
        clear();
        if(block_pointers != NULL){
			delete [] block_pointers;
		}
        
        first_bp = last_bp = block_pointers_end = block_pointers = NULL;
        front_ptr = back_ptr = NULL;
    }
    
    template <class Item>
    void deque<Item>::clear () {
		//Implements the clear function for the deque<Item> class which cleans out all the data from the blocks and resets the first_bp, last_bp, front_ptr, and back_ptr
        for(size_type i = 0; i < bp_array_size; ++i) {
            if(*(block_pointers+i) != NULL) {
                delete [] block_pointers[i];
                block_pointers[i] = NULL;
            }
        }
        
        delete [] block_pointers;
        first_bp = last_bp = NULL;
        front_ptr = back_ptr = NULL;
        block_pointers = NULL;
    }
    
    template <class Item>
    void deque<Item>::reserve(){
		//Implements the reserve function for the deque<Item> class which allows us to reserve more memory when we fill up the deque (specifically 20 new blocks)
        size_type newSize = bp_array_size + 20;
        value_type** new_block_pointers = new value_type* [newSize];
        for (size_type index = 0; index < newSize; ++index){
            new_block_pointers[index] = NULL;
        }
        size_type offsett_first_bp = first_bp - block_pointers;
        size_type offsett_last_bp = last_bp - block_pointers;
		
        std::copy(first_bp, last_bp + 1, new_block_pointers + 10 + offsett_first_bp);
		
        delete [] block_pointers;
		
        block_pointers = new_block_pointers;
        bp_array_size = newSize;
        block_pointers_end = block_pointers + bp_array_size - 1;
        first_bp = block_pointers + offsett_first_bp + 10;
        last_bp = block_pointers + offsett_last_bp + 10;
    }
    
    
    template <class Item>
    void deque<Item>::push_front(const value_type& entry){
		//Implements the push front function for the deque<Item> class which adds entry to the front of the deque
        if (first_bp == NULL){
            assert(bp_array_size > 1);
            size_t bp_mid = floor(bp_array_size/2); 
            last_bp = first_bp = block_pointers + bp_mid - 1;
            *first_bp = new value_type[block_size];
            **first_bp = entry;
            front_ptr = back_ptr = *first_bp;
        }
		
        else if (front_ptr != *first_bp){
            --front_ptr;
            *front_ptr = entry;
        }
		
        else if ((*first_bp == front_ptr) && (first_bp != block_pointers)){
            --first_bp;
            *first_bp = new value_type[block_size];
            (*first_bp)[block_size-1] = entry;
            front_ptr = (*first_bp) + (block_size-1);

        }
		
        else if ((*first_bp == front_ptr) && (first_bp == block_pointers)){
            reserve();
            --first_bp;
            *first_bp = new value_type[block_size];
            (*first_bp)[block_size-1] = entry;
            front_ptr = (*first_bp) + (block_size-1);

        }
    }
    
    
    template <class Item>
    void deque<Item>::push_back(const value_type& entry){
		//Implements the push back function for the deque<Item> class which adds entry to the end of the deque
        if (last_bp == NULL){
            assert(bp_array_size > 1);
            size_t bp_mid = floor(bp_array_size/2);
            last_bp = first_bp = block_pointers + bp_mid  - 1;
            *last_bp = new value_type[block_size];
            **last_bp = entry;
            front_ptr = back_ptr = *last_bp;
        }
        
        else if (back_ptr != ((*last_bp) + (block_size - 1))){
            back_ptr++;
            *back_ptr = entry;
        }
        
        else if ((back_ptr == ((*last_bp) + (block_size - 1))) && (last_bp != block_pointers_end)){
            last_bp++;
            *last_bp = new value_type[block_size];
            (**last_bp) = entry;
            back_ptr = *last_bp;
        }
        

        else if ((back_ptr == ((*last_bp) + (block_size - 1))) && (last_bp == block_pointers_end)){
            reserve();
            last_bp++;
            *last_bp = new value_type[block_size];
            (**last_bp) = entry;
            back_ptr = *last_bp;
        }
    }
    
    
    template <class Item>
    void deque<Item>::pop_front(){
		//Implements the pop front function for the deque<Item> class which removes the element in the front of the deque
        assert(!isEmpty());
        if (back_ptr == front_ptr){
            clear();
        }
        else if (front_ptr == ((*first_bp) + block_size - 1)){
            delete [] *first_bp;
            *first_bp = NULL;
            ++first_bp;
            front_ptr = *first_bp;
        }
        else{
            ++front_ptr; 
        }
    }
    
    
    template <class Item>
    void deque<Item>::pop_back(){
		//Implements the pop back function for the deque<Item> class which removes the element in the back of the deque
        assert(!isEmpty());
        if (back_ptr == front_ptr){
            clear();
        }
        else if (back_ptr == *last_bp){
            delete [] * last_bp;
            *last_bp = NULL;
            --last_bp;
            back_ptr = (*last_bp) + (block_size - 1);
        }
        else{
            --back_ptr;
        }
    }
    
    template <class Item>
    bool deque<Item>::isEmpty(){
		//Implements the is empty function for the deque<Item> class which returns whether or not the deque is empty
        if (front_ptr == NULL){
            return true;
		}        
        return false;
    }
    
    template <class Item>
    typename deque<Item>::value_type deque<Item>::back(){
		//Implements the back function for the deque<Item> class which returns a pointer to back_ptr
        assert(!isEmpty());
        return *back_ptr;
    }
    
    template <class Item>
    typename deque<Item>::value_type deque<Item>::front(){
		//Implements the front function for the deque<Item> class which returns a pointer to front_ptr
        assert(!isEmpty());
        return *front_ptr;
    }
   
    template <class Item>
    typename deque<Item>::iterator deque<Item>::begin(){
		//Implements the begin function for the deque<Item> iterator
        value_type* tmp_cursor = NULL;
        value_type* tmp_current_boundary = NULL;
        value_type** tmp_current_block_pointer = NULL;
        
        if (front_ptr != NULL){
            tmp_cursor = front_ptr;
            tmp_current_block_pointer = first_bp;
            tmp_current_boundary = (*first_bp) + (block_size - 1);
        }
        
        return iterator(block_pointers, block_pointers_end, first_bp, last_bp,
                        front_ptr, back_ptr, bp_array_size, block_size,
                        tmp_cursor, tmp_current_boundary, tmp_current_block_pointer);
    }

    template <class Item>
    typename deque<Item>::iterator deque<Item>::end(){
		//Implements the end function for the deque<Item> iterator
        value_type* tmp_cursor = NULL;
        value_type* tmp_current_boundary = NULL;
        value_type** tmp_current_block_pointer = NULL;
        
        return iterator(block_pointers, block_pointers_end, first_bp, last_bp,
                        front_ptr, back_ptr, bp_array_size, block_size,
                        tmp_cursor, tmp_current_boundary, tmp_current_block_pointer);
    }
}

#endif 
