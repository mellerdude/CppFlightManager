#include <iostream>
using namespace std;
#include "Seat.h"

bool Seat::operator==(Customer& cust) const
{	
	if(this->customer != nullptr && &cust != nullptr)
		return strcmp(customer->getTicketNumber(),cust.getTicketNumber()) == 0;
	return false;
}


bool Seat::operator==(Seat& seat) const
{
	if(this->customer != nullptr && seat.getCustomer() != nullptr)
		return strcmp(this->customer->getTicketNumber(),seat.customer->getTicketNumber()) == 0;
	return false;
}
