//app.cpp
//Drake Wheeler
//CS302
//Program 3
//Karla Fant
//7/30/2024
//This file holds the funciton definitions for the app class.

#include "app.h"
#include "error.h"
#include <iostream>
using namespace std;


//constructor
app::app()
{}



//destructor
app::~app()
{}



//intro to user
void app::intro(void)
{
    cout << "\nThis program helps you keep track of all the food items you need for your restaurant" << endl;
	cout << "and how often you need to order the ingredient. You can add food items to the inventory" << endl;
	cout << "in three categories: canned, fish, and poultry. Additional details can also be trakced" << endl;
	cout << "based on the item's category." << endl;

	return;
}



//returns user menu choice
int app::menu(void)
{
	int choice {}; //Holds user's menu choice

	cout << "\nWould you like to:" << endl;
	cout << "1) Add a new item" << endl;
	cout << "2) Remove a item specific by name" << endl;
	cout << "3) Display a specific item by name" << endl;
	cout << "4) Display all items" << endl;
	cout << "5) Remove all items" << endl;
	cout << "6) Update the frequency of an item's order" << endl;
	cout << "7) Update the fresh before date of a poultry item (uses downcasting)" << endl;
	cout << "8) End the program" << endl;
    
	//Utalizes bst's menu_choice function to set menu choice
	choice = inventory.menu_choice(8);

	return choice;
}



//adds new item to inventory
void app::insert(void)
{
	try
	{
		inventory.insert(); //Insert new item based on user input
	}
	catch(missing_data error) //Catch error throw if there was missing data used to compare during traversal
	{
		cout << error.detail << endl; //Display error message
	}

	return;
}



//removes specific food item from inventory based on use input
void app::remove(void)
{
	try
	{
		//Removes item based on user input
		if(inventory.remove_specific()) cout << "\nThe item was removed from inventory." << endl;
		else cout << "\nThere is no item by that name currently in inventory." << endl;
	}
	catch(const missing_data & error)
	{
		cout << error.detail << endl;
		cout << "During remove specific." << endl;
	}

	return;
}



//display all items alphabetically
void app::display_all(void)
{
	try
	{
		//Displays entire invetory
		if(!inventory.display_all()) cout << "\nThere are no items logged, there is nothing to display." << endl;
	}
	catch(const missing_data & error) //Catches error if there is missing data detected during displaying
	{
		cout << error.detail << endl;
	}


	return;
}



//Displays food searched for by user
void app::display(void)
{
	//Displays item searched for by user
	if(!inventory.display_specific()) cout << "\nThere are no items logged, there is nothing to display." << endl;

	return;
}



//Removes all items in inventroy
void app::remove_all(void)
{
	//Removes items
	if(!inventory.remove_all()) cout << "\nThere are no items logged, there is nothing to be removed." << endl;
	else cout << "\nAll items have been removed from inventory." << endl;

	return;
}



//updates the frequency of an item
void app::update_frequency(void)
{
	if(!inventory.update_item_frequency()) cout << "\nThere is no item by that name in the inventory" << endl;

	return;
}



//updates a poultry items fresh by date with user input
void app::update_poultry_fresh(void)
{
	int result = inventory.update_poultry_fresh();

	if(result == 0) cout << "\nThere is no food item by that name in inventory." << endl;
	if(result == 1) cout << "\nThe fresh by date has been succesfully updated." << endl;
	if(result == 2) cout << "\nThat food item was not logged as a poultry item. The fresh by date has not been updated." << endl;
	if(result == 3) cout << "\nThe item was found and is a poultry item, but there was an error updating the fresh by date." << endl;

	return;
}

