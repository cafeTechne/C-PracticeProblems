// CW_2_CSC_215_LaGuardia_LoBianco.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string> //to use strings
#include <iostream> //for input/output

using namespace std;

const int setSize = 5;

int main()
{

	string name;
	int *agePtr = nullptr;
	double *salaryPtr = nullptr;
	int set[setSize] = { 10, 30, 54, 76, 8 };

	int age = 0;
	double salary = 0;

	agePtr = &age;
	salaryPtr = &salary;

	cout << "User, what is your name?" << endl;
	cin >> name;
	cout << "User, what is your age?" << endl;
	cin >> *agePtr;
	cout << "User, what is your salary?" << endl;
	cin >> *salaryPtr;

	cout << "Your age is " << *agePtr << endl;
	cout << "Your name is " << name << endl;
	cout << "Your salary is " << *salaryPtr << endl;

	if (*agePtr <= 60)
	{
		cout << "You have " << 60 - *agePtr << " years until retirement." << endl;
	}
	else
	{
		cout << "You retired " << *agePtr - 60 << " years ago." << endl;
	}

	return 0;
}

