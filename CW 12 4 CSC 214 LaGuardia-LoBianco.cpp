// CW 12 4 CSC 214 LaGuardia-LoBianco.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct studentData {
	int ssn;
	double amountDue;
	string name;
};

void writeStudentData(studentData *strPtr, fstream &file);

	int main()
{
		int ssn, numOfStu;
		double amountDue;
		string name;
		studentData s1;

		cout << "User, how many students do you want to enter? " << endl;
		cin >> numOfStu;

		fstream output;
		output.open("text.txt", ios::out | ios::binary);

		studentData* strPtr;
		strPtr = &s1;


		for (int i = 0; i < numOfStu; i++)
		{
			cout << " what is your ssn?" << endl;
			cin >> s1.ssn;
			cout << " how much do you owe?" << endl;
			cin >> s1.amountDue;
			cout << " what is your name?" << endl;
			cin >> s1.name;
			writeStudentData(strPtr, output);
		}
		
    return 0;
}

	void writeStudentData(studentData *strPtr, fstream &output)
	{

		studentData s1;
		s1 = *strPtr;
		output.write(reinterpret_cast<char*>(&s1), sizeof(s1));

	}
