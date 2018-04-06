// HW 13-3 CSC215 LaGuardia-LoBianco.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class TemperatureStorer
{

private:
	double const EthylFreezingPoint = -173;
	double const OxygenFreezingPoint = -362;
	double const WaterFreezingPoint = 32;

	double const EthylBoilingPoint = 172;
	double const OxygenBoilingPoint = -306;
	double const WaterBoilingPoint = 212;
	double temperature = 0;

public:

	//default constructor
	TemperatureStorer() {}
	
	//setter
	void setTemperature(double temp)
	{
		temperature = temp;
	}


	//getter
	double getTemperature() {
		return temperature;
	}
	
	

bool isEthylFreezing(double temp)
{
	bool ethylFreezing = true;
	if (!(temp < EthylFreezingPoint)) { ethylFreezing = false; }
	else
	{
		ethylFreezing = true;
	}
	//if freeze or below, then return true, otherwise return false
	return ethylFreezing;
}
bool isEthylBoiling(double temp)
{
	bool ethylBoiling = true;
	if (!(temp > EthylBoilingPoint)) { ethylBoiling = false; }
	else
	{
		ethylBoiling = true;
	}

	//if freeze or below, then return true, otherwise return false
	return ethylBoiling;
}
bool isOxygenFreezing(double temp)
{
	bool oxygenFreezing = true;
	//if freeze or below, then return true, otherwise return false

	if (!(temp < OxygenFreezingPoint)) { oxygenFreezing = false; }
	else
	{
		oxygenFreezing = true;
	}


	return oxygenFreezing;
}
bool isOxygenBoiling(double temp)
{
	bool oxygenBoiling = true;
	//if freeze or below, then return true, otherwise return false

	if (!(temp > OxygenBoilingPoint)) { oxygenBoiling = false; }
	else
	{
		oxygenBoiling = true;
	}

	return oxygenBoiling;
}
bool isWaterFreezing(double temp)
{
	bool waterFreezing = true;
	//if freeze or below, then return true, otherwise return false

	if (!(temp < WaterFreezingPoint)) { waterFreezing = false; }
	else
	{
		waterFreezing = true;
	}


	return waterFreezing;
}
bool isWaterBoiling(double temp)
{
	bool waterBoiling = true;
	//if freeze or below, then return true, otherwise return false
	if (!(temp > WaterBoilingPoint)) { waterBoiling = false; }
	else
	{
		waterBoiling = true;
	}

	return waterBoiling;
}
};



int main()
{
	double temp;

	cout << "User, enter a temperature: " << endl;
	cin >> temp;

	cout << " Here are all the substances that freeze or boil at that temperature!: " << endl;

	//if -20 then program should report that water will freeze and oxygen will boil at that temperature

	TemperatureStorer t;
	t.setTemperature(temp);

	if (t.isEthylFreezing(temp)) { cout << "Ethyl Alcohol will Freeze" << endl; }
	
	if (t.isEthylBoiling(temp)) { cout << "Ethyl Alcohol will Boil" << endl; }
	
	if (t.isOxygenFreezing(temp)) { cout << "Oxygen will Freeze" << endl; }
	
	if (t.isOxygenBoiling(temp)) { cout << "Oxygen will Boil" << endl; }
	
	if (t.isWaterFreezing(temp)) { cout << "Water will Freeze" << endl; }
	
	if (t.isWaterBoiling(temp)) { cout << "Water will Boil"; }


    return 0;
}

