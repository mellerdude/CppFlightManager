#include "SecurityGuard.h"

string SecurityGuard::getWeapon()
{
	return weapon;
}

bool SecurityGuard::setWeapon(string newWeapon)
{
	weapon, newWeapon;
	return true;
}

ostream& operator<<(ostream& os, const SecurityGuard& sec)
{
	return os << "Security guard " << (Crew&)sec;
}
