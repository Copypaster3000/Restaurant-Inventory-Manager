//node.cpp
//Drake Wheeler
//CS302
//Program 3
//Karla Fant
//7/30/2024
//This file holds the funciton definitions for the node class.

#include "node.h"


//default constructor
node::node() : item(nullptr), left(nullptr), right(nullptr)
{}



//custom constructor
node::node(unique_ptr<food> obj) : item(move(obj)), left(nullptr), right(nullptr)
{}



//destructor
node::~node()
{}



//Set class item with new item
int node::set_item(unique_ptr<food> new_item)
{
	//if pointer is null return error
	if(!new_item) return 0; 
	
	//Transfer ownership of new item to class item pointer, delete's "old" item
	item = move(new_item);

	return 1; //success
}



//returns unique_ptr to item
unique_ptr<food> node::transfer_item(void)
{
	return move(item);
}




//returns item object
food & node::get_item(void)
{
	return *item;
}



//returns left pointer
unique_ptr<node> & node::get_left(void)
{
	return left;
}



//return right pointer
unique_ptr<node> & node::get_right(void)
{
	return right;
}

