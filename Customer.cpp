#include "Customer.h"

char* Customer::getTicketNumber()
{
	return ticketNumber;
}

bool Customer::setTicketNumber(char* ticketNum)
{
	delete[] ticketNumber;
	ticketNumber = new char[strlen(ticketNum) + 1];
	if (ticketNumber == nullptr)
		return false;
	strcpy(ticketNumber, ticketNum);
	return true;
}

char* Customer::getName()
{
	return name;
}

bool Customer::setName(char* n)
{
	delete[] name;
	name = new char[strlen(n) + 1];
	if (name == nullptr)
		return false;
	strcpy(name, n);
	return true;
}

Luggage* Customer::getLuggage()
{
	return luggage;
}

bool Customer::changeLuggage(Luggage& newluggage)
{
	if (this->getLuggage() != luggage) {
		luggage->setvolume(newluggage.getVolume());
		luggage->setWeight(newluggage.getWeight());
		return true;
	}
	return false;
}
