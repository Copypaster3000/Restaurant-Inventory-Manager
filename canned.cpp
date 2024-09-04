//canned.cpp
//Drake Wheeler
//Program 3
//CS302
//Karla Fant
//7/30/2024
//This file holds the function definitions of the canned class.

#include "canned.h"
#include "error.h"
#include <iostream>
using namespace std;



//constructor
canned::canned() : expiration(""), temp(-1)
{}



//destructor
canned::~canned()
{}



//sets class data member with user input
void canned::input_details(void)
{
	//Set base class members with user input
	food::input_details();

	//If data members already have been set w/ custom data
	if(!expiration.empty() || temp !=  -1)
	{
		//throw over write error
		over_write error;
		throw error;
	}

	//clear input stream
	cin.clear();
	cin.ignore(100, '\n');
	cout << "Enter the expiration date: ";
	getline(cin, expiration);
	cout << "Enter the temperature to store the food at as an integer: ";
	cin>> temp;

	return;
}



//Displays all food's details
void canned::display(void) const
{
	//Displays base food details and throws error if missing details
	food::display();

	cout << "   Expiration date: " << expiration << "   Storage temperature: " << temp << endl;

	//if canned is missing data
	if(expiration.empty() || temp == -1)
	{
		missing_data error;
		throw error;
	}

	return;
}



//updates order frequency
int canned::update_frequency(void)
{
	return food::update_frequency();
}

