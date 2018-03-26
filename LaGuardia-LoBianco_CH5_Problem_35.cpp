
//Gino LaGuardia-LoBianco, CH5, Problem 35
// This program reads critical-path information from a file and prints a project completion timetable that lists each event number, 
// maximum number of days for a task within an event, and calculates the total number of days for the completion of a project based on the critical path analysis methodology.


#include "stdafx.h"
#include <iostream>
#include <fstream>


using namespace std;

int main()
{
	double event = 0, task = 0, numberOfDays1 = 0, numberOfDays2 = 0, MaxDaysForTaskInEvent = 0, TotalProjectTime = 0, event1DaysTotal = 0, event2DaysTotal = 0, event3DaysTotal = 0, event4DaysTotal = 0, event5DaysTotal = 0;

	ifstream fileInput("criticalPathData.txt");

		 																	//checks to make sure the file loads properly, if not, it exits the program and logs an error
	if (fileInput.fail())
	{
		cerr << "File error!" << endl;
		exit(-1);
	}
	while (!fileInput.eof())													//the outside while loop runs the loop until it is at the end of the file
	{
		fileInput >> event >> task >> numberOfDays1;
		while (event == 1)														//takes input, checks value against other value, stores the highest
		{
			if (numberOfDays1 > numberOfDays2)
			{
				numberOfDays2 = numberOfDays1;
 				event1DaysTotal = numberOfDays2;
				fileInput >> event >> task >> numberOfDays1;
			}
			if (event == 2)
			{
				numberOfDays2 = 0;
				break;
			}
			if (numberOfDays2 >= numberOfDays1)
				fileInput >> event >> task >> numberOfDays1;
			if (event == 2)
			{ 
				numberOfDays2 = 0;
				break;
			}
			continue;
		}
		while (event == 2)													//different while loop for each event state
		{
			if (numberOfDays1 > numberOfDays2)
			{
				numberOfDays2 = numberOfDays1;
				event2DaysTotal = numberOfDays2;
				fileInput >> event >> task >> numberOfDays1;
			}
			if (event == 3)
			{
				numberOfDays2 = 0;
				break;
			}
			if (numberOfDays2 >= numberOfDays1)
				fileInput >> event >> task >> numberOfDays1;
			if (event == 3)
			{
				numberOfDays2 = 0;
				break;
			}
			continue;
		}
		while (event == 3)
		{
			if (numberOfDays1 > numberOfDays2)
			{
				numberOfDays2 = numberOfDays1;
				event3DaysTotal = numberOfDays2;
				fileInput >> event >> task >> numberOfDays1;
			}
			if (event == 4)
			{
				numberOfDays2 = 0;
				break;
			}
			if (numberOfDays2 >= numberOfDays1)
				fileInput >> event >> task >> numberOfDays1;
			if (event == 4)
			{ 
				numberOfDays2 = 0;
				break;
			}
			continue;
		}
		while (event == 4)
		{
			if (numberOfDays1 > numberOfDays2)
			{
				numberOfDays2 = numberOfDays1;
				event4DaysTotal = numberOfDays2;
				fileInput >> event >> task >> numberOfDays1;
			}
			if (event == 5)
			{
				numberOfDays2 = 0;
				break;
			}
			if (numberOfDays2 >= numberOfDays1)
				fileInput >> event >> task >> numberOfDays1;
			if (event == 5)
			{
				numberOfDays2 = 0;
				break;
			}
			continue;
		}
		while (event == 5)
		{
			if (numberOfDays1 > numberOfDays2)
			{
				numberOfDays2 = numberOfDays1;
				event5DaysTotal = numberOfDays2;
				fileInput >> event >> task >> numberOfDays1;
			}
			if (!(event == 5))
			{
				numberOfDays2 = 0;
				break;
			}
			if (numberOfDays2 >= numberOfDays1)
			{
				fileInput >> event >> task >> numberOfDays1;	
			}
			if (!(event == 5))
			{
				numberOfDays2 = 0;
				break;
			}
			if (fileInput.eof())
				break;
			numberOfDays2 = 0;

		}
	}

	//output informing the user of the results!
	cout << "The total project completion time is " << event1DaysTotal + event2DaysTotal + event3DaysTotal + event4DaysTotal + event5DaysTotal << " days." << endl;

	cout << endl << "The longest running task for Event 1 will take " << event1DaysTotal << " days." << endl;
	cout << endl << "The longest running task for Event 2 will take " << event2DaysTotal << " days." << endl;
	cout << endl << "The longest running task for Event 3 will take " << event3DaysTotal << " days." << endl;
	cout << endl << "The longest running task for Event 4 will take " << event4DaysTotal << " days." << endl;
	cout << endl << "The longest running task for Event 5 will take " << event5DaysTotal << " days." << endl;

return 0;
}


		

