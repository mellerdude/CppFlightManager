#pragma once
#pragma warning (disable : 4996)

#include "Crew.h"
#include "Customer.h"
#include <string.h>

class SecurityGuard :
	public Crew, public Customer
{
private:
	char* weapon;

public:
	// Getters & Setters
	char* getWeapon();
	bool setWeapon(char* newWeapon);

	// Constructors & Destructors
	SecurityGuard(const char* newTicketNumber, const char* name, Luggage& newLuggage, const int eid, const char* newWeapon)
		: Customer(newTicketNumber, name, newLuggage), Crew(eid, name)				// Activating corresponding constructors
	{
		this->weapon = new char[strlen(newWeapon) + 1];
		strcpy(this->weapon, newWeapon);
	}

	~SecurityGuard()
	{
		delete[]weapon;
	}
};