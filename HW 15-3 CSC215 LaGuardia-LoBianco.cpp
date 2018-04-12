// HW 15-3 CSC215 LaGuardia-LoBianco.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>

using namespace std;

static int encryptionKey=0;

class fileFilterBase 
{

public:
	fileFilterBase() {}
	char virtual transform(char ch) = 0 {}
};

class fileFilterDerivedEncryption : public fileFilterBase
{
protected:
	//int encryptionKey;
	char encryptedCharacter;
	char character;
	//char *charPtr = nullptr;
	//char *charPtr = &character;

public:
	fileFilterDerivedEncryption() { encryptionKey = 0; }
	fileFilterDerivedEncryption(int n) { encryptionKey = n; }

	int getEncryptionKey() { return encryptionKey; }
	void setEncryptionKey(int n) { encryptionKey = n; }

void doFilter(ifstream &in, ofstream &out)
{
	in.clear();
	in.seekg(0, ios::beg); //set reader to beginning of input file
	while (!in.eof()) 
	{
		//in >> character;
		in.get(character);
		fileFilterDerivedEncryption::transform(character);
		//out << character;
		out.put(encryptedCharacter);
	}
}

	char virtual transform(char ch)
	{
		encryptedCharacter = ch + encryptionKey;
		return encryptedCharacter;
	}

};

class blargh : public fileFilterDerivedEncryption
{
	char virtual transform(char ch) override final
	{
		encryptedCharacter = ch + encryptionKey;
		return encryptedCharacter;
	}

};

class toUpperCase : public fileFilterDerivedEncryption
{
protected:
	char c;
	
public:
	toUpperCase() { c = 'c'; };
		void upperCaseMethod(ifstream &in, ofstream &out)
		{
			in.clear();
			in.seekg(0, ios::beg); //set reader to beginning of input file
			while (!in.eof())
			{
				in.get(c);
				//in >> c;
				if (c >= 'a' && c <= 'z') c -= 32;
				//upper = toupper(c);
				out.put(c);
			} 
	}
};


class copyFile : public fileFilterBase 
{
public: 	
	copyFile() {};
	void copyFileMethod(ifstream &in, ofstream &out, char c)
	{
		while (!in.eof())
		{
			in.get(c);
			out.put(c);
		}
	}
};


int main()
{
	char c = 'c';
	int n;

	ifstream input;
	ofstream output;
	

	input.open("raw.txt", c);
	if (!input)
	{
		cout << "file open failure!" << endl;
		exit(-1);
	}	

	output.open("copiedText.txt");
	copyFile* f = nullptr;
	f->copyFileMethod(input, output, c);
	output.close();

	output.open("upperCaseText.txt");
	toUpperCase* t = new toUpperCase;
	t->upperCaseMethod(input, output);
	output.close();

	cout << "User, enter a random integer!" << endl;
	cin >> n;

	output.open("encryptedText.txt");
	fileFilterDerivedEncryption * g = new fileFilterDerivedEncryption;
	g->setEncryptionKey(n);
	g->doFilter(input, output);
	output.close();

	input.close(); //close file after finished with it


		return 0;
}

