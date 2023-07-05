#pragma once
#pragma warning (disable : 4996)

#include "Plane.h"
#include "Airport.h"
#include "Attendant.h"
#include "SecurityGuard.h"
#include "Pilot.h"
#include <time.h>
#include <ostream>
#include <vector>

using namespace std;
class State;


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
	//Attendant** attendantsList = nullptr;
	int currentNumberOfAttendants = 0;
	vector<Attendant*> tempNewAttendantsList;

	//state
	bool inMidFlyight;
	State* currentState;


public:

	bool getInMidFlyight();
	void setInMidFlyight(bool newValue);

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
		currentState = nullptr;
		this->sourceAirport = &src;
		this->destinationAirport = &dest;
	}

	void setInMidFlyightState(State* state); //set if in mid flight or on ground

	void performStateProtocol();

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
	vector<Attendant*> getAllAttendants();
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
	bool removeCustomerByName(const string name);
	bool removeCustomerBySeat(int seatRow, int seatCol);
	bool resitCustomerByName(const string name, int seatRow, int seatColumn);
	bool resitCustomerBySeat(int oldSeatRow, int oldSeatColumn, int newSeatRow, int newSeatColumn);
	bool changeCustomerLuggageByName(const string name, Luggage* newLuggage);

	// General Flight details methods
	void showFlight() const;						// show minimal details about the flight itself
	const string getStatusAt(tm& time) const;	// returns the state of the flight at [time]. E.G.: at 7:00 the flight has not left. at 16:00 the flight has landed.

	// Operators
	bool operator<(tm& time) const;
	bool operator>(tm& time) const;
	bool operator==(tm& time) const;

	bool operator+=(Customer& cust) const;
	bool operator-=(Customer& cust) const;

	friend ostream& operator<<(ostream& os, const Flight& flight);
};


class State {

public:
	virtual void handleTakeOffAndLanding(Flight* context) = 0;
};

// Concrete State classes
class landingProtocol : public State {
public:
	void handleTakeOffAndLanding(Flight* context) override {
		cout << "The plane has completed the route\n";
		//TODO :concept maybey engine 10% (on) 
		//TODO :concept maybey flap open
		//TODO :conceptmaybey TIMER 10 sec
		//TODO :concept maybeyengine (50%)
		//TODO :concept maybey TIMER 10 sec
		//TODO :concept maybey engine (100%)
	    //TODO :concept maybey TIMER 10 sec
		//TODO :concept maybeyengine (80%)
		//TODO :concept maybey flap close
		context->setInMidFlyight(true);
	}
};

class takeOffProtocol : public State {
public:
	void handleTakeOffAndLanding(Flight* context) override {
		cout << "The plane has taken off.\n" ;
		//TODO  : same as but revrse
		context->setInMidFlyight(false);
	}
};
