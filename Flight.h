#pragma once
#pragma warning (disable : 4996)

#include "Plane.h"
#include "Airport.h"
#include "Attendant.h"
#include "SecurityGuard.h"
#include "Pilot.h"
#include <time.h>
#include <ostream>
using namespace std;

class Flight
{
private:
	// Equipment:
	Plane* plane = nullptr;

	// Flight details:
	Airport* sourceAirport = nullptr, * destinationAirport = nullptr;
	tm takeoffTime = *(new tm()), landingTime = *(new tm());

	// Crew:
	Pilot* mainPilot = nullptr, * coPilot = nullptr;
	SecurityGuard* securityGuard1 = nullptr, * securityGuard2 = nullptr;
	Attendant** attendantsList = nullptr;
	int currentNumberOfAttendants = 0;

public:
	// Getters & Setters
	const Plane* getPlane() const;
	void setPlane(Plane* p);

	const Airport* getSourceAirport() const;
	void setSourceAirport(Airport* s);

	const Airport* getDestinationAirport() const;
	void setDestinationAirport(Airport* d);

	const tm* getTakeoffTime() const;
	void setTakeoffTime(tm t);

	const tm* getLandingTime() const;
	void setLandingTime(tm l);

	const Pilot* getMainPilot() const;
	void setMainPilot(Pilot* p);

	const Pilot* getCoPilot() const;
	void setCoPilot(Pilot* p);

	const SecurityGuard* getSecurityGuard1() const;
	void setSecurityGuard1(SecurityGuard* s1);

	const SecurityGuard* getSecurityGuard2() const;
	void setSecurityGuard2(SecurityGuard* s2);

	// Constructors & Destructors
	Flight(Airport& src, Airport& dest)
	{
		this->sourceAirport = &src;
		this->destinationAirport = &dest;
	}

	// Methods
	// Pilot Methods
	bool addMainPilot(Pilot& p);
	bool addCoPilot(Pilot& p);
	bool removeMainPilot();
	bool removeCoPilot();

	//Plane methods
	bool addPlane(Plane& pl);
	bool removePlane();

	// Attendant Methods
	int getCurrentNumberOfAttendants();
	Attendant** getAllAttendants() const;
	const Attendant* getAttendantAt(const int position) const;
	bool removeAttendantAt(const int position);
	bool addAttendant(Attendant& a);
	bool removeAttendant(Attendant& a);
	bool removeAllAttendants();

	// SecurityGuard Methods
	bool addSecurityGuard1(SecurityGuard& s1);
	bool removeSecurityGuard1();
	bool addSecurityGuard2(SecurityGuard& s2);
	bool removeSecurityGuard2();

	// Customer Methods
	bool addCustomer(Customer& c, const int row, const int col);
	bool removeCustomerByName(const char* name);
	bool removeCustomerBySeat(int seatRow, int seatCol);
	bool resitCustomerByName(const char* name, int seatRow, int seatColumn);
	bool resitCustomerBySeat(int oldSeatRow, int oldSeatColumn, int newSeatRow, int newSeatColumn);
	bool changeCustomerLuggageByName(const char* name, Luggage* newLuggage);

	// General Flight details methods
	void showFlight() const;						// show minimal details about the flight itself
	const char* getStatusAt(tm& time) const;	// returns the state of the flight at [time]. E.G.: at 7:00 the flight has not left. at 16:00 the flight has landed.

	// Operators
	bool operator<(tm& time) const;
	bool operator>(tm& time) const;
	bool operator==(tm& time) const;

	bool operator+=(Customer& cust) const;
	bool operator-=(Customer& cust) const;

	friend ostream& operator<<(ostream& os, const Flight& flight);
};