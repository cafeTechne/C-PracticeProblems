// CW 13-2 CSC 215 LaGuardia-LoBianco.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Date.h"
#include <ctime>

using namespace std;


//inline functions!
//create a date.h file for

void printDate(Date &date) {
	cout << date.getDay() << "/" << date.getMonth() << "/" << date.getYear() << endl;
}

int main()
{
	//use the accessor functions to print the contents of the Date object
	Date date;
	Date *datePointer = nullptr;
	datePointer = new Date;
	int d, m, y;
	int a, b, c;


	time_t t = time(0);
	struct tm * now = localtime(&t);
	//cout << (now->tm_mon + 1) << '/' << (now->tm_mday) << '/' << (now->tm_year + 1900);


	a = (now->tm_mon + 1);
	b = (now->tm_mday);
	c = (now->tm_year + 1900);


	date.setDay(a);
	date.setMonth(b);
	date.setYear(c);


	//sets its members using the mutator functions
	/*datePointer->setDay(a);
	datePointer->setMonth(b);
	datePointer->setYear((c));
	*/

	cout << date.getMonth() << '/' << date.getDay() << '/' << date.getYear() << endl;

	//prints the date using printDate
	printDate(date);

	delete datePointer;
	datePointer = nullptr;

	return 0;
}

