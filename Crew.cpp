#include "Crew.h"
int Crew::getEmployeeID()
{
	return employeeID;
}

bool Crew::setemployeeID(int eID)
{
	if(eID >= 10000 || eID < 0)
		return false;
	return true;
}

char* Crew::getName()
{
	return name;
}

bool Crew::setName(char* n)
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
	return os << "Crew member\n" << "Name: " << crew.name << " ID: " << crew.employeeID;
}
