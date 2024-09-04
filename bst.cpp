//bst.cpp
//Drake Wheeler
//CS302
//Program 3
//Karla Fant
//7/30/2024
//This file holds the function definitions for the bst class.

#include "bst.h"
#include "error.h"
#include <iostream>




//constructor
bst::bst() :  root(nullptr)
{}



//destructor
bst::~bst()
{}



//insert new node into bst
int bst::insert(void)
{
	int choice {}; //Holds user choice
	unique_ptr<food> food_item; //Temporary pointer to hold onto food type object

	cout << "\nWhat type of food would you like to add to the order system?" << endl;
	cout << "1) canned" << endl;
	cout << "2) poultry" << endl;
	cout << "3) fish" << endl;
	choice = menu_choice(3);

	//Set food_item pointer to type of food object chosen by user
	if(choice == 1) food_item = make_unique<canned>();
	else if(choice == 2) food_item = make_unique<poultry>();
	else food_item = make_unique<fish>();

	try
	{
		food_item->input_details(); //Set food type object with details from user input
	}
	catch(const over_write & error)
	{
		cout << error.detail;
	}

	//Call recursive function to input food item in correct spot in bst
	return insert(move(food_item), root);
}



//recusrive part of insert
int bst::insert(unique_ptr<food> to_insert, unique_ptr<node> & root)
{
	if(!root) //If the pointer we have traveresd to is null
	{
		root = make_unique<node>(move(to_insert)); //Set pointer to new node, w/ food object passed in

		return 1;// return 1 for success
	}

	//If to_insert is less the current item aplhabetically, go to left child
	if(*to_insert < root->get_item()) return insert(move(to_insert), root->get_left());
	//If to_insrt is greater than the current item alphabetically, go to right child
	if(*to_insert > root->get_item()) return insert(move(to_insert), root->get_right());
	//If they are equal alphabetically, refer to second key, frequency
	if(*to_insert == root->get_item())
	{
		//If to_insert frequency is less than current item frequency go to left child
		if(root->get_item().cmp_frequency(*to_insert)) return insert(move(to_insert), root->get_left());
		else return insert(move(to_insert), root->get_right()); //If to_insert is greater than are eqaul to current frequency, go to right child
	};

	return 0; //If none of the previous statments were hit, return an error
}



//displays all items in bst
int bst::display_all(void) const
{
	//Return 0 if nothing to display
	if(!root) return 0;

	cout << endl;

	//Display tree
	display_all(root);

	return 1;
}



//recusrsive part of display all
void bst::display_all(const unique_ptr<node> & root) const
{
	if(!root) return; //Return after hitting base case

	//traverse all the way to the left
	display_all(root->get_left());

	//Display current node
	root->get_item().display();

	//Traverse to the right
	display_all(root->get_right());

	return;
}



//display food item user searched for
int bst::display_specific(void) const
{
	if(!root) return 0; //No items to display
	
	string search; //Hold food user wants to display
	
	//clear input stream
	cin.clear();
	cin.ignore(100, '\n');
	cout << "\nEnter the name of the food item you would like to view, it is case sensative: ";
	getline(cin, search);

	
	node* match = nullptr; //Create pointer to hold match

	try
	{
		//Set match to node with matching name of search
		match = find_node(root, search);
	}
	catch (const missing_data & error) //Display error if one was thrown while looking for match
	{
		cout << error.detail << endl;
		cout << "Triggered while searching for match" << endl;
	}

	if(match) //IF a match was found
	{
		cout << endl;
		match->get_item().display(); //Display food details
	}
	else cout << "\nThere is no food currently logged named \"" << search << "\"." << endl;

	return 1;
}



//Returns pointer to node with match name
node* bst::find_node(const unique_ptr<node> & root, const string & search) const
{
	if(!root) return nullptr; //No match found

	if(search == root->get_item()) return root.get(); //Return pointer to current node if there's a match

	//Call function on left subtree if search is less then current name
	if(search < root->get_item()) return find_node(root->get_left(), search);

	//call funciton or right subtree otherwise
	return find_node(root->get_right(), search);
}



//Removes all nodes from bst
int bst::remove_all(void)
{
	if(!root) return 0; //No nodes to remove

	remove_all(root); //Delete all nodes in tree

	return 1; //For success
}



//recursive part of remove all
void bst::remove_all(unique_ptr<node> & root)
{
	if(!root) return; //Return if current pointer is already null

	remove_all(root->get_left()); //Call on left subtree
	remove_all(root->get_right()); //Call on right subtree

	root.reset(); //Delete node and set pointer to null

	return;
}



//removes node based on user input
int bst::remove_specific(void)
{
	if(!root) return 0; // no node's to remove

	string to_find;

	//clear input stream
	cin.clear();
	cin.ignore(100, '\n');
	cout << "\nEnter the name of the food item you would like to remove, it is case sensative: ";
	getline(cin, to_find); //Get and store name of food to remove from user

	return remove_specific(root, to_find);

}



int bst::remove_specific(unique_ptr<node> & root, const string & to_find)
{
	if(!root) return 0; //No match found

	//If current node is to be removed
	if(to_find == root->get_item())
	{
		if(!root->get_left() && !root->get_right()) //If node has no childern
		{
			root.reset(); //Delete it and set it to nullptr
		}
		else if(root->get_left() && !root->get_right()) //If node has one left child
		{
			unique_ptr<node> to_remove = move(root); //Hold onto pointer to be removed
			root = move(to_remove->get_left()); //Set pointer from parent to ios of node being removed
			//Node to be removed is automatically deleted when smart pointer's transfered ownership
		}
		else if(!root->get_left() && root->get_right()) //If node has one left child
		{
			root = move(root->get_right()); //Set pointer from parent to ios of node being removed
			//Node to be removed is automatically deleted when smart pointer's transfered ownership
		}
		else //Node has two children
		{
			if(!root->get_right()->get_left()) //If the right child has no left child
			{
				unique_ptr<node> hold = move(root->get_left()); //Hold onto left child of node being removed
				root = move(root->get_right()); //transfer current pointer to ios pointer, which deletes the node being removed
				root->get_left() = move(hold); //Set ios's left child as left child of removed node
			}
			else //If the right child is not the ios
			{
				//sets the node being removed food item to the ios food item and removes ios from where it was in the tree
				root->set_item(move(return_ios_item(root->get_right())));
			}
		}
	
		return 1; //For success
	}

	//If name looking for is less then current node, call funciton on left sub tree
	if(to_find < root->get_item()) return remove_specific(root->get_left(), to_find);
	else return remove_specific(root->get_right(), to_find);
}



//returns ios given the right child of node to be removed
unique_ptr<food> bst::return_ios_item(unique_ptr<node> & current)
{
	//If current is the ios
	if(!current->get_left())
	{
		unique_ptr<food> hold_item = current->transfer_item(); //Hold onto ios's data
		current = move(current->get_right()); //Replace ios that is being move with it's right child
		return hold_item; //Return ios's food item
	}

	return return_ios_item(current->get_left());
}




//get choice from user
int bst::menu_choice(int range)
{
	int choice {};
	bool valid = false;


	cout << "Enter your choice as an integer: ";
	cin >> choice;

	while(!valid) //While user input is invalid
	{


		//If input is invalid
		if (cin.fail() || choice < 1 || choice > range)
		{
			//clear input stream
			cin.clear();
			cin.ignore(100, '\n');

			//get user input again
			cout << "Invalid input. Enter your choice as an integer: ";
			cin >> choice;
		}
		else valid = true; //if user input is valid
	}

	return choice; //return user's input
}



//updates the order frequency of a specific item
int bst::update_item_frequency(void)
{
	string item_name; //To hold item name from user
	
	//clear input stream
	cin.clear();
	cin.ignore(100, '\n');
	cout << "\nEnter the name of the item you want to update the order frequency of: ";
	getline(cin, item_name);

	//pointer to hold food item
	node* node_w_item = nullptr;

	try
	{
		//set temporary pointer to node w/ item
		node_w_item = find_node(root, item_name); 
	}
	catch (const missing_data & error)
	{
		cout << error.detail << endl;
		cout << "While finding food item to update it's order frequency." << endl;
	}

	//Return 0 if there is no node with that item
	if(!node_w_item) return 0;

	//Updates frequency of item oder with user input and stores it in variable
	int frequency = node_w_item->get_item().update_frequency();

	cout << "The order frequency for " << item_name << " has been succesfully updated to every " << frequency << " days." << endl;

	return 1;
}




//updates the fresh by date for a poultry item
int bst::update_poultry_fresh(void)
{
	string to_find; //to hold item name from user input
				
	cout << "\nEnter the name of the poultry item you would like to update the fresh by date of: ";
	cin.clear(); //clear input stream
	cin.ignore(100, '\n');
	getline(cin, to_find);

	//pointer to hold node with matching food item
	node* found_node = nullptr;

	try
	{
		//Set pointer to node with matching name or no node if no match found
		found_node = find_node(root, to_find);
	}
	catch (const missing_data & error)
	{
		cout << error.detail << endl;
	}

	if(!found_node) return 0; //return 0 if no match found
						
	//Sets p_item to poultry object is the food item of the node is a poultry object, or sets p_item to nullptr if not
	poultry* p_item = dynamic_cast<poultry*>(&found_node->get_item());
	
	if(p_item) //If the p_item was succesfully down casted to poultry object
	{
		//updates poultry item fresh by date with user input
		if(!p_item->update_fresh()) return 3; //If error return special error code

		return 1;
	}

	return 2; //Food item was not a poultry item, downcasting unsuccessful
}
	









