// LaGuardia-LoBianco_CH7_Problem_16.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;


/********************************************/
/* Gino LaGuardia-LoBianco, CH7, Problem 16	*/
/* This program reads the wind-tunnel test data, given in tunnel.txt, and then*/
/* allows the user to enter a flight path angle. if the angle is within the bounds of the data set, the*/
/* program then uses linear interpolation to compute the corresponding coefficient of lift.
   This program adds to Problem 14 in that i wrote a user defined function to check to make sure the flight path data was in ascending order!
*/


int ordered(vector<double> &v); //define function prototype


#include "stdafx.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;


/********************************************/
/* Gino LaGuardia-LoBianco, CH7, Problem 14	*/
/* This program reads the wind-tunnel test data, given in tunnel.txt and formatted as two columns, and then*/
/* allows the user to enter a flight path angle. If the angle is within the bounds of the data set, the*/
/* program then uses linear interpolation to compute the corresponding coefficient of lift.*/

int ordered(vector<double> &v); //function prototype

int main()
{
	ifstream fin;
	vector<double> flightPathAngle(17);
	vector<double> coefficientOfLift(17);
	double userlnput;
	static bool flag = true;

	int num = 0;
	fin.open("tunnel.txt");
	if (fin.fail())
	{
		cout << "error" << endl;
		return 1;
	}
	while (!fin.eof()) //error checks for end of file while pushing input from 2 columns into 2 vectors
	{
		fin >> flightPathAngle[num];
		fin >> coefficientOfLift[num];

		++num;
	}
	fin.close();

	auto fpOrdered = ordered(flightPathAngle);  //my function returns a flag bool to indicate the status of the list
	

	if (flag = true) //checks against the flag return by the function
	{
		cout << "Checked to see if the lists were in ascending order--all's well!" << endl << fpOrdered << endl;
	}
	if (flag = false) 
	{
		cout << "Checked to see if the lists were in ascending order--Houston--we have a problem!!" << endl << fpOrdered << endl;
	}

	cout << "What is the flight-path angle?" << endl;
	cin >> userlnput;

	//This function loops in order to continuosly check new values (and debug the code as you write it!) after checking to ensure that the user
	//input is within the domain of the data set given in the file. The user can enter -99 to terminate the program.
	while (userlnput != -99)
	{
		if (userlnput < flightPathAngle[0] || userlnput > flightPathAngle[flightPathAngle.size() - 1])
		{
			cout << "Your inputed flight-path angle is not within the established bounds of the data set!" << endl;
		}
		else
		{

			/*If you want the iterator before the iterator returned by lower_bound,
			you can subtract 1 (for a random access iterator), decrement (for a bidirectional iterator),
			or do a linear search instead of using lower_bound (for a forward iterator that is none of those).
			https://stackoverflow.com/questions/12158948/lower-bound-upper-bound
			*/
			cout << "flight path angle maximum is " << flightPathAngle[flightPathAngle.size() - 1] << endl;    //size()-1 is the last member in a non-empty vector!  https://stackoverflow.com/questions/24930517/does-stdvector-size-1-always-give-the-index-of-the-last-element 
			cout << "flight path angle minimum is " << flightPathAngle[0] << endl;							 //returns the first element, note: the data was presorted.
			auto low = lower_bound(flightPathAngle.begin(), flightPathAngle.end(), userlnput);	// low is set equal to the value of the number above 5 in the ordered set
			auto up = upper_bound(flightPathAngle.begin(), flightPathAngle.end(), userlnput);   // up
			int lowIndex = int(low - flightPathAngle.begin()) - 1; //see above link for detailed explanation from someone who knows way more than me!
			int upIndex = int(up - flightPathAngle.begin());
			double lowX = flightPathAngle[lowIndex];
			double lowY = coefficientOfLift[lowIndex];
			double upX = flightPathAngle[upIndex];
			double upY = coefficientOfLift[upIndex];
			double interpolation = lowY + ((userlnput - lowX) / (upX - lowX)) * (upY - lowY); //interpolation formula
			cout << "LowX " << flightPathAngle[lowIndex] << " LowY " << coefficientOfLift[lowIndex] << endl;
			cout << "UpX " << flightPathAngle[upIndex] << " UpY " << coefficientOfLift[upIndex] << endl;
			cout << "Interpolated Value: " << interpolation << endl;
		}

		cout << endl << "Enter flight-path angle to perform another calculation or -99 to exit." << endl;
		cin >> userlnput;
	}

	return 0;
}

int ordered(vector<double> &v)
{
	double a = 0.0, b = 0.0;
	static bool flag=true;

	for (auto i = 0; i < (v.size())-1; ++i)
	{
		a = v[i];
		b = v[i + 1];
		if (a <= b)
		{
			flag = true;
			continue;
		}
		else
		{
			if (!(a <= b) &&!(b == (v.size()-1)))
			{
				cout << endl << "This list is not sorted in ascending order!!" << endl;
				flag = false;
			}
		}		
	}
	return flag;
}

