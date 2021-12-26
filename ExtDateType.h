/*
Cameron Berg, 5440507, berg2318
10 December, 2021
Homework 8
Description: This is the header rile for the ExtDateType class. It declares
	all of the prototypes for the member functions and overloaded
	operators. It inherits from DateType.
Input: None
Return Value(s): None
*/

#include <iostream>
#include <string>
#include "DateType.h"

using namespace std;

#ifndef EXTDATETYPE_H
#define EXTDATETYPE_H

class ExtDateType:public DateType
{
	public:
		ExtDateType(int month = 1, int day = 1, int year = 1900);
		string getMonthString();
		void setMonthString(string);
		void print1(ostream &);
		void print2(ostream &);
		void print3(ostream &);//Putting const on these gives errors.
	private:
		string monthString;
};

ostream& operator<<(ostream &, ExtDateType &);

#endif


