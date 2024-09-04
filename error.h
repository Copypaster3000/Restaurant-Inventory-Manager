//error.h
//Drake Wheeler
//Program 3
//CS302
//Karla Fant
//7/30/2024
//This is the header file for the error structs.

#include <string>

struct over_write
{
	string detail = "\nWARNING. Some data was over written.";
};


struct missing_data
{
	string detail = "\nERROR. Data that was used for something was missing.";
};
