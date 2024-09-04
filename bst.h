//bst.h
//Drake Wheeler
//CS302
//Program 3
//Karla Fant
//7/30/2024
//This is the header file for the bst class. This class manages the binary search tree.


#ifndef BST_H
#define BST_H

#include "node.h"
#include "canned.h"
#include "poultry.h"
#include "fish.h"

class bst
{
	public:
		bst(); //constructor
		~bst(); //destructor
		int insert(void); //Inserts new food into bst from user input, returns 1 for success, 0 for error
		int display_all(void) const; //Displays all items in bst alphabetically, returns 1 for succes, 0 for no items to display, can throw missing data error
		int display_specific(void) const; //Displays specific item based on user input, returns 1 for success, 0 for empty tree
		int menu_choice(int choices); //Pass in the number of choices that are valid and it get and returns in from the user
		int remove_all(void); //Removes all nodes in bst, returns 1 for success, 0 for bst already empty
		int remove_specific(void); //Removes node based on user input, returns 1 for success, 0 for no match
		int update_item_frequency(void); //Updates the order frequency of a specific item
		int update_poultry_fresh(void); //Uses downcasting to update the fresh by dat for a poultry item, returns 0 for no match, 1 for success, and 2 for unsuccesful downcasting, return 3 for error udpating fresh by date



	private:
		unique_ptr<node> root; //pointer to root of bst

		int insert(unique_ptr<food> to_insert, unique_ptr<node> & root); //Recusrive part of insert function, 1st key name, second key, delivery frequency
		void display_all(const unique_ptr<node> & root) const; //Recusrive part of display all, throws missing data error if a item detail is missing
		node* find_node(const unique_ptr<node> & root, const string & search) const; //Returns a pointer to the node once found or nullptr if not found, throws missing data error if name data was missing in food items
		void remove_all(unique_ptr<node> & root); //recusrivse part of remove all
		int remove_specific(unique_ptr<node> & root, const string & to_find); //recustive part of remove specific
		unique_ptr<food> return_ios_item(unique_ptr<node> & current); //given the right child of the node being removed, it returns the ios
};


#endif // BST_H
