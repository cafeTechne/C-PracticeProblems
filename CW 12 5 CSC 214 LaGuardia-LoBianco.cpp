// CW 12 5 CSC 214 LaGuardia-LoBianco.cpp : Defines the entry point for the console application.
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
	int numOfStu;
	string name;
	studentData s1;

	cout << "User, how many students do you want to enter? " << endl;
	cin >> numOfStu;

	fstream output;
	output.open("text.txt", ios::out |ios::binary);

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
	output.close();

	cout << "User what field would you like to modify? 1 for ssn, 2 for amountDue, 3 for name" << endl;
	int k;
	cin >> k;

	if(k == 1)
	{
		studentData s1;
		cout << "what is your new ssn?" << endl;
		cin >> s1.ssn;
		output.open("text.txt", ios::binary | ios::out);
		output.write(reinterpret_cast<char*>(&s1.ssn), sizeof(s1));
	}
	if(k == 2)
	{
		studentData s1;
		cout << "what is your new amount due?" << endl;
		cin >> s1.ssn;
		output.open("text.txt", ios::binary | ios::out);
		output.write(reinterpret_cast<char*>(&s1.amountDue), sizeof(s1));
	}
	if(k == 3)
	{
		studentData s1;
		cout << "what is your new name?" << endl;
		cin >> s1.ssn;
		output.open("text.txt", ios::binary | ios::out);
		output.write(reinterpret_cast<char*>(&s1.name), sizeof(s1));
	}

	return 0;
}

void writeStudentData(studentData *strPtr, fstream &output)
{

	studentData s1;
	s1 = *strPtr;
	output.write(reinterpret_cast<char*>(&s1), sizeof(s1));

}
