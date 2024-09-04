//poultry.h
//Drake Wheeler
//Program 3
//CS302
//Karla Fant
//7/30/2024
//This is the header file for the poultry class.

#ifndef POULTRY_H
#define POULTRY_H

#include "food.h"

class poultry : public food
{
	public:
		poultry(); //constructor
		~poultry(); //destructor

		void input_details(void); //sets class data members w/ user input. Throws over_write error if any data is over written
		void display(void) const; //Display's food details to user, throws missing data error if data members are empty
		int update_frequency(void); //Update the frequencey the food needs to be reordered at with user input, returns 1 for success or 0 for invalid user input
		int update_fresh(void); //Changes fresh_before date from user input, returns 1 for success, 0 for error


	private:
		string cut; //cut type of the meat
		string fresh_before; //fresh before date
};



#endif // POULTRY_H
