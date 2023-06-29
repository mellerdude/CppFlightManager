#pragma once
#pragma warning (disable : 4996)

#include <string.h>

class Airport
{
private:
	char* IATA;
	char* countryName;

public:
	// Getters & Setters
	char* getIATA();
	bool setIATA(char* IATACode);

	char* getCountryName();
	bool setCountryName(char* countryName);

	// Constructors & Destructors
	Airport(const char* newIATA, const char* county)
	{
		this->IATA = new char[strlen(newIATA) + 1];
		this->countryName = new char[strlen(county) + 1];

		strcpy(this->IATA, newIATA);
		strcpy(this->countryName, county);
	}

	~Airport()
	{
		delete[]IATA;
		delete[]countryName;
	}
};