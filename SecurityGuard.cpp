#include "SecurityGuard.h"

char* SecurityGuard::getWeapon()
{
	return weapon;
}

bool SecurityGuard::setWeapon(char* newWeapon)
{
	delete[] weapon;
	weapon = new char[strlen(newWeapon) + 1];
	if (weapon == nullptr)
		return false;
	strcpy(weapon, newWeapon);
	return true;
}

ostream& operator<<(ostream& os, const SecurityGuard& sec)
{
	return os << "Security guard " << (Crew&)sec;
}
