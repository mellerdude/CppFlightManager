#include "Customer.h"

const string Customer::getTicketNumber() const
{
	return ticketNumber;
}

bool Customer::setTicketNumber(string ticketNum)
{
	ticketNumber =  ticketNum;
	return true;
}

const string Customer::getName() const
{
	return name;
}

bool Customer::setName(char* n)
{
	name=n;
	return true;
}

const Luggage* Customer::getLuggage() const
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

ostream& operator<<(ostream& os, const Customer& cust)
{
	return os << "Customer " << cust.name << " ticket number" << cust.ticketNumber << " luggage: " << cust.luggage << endl;
}
