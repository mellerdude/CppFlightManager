#pragma once
#pragma warning (disable : 4996)

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
	char* getTicketNumber();
	bool setTicketNumber(char* ticketNum);

	char* getName();
	bool setName(char* n);

	Luggage* getLuggage();
	bool changeLuggage(Luggage& newluggage);

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
		luggage->~Luggage();

		delete[]ticketNumber;
		delete[]name;
	}

};