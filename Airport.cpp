#include <iostream>
using namespace std;

#include "Airport.h"
char* Airport::getIATA()
{
	return IATA;
}

bool Airport::setIATA(char* IATACode)
{
	delete[] IATA;
	IATA = new char[strlen(IATACode) + 1];
	if (IATA == nullptr)
		return false;
	strcpy(IATA, IATACode);
	return true;
}

char* Airport::getCountryName()
{
	return countryName;
}

bool Airport::setCountryName(char* cName)
{
	delete[] countryName;
	countryName = new char[strlen(cName) + 1];
	if (countryName == nullptr)
		return false;
	strcpy(countryName, cName);
	return true;
}

ostream& operator<<(ostream& os, const Airport& airport)
{
	return os << "Country: " << airport.countryName << " IATA: " << airport.IATA;
};
