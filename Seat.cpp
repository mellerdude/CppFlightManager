#include "Seat.h"

bool Seat::operator==(const Customer& cust) const
{	
	if(this->customer != nullptr && &cust != nullptr)
		return customer->getTicketNumber() == cust.getTicketNumber();
	return false;
}


bool Seat::operator==(const Seat& seat) const
{
	if(this->customer != nullptr && seat.getCustomer() != nullptr)
		return this->customer->getTicketNumber() == seat.customer->getTicketNumber();
	return false;
}
