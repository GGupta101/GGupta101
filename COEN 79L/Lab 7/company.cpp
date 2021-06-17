//FILE: company.cpp
//Name: Gagan Gupta
//Date: 02/21/20
//Assignment: Lab 7 Company Implementation File


#include <cassert>
#include "company.h"

//#define USEDEBUG

#ifdef USEDEBUG
#define Debug( x ) std::cout << x
#else
#define Debug( x )
#endif

namespace coen79_lab7
{
    company::company() {
        this->company_name = "";
        this->head_ptr = NULL;
        this->tail_ptr = NULL;
    }
    
    company::company(const std::string& company_name) {
        assert(company_name.length() > 0);
		this->company_name=company_name;
        this->head_ptr=NULL; 
		this->tail_ptr=NULL;
    }
    
    company::company(const company &src) {
        Debug("Company copy constructor..." << std::endl);
		*this=src;
    }

    
    company& company::operator= (const company &src) {
        Debug("Company assignemnt operator..." << std::endl);
		//Clear current head pointer and use list_copy to copy over the item data to current head pointer from src
		list_clear(this->head_ptr);
        list_copy(src.head_ptr,this->head_ptr,this->tail_ptr);
		//Copy the company name and return
        this->company_name=src.company_name;
        return *this;
    }
    
    
    company::~company() {
        list_clear(head_ptr);
    }
    
    
    std::string company::get_name() const {
        return company_name;
    }
    
    const node *company::get_head() const {
        return head_ptr;
    }
    
    const node *company::get_tail() const {
        return tail_ptr;
    }
    
    node* company::get_head() {
        return head_ptr;
    }
    
    node* company::get_tail() {
        return tail_ptr;
    }
    
    void company::print_items() {
        list_print(head_ptr);
    }
    
    
    bool company::insert(const std::string& product_name, const float& price) {
        assert(product_name.length() > 0);
        if (list_contains_item(head_ptr, product_name)) {
            return false;
        }
        //Create new node with data passed in
        if (head_ptr == NULL) {
            list_init(head_ptr, tail_ptr, product_name, price);
        }
        else {
			//Make tail_ptr point to new_node and then set it to new_node
            list_tail_insert(tail_ptr, product_name, price);
        }
        return true;
    }

    
    bool company::erase(const std::string& product_name) {
        assert(product_name.length() > 0);
		
        node* temp;
        node* prev;
		//If company empty or item doesn't exsist return false
		if(head_ptr==NULL){
			return false;
		}
        if(!list_contains_item(head_ptr,product_name)){
            return false;
        }
		//If found at head and is the same, erase and return true
        if(head_ptr->getName().compare(product_name)==0){   
			temp=head_ptr; 
			head_ptr=head_ptr->getLink();
            free(temp); 
			return true;            
        }
		//Find the element. When found break out of the while and redirect link and erase the specific item then return true
        prev=head_ptr;
		temp=head_ptr;
        while(temp!=NULL){
            if(temp->getName().compare(product_name)==0){
                break;
            }
            prev=temp; 
			temp=temp->getLink();
        }
        
        prev->setLink(temp->getLink());
        free(temp);
        return true;
    }
    
    
}
