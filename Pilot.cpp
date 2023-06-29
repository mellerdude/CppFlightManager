#include "Pilot.h"

int Pilot::GetLicenseNumber()
{
	return licenseNumber;
}

bool Pilot::setLicenseNumber(int number)
{
	if (number > 100000 || number < 0)
		return false;
	licenseNumber = number;
	return true;
}
