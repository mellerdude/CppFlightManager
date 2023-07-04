#include "Airport.h"

const string& Airport::getIATA() const
{
	return IATA;
}

bool Airport::setIATA(const string& IATACode)
{
	IATA = IATACode;
	return true;
}

const string& Airport::getCountryName() const
{
	return countryName;
}

bool Airport::setCountryName(const string& cName)
{
	countryName = cName;
	return true;
}

std::ostream& operator<<(std::ostream& os, const Airport& airport)
{
	return os << "Country: " << airport.countryName << " IATA: " << airport.IATA;
}
