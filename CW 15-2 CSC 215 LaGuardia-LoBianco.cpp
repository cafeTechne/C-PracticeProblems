// CW 15-2 CSC 215 LaGuardia-LoBianco.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class Polygon 
{
protected:
	int numberOfSides;
	bool regularPolygonTruthValue;
	//reg polys have all sides the same length and all angles the same

public:
	Polygon() { numberOfSides = 3; regularPolygonTruthValue = false; }
	Polygon(int n, bool b) { numberOfSides = n; regularPolygonTruthValue = b; }
	~Polygon() {}


	//setter
	void setNumberofSides(int n) { numberOfSides = n;}
	void setRegularPolygonTruthValue(bool b) { regularPolygonTruthValue = b; }
	
	//getter
	int getNumberofSides() { return numberOfSides; }
	bool getPolygonTruthValue (){ return regularPolygonTruthValue; }
	
	void virtual Print(const Polygon &c)
	{
		cout << "Polygon " << endl;
		cout << "Number of Sides: " << c.numberOfSides << endl;
		cout << "Regular: " << c.regularPolygonTruthValue << endl;
	}

};

class Triangle : public Polygon
{
protected: 
	double lengthOfSide1;
	double lengthOfSide2;
	double lengthOfSide3;
	double angleOfSide1;
	double angleOfSide2;
	double angleOfSide3;
	bool regularPolygonTruthValue = false;

public:
	Triangle(double l1, double l2, double l3, double a1, double a2, double a3) 
	{
		lengthOfSide1 = l1;
		lengthOfSide2 = l2;
		lengthOfSide3 = l3;
		angleOfSide1 = a1;
		angleOfSide2 = a2;
		angleOfSide3 = a3;
	}
	Triangle() {}
	~Triangle() {}

	void setTriangle(double l1, double l2, double l3, double a1, double a2, double a3)
	{
		lengthOfSide1 = l1;
		lengthOfSide2 = l2;
		lengthOfSide3 = l3;
		angleOfSide1 = a1;
		angleOfSide2 = a2;
		angleOfSide3 = a3;
		
	}
	
	double getTriangle()
	{
		return lengthOfSide1;
		return lengthOfSide2;
		return lengthOfSide3;
		return angleOfSide1;
		return angleOfSide2;
		return angleOfSide3;
	}

	void virtual Print(const Triangle &c)
	{
		cout << "Triangle " << endl;
		cout << "Number of Sides: " << c.numberOfSides << endl;
		cout << "Interior Angle 1: " << c.angleOfSide1 << endl;
		cout << "Interior Angle 2: " << c.angleOfSide2 << endl;
		cout << "Interior Angle 3: " << c.angleOfSide3 << endl;
		cout << "Length of Side 1: " << c.lengthOfSide1 << endl;
		cout << "Length of Side 2: " << c.lengthOfSide2 << endl;
		cout << "Length of Side 3: " << c.lengthOfSide3 << endl;
		cout << "Regular: " << c.regularPolygonTruthValue << endl;
	}
};

class EquiTriangle : public Triangle
{

protected:
	double lengthOfSide1;
	double lengthOfSide2;
	double lengthOfSide3;
	double angleOfSide1;
	double angleOfSide2;
	double angleOfSide3;
	bool regularPolygonTruthValue = true;

public:
	
	EquiTriangle() {
		lengthOfSide1 = 1; lengthOfSide2 = 1; lengthOfSide3 = 1; angleOfSide1 = 60; angleOfSide2 = 60; angleOfSide3 = 60; regularPolygonTruthValue = true;
	};
	~EquiTriangle() {};

	EquiTriangle(const double l1)
	{
		lengthOfSide1 = l1;
		lengthOfSide2 = l1;
		lengthOfSide3 = l1;
		angleOfSide1 = 60;
		angleOfSide2 = 60;
		angleOfSide3 = 60;
		regularPolygonTruthValue = true;
	}

	void virtual Print(const EquiTriangle &c)
	{
		cout << "Equilateral Triangle " << endl;
		cout << "Number of Sides: " << c.numberOfSides << endl;
		cout << "Interior Angle 1: " << c.angleOfSide1 << endl;
		cout << "Interior Angle 2: " << c.angleOfSide2 << endl;
		cout << "Interior Angle 3: " << c.angleOfSide3 << endl;
		cout << "Length of Side 1: " << c.lengthOfSide1 << endl;
		cout << "Length of Side 2: " << c.lengthOfSide2 << endl;
		cout << "Length of Side 3: " << c.lengthOfSide3 << endl;

		cout << "Regular: " << c.regularPolygonTruthValue << endl;
	}
};

int main()
{
	// Polygon* polyPtr = nullptr;
	// Polygon* polyPtr = new Polygon(1, false);

	Polygon** base = new Polygon*[6];

	Polygon * polyPtr = nullptr;

	//Polygon p1;
	//Polygon p2;

	//Triangle t1;
	//Triangle t2;

	//EquiTriangle e1;
	//EquiTriangle e2;


	Triangle *t1 = new Triangle(30.0, 60.0, 90.0, 30.0, 60.0, 90.0);
	Triangle *t2 = new Triangle(30.0, 60.0, 90.0, 30.0, 60.0, 90.0);
	
	EquiTriangle *e1 = new EquiTriangle;
	EquiTriangle *e2 = new EquiTriangle;
	
	Polygon * p1 = new Polygon;
	Polygon * p2 = new Polygon;

	base[0] = t1;
	base[1] = t2;
	base[2] = e1;
	base[3] = e2;
	base[4] = p1;
	base[5] = p2;

	p1->Print(*p2);
	p2->Print(*p2);
	e1->Print(*e1);
	e2->Print(*e2);
	t1->Print(*t1);
	t2->Print(*t2);

    return 0;
}

