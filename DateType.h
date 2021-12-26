/*
Cameron Berg, 5440507, berg2318
10 December, 2021
Homework 8
Description: This is the header rile for the DateType class. It declares
	all of the prototypes for the member functions and overloaded
	operators. (Part of this file was provided for us)
Input: None
Return Value(s): None
*/

#include <iostream>
using namespace std;
#ifndef DATETYPE_H
#define DATETYPE_H
class DateType {
public:
	DateType(int month = 1, int day = 1, int year = 1900) {
		this->month = month;
		this->day = day;
		this->year = year;
	}
	void setDate(int month, int day, int year);
	int getDay() const { return day; }
	int getMonth() const { return month; }
	int getYear() const { return year; }
	int daysInMonth();
	void setDay(int day);
	void setMonth(int month);
	void setMonth(string month);
	void setYear(int year);
	void print(ostream &out) const;
	bool isLeapYear();
	int daysPassedInYear() const;
	int daysRemainingInYear() const;
	DateType calculateNewDate(int days);
	
private:
	int month;
	int day;
	int year;

};

ostream& operator<<(ostream& out, const DateType &date);



#endif
