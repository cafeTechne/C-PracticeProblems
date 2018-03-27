
#include "stdafx.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

//define function prototypes
double maxVal(vector<double> x, int n);
double minVal(vector<double> x, int n);

/********************************************/
/* Gino LaGuardia-LoBianco, CH7, Problem 14	*/
/* This program reads the wind-tunnel test data, given in tunnel.txt, and then*/
/* allows the user to enter a flight path angle. if the angle is within the bounds of the data set, the*/
/* program then uses linear interpolation to compute the corresponding coefficient of lift.*/

int main()
{
	ifstream fin;
	vector<double> flightPathAngle(17);
	vector<double> coefficientOfLift(17);
	double userlnput;

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

	cout << "What is the flight-path angle?" << endl;
	cin >> userlnput;

	 
	//This function loops in order to continuosly check new values (and debug the code as you write it!) after checking to ensure that the user
	//input is within the domain of the data set given in the file.
	while (userlnput != -99) 
	{
		if (userlnput < flightPathAngle[0] || userlnput > flightPathAngle[flightPathAngle.size() - 1]) 
		{
			cout << "Your inputed flight-path angle is not within the established bounds of the data set!" << endl;
		}
		else 
		{
			cout << "flight path angle maximum is " << flightPathAngle[0] << endl;
			cout << "flight path angle minimum is " << flightPathAngle[flightPathAngle.size() - 1] << endl;
			auto low = lower_bound(flightPathAngle.begin(), flightPathAngle.end(), userlnput);
			auto up = upper_bound(flightPathAngle.begin(), flightPathAngle.end(), userlnput);
			int lowIndex = int(low - flightPathAngle.begin()) - 1;
			int upIndex = int(up - flightPathAngle.begin());
			double lowX = flightPathAngle[lowIndex];
			double lowY = coefficientOfLift[lowIndex];
			double upX = flightPathAngle[upIndex];
			double upY = coefficientOfLift[upIndex];
			double interpolation = lowY + ((userlnput - lowX) / (upX - lowX)) * (upY - lowY);
			cout << "LowX " << flightPathAngle[lowIndex] << " LowY " << coefficientOfLift[lowIndex] << endl;
			cout << "UpX " << flightPathAngle[upIndex] << " UpY " << coefficientOfLift[upIndex] << endl;
			cout << "Interpolated Value: " << interpolation << endl;
		}
		cout << endl << "Enter flight-path angle to perform another calculation or -99 to exit." << endl;
		cin >> userlnput;
	}

	return 0;
}



