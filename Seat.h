#pragma once
#pragma warning (disable : 4996)
#include <ostream>
using namespace std;
#include "Customer.h"

class Seat
{
private:
	bool occupied;
	Customer* customer;

public:
	// Getters & Setters
	bool isOccupied()
	{
		return this->occupied;
	}

	Customer* getCustomer()
	{
		return this->customer;
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
	bool sitCustomerC(Customer* cust)
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

	bool sitCustomer(const Customer* cust)
	{
		if (cust == nullptr) {
			this->occupied = false;
			this->customer = nullptr;
			return false;
		}

		this->occupied = true;
		this->customer = const_cast<Customer*>(cust);
		return true;
	}


	bool operator==(Customer& cust) const;
	bool operator==(Seat& seat) const;
};