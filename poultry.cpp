//poultry.cpp
//Drake Wheeler
//Program 3
//CS302
//Karla Fant
//7/30/2024

#include "poultry.h"
#include "error.h"
#include <iostream>
using namespace std;


//constructor
poultry::poultry() : cut(""), fresh_before("")
{}



//destructor
poultry::~poultry()
{}



//sets class members with user input
void poultry::input_details(void)
{
	//Sets base details with user input
	food::input_details();

	//If poultry details are already set
	if(!cut.empty() || !fresh_before.empty())
	{
		over_write error;
		throw error;
	}

	//clear input stream
	cin.clear();
	cin.ignore(100, '\n');

	//Get input from user and set data member with it
	cout << "Enter the cut type of the meat: ";
	getline(cin, cut);
	cout << "Enter the date the meat is fresh until: ";
	getline(cin, fresh_before);

	return;
}



//display's all of the food's details to user
void poultry::display(void) const
{
	//Displays base food details, throw error if data is missing
	food::display(); 

	cout << "   Type of cut: " << cut << "   Fresh before: " << fresh_before << endl;

	//if poultry is missing data
	if(cut.empty() || fresh_before.empty())
	{
		missing_data error;
		throw error;
	}

	return;
}



//updates order frequency
int poultry::update_frequency(void)
{
	return food::update_frequency();
}



//changes fresh_before date with user input
int poultry::update_fresh(void)
{
	cout << "Current fresh before data: " << fresh_before << endl;
	cout << "Enter the updated fresh before data: ";
	getline(cin, fresh_before);

	return 1;
}


