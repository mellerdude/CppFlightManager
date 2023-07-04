#include "Seat.h"

bool Seat::operator==(const Customer& cust) const
{
    if (customer != nullptr && &cust != nullptr)
        return strcmp(customer->getTicketNumber(), cust.getTicketNumber()) == 0;
    return false;
}

bool Seat::operator==(const Seat& seat) const
{
    if (customer != nullptr && seat.getCustomer() != nullptr)
        return strcmp(customer->getTicketNumber(), seat.getCustomer()->getTicketNumber()) == 0;
    return false;
}
