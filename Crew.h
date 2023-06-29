#pragma once
#pragma warning (disable : 4996)

#include <stdio.h>
#include <string.h>

class Crew
{
protected:
	int employeeID;
	char* name;

	// Constructors & Destructors
	Crew(const int eid, const char* newName) // constructor in 'protected' to make the class abstract
	{
		this->employeeID = eid;

		this->name = new char[strlen(newName) + 1];
		strcpy(this->name, newName);
	}

public:
	// Getters & Setters
	int getEmployeeID();
	bool setemployeeID(int eID);

	char* getName();
	bool setName(char* n);

	// Constructors & Destructors
	virtual ~Crew()
	{
			delete[] name;
	}
};