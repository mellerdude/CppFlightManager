#include "Customer.h"

string Customer::getTicketNumber()
{
	return ticketNumber;
}

bool Customer::setTicketNumber(string ticketNum)
{
	ticketNumber =  ticketNum;
	return true;
}

string Customer::getName()
{
	return name;
}

bool Customer::setName(char* n)
{
	name=n;
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

ostream& operator<<(ostream& os, const Customer& cust)
{
	return os << "Customer " << cust.name << " ticket number" << cust.ticketNumber << " luggage: " << cust.luggage << endl;
}
