// CW 15-1 CSC215 LaGuardia-LoBianco.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;


class PersonData
{
protected:
	string firstName;
	string lastName;
	int phoneNumber;

public:

	PersonData()
	{
		firstName = "";
		lastName = "";
	}

	~PersonData(){}

	PersonData(string f, string l, int n)
	{
		firstName = f;
		lastName = l;
		phoneNumber = n;
	}

	PersonData(string f, string l)
	{
		firstName = f;
		lastName = l;
	}

	//setter
	void setPersonData(string f, string l, int n) 
	{
		firstName = f;
		lastName = l;
		phoneNumber = n;
	}
	//getter
	string getPersonData()
	{
		return firstName;
		return lastName;
	}
};


class CustomerData : public PersonData
{
private:
	string city;
	string state;
	int zipCode;

	

public:
	CustomerData() { city = ""; state = ""; zipCode = 0; }

	CustomerData(string c, string s, int z) { city = c; state = s; zipCode = z; }

	void setCity(string c) { city = c; }
	string getCity() { return city; }
	
	void setState(string s) { state = s; }
	string getState() { return state; }

	void setZip(int z) { zipCode = z; }
	int getZip() { return zipCode; }

	void setPhoneNumber(int pn) { phoneNumber = pn; }
	int getPhoneNumber() { return phoneNumber; }
};

void printCustomerData(CustomerData c) 
{
	CustomerData e = c;
	//cout << string
	cout << e.getPersonData() << endl;
	cout << e.getCity() << endl;
	cout << e.getState() << endl;
	cout << e.getZip() << endl;
}

int main()
{
	string c, s, fn, ln;
	CustomerData f;
	CustomerData d;
	int pn, z;

	//user 1 input
	cout << "user, what is your first name?" << endl;
	cin >> fn;

	cout << "user, what is your last name?" << endl;
	cin >> ln;

	cout << "user, what is your phone number?" << endl;
	cin >> pn;
	
	f.setPhoneNumber(pn);
	f.setPersonData(fn, ln, pn);
	
	cout << "user what city do you live in?" << endl;
	cin >> c;
	f.setCity(c);

	cout << "user what state do you live in?" << endl;
	cin >> s;
	f.setState(s);

	cout << "user what is your zip code?" << endl;
	cin >> z;
	f.setZip(z);

	
	//user 2 input
	cout << "user, what is your first name?" << endl;
	cin >> fn;

	cout << "user, what is your last name?" << endl;
	cin >> ln;

	cout << "user, what is your phone number?" << endl;
	cin >> pn;

	d.setPhoneNumber(pn);
	d.setPersonData(fn, ln, pn);

	cout << "user what city do you live in?" << endl;
	cin >> c;
	d.setCity(c);

	cout << "user what state do you live in?" << endl;
	cin >> s;
	d.setState(s);

	cout << "user what is your zip code?" << endl;
	cin >> z;
	d.setZip(z);

	printCustomerData(f);
	printCustomerData(d);

	cout << "test" << endl;
	int test;
	cin >> test;


    return 0;
}

