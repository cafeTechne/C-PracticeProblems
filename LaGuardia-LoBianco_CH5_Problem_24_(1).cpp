// LaGuardia-LoBianco_CH5_Problem_24_(1).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream> //needed for cerr()
#include <fstream> //needed for ifstream


using namespace std;


//Gino LaGuardia-LoBianco, CH5, Problem 24.
//This program calculates the percent of batches of sutures rejected due to temperature, the percent rejected due to pressure, and the percent rejected due to dwell time
//base on input from a sensor file. Some batches are rejected for multiple reasons and so will be counted as such.

//accep. range temp 150-170 degrees C
//"           " pressure 60-70 psi
//Dwell time 2-2.5s



int main()
{

	ifstream sutureInput("suture.txt");
	double batchNumber(0.0), temperature(0.0), pressure(0.0), dwellTime(0.0);
	double temperatureRejectCount(0), pressureRejectCount(0), dwellTimeRejectCount(0), totalCount(0), batchCount(0);


	sutureInput >> batchNumber >> temperature >> pressure >> dwellTime;

	cout << "This program calculates the percent of batches of sutures \n rejected due to temperature, the percent rejected due to pressure,\n and the percent rejected due to dwell time based on input from a sensor file. \n Some batches are rejected for multiple reasons \n and so will be counted as such. \n" << endl;

	while (!sutureInput.eof())
	{
	

		sutureInput >> batchNumber >> temperature >> pressure >> dwellTime;
		++batchCount;

		if (temperature<150 || temperature>170)
			++temperatureRejectCount;

		if (pressure<60 || pressure>70)
			++pressureRejectCount;

		if (dwellTime<2.0 || dwellTime>2.5)
			++dwellTimeRejectCount;
	}

	cout << "The percent rejected due to temperature is " << ((temperatureRejectCount/batchCount)*100) << " percent." << endl << endl;
	cout << "The percent rejected due to pressure is " << ((pressureRejectCount / batchCount) * 100) << " percent." << endl << endl;
	cout << "The percent rejected due to dwell time is " << ((dwellTimeRejectCount) / (batchCount) * 100) << " percent." << endl << endl;

    return 0;
}





