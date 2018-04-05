// CW 13-1 CSC215 LaGuardia-LoBianco.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;


class Date {

private:
	int month;
	int day;
	int year;
	//setter and getter for each of the 3 ints stored
	//use const when appropriate

public:
	int getMonth() const { return month; }
	int getDay() const { return day; }
	int getYear() const { return year; }

	//Date();		//constructor

	void setMonth(int m)
	{
		if ((m <= 12 || m >= 1))
		{
			month = m;
		}
		else
		{
			cout << "Invalid Month!" << endl;
			exit(EXIT_FAILURE);
		}
	};
	void setDay(int d)
	{
		if ((d <= 31 && d >= 1))
		{
			day = d;
		}
		else
		{
			cout << "Invalid Day!" << endl;
			exit(EXIT_FAILURE);
		}
	};
	void setYear(int y)
	{
		if ((y < 2100 && y > 1900))
		{
			year = y;
		}
		else
		{
			cout << "Invalid Year!" << endl;
			exit(EXIT_FAILURE);
		}
	};




};

void printDate(Date &date) {
	cout << date.getDay() << "/" << date.getMonth() << "/" << date.getYear() << endl;
}


int main()
{
	int d, m, y;
	Date date;

	//sets its members using the mutator functions
	cout << " user enter a day value (1-31) " << endl;
	cin >> d;
	date.setDay(d);

	cout << " user enter a month value (1-12) " << endl;
	cin >> m;
	date.setMonth(m);

	cout << " user enter a recent year value " << endl;
	cin >> y;
	date.setYear(y);

	//prints the date using printDate
	printDate(date);

	//int test;
	//cout << "this is a test" << endl;
	//cin >> test;

    return 0;
}

