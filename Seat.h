#pragma once
#pragma warning (disable : 4996)
#include "Customer.h"

class Seat
{
private:
	bool occupied;
	Customer* customer;

public:
	// Getters & Setters
	bool isOccupied() const
	{
		return occupied;
	}
	const Customer* getCustomer() const
	{
		return customer;
	}
	Customer* getMutableCustomer()
	{
		return customer;
	}

	// Constructors & Destructors
	Seat()
	{
		occupied = false;
		customer = NULL;
	}

	Seat(Customer* cust)
	{
		occupied = true;
		customer = cust;
	}

	// Methods
	bool sitCustomer(Customer* cust)
	{
		if (cust == NULL)
		{
			occupied = false;
			customer = NULL;

			return false;
		}

		occupied = true;
		customer = cust;

		return true;
	}


	bool operator==(const Customer& cust) const;
	bool operator==(const Seat& seat) const;
};