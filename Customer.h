#pragma once
#pragma warning (disable : 4996)
#include <iostream>
using namespace std;
#include <string.h>
#include "Luggage.h"

class Customer
{
protected:
	char* ticketNumber; // NOT NECCESSRILY A NUMBER, can be 'y7xu2mm54' for example
	char* name;
	Luggage* luggage;

public:
	// Getters & Setters
	const char* getTicketNumber() const;
	bool setTicketNumber(const char* ticketNum);

	const char* getName() const;
	bool setName(const char* n);

	const Luggage* getLuggage() const;
	bool changeLuggage(const Luggage& newluggage);

	// Constructors & Destrcutrors
	Customer(const char* newTicketNumber, const char* custName, Luggage& newLuggage)
	{
		this->ticketNumber = new char[strlen(newTicketNumber) + 1];
		this->name = new char[strlen(custName) + 1];

		strcpy(this->ticketNumber, newTicketNumber);
		strcpy(this->name, custName);
		this->luggage = &newLuggage;
	}

	~Customer()
	{
		delete[]ticketNumber;
		delete[]name;
	}

	friend ostream& operator<<(ostream& os, const Customer& cust);

};