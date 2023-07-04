#include "Crew.h"
int Crew::getEmployeeID() const
{
	return employeeID;
}

bool Crew::setemployeeID(int eID)
{
	if(eID >= 10000 || eID < 0)
		return false;
	return true;
}

const string Crew::getName() const
{
	return name;
}

bool Crew::setName(string n)
{
	name = n;
	return true;
}

ostream& operator<<(ostream& os, const Crew& crew)
{
	if (&crew == nullptr)
		return os << "No Crew member";
	return os << "Crew member\n" << "Name: " << crew.getName() << " ID: " << crew.getEmployeeID() << endl;
}

