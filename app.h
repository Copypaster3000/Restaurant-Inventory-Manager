//app.h
//Drake Wheeler
//CS302
//Program 3
//Karla Fant
//7/30/2024
//This is the header file for the app class.


#ifndef APP_H
#define APP_H

#include "bst.h"

class app
{
	public:
		app(); //constructor
		~app(); //destructor
		void intro(void); //explains program to the user
		int menu(void); //Displays program options to the user and returns their choice
		void insert(void); //Adds new item to inventory
		void remove(void); //Remove specific item from inventory base on user input
		void display_all(void); //displays all items alphabetically
		void display(void); //Displays specific inventory item to user based on user input
		void remove_all(void); //Removes all items from inventory
		void update_frequency(void); //Updates the order frequency of an item based on user input
		void update_poultry_fresh(void); //updaets the fresh by date for a poultry item based on user input



	private:
		bst inventory; //bst of all the food items in the restaurant
};


#endif // APP_H
