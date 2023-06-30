#pragma once
#pragma warning (disable : 4996)
#include <iostream>
using namespace std;
#include <string.h>
#include "Luggage.h"

class Customer
{
protected:
	string ticketNumber; // NOT NECCESSRILY A NUMBER, can be 'y7xu2mm54' for example
	string name;
	Luggage* luggage;

public:
	// Getters & Setters
	string getTicketNumber();
	bool setTicketNumber(string ticketNum);

	string getName();
	bool setName(char* n);

	Luggage* getLuggage();
	bool changeLuggage(Luggage& newluggage);

	// Constructors & Destrcutrors
	Customer(const string newTicketNumber, const string custName, Luggage& newLuggage)
	{
		

		this->ticketNumber = newTicketNumber;
		this->name = custName;
		this->luggage = &newLuggage;
	}

	~Customer()
	{
		luggage->~Luggage();
	}

	friend ostream& operator<<(ostream& os, const Customer& cust);

};