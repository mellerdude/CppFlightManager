#include "Customer.h"

const char* Customer::getTicketNumber() const
{
	return ticketNumber;
}

bool Customer::setTicketNumber(const char* ticketNum)
{
	delete[] ticketNumber;
	ticketNumber = new char[strlen(ticketNum) + 1];
	if (ticketNumber == nullptr)
		return false;
	strcpy(ticketNumber, ticketNum);
	return true;
}

const char* Customer::getName() const
{
	return name;
}

bool Customer::setName(const char* n)
{
	delete[] name;
	name = new char[strlen(n) + 1];
	if (name == nullptr)
		return false;
	strcpy(name, n);
	return true;
}

const Luggage* Customer::getLuggage() const
{
	return luggage;
}

bool Customer::changeLuggage(const Luggage& newluggage)
{
	if (this->getLuggage() != luggage) {
		luggage->setvolume(newluggage.getVolume());
		luggage->setWeight(newluggage.getWeight());
		return true;
	}
	return false;
}

ostream& operator<<(ostream& os, const Customer& cust)
{
	return os << "Customer " << cust.name << " ticket number" << cust.ticketNumber << " luggage: " << cust.luggage << endl;
}
