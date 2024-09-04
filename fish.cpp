//fish.cpp
//Drake Wheeler
//Program 3
//CS302
//Karla Fant
//7/30/2024
//This file holds the function definitions for the fish class.

#include "fish.h"
#include "error.h"
#include <iostream>
using namespace std;


//constructor
fish::fish() : origin(""), water_type(""), fat(-1)
{}



//destructor
fish::~fish() 
{}



//set class data members with user input
void fish::input_details(void)
{
	//set base data members w/ user input
	food::input_details();

	//If a data member has already been set
	if(!origin.empty() || !water_type.empty() || fat != -1)
	{
		//throw over write error
		over_write error;
		throw error;
	}
	
	//clear input stream
	cin.clear();
	cin.ignore(100, '\n');

	cout << "Where did the fish come from: ";
	getline(cin, origin);
	cout << "Is it a salt water or fresh water fish: ";
	getline(cin, water_type);
	cout << "Enter its fat content percentage as an integer: ";
	cin >> fat;

	return;
}
		


//displays food details to user
void fish::display(void) const
{
	//displays base food details and throws error if missing details
	food::display();

	cout << "   Fish orgin: " << origin << "   Water type: " << water_type << "   Fat content: " << fat << "%" << endl;

	//if missing poultry details
	if(origin.empty() || water_type.empty() || fat == -1)
	{
		missing_data error;
		throw error;
	}

	return;
}



//updates order frequency
int fish::update_frequency(void)
{
	return food::update_frequency();
}



