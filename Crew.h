#pragma once
#pragma warning (disable : 4996)
#include <iostream>
using namespace std;
#include <stdio.h>
#include <string.h>

class Crew
{
protected:

	int employeeID;
	std::string name;

	// Constructors & Destructors
	Crew(const int eid, const string newName) // constructor in 'protected' to make the class abstract
	{
		this->employeeID = eid;
		this->name = newName;
	
	}

public:
	// Getters & Setters
	int getEmployeeID();
	bool setemployeeID(int eID);

	string getName();
	bool setName(string n);

	// Constructors & Destructors
	virtual ~Crew()
	{
			
	}

	friend ostream& operator<<(ostream& os, const Crew& crew);
};