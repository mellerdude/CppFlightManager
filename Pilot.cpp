#include "Pilot.h"

int Pilot::GetLicenseNumber() const
{
	return licenseNumber;
}

bool Pilot::setLicenseNumber(int number)
{
	if (number >= 10000 || number < 0)
		return false;
	licenseNumber = number;
	return true;
}

ostream& operator<<(ostream& os, const Pilot& p)
{
	return os << "Pilot " << (Crew&)p;
}
