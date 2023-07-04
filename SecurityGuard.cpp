#include "SecurityGuard.h"

const string SecurityGuard::getWeapon() const
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
	return os << "Security guard " << (Crew&)sec << "Weapon = " << sec.weapon << endl;
}
