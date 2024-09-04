//fish.h
//Drake Wheeler
//Program 3
//CS302
//Karla Fant
//7/30/2024
//This is the header file for the fish class, it is derived from the food class.

#ifndef FISH_H
#define FISH_H

#include "food.h"

class fish : public food
{
	public:
		fish(); //constructor
		~fish(); //destructor

		void input_details(void); //sets class data members w/ user input. Throws over_write error if any data is over written
		void display(void) const; //Display's food details to user, throws missing data error is data is missing
		int update_frequency(void); //Update the frequencey the food needs to be reordered at with user input, returns 1 for success, 0 for invalid user input


	private:
		string origin; //Where the fish is from
		string water_type; //Fresh or salt water fish
		int fat; //Fat content of the fish in percentage
};



#endif // FISH_H
