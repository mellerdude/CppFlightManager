#include "Flight.h"

Plane* Flight::getPlane()
{
	return plane;
}

void Flight::setPlane(Plane* p)
{
	if (plane != p && plane == nullptr)
		plane = p;
	
}

Airport* Flight::getSourceAirport()
{
	return sourceAirport;
}

void Flight::setSourceAirport(Airport* s)
{
	sourceAirport = s;
}

Airport* Flight::getDestinationAirport()
{
	return destinationAirport;
}

void Flight::setDestinationAirport(Airport* d)
{
	destinationAirport = d;
}

tm* Flight::getTakeoffTime()
{
	return &takeoffTime;
}

void Flight::setTakeoffTime(tm t)
{
	takeoffTime = t;
}

tm* Flight::getLandingTime()
{
	return &landingTime;
}

void Flight::setLandingTime(tm l)
{
	landingTime = l;
}

Pilot* Flight::getMainPilot()
{
	return mainPilot;
}

void Flight::setMainPilot(Pilot* p)
{
		mainPilot = p;
}

Pilot* Flight::getCoPilot()
{
	return coPilot;
}

void Flight::setCoPilot(Pilot* p)
{
		coPilot = p;
}

SecurityGuard* Flight::getSecurityGuard1()
{
	return securityGuard1;
}

void Flight::setSecurityGuard1(SecurityGuard* s1)
{
		securityGuard1 = s1;
}

SecurityGuard* Flight::getSecurityGuard2()
{
	return securityGuard2;
}

void Flight::setSecurityGuard2(SecurityGuard* s2)
{
		securityGuard2 = s2;
}

bool Flight::addMainPilot(Pilot& p)
{
	if (&p != nullptr) {
		if (mainPilot == nullptr) {
			setMainPilot(&p);
			return true;
		}
		else {
			if (removeMainPilot()) {
				mainPilot = &p;
				return true;
			}
		}
	}
	return false;
}

bool Flight::addCoPilot(Pilot& p)
{
	if (&p != nullptr) {
		if (coPilot == nullptr) {
			setCoPilot(&p);
			return true;
		}
		else {
			if (removeCoPilot())
			{
				setCoPilot(&p);
				return true;
			}
			return false;
		}
	}
	return false;
}

bool Flight::removeMainPilot()
{
	if(mainPilot == nullptr)
		return false;
	delete[] mainPilot;
	mainPilot = nullptr;
	return true;
}

bool Flight::removeCoPilot()
{
	if (coPilot == nullptr)
		return false;
	delete[] coPilot;
	coPilot = nullptr;
	return true;
}

bool Flight::addPlane(Plane& pl)
{
	if (&pl != nullptr) {
		if (plane == nullptr) {
			setPlane(&pl);
			return true;
		}
		else {
			if (removePlane())
			{
				setPlane(&pl);
				return true;
			}
			return false;
		}
	}
	return false;
}

bool Flight::removePlane()
{
	plane->~Plane();
	return true;
}

int Flight::getCurrentNumberOfAttendants()
{
	return currentNumberOfAttendants;
}

Attendant** Flight::getAllAttendants()
{
	return attendantsList;
}

Attendant* Flight::getAttendantAt(const int position)
{
	return attendantsList[position];
}

bool Flight::removeAttendantAt(const int position)
{

	// Check if the position is valid
	if (position >= 0 && position < currentNumberOfAttendants)
	{
		// Shift elements to overwrite the element at the given position
		for (int i = position; i < currentNumberOfAttendants - 1; i++)
		{
			attendantsList[i] = attendantsList[i + 1];
		}

		attendantsList[currentNumberOfAttendants - 1] = nullptr; // Set the last element to nullptr

		// Dynamically reduce the size of the array
		Attendant** newAttendantsList = new Attendant * [currentNumberOfAttendants - 1];
		for (int i = 0; i < currentNumberOfAttendants - 1; i++)
		{
			newAttendantsList[i] = attendantsList[i];
		}

		delete[] attendantsList;
		attendantsList = newAttendantsList;

		return true; // Attendant removed successfully
	}

	return false; // Invalid position
}



bool Flight::addAttendant(Attendant& a)
{

	// Dynamically allocate a new array with increased size
	Attendant** newAttendantsList = new Attendant * [currentNumberOfAttendants + 1];

	// Copy elements from the original array to the new array
	for (int i = 0; i < currentNumberOfAttendants; i++)
	{
		newAttendantsList[i] = attendantsList[i];
	}

	// Add the new attendant at the end of the new array
	newAttendantsList[currentNumberOfAttendants] = &a;

	// Release the memory allocated for the original array
	delete[] attendantsList;

	// Assign the new array to the attendantsList
	attendantsList = newAttendantsList;

	currentNumberOfAttendants++;

	return true; // Attendant added successfully
}

bool Flight::removeAttendant(Attendant& a)
{
	    // Find the position of the attendant in the attendantsList array
    int position = -1;
    for (int i=0; i<currentNumberOfAttendants; i++)
    {
        if (*(attendantsList[i]) == a)
        {
            position = i;
            break;
        }
    }

    // Check if the attendant was found
    if (position != -1)
    {
        return removeAttendantAt(position);
    }

    return false; // Attendant not found
}

bool Flight::removeAllAttendants()
{
	int size = 0;
	for (int i = 0; i < currentNumberOfAttendants; i++)
	{
		delete attendantsList[i];
		attendantsList[i] = nullptr;
	}

	delete[] attendantsList;
	attendantsList = nullptr;
	return true;
}

bool Flight::addSecurityGuard1(SecurityGuard& s1)
{
	if (&s1 != nullptr) {
		if (securityGuard1 == nullptr) {
			setSecurityGuard1(&s1);
			return true;
		}
		else {
			if (removeSecurityGuard1()) {
				securityGuard1 = &s1;
				return true;
			}
		}
	}
	return false;
}
bool Flight::removeSecurityGuard1()
{
		if (securityGuard1 == nullptr)
			return false;
		delete[] securityGuard1;
		securityGuard1 = nullptr;
		return true;
}

bool Flight::addSecurityGuard2(SecurityGuard& s2)
{
	if (&s2 != nullptr) {
		if (securityGuard2 == nullptr) {
			setSecurityGuard2(&s2);
			return true;
		}
		else {
			if (removeSecurityGuard2()) {
				securityGuard2 = &s2;
				return true;
			}
		}
	}
	return false;
}

bool Flight::removeSecurityGuard2()
{
	if (securityGuard2 == nullptr)
		return false;
	delete[] securityGuard2;
	securityGuard2 = nullptr;
	return true;
}

bool Flight::addCustomer(Customer& c, const int row, const int col)
{
	return plane->addCustomer(&c, row, col);
}

bool Flight::removeCustomerByName(char* name)
{
	return plane->removeCustomer(name);
}

bool Flight::removeCustomerBySeat(int seatRow, int seatCol)
{
	return plane->getSeatAt(seatRow,seatCol)->sitCustomerC(nullptr);
}

bool Flight::resitCustomerByName(char* name, int seatRow, int seatCol)
{
	Customer* c = plane->getSeatAt(seatRow,seatCol)->getCustomer();
	if (plane->removeCustomer(c->getName()))
		return plane->addCustomer(c);
	else
		return false;
}

bool Flight::resitCustomerBySeat(int oldSeatRow, int oldSeatColumn, int newSeatRow, int newSeatColumn)
{
	Customer* c= plane->getSeatAt(oldSeatRow,oldSeatColumn)->getCustomer();
	if (plane->removeCustomer(c->getName()))
		return plane->getSeatAt(newSeatRow, newSeatColumn)->sitCustomerC(c);
	else
		return false;
}

bool Flight::changeCustomerLuggageByName(char* name, Luggage* newLuggage)
{
	int size = 0;
	Customer** c = plane->getCustomers();
	while (c[size] != nullptr)
	{
		size++;
	}
	for (int i = 0; i < size; i++) 
	{
		if (strcmp(c[i]->getName(), name) == 0)
			return c[i]->changeLuggage(*newLuggage);
	}
	return false;
}

void Flight::showFlight()
{
	plane->showSeats();
}

char* Flight::getStatusAt(tm& time)
{
	const char* status;

	if (*this > time)
		status = "The flight hasn't taken off yet\n";
	else if (*this < time)
		status = "The flight has landed\n";
	else
		status = "The flight is currently underway\n";

	// Create a copy of the status string
	char* statusCopy = new char[strlen(status) + 1];
	strcpy(statusCopy, status);

	return statusCopy;
}

//Check if time is before take off
bool Flight::operator>(tm& time) const
{
	if (takeoffTime.tm_hour > time.tm_hour)
		return true;
	if (takeoffTime.tm_hour < time.tm_hour)
		return false;

	if (takeoffTime.tm_min > time.tm_min)
		return true;
	if (takeoffTime.tm_min < time.tm_min)
		return false;

	if (takeoffTime.tm_sec > time.tm_sec)
		return true;

	return false;
}

//Check if time is after landing
bool Flight::operator<(tm& time) const
{

	if (landingTime.tm_hour < time.tm_hour)
		return true;
	if (landingTime.tm_hour > time.tm_hour)
		return false;

	if (landingTime.tm_min < time.tm_min)
		return true;
	if (landingTime.tm_min > time.tm_min)
		return false;

	if (landingTime.tm_sec < time.tm_sec)
		return true;

	return false;
}

bool Flight::operator==(tm& time) const
{
	return !(*this < time) && !(*this > time);
}

bool Flight::operator+=(Customer& cust) const
{
	return plane->addCustomer(&cust);
}

bool Flight::operator-=(Customer& cust) const
{
	return plane->removeCustomer(&cust);
}

ostream& operator<<(ostream& os, const Flight& flight)
{
	os << "Flight from " << *flight.sourceAirport << " to " << *flight.destinationAirport << "\n"
		<< "On " << *flight.plane << "\n"
		<< "Main " << *flight.mainPilot << "\nCo " << *flight.coPilot << "\n"
		<< "Attendants\n";
	for (int i = 0; i < flight.currentNumberOfAttendants; i++) {
		os << *flight.attendantsList[i] << endl;
	}
	os << "Security guards\n" << "Security Guard 1 " << *flight.securityGuard1 << "\nSecurity Guard 2" << *flight.securityGuard2 << endl;
	return os;
}

