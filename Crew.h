#pragma once
#pragma warning (disable : 4996)
#include <ostream>
using namespace std;

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
	int getEmployeeID() const;
	bool setEmployeeID(int eID);

	const char* getName() const;
	bool setName(const char* n);

	// Constructors & Destructors
	virtual ~Crew()
	{
		delete[] name;
	}

	friend std::ostream& operator<<(std::ostream& os, const Crew& crew);
};
