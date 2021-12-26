/*
Cameron Berg, 5440507, berg2318
10 December, 2021
Homework 8
Description: This is the driver file that contains main().
	It tests the functions/operators in the class.
Input: None
Return Value(s): None
*/

#include <iostream>
#include "DateType.h"
#include "ExtDateType.h"

using namespace std;

int main()
{
	DateType date1(1,28,2000), date2;
	
	cout << "-------------Testing Display Method-------------\n\n";
	
	cout << "date1: " << date1 << endl
		 << "date2: " << date2 << endl << endl;
	
	cout << "-------------Testing Get/Set Methods-------------\n\n";
	
	cout << "date1 Month: " << date1.getMonth() << endl;
	cout << "date1 Day: " << date1.getDay() << endl;
	cout << "date1 Year: " << date1.getYear() << endl;
	
	date1.setDay(12);
	date1.setMonth(3);
	date1.setYear(1852);
	date2.setDate(4, 20, 1337);
	
	cout << "After setting new dates, date1 is " << date1
		 << " and date2 is " << date2 << endl << endl;
		 
	cout << "-------------Testing isLeapYear Method-------------\n\n";
	
	date1.setYear(2015);
	
	if (date1.isLeapYear())
	{
		cout << date1.getYear() << " is a leap year.\n";
	}
	else
	{
		cout << date1.getYear() << " is not a leap year.\n";
	}
	
	date1.setYear(1980);
	
	if (date1.isLeapYear())
	{
		cout << date1.getYear() << " is a leap year.\n";
	}
	else
	{
		cout << date1.getYear() << " is not a leap year.\n";
	}
	
	date1.setYear(2000);
	
	if (date1.isLeapYear())
	{
		cout << date1.getYear() << " is a leap year.\n";
	}
	else
	{
		cout << date1.getYear() << " is not a leap year.\n";
	}
	
	date1.setYear(1900);
	
	if (date1.isLeapYear())
	{
		cout << date1.getYear() << " is a leap year.\n";
	}
	else
	{
		cout << date1.getYear() << " is not a leap year.\n";
	}
	
	cout << endl;
	
	cout << "-------------Testing daysInMonth Method-------------\n\n";
	
	date1.setYear(2000);
	date1.setMonth(2);
	date2.setYear(2015);
	date2.setMonth(2);
	
	cout << "February has " << date1.daysInMonth()
		 << " days on a leap year.\n";
	cout << "February has " << date2.daysInMonth()
		 << " days on a non-leap year.\n";
		 
	date1.setMonth(1);
	date2.setMonth(4);
	
	cout << "January has " << date1.daysInMonth() << " days.\n";
	cout << "April has " << date2.daysInMonth() << " days.\n";
	
	cout << endl;
	
	cout << "-----------Testing daysPassedInYear Method-----------\n\n";
	
	date1.setDate(2,1,2022);
	
	cout << "If the date is " << date1 << ", then "
		 << date1.daysPassedInYear() << " days have gone by.\n";
		 
	date2.setDate(1,1,2000);
	
	cout << "If the date is " << date2 << ", then "
		 << date2.daysPassedInYear() << " days have gone by.\n";
		 
	date2.setDate(12,31,2015);
	
	cout << "If the date is " << date2 << ", then "
		 << date2.daysPassedInYear() << " days have gone by.\n";
	
	date1.setDate(3,1,2015);
	date2.setDate(3,1,2000);
	
	cout << "If the date is " << date1 << ", then "
		 << date1.daysPassedInYear() << " days have gone by.\n";
	cout << "If the date is " << date2 << ", then "
		 << date2.daysPassedInYear() << " days have gone by.\n";
		 
	cout << endl;
	
	cout << "---------Testing daysRemainingInYear Method---------\n\n";
	
	date1.setDate(1,1,2015);
	date2.setDate(1,1,2000);
	
	cout << "If the date is " << date1 << ", then there are "
		 <<	date1.daysRemainingInYear() << " days left in the year.\n";
	cout << "If the date is " << date2 << ", then there are "
		 <<	date2.daysRemainingInYear() << " days left in the year.\n";
	
	date1.setDate(12,31,2015);
	
	cout << "If the date is " << date1 << ", then there are "
		 <<	date1.daysRemainingInYear() << " days left in the year.\n";
		 
	date1.setDate(12,1,2015);
	
	cout << "If the date is " << date1 << ", then there are "
		 <<	date1.daysRemainingInYear() << " days left in the year.\n";
		 
	date1.setDate(5,26,2015);
	
	cout << "If the date is " << date1 << ", then there are "
		 <<	date1.daysRemainingInYear() << " days left in the year.\n";
		 
	cout << endl;
	
	cout << "----------Testing calculateNewDate Method----------\n\n";
	
	date1.setDate(1,1,2015);
	date2.setDate(1,1,2000);
	
	DateType date3 = date1.calculateNewDate(365);
	
	cout << "Adding 365 days to " << date1 << " gives us " << date3
		 << endl;
	
	date3 = date2.calculateNewDate(365);
	
	cout << "Adding 365 days to " << date2 << " gives us " << date3
		 << endl;
	
	date3 = date1.calculateNewDate(243);
	
	cout << "Adding 243 days to " << date1 << " gives us " << date3
		 << endl;
	
	date1.setDate(12,3,2021);
	
	date3 = date1.calculateNewDate(100);
	
	cout << "Adding 100 days to " << date1 << " gives us " << date3
		 << endl;
	
	cout << endl;
	
	cout << "----------Testing constructor/print----------\n\n";
	
	ExtDateType date4(2,14,2008), date5;
	
	cout << "date4: " << date4 << endl;
	cout << "date5: " << date5 << endl << endl;
	
	date4.print1(cout);
	cout << endl;
	date5.print2(cout);
	cout << endl;
	date5.print3(cout);
	cout << endl << endl;
	
	cout << "----------Testing get/setMonthString----------\n\n";
	
	cout << "date4 Month: " << date4.getMonthString() << endl;
	
	date5.setMonthString("ApRiL");
	
	cout << "date5 New Month: " << date5.getMonthString()
		 << endl << endl;
		 
	cout << "----------Testing Complete----------\n\n";
	
	return 0;
}
