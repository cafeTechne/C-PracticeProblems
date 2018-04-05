#pragma once
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
	int getMonth() { return month; }
	int getDay() { return day; }
	int getYear() { return year; }

	//Date();		//constructor

	void setMonth(int m)
	{
			month = m;	
	};
	
	void setDay(int d)
	{
			day = d;
	};
	
	void setYear(int y)
	{
			year = y;
	
	};




};
