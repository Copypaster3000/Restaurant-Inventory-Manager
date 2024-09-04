//canned.h
//Drake Wheeler
//Program 3
//CS302
//Karla Fant
//7/30/2024
//This is the header file for the canned clas.

#ifndef CANNED_H
#define CANNED_H

#include "food.h"

class canned : public food
{
	public:
		canned(); //Constructor
		~canned(); //Destructor
				   
		void input_details(void); //sets class data members w/ user input. Throws over_write error if any data is over written
		void display(void) const; //Display's food details to user, throws missing data error if any data members are empty
		int update_frequency(void); //Update the frequencey the food needs to be reordered at with user input, returns 1 for success, 0 for invalid user input



	private:
		string expiration; //Date the canned food expires
		int temp; //The tempurature the food needs to be stored at
};


#endif // CANNED_H
