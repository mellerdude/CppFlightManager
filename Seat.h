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
		return this->occupied;
	}

	Customer* getCustomer() const
	{
		return this->customer;
	}
	Customer* getMutableCustomer()
	{
		return customer;
	}

	// Constructors & Destructors
	Seat()
	{
		this->occupied = false;
		this->customer = NULL;
	}

	Seat(Customer* cust)
	{
		this->occupied = true;
		this->customer = cust;
	}

	// Methods
	bool sitCustomer(Customer* cust)
	{
		if (cust == NULL)
		{
			this->occupied = false;
			this->customer = NULL;

			return false;
		}

		this->occupied = true;
		this->customer = cust;

		return true;
	}


	bool operator==(const Customer& cust) const;
	bool operator==(const Seat& seat) const;
};