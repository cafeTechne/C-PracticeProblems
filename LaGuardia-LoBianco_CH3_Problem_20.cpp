// LaGuardia-LoBianco_CH3_Problem_20.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

/*Gino LaGuardia-LoBianco, Chapter 3, Problem 20
This program generates a truth table and evaluates if the condition (A && B || B && C) is a contingency.
A logical expression is a contingency IFF atleast one line of it's truth table is true.*/


int main()
{
	//Declare and initialize objects: A, B and C are our atomic sententials.
	//truthValue variables are numbered and they store the boolean result of each line
	bool A(false), B(false), C(false);
	bool truthValue1(false), truthValue2(false), truthValue3(false), truthValue4(false),
		truthValue5(false), truthValue6(false), truthValue7(false), truthValue8(false);


	//Print table header
	cout << "TABLE 3.2\n A\tB\tC\t\tA && B ||B && C"
		<< endl;
	cout << "_________________________________________"
		<< endl;

	cout << A << '\t' << B << '\t' << C << "\t\t\t"
		<< (A && B || B && C) << endl;

	// The if statements evaluate the boolean value of the expression being evaluated and store the result to truthValueN.
	if ((A && B || B && C))
	{
		truthValue1 = true;
	}

	//Toggle C
	C = !C;
	cout << A << '\t' << B << '\t' << C << "\t\t\t"
		<< (A && B || B && C) << endl;

	if ((A && B || B && C))
	{
		truthValue2 = true;
	}

	//Toggle B and C
	B = !B;
	C = !C;
	cout << A << '\t' << B << '\t' << C << "\t\t\t"
		<< (A && B || B && C) << endl;

	if ((A && B || B && C))
	{
		truthValue3 = true;
	}


	//Toggle C
	C = !C;
	cout << A << '\t' << B << '\t' << C << "\t\t\t"
		<< (A && B || B && C) << endl;

	if ((A && B || B && C))
	{
		truthValue4 = true;
	}



	//Toggle A, B and C
	A = !A;
	B = !B;
	C = !C;
	cout << A << '\t' << B << '\t' << C << "\t\t\t"
		<< (A && B || B && C) << endl;

	if ((A && B || B && C))
	{
		truthValue5 = true;
	}



	//Toggle C
	C = !C;
	cout << A << '\t' << B << '\t' << C << "\t\t\t"
		<< (A && B || B && C) << endl;

	if ((A && B || B && C))
	{
		truthValue6 = true;
	}


	//Toggle B & C
	B = !B;
	C = !C;
	cout << A << '\t' << B << '\t' << C << "\t\t\t"
		<< (A && B || B && C) << endl;

	if ((A && B || B && C))
	{
		truthValue7 = true;
	}


	//Toggle C
	C = !C;
	cout << A << '\t' << B << '\t' << C << "\t\t\t"
		<< (A && B || B && C) << endl;
	if ((A && B || B && C))
	{
		truthValue8 = true;
	}

	/*This if statement evaluates the conjunct of all the stored boolean placeholders, if one of them is
	true, then the statement is a contingency, otherwise it is not.*/

	if ((truthValue1 || truthValue2 || truthValue3 || truthValue4 ||
		truthValue5 || truthValue6 || truthValue7 || truthValue8 ))
	{
		cout << "Your statement is a contingency!\n" << endl;
	}
	else
	{
		cout << "Your statement is not a contingency!";
	}


	return 0;
}

