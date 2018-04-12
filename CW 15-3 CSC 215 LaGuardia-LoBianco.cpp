// CW 15-3 CSC215 LaGuardia-LoBianco.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class BasicShape
{
protected:
	double area;
public:
	BasicShape() { area = 0;}
	~BasicShape() {}
	
	BasicShape(double a) { area = a; }

	double getArea()
	{
		return area;
	}
	void setArea(double &a)
	{
		area = a;
	}
	double virtual calcArea(double radius) =0 {};
};

class Circle : public BasicShape
{
protected:
	
	double radius = 0;
	double centerX = 0;
	double centerY = 0;		// x & y coordinates for the circle's center
							// not used in this problem.
public:
	
	Circle() { radius = 0;  double centerX = 0; double centerY = 0;}
	
	Circle(double r) { radius = r; double centerX = 0; double centerY = 0;}

	void virtual setRadius(double r)
	{
		radius = r;
	}
	double getRadius()
	{
		return radius;
	}
	double getCenterX()
	{
		return centerX;
	}
	double getCenterY()
	{
		return centerY;
	}
	double virtual calcArea (double radius) final
	{
		area = (3.14*(radius * radius));
		return area;
	}
};


int main()
{
	double r = 0;
	double r1 = 0;
	int size;

	//can't dynamically allocate an abstract class
	cout << "User, how many circles would you like to create?" << endl;
	cin >> size;
		
	BasicShape ** arr = new BasicShape *[size];

	Circle *c = new Circle(5);
	
	
	cout << "User, we are going to enter " << size << " circles!" << endl;

	for (int i = 0; i < size; i++)
	{
		cout << "User, what is the radius of this circle?" << endl;
		cin >> r;
		Circle *c = new Circle(r);
		c->calcArea(r);
		arr[i] = c;
		cout << endl;
	}

	for (int i = 0; i < size; i++)
	{
		cout << endl << "Area of this circle is : " << arr[i]->getArea();
	}
	

	return 0;
}