/*
Cameron Berg, 5440507, berg2318
10 December, 2021
Homework 8
Description: This is the main ExtDateType file that contains all of the
	member function and overloaded operator definitions.
Input: None
Return Value(s): None (ExtDateType.cpp has no main() function)
*/

#include <iostream>
#include <string>
#include <cctype>
#include "ExtDateType.h"

using namespace std;

/*-------------------ExtDateType-----------------------
Purpose/Description: This is the construtor for the ExtDateType class.
Required Pre-Conditions: An ExtDateType object has been declared
	with correct parameters (if parameters are included). It
	uses the DateType constructor via inheritance.
Output: Error if invalid month parameter.
Return Value(s): None
-----------------------------------------------------*/
ExtDateType::ExtDateType(int month, int day, int year) : DateType(month,day,year)
{
	switch (month)
	{
		case 1:
			monthString = "January";
			break;
		case 2:
			monthString = "February";
			break;
		case 3:
			monthString = "March";
			break;
		case 4:
			monthString = "April";
			break;
		case 5:
			monthString = "May";
			break;
		case 6:
			monthString = "June";
			break;
		case 7:
			monthString = "July";
			break;
		case 8:
			monthString = "August";
			break;
		case 9:
			monthString = "September";
			break;
		case 10:
			monthString = "October";
			break;
		case 11:
			monthString = "November";
			break;
		case 12:
			monthString = "December";
			break;
		default:
			cerr << "why are you like this\n";
			exit(420);
	}
}

/*-------------------getMonthString-----------------------
Purpose/Description: This gets the month of a DateType object.
Required Pre-Conditions: An ExtDateType object has been declared.
Output: None
Return Value(s): monthString (string, the month)
--------------------------------------------------------*/
string ExtDateType::getMonthString()
{
	return monthString;
}

/*-------------------setMonthString-----------------------
Purpose/Description: This sets the monthString of a DateType object.
Required Pre-Conditions: An ExtDateType object has been declared,
	valid input is used.
Output: Error if invalid input.
Return Value(s): None
--------------------------------------------------------*/
void ExtDateType::setMonthString(string month)
{
	for (int i = 0; i < month.length(); i++)
	{
		month[i] = toupper(month[i]);
	}
	
	if (month == "")
	{
		monthString = "";
	}
	else if (month == "JANUARY")
	{
		monthString = "January";
	}
	else if (month == "FEBRUARY")
	{
		monthString = "February";
	}
	else if (month == "MARCH")
	{
		monthString = "March";
	}
	else if (month == "APRIL")
	{
		monthString = "April";
	}
	else if (month == "MAY")
	{
		monthString = "May";
	}
	else if (month == "JUNE")
	{
		monthString = "June";
	}
	else if (month == "JULY")
	{
		monthString = "July";
	}
	else if (month == "AUGUST")
	{
		monthString = "August";
	}
	else if (month == "SEPTEMBER")
	{
		monthString = "September";
	}
	else if (month == "OCTOBER")
	{
		monthString = "October";
	}
	else if (month == "NOVEMBER")
	{
		monthString = "November";
	}
	else if (month == "DECEMBER")
	{
		monthString = "December";
	}
	else
	{
		cerr << "Error in setMonthString()\n";
		exit(421);
	}
}

/*-------------------print1-----------------------
Purpose/Description: This outputs a full date to the desired output
	location.
Required Pre-Conditions: An ExtDateType object has been declared.
Output: MMM-DD-YYYY
Return Value(s): None
------------------------------------------------*/
void ExtDateType::print1(ostream &out)//Dec-01-2021
{
	string substring = getMonthString().substr(0,3);
	
	out << substring << "-";
	
	if (getDay() < 10)
	{
		out << "0";
	}
	
	out << getDay() << "-" << getYear();
}

/*-------------------print2-----------------------
Purpose/Description: This outputs a full date to the desired output
	location.
Required Pre-Conditions: An ExtDateType object has been declared.
Output: Month Day, Year
Return Value(s): None
------------------------------------------------*/
void ExtDateType::print2(ostream &out)//December 1, 2021
{
	out << getMonthString() << " " << getDay() << ", "
		<< getYear();
}

/*-------------------print3-----------------------
Purpose/Description: This outputs a full date to the desired output
	location.
Required Pre-Conditions: An ExtDateType object has been declared.
Output: DD-MMM-YYYY
Return Value(s): None
------------------------------------------------*/
void ExtDateType::print3(ostream &out)//01-Dec-2021
{
	string substring = getMonthString().substr(0,3);
	
	if (getDay() < 10)
	{
		out << "0";
	}
	
	out << getDay() << "-" << substring << "-" << getYear();
}

/*------------------operator<<-----------------------
Purpose/Description: This is the overloaded << operator for
	the ExtDateType class.
Required Pre-Conditions: An ExtDateType object has been declared.
Output: MMM-DD-YYYY
Return Value(s): out (ostream &, reference to output location)
---------------------------------------------------*/
ostream& operator<<(ostream &out, ExtDateType &date)
{
	date.print1(out);
	return out;
}


