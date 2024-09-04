//food.h
//Drake Wheeler
//Program 3
//CS302
//Karla Fant
//7/30/2024
//This is the header file for the food class.

#ifndef FOOD_H
#define FOOD_H

#include <string>
using std::string;

class food
{
	public:
		food(); //constructor
		virtual ~food(); //Destructor
						 
    	//Relational operator overloads these functions will be used to help sort the bst
		//They will compare the names of the objects and strings and return the value
		//in terms of being <, >, etc.. alphabetically by the food name
		//All throw missing data error if either of the names are empty
    	friend bool operator<(const food& op1, const food& op2);
    	friend bool operator<=(const food& op1, const food& op2);
    	friend bool operator>(const food& op1, const food& op2);
    	friend bool operator>=(const food& op1, const food& op2);
    	friend bool operator==(const food& op1, const food& op2);
    	friend bool operator!=(const food& op1, const food& op2);
    	friend bool operator<(const string& op1, const food& op2);
    	friend bool operator<=(const string& op1, const food& op2);
    	friend bool operator>(const string& op1, const food& op2);
    	friend bool operator>=(const string& op1, const food& op2);
    	friend bool operator==(const string& op1, const food& op2);
    	friend bool operator!=(const string& op1, const food& op2);
    	friend bool operator<(const food& op1, const string& op2);
    	friend bool operator<=(const food& op1, const string& op2);
    	friend bool operator>(const food& op1, const string& op2);
    	friend bool operator>=(const food& op1, const string& op2);
    	friend bool operator==(const food& op1, const string& op2);
    	friend bool operator!=(const food& op1, const string& op2);

		//returns 1 if object passed in has a frequency less then this object frequency or 0 if it is greater than or equal to
		int cmp_frequency(const food& obj) const; //Throws missing data error if either of the frequencies are still -1
		virtual void input_details(void); //Set's object's details with user input, throws over_write error if something is over_written
		virtual void display(void) const; //Display's food details to user, throws missing data error if data is missing
		virtual int update_frequency(void); //Update the frequency the food needs to be reordered at with user input, returns new frequency


	private:
		string name; //Name of food
		int frequency; //The frequency the food needs to be delivered in days
};


#endif // FOOD_H
