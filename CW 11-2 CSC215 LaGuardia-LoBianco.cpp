// CW 11-2 CSC215 LaGuardia-LoBianco.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct Rectangle {
	int length;
	int width;
};

void displayAreaContent(Rectangle* rectPtr) 
{
	//Rectangle *rectPtr;
	int length1, width1;
	
	length1 = rectPtr->length;
	width1 = rectPtr->width;
	cout << " length is " << length1 << endl;
	cout << " width is " << width1 << endl;

	cout << " area is " << (length1*width1);
}

void gatherContent(Rectangle rectPtr[]) //trying with void sans rectangle
{
	Rectangle rectangle;
	int length2, width2;
	cout << "User what is your length?";
	cin >> length2;
	rectPtr->length = length2;

	cout << "User what is your width?";
	cin >> width2;
	rectPtr->width = width2;
	//return rectangle;
}


int main()
{
	const int SIZE = 180;
	Rectangle arr[SIZE];
	int numOfRectangles;
	cout << "User, how many rectangles would you like to create?" << endl;
	cin >> numOfRectangles;
	new Rectangle[numOfRectangles];
	Rectangle rect;

	for (int i = 0; i < numOfRectangles; i++)
	{
		gatherContent(&arr[i]);
	}

	for (int i = 0; i < numOfRectangles; i++) 
	{
		displayAreaContent(&arr[i]);
	}

    return 0;
}

