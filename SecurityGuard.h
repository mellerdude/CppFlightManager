#pragma once
#pragma warning (disable : 4996)
#include "Crew.h"
#include "Customer.h"
#include <string.h>

class SecurityGuard :
	public Crew, public Customer
{
private:
	string weapon;

public:
	// Getters & Setters
	const string getWeapon() const;
	bool setWeapon(string newWeapon);

	// Constructors & Destructors
	SecurityGuard(const string newTicketNumber, const string name, Luggage& newLuggage, const int eid, const string newWeapon)
		: Customer(newTicketNumber, name, newLuggage), Crew(eid, name)				// Activating corresponding constructors
	{
		
		this->weapon = newWeapon;
	}

	~SecurityGuard()
	{
		
	}

	friend ostream& operator<<(ostream& os, const SecurityGuard& sec);
};