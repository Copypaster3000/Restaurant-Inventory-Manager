//food.h
//Drake Wheeler
//Program 3
//CS302
//Karla Fant
//7/30/2024
//This file holds the food class definitions.

#include "food.h"
#include "error.h"
#include <iostream>
using namespace std;


//constructor
food::food() : name(""), frequency(-1)
{}



//destructor
food::~food()
{}





//Displays food details to user
void food::display(void) const
{
	cout << "Food name: " << name << "   Order frequency in days: " << frequency;

	//If food is missing details
	if(name.empty() || frequency == -1)
	{
		missing_data error;
		throw error;
	}

	return;
}



//updates order frequency with user input
int food::update_frequency(void)
{
	cout << "\nThe current frequency of order for " << name << " is every " << frequency << " days." << endl;
	cout << "Enter what you would like to update it to as an integer: ";
	cin >> frequency;

	return frequency;
}



//less than operator
bool operator < (const food & op1, const food & op2)
{
	//If either of the strings beinf compared are empty
	if(op1.name.empty() || op2.name.empty())
	{
		missing_data error;
		throw error; //Throw missing data error
	}

	return op1.name < op2.name;
}



//less than operator
bool operator < (const string & op1, const food & op2)
{
	//If either of the strings beinf compared are empty
	if(op1.empty() || op2.name.empty())
	{
		missing_data error;
		throw error; //Throw missing data error
	}

	return op1 < op2.name;
}



//less than operator
bool operator < (const food & op1, const string & op2)
{
	//If either of the strings beinf compared are empty
	if(op1.name.empty() || op2.empty())
	{
		missing_data error;
		throw error; //Throw missing data error
	}

	return op1.name < op2;
}


//less than or equal to operator
bool operator <= (const food & op1, const food & op2)
{
	//If either of the strings beinf compared are empty
	if(op1.name.empty() || op2.name.empty())
	{
		missing_data error;
		throw error; //Throw missing data error
	}

	return op1.name <= op2.name;
}



//less than operator
bool operator <= (const string & op1, const food & op2)
{
	//If either of the strings beinf compared are empty
	if(op1.empty() || op2.name.empty())
	{
		missing_data error;
		throw error; //Throw missing data error
	}

	return op1 <= op2.name;
}



//less than operator
bool operator <= (const food & op1, const string & op2)
{
	//If either of the strings beinf compared are empty
	if(op1.name.empty() || op2.empty())
	{
		missing_data error;
		throw error; //Throw missing data error
	}

	return op1.name <= op2;
}



//greater than operator
bool operator > (const food & op1, const food & op2)
{
	//If either of the strings beinf compared are empty
	if(op1.name.empty() || op2.name.empty())
	{
		missing_data error;
		throw error; //Throw missing data error
	}

	return op1.name > op2.name;
}



//less than operator
bool operator > (const string & op1, const food & op2)
{
	//If either of the strings beinf compared are empty
	if(op1.empty() || op2.name.empty())
	{
		missing_data error;
		throw error; //Throw missing data error
	}

	return op1 > op2.name;
}



//less than operator
bool operator > (const food & op1, const string & op2)
{
	//If either of the strings beinf compared are empty
	if(op1.name.empty() || op2.empty())
	{
		missing_data error;
		throw error; //Throw missing data error
	}

	return op1.name > op2;
}




//greater than or equal to operator
bool operator >= (const food & op1, const food & op2)
{
	//If either of the strings beinf compared are empty
	if(op1.name.empty() || op2.name.empty())
	{
		missing_data error;
		throw error; //Throw missing data error
	}

	return op1.name >= op2.name;
}



//less than operator
bool operator >= (const string & op1, const food & op2)
{
	//If either of the strings beinf compared are empty
	if(op1.empty() || op2.name.empty())
	{
		missing_data error;
		throw error; //Throw missing data error
	}

	return op1 >= op2.name;
}



//less than operator
bool operator >= (const food & op1, const string & op2)
{
	//If either of the strings beinf compared are empty
	if(op1.name.empty() || op2.empty())
	{
		missing_data error;
		throw error; //Throw missing data error
	}

	return op1.name >= op2;
}




//equality operator
bool operator == (const food & op1, const food & op2)
{
	//If either of the strings beinf compared are empty
	if(op1.name.empty() || op2.name.empty())
	{
		missing_data error;
		throw error; //Throw missing data error
	}

	return op1.name == op2.name;
}



//less than operator
bool operator == (const string & op1, const food & op2)
{
	//If either of the strings beinf compared are empty
	if(op1.empty() || op2.name.empty())
	{
		missing_data error;
		throw error; //Throw missing data error
	}

	return op1 == op2.name;
}



//less than operator
bool operator == (const food & op1, const string & op2)
{
	//If either of the strings beinf compared are empty
	if(op1.name.empty() || op2.empty())
	{
		missing_data error;
		throw error; //Throw missing data error
	}

	return op1.name == op2;
}


//inequality operator
bool operator != (const food & op1, const food & op2)
{
	//If either of the strings beinf compared are empty
	if(op1.name.empty() || op2.name.empty())
	{
		missing_data error;
		throw error; //Throw missing data error
	}

	return op1.name != op2.name;
}



//less than operator
bool operator != (const string & op1, const food & op2)
{
	//If either of the strings beinf compared are empty
	if(op1.empty() || op2.name.empty())
	{
		missing_data error;
		throw error; //Throw missing data error
	}

	return op1 != op2.name;
}



//less than operator
bool operator != (const food & op1, const string & op2)
{
	//If either of the strings beinf compared are empty
	if(op1.name.empty() || op2.empty())
	{
		missing_data error;
		throw error; //Throw missing data error
	}

	return op1.name != op2;
}




// compares order frequency
int food::cmp_frequency(const food & obj) const
{
	//If either of the frequencies have not been set with user data
	if(obj.frequency == -1 || frequency == -1)
	{
		missing_data error;
		throw error;
	}

	if(obj.frequency < frequency) return 1;

	return 0;
}



//sets class data members with user input
void food::input_details(void)
{
	//If name or frequency have already been set with custom data
	if(!name.empty() || frequency != -1)
	{
		//throw over write error
		over_write error;
		throw error;
	}

	//clear input stream
	cin.clear();
	cin.ignore(100, '\n');
	cout << "\nEnter food name: ";
	getline(cin, name);
	cout << "Enter how often the food needs to be ordered in days as an integer: ";
	cin >> frequency;

	return;
}









