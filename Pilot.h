#pragma once
#pragma warning (disable : 4996)
#include "Crew.h"
#include <string>

class Pilot :
	public Crew
{
private:
	int licenseNumber;

public:
	// Getters & Setters
	int GetLicenseNumber();
	bool setLicenseNumber(int number);

	// Constructors & Destructors
	Pilot(const int eid, const string newName, const int licenseNum) : Crew(eid, newName)
	{
		this->licenseNumber = licenseNum;
	}

	friend ostream& operator<<(ostream& os, const Pilot& p);
};