// HW Chapter 11 prob12 CSC 215 LaGuardia-LoBianco.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

struct Student {
	string Name;
	int Idnum;
	double* Tests;
	double Average;
	char Grade;
};



int main()
{
	string name;
	int numberOftestScores, numberOfStudents;
	int idNumber = 0;
	int const SIZE = 150;
	Student arr[SIZE];
	double  arr1[SIZE];

	cout << "User how many test scores are there to be ?" << endl;
	cin >> numberOftestScores;
	cout << "User how many students are there to be ?" << endl;
	cin >> numberOfStudents;

	new Student[numberOfStudents];

	
	for (int i = 0; i < numberOfStudents; i++)
	{
		cout << "User, what is your name?" << endl;
		cin >> name;
		arr[i].Name = name;

		cout << "User, what is the student's ID number?" << endl;
		cin >> idNumber;
		arr[i].Idnum = idNumber;

		cout << "User, how many tests do you have to enter?" << endl;
		cin >> numberOftestScores;
		new double[numberOftestScores];
		
		double runningSum=0;
		for (int k = 0; k < numberOftestScores; k++)
		{
			cout << "User, enter a grade: " << endl;
			cin >> arr1[k];
			runningSum = arr1[k] + runningSum;
		}
		arr[i].Average = (runningSum / numberOftestScores);

		if (arr[i].Average >= 91 && arr[i].Average <= 100) arr[i].Grade = 'A';
		if (arr[i].Average >= 81 && arr[i].Average <= 90) arr[i].Grade = 'B';
		if (arr[i].Average >= 71 && arr[i].Average <= 80) arr[i].Grade = 'C';
		if (arr[i].Average >= 61 && arr[i].Average <= 70) arr[i].Grade = 'D';
		if (arr[i].Average >= 51 && arr[i].Average <= 60) arr[i].Grade = 'F';

	}
	
	cout << "************************************************************" << endl;
	cout << "-NAME-------ID NUMBER----------TEST AVERAGE----COURSE GRADE-" << endl;
	cout << "************************************************************" << endl;
	
	for (int i = 0; i < numberOfStudents; i++)
	{
		cout << arr[i].Name << "      " << arr[i].Idnum << "        " << arr[i].Average << "        " << arr[i].Grade << endl;
	}

	int dummy;
	cout << "test" << endl; // dummy variable for testing
	cin >> dummy;
	
    return 0;
}

