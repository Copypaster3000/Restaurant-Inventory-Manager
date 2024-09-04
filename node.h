//node.h
//Drake Wheeler
//CS302
//Program 3
//Karla Fant
//7/30/2024
//This is the header file for the node class.

#ifndef NODE_H
#define NODE_H

#include "food.h"
#include <memory>
using namespace std;

class node
{
	public:
		node(); //default constructor
		node(unique_ptr<food> obj); //custom constructor
		~node(); //destructor
								
		food & get_item(void); //returns the item object
		int set_item(unique_ptr<food> new_item); //pass in move(new_item), sets class item pointer to new_item, returns 1 for success, 0 for error
		unique_ptr<food> transfer_item(void); //Returns a unqiue pointer to item and allows ownership to be transfered
		unique_ptr<node> & get_left(void); //returns left pointer
		unique_ptr<node> & get_right(void); //returns right pointer


	private:
		unique_ptr<food> item; //Points to food item this node holds
		unique_ptr<node> left; //points to right child
		unique_ptr<node> right; //points to left child
};


#endif // NODE_H
