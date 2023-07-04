#include "Crew.h"
int Crew::getEmployeeID() const
{
	return employeeID;
}

bool Crew::setEmployeeID(int eID)
{
	if(eID >= 10000 || eID < 0)
		return false;
	return true;
}

const char* Crew::getName() const
{
	return name;
}

bool Crew::setName(const char* n)
{
	delete[] name;
	name = new char[strlen(n) + 1];
	if (name == nullptr)
		return false;
	strcpy(name, n);
	return true;
}

ostream& operator<<(ostream& os, const Crew& crew)
{
	if (&crew == nullptr)
		return os << "No Crew member";
	return os << "Crew member\n" << "Name: " << crew.getName() << " ID: " << crew.getEmployeeID() << endl;
}
