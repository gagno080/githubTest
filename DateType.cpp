/*
Cameron Berg, 5440507, berg2318
10 December, 2021
Homework 8
Description: This is the main DateType file that contains all of the
	member function and overloaded operator definitions.
Input: None
Return Value(s): None (DateType.cpp has no main() function)
*/
//Tester Comment Git
#include <iostream>
#include <string>
#include "DateType.h"
using namespace std;

/*-------------------setDate-----------------------
Purpose/Description: This sets the date of a DateType object.
Required Pre-Conditions: A DateType object has been declared,
	valid input is used.
Output: None
Return Value(s): None
-------------------------------------------------*/
void DateType::setDate(int month, int day, int year) {
	this->month = month;
	this->day = day;
	this->year = year;
}

/*-------------------setDay-----------------------
Purpose/Description: This sets the day of a DateType object.
Required Pre-Conditions: A DateType object has been declared.
Output: Notification if invalid input is used.
Return Value(s): None
------------------------------------------------*/
void DateType::setDay(int day)//Add check to change day based on month's day limit?
{
	if (day > 31 || day < 1)
	{
		cerr << "Invalid day inputted. Setting to 1.\n";
		this->day = 1;
	}
	else
	{
		this->day = day;
	}
}

/*-------------------setMonth-----------------------
Purpose/Description: This sets the month of a DateType object.
Required Pre-Conditions: A DateType object has been declared,
	valid input is used.
Output: None
Return Value(s): None
--------------------------------------------------*/
void DateType::setMonth(int month)
{
	if (month > 12 || month < 1)
	{
		this->month = -1;//Invalid month.
	}
	else
	{
		this->month = month;
	}
}

/*-------------------setMonth-----------------------
Purpose/Description: This sets the month of a DateType object.
Required Pre-Conditions: A DateType object has been declared,
	valid input is used.
Output: Error if invalid input.
Return Value(s): None
--------------------------------------------------*/
void DateType::setMonth(string month)
{
	for (int i = 0; i < month.length(); i++)
	{
		month[i] = toupper(month[i]);
	}
	
	if (month == "")
	{
		this->month = -1;
	}
	if (month == "JANUARY")
	{
		this->month = 1;
	}
	else if (month == "FEBRUARY")
	{
		this->month = 2;
	}
	else if (month == "MARCH")
	{
		this->month = 3;
	}
	else if (month == "APRIL")
	{
		this->month = 4;
	}
	else if (month == "MAY")
	{
		this->month = 5;
	}
	else if (month == "JUNE")
	{
		this->month = 6;
	}
	else if (month == "JULY")
	{
		this->month = 7;
	}
	else if (month == "AUGUST")
	{
		this->month = 8;
	}
	else if (month == "SEPTEMBER")
	{
		this->month = 9;
	}
	else if (month == "OCTOBER")
	{
		this->month = 10;
	}
	else if (month == "NOVEMBER")
	{
		this->month = 11;
	}
	else if (month == "DECEMBER")
	{
		this->month = 12;
	}
	else
	{
		cerr << "Error in setMonth(string)\n";
		exit(421);
	}
}

/*-------------------setYear-----------------------
Purpose/Description: This sets the year of a DateType object.
Required Pre-Conditions: A DateType object has been declared,
	valid input is used.
Output: Notification if invalid input.
Return Value(s): None
-------------------------------------------------*/
void DateType::setYear(int year)
{
	if (year < 1)
	{
		cerr << "Invalid year inputted. Setting to 0001.\n";
		this->year = 1;
	}
	else
	{
		this->year = year;
	}
}

/*-------------------daysInMonth-----------------------
Purpose/Description: This returns the number of days in a
	particular month.
Required Pre-Conditions: A DateType object has been declared,
	valid input is used.
Output: Error if somehow the function fails.
Return Value(s): Number of days in the month (int)
-----------------------------------------------------*/
int DateType::daysInMonth()//const here gives that error again...
{
	switch(month)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			return 31;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			return 30;
			break;
		case 2:
			return isLeapYear() ? 29 : 28;
			break;
		default:
			cerr << "Error has occured in daysInMonth method.\n";
			exit(27);
	}
}

/*-------------------print-----------------------
Purpose/Description: This outputs a full date to the desired output
	location.
Required Pre-Conditions: A DateType object has been declared.
Output: Month / Day / Year
Return Value(s): None
-----------------------------------------------*/
void DateType::print(ostream& out) const {

	out << this->month << " / "
		<< this->day << " / "
		<< this->year;
}

/*-------------------isLeapYear-----------------------
Purpose/Description: This indicates whether or not the year
	in a DateType object is a leap year.
Required Pre-Conditions: A DateType object has been declared.
Output: None
Return Value(s): true/false if is/is not a leap year.
----------------------------------------------------*/
bool DateType::isLeapYear()
{
	if (year % 4 == 0)//Leap year: Divisible by 4...
	{
		if (year % 100 == 0)//...unless it is a century...
		{
			if (year % 400 != 0)///...that is not divisible by 400.
			{
				return false;
			}
		}
		return true;
	}
	return false;
}

/*-------------------daysPassedInYear-----------------------
Purpose/Description: This calculates how many days have gone
	by in the year so far, as indicated by the date.
Required Pre-Conditions: A DateType object has been declared.
Output: None
Return Value(s): total (int, number of days passed)
----------------------------------------------------------*/
int DateType::daysPassedInYear() const
{
	int total = 0;
	DateType tempDate(1,1,year);
	
	for (int m = 1; m <= month; m++)
	{
		tempDate.setMonth(m);
		
		if (m == month)//Must add only some days in the month.
		{
			total += (getDay() - tempDate.getDay());
		}
		else
		{
			total += tempDate.daysInMonth();
		}
	}
	
	return total;
}

/*-------------------daysRemainingInYear-----------------------
Purpose/Description: This calculates how many days are left
	in the year, as indicated by the date.
Required Pre-Conditions: A DateType object has been declared.
Output: None
Return Value(s): total (int, number of days left)
-------------------------------------------------------------*/
int DateType::daysRemainingInYear() const
{
	int total = 0;
	DateType tempDate(day,month,year);
	
	for (int m = month; m <= 12; m++)
	{
		tempDate.setMonth(m);
		
		if (m == month)
		{
			total += (31 - day + 1);
		}
		else
		{
			total += tempDate.daysInMonth();
		}
	}
	
	return total;
}

/*-------------------calculateNewDate-----------------------
Purpose/Description: This calculates a new date that is (days) days
	past the current indicated date. It returns a new object with the
	new date.
Required Pre-Conditions: A DateType object has been declared,
	days is positive.
Output: None
Return Value(s): newDate (DateType, the new date)
----------------------------------------------------------*/
DateType DateType::calculateNewDate(int days)
{
	DateType newDate(month,day,year);
	
	for (int d = 1; d <= days; d++)//Add the days one-by-one.
	{
		//Change month and year as necessary.
		if (newDate.getDay() + 1 > newDate.daysInMonth())
		{
			if (newDate.getMonth() + 1 > 12)
			{
				newDate.setYear(newDate.getYear() + 1);
				newDate.setMonth(1);
			}
			else
			{
				newDate.setMonth(newDate.getMonth() + 1);
			}
			
			newDate.setDay(1);
		}
		else
		{
			newDate.setDay(newDate.getDay() + 1);
		}
	}
	
	return newDate;
}

//****************************************************************
// Non-member functions are defined below
//****************************************************************

/*------------------operator<<-----------------------
Purpose/Description: This is the overloaded << operator for
	the DateType class.
Required Pre-Conditions: A DateType object has been declared.
Output: Month / Day / Year
Return Value(s): out (ostream &, reference to output location)
---------------------------------------------------*/
ostream& operator<<(ostream& out, const DateType& date) {
	date.print(out);
	return out;
}

