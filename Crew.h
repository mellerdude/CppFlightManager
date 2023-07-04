#pragma once
#pragma warning (disable : 4996)
#include <iostream>
using namespace std;
#include <stdio.h>
#include <string>

class Crew
{
protected:

	int employeeID;
	string name;

	// Constructors & Destructors
	Crew(const int eid, const string newName) // constructor in 'protected' to make the class abstract
	{
		this->employeeID = eid;
		this->name = newName;
	
	}

public:
	// Getters & Setters
	int getEmployeeID() const;
	bool setemployeeID(int eID);

	const string getName() const;
	bool setName(const string n);

	// Constructors & Destructors
	virtual ~Crew()
	{
			
	}

	friend ostream& operator<<(ostream& os, const Crew& crew);
};