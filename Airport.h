#pragma once
#pragma warning (disable : 4996)
#include <iostream>
using namespace std;
#include <string.h>

class Airport
{
private:
	char* IATA;
	char* countryName;

public:
	// Getters & Setters
	const char* getIATA() const;
	bool setIATA(char* IATACode);

	const char* getCountryName() const;
	bool setCountryName(char* countryName);

	// Constructors & Destructors
	Airport(const char* newIATA, const char* county)
	{
		this->IATA = new char[strlen(newIATA) + 1];
		this->countryName = new char[strlen(county) + 1];

		strcpy(this->IATA, newIATA);
		strcpy(this->countryName, county);
	};
	
	~Airport()
	{
		delete[]IATA;
		delete[]countryName;
	};

	friend ostream& operator<<(ostream& os, const Airport& airport);

};