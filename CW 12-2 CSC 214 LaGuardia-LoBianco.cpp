// CW 12-2 CSC 214 LaGuardia-LoBianco.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;

//submit in blackboard along with a screenshot of the output

void convert(double &input)
{
	double k = 0, j=0;
	double dummyVariable;

	j = k;
		while (k >= 0 && k <= 200)
		{
			
		cout << k << '\t' << '\t';
		cout << ((k + 459.67)*(5.0 / 9.0)) << '\t' << '\t' << endl;
		k++;
		k = k+input;
		}

	cout << "User, don't you love this chart?!";
	cin >> dummyVariable;
}

int main()
{
	double input;
	double k = 0;

	cout << " User, I will generate a chart of conversions from F to K for you." << endl;
	cout << " User, enter an increment for the chart: " << endl;
	cin >> input;
	
	convert(input);

	return 0;
}

