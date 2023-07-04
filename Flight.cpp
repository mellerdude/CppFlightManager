#include "Flight.h"



bool Flight::getInMidFlyight() {
	return inMidFlyight;
};
void Flight::setInMidFlyight(bool newValue) {
	inMidFlyight = newValue;
};

void Flight::performStateProtocol() {
	currentState->handleTakeOffAndLanding(this);
}

void Flight::setInMidFlyightState(State* state) {
	currentState = state;
}


const Plane* Flight::getPlane() const
{
	return plane;
}

void Flight::setPlane(Plane* p)
{
	if (plane != p && plane == nullptr)
		plane = p;
	
}

const Airport* Flight::getSourceAirport() const
{
	return sourceAirport;
}

void Flight::setSourceAirport(Airport* s)
{
	sourceAirport = s;
}

const Airport* Flight::getDestinationAirport() const
{
	return destinationAirport;
}

void Flight::setDestinationAirport(Airport* d)
{
	destinationAirport = d;
}

const tm* Flight::getTakeoffTime() const
{
	return &takeoffTime;
}

void Flight::setTakeoffTime(tm t)
{
	takeoffTime = t;
}

const tm* Flight::getLandingTime() const
{
	return &landingTime;
}

void Flight::setLandingTime(tm l)
{
	landingTime = l;
}

const Pilot* Flight::getMainPilot() const
{
	return mainPilot;
}

void Flight::setMainPilot(Pilot* p)
{
		mainPilot = p;
}

const Pilot* Flight::getCoPilot() const
{
	return coPilot;
}

void Flight::setCoPilot(Pilot* p)
{
		coPilot = p;
}

const SecurityGuard* Flight::getSecurityGuard1() const
{
	return securityGuard1;
}

void Flight::setSecurityGuard1(SecurityGuard* s1)
{
		securityGuard1 = s1;
}

const SecurityGuard* Flight::getSecurityGuard2() const
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

vector<Attendant*> Flight::getAllAttendants()
{
	return tempNewAttendantsList;
}

const Attendant* Flight::getAttendantAt(const int position) const
{
	return tempNewAttendantsList[position];
}

bool Flight::removeAttendantAt(const int position)
{
	if (position >= 0 && position < tempNewAttendantsList.size()) {
		currentNumberOfAttendants--;
		tempNewAttendantsList.erase(tempNewAttendantsList.begin() + position);
		return true;  // Removal successful
	}
	return false;
}



bool Flight::addAttendant(Attendant& a)
{
	if (&a == nullptr)
		return false;
	tempNewAttendantsList.push_back(&a);
	currentNumberOfAttendants++;
	return true;
}

bool Flight::removeAttendant(Attendant& a)
{
	    // Find the position of the attendant in the attendantsList array
    int position = -1;
    for (int i=0; i<currentNumberOfAttendants; i++)
    {
        if (*(tempNewAttendantsList[i]) == a)
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
	tempNewAttendantsList.clear();
	currentNumberOfAttendants = 0;
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

bool Flight::removeCustomerByName(string name)
{
	return plane->removeCustomer(name);
}

bool Flight::removeCustomerBySeat(int seatRow, int seatCol)
{
	return plane->getSeatAt(seatRow,seatCol)->sitCustomer(nullptr);
}

bool Flight::resitCustomerByName(string name, int seatRow, int seatCol)
{
	Customer* c = plane->getSeatAt(seatRow, seatCol)->getMutableCustomer();
	if (c != nullptr) {
		if (plane->removeCustomer(c->getName()))
			return plane->addCustomer(c);
		else
			return false;
	}
	return false;
}

bool Flight::resitCustomerBySeat(int oldSeatRow, int oldSeatColumn, int newSeatRow, int newSeatColumn)
{
	Customer* c = plane->getSeatAt(oldSeatRow, oldSeatColumn)->getMutableCustomer();
	if (c != nullptr) {
		if (plane->removeCustomer(c->getName()))
			return plane->getSeatAt(newSeatRow, newSeatColumn)->sitCustomer(c);
		else
			return false;
	}
	return false;
}

bool Flight::changeCustomerLuggageByName(string name, Luggage* newLuggage)
{
	int size = 0;
	Customer** c = plane->getCustomersMutable();
	if (c != nullptr) {
		while (c[size] != nullptr)
		{
			size++;
		}
	}
	for (int i = 0; i < size; i++)
	{
		if (c[i]->getName() == name)
			return c[i]->changeLuggage(*newLuggage);
	}
	return false;
}

void Flight::showFlight() const
{
	plane->showSeats();
}

const string Flight::getStatusAt(tm& time) const
{
	 string status = "";

	if (*this > time)
		status = "The flight hasn't taken off yet\n";
	else if (*this < time)
		status = "The flight has landed\n";
	else
		status = "The flight is currently underway\n";

	

	return status;
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
	os << "Flight from " << *flight.sourceAirport << " to " << *flight.destinationAirport << "\nCrew\n"
		<< "Main " << *flight.mainPilot << "\nCo " << *flight.coPilot << "\n"
		<< "Attendants\n";
	for (int i = 0; i < flight.currentNumberOfAttendants; i++) {
		os << *flight.tempNewAttendantsList[i] << endl;
	}
	os << "Security guards\n" << "Security Guard 1 " << *flight.securityGuard1 << "\nSecurity Guard 2" << *flight.securityGuard2 << endl
		<< "Plane\nFlying On " << *flight.plane << "\n";
		return os;

}

