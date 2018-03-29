// HW Chapter 11 problem 4 LaGuardia-LoBianco.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

//write a program that uses a structure to store the following weather data for a particular month:
// total rainfall, high temperature, low temperature, average temperature

//The program should have an array of 12 structures to hold weather data for an entire year.

//when the program runs, it should ask the user to enter data for each month
//the average temperature should be calculated

//Once the data are entered for all the months, the program should calculate and display

//the average monthly rainfall, the total rainfall for the year,

//the highest and lowest temperatures for the year (and the months they occured in),
//and the average of all the monthly average temperatures

//input validation: only accept temperatures within the range between -100 and +140


using namespace std;

struct Weather {
	double rainfall;
	double highTemp;
	double lowTemp;
	double AvgTemp;
};
int main()
{
	double rainfall, highTemp, lowTemp, AvgTemp, sumOfTemperatures=0.0;
	Weather january, february, march, april, may, june, july, august, september, october, november, december;
	double arr[12];
	double arr1[12];

	for (int i=0; i<12; i++)
	{
	cout << "User, please tell me the rainfall for month " << i+1 << endl;
	cin >> rainfall;
	arr[i] = rainfall;
	}

	january.rainfall = arr[0];
	february.rainfall = arr[1];
	march.rainfall = arr[2];
	april.rainfall = arr[3];
	may.rainfall = arr[4];
	june.rainfall = arr[5];
	july.rainfall = arr[6];
	august.rainfall = arr[7];
	september.rainfall = arr[8];
	october.rainfall = arr[9];
	november.rainfall = arr[10];
	december.rainfall = arr[11];
	
	double highestTemp = 0;
	for (int i = 0; i<12; i++)
	{
		cout << "User, please tell me the highTemp for month " << i+1 << endl;
		cin >> highTemp;
		if ((highTemp < (-100.0)) || (highTemp > +140.0))
		{
			cout << "Please enter a temperature between -100 and 400" << endl;
			cin >> highTemp;
			if ((highTemp < (-100.0)) || (highTemp > +140.0))
			{
				cout << "come onnnnnn!" << endl;
				return -1;
			}
		}
		if (highTemp > highestTemp) highTemp = highestTemp;
		arr[i] = highTemp;
		sumOfTemperatures = (arr[i] + sumOfTemperatures);
		
	}


	january.highTemp = arr[0];
	february.highTemp = arr[1];
	march.highTemp = arr[2];
	april.highTemp = arr[3];
	may.highTemp = arr[4];
	june.highTemp = arr[5];
	july.highTemp = arr[6];
	august.highTemp = arr[7];
	september.highTemp = arr[8];
	october.highTemp = arr[9];
	november.highTemp = arr[10];
	december.highTemp = arr[11];

	double lowestTemp=0.0;
	for (int i = 0; i<12; i++)
	{
		cout << "User, please tell me the lowTemp for month " << i+1 << endl;
		cin >> lowTemp;
		if ((lowTemp < (-100.0)) || (lowTemp > +140.0))
		{
			cout << "Please enter a temperature between" << endl;
			cin >> lowTemp;
			if ((lowTemp < (-100.0)) || (lowTemp > +140.0))
			{
				cout << "come onnnnnn!" << endl;
				return -1;
			}

		}
		
		if (lowTemp < lowestTemp) lowTemp = lowestTemp;
		arr1[i] = lowTemp;
		sumOfTemperatures = (arr[i] + sumOfTemperatures);
	}

	january.lowTemp = arr1[0];
	february.lowTemp = arr1[1];
	march.lowTemp = arr1[2];
	april.lowTemp = arr1[3];
	may.lowTemp = arr1[4];
	june.lowTemp = arr1[5];
	july.lowTemp = arr1[6];
	august.lowTemp = arr1[7];
	september.lowTemp = arr1[8];
	october.lowTemp = arr1[9];
	november.lowTemp = arr1[10];
	december.lowTemp = arr1[11];


	january.AvgTemp = (arr1[0]+arr[0]);
	february.AvgTemp = (arr1[1] + arr[1]);
	march.AvgTemp = (arr1[2] + arr[2]);
	april.AvgTemp = (arr1[3] + arr[3]);
	may.AvgTemp = (arr1[4] + arr[4]);
	june.AvgTemp = (arr1[5] + arr[5]);
	july.AvgTemp = (arr1[6] + arr[6]);
	august.AvgTemp = (arr1[7] + arr[7]);
	september.AvgTemp = (arr1[8] + arr[8]);
	october.AvgTemp = (arr1[9] + arr[9]);
	november.AvgTemp = (arr1[10] + arr[10]);
	december.AvgTemp = (arr1[11] + arr[11]);


	//Once the data are entered for all the months, the program should calculate and display

	double rainTotal;

	rainTotal = (january.rainfall + february.rainfall + march.rainfall + april.rainfall + may.rainfall +june.rainfall +july.rainfall + august.rainfall + september.rainfall + october.rainfall + november.rainfall + december.rainfall);
	
	cout << "Annual total rainfall is : " << (rainTotal) << endl;
	cout << "Average montly rainfall is : " << (rainTotal / 12) << endl;
	cout << "Highest Temperature this year was " << highestTemp << endl;
	cout << "Lowest Temperature this year was " << lowestTemp << endl;
	

	rainTotal = (january.rainfall + february.rainfall + march.rainfall + april.rainfall + may.rainfall + june.rainfall + july.rainfall + august.rainfall + september.rainfall + october.rainfall + november.rainfall + december.rainfall);


	//the highest and lowest temperatures for the year (and the months they occured in),
	//and the average of all the monthly average temperatures


    return 0;
}

