#include "Airport.h"

const std::string& Airport::getIATA() const
{
	return IATA;
}

bool Airport::setIATA(const std::string& IATACode)
{
	IATA = IATACode;
	return true;
}

const std::string& Airport::getCountryName() const
{
	return countryName;
}

bool Airport::setCountryName(const std::string& cName)
{
	countryName = cName;
	return true;
}

std::ostream& operator<<(std::ostream& os, const Airport& airport)
{
	return os << "Country: " << airport.countryName << " IATA: " << airport.IATA;
}
