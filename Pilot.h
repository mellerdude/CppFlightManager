#pragma once
#pragma warning (disable : 4996)
#include "Crew.h"

class Pilot :
	public Crew
{
private:
	int licenseNumber;

public:
	// Getters & Setters
	int GetLicenseNumber() const;
	bool setLicenseNumber(int number);

	// Constructors & Destructors
	Pilot(const int eid, const char* newName, const int licenseNum) : Crew(eid, newName)
	{
		this->licenseNumber = licenseNum;
	}

	friend ostream& operator<<(ostream& os, const Pilot& p);
};