// CW 14 CSC215 LaGuardia-LoBianco.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

//friend void Date::addHolidayDate(int const day, int const month, int const year);

class Date 
{
private:
	int day;
	int month;
	int year;

public:

	//default constructor
	Date() { day = 0; month = 0; year = 0; };
	
	//overloaded constructor
	Date(int iDay, int iMonth, int iYear) { day = iDay; month = iMonth; year = iYear; };


	void printDate() 
	{
		cout << day << endl;
		cout << month << endl;
		cout << year << endl;
	}
	//do not add any get/set methods
};


class Calendar
{
private:
	static int holidayCount;
	Date * holidayDates = new Date[10];
	// holidayDates[0] = 1;

public:
	static void addHolidayCount()
	{
		holidayCount++;
	}

	static int getHolidayCount()
	{
		return holidayCount;
	}

	void addHolidayDate(int day, int month, int year)
	{
		holidayDates[holidayCount] = Date();
		holidayCount++;
	}

	/* //can't get this working, out of time.
	void printHolidays()
	{
		cout << "holidays:" << endl;

		for (int i = 0; i < holidayCount; i++)
		{
			cout << holidayDates[i] << endl;
		}
	}
	*/
};



int Calendar::holidayCount = 0;


int main()
{
	Calendar calendar;
	calendar.addHolidayDate(1, 1, 2017);
	calendar.addHolidayDate(4, 7, 2017);
	calendar.addHolidayDate(23, 11, 2017);

	cout << calendar.getHolidayCount();

	return 0;
}

