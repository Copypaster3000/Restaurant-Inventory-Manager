//main.cpp
//Drake Wheeler
//CS302
//Program 3
//Karla Fant
//7/30/2024
//This file contains the main program function. 

#include "app.h"
#include <iostream>
using namespace std;

int main()
{
	int choice {}; //to hold user menu choice
	app application; //Create an app object

	application.intro(); //Exaplian the program to the user
						 

	while(choice != 8) //While user hasn't chosen to end the program
	{
		choice = application.menu(); //Set choice with user's input

		if(choice == 1) application.insert(); //If user chose to insert a new item, do so
		else if(choice == 2) application.remove(); //remove specific item from inventory
		else if(choice == 3) application.display(); //Display item by name from user input
		else if(choice == 4) application.display_all(); //if user chose to display all, do so
		else if(choice == 5) application.remove_all(); //Removes all items in inventory
		else if(choice == 6) application.update_frequency(); //Updates the order frequency of an item from user input
		else if(choice == 7) application.update_poultry_fresh(); //Updates the fresh by date for a poultry item with user input, uses downcasting
	}


	cout << "\nThe program has ended." << endl;


	return 0;
}

