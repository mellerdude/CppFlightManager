// Pragmas
#pragma warning(disable: 4996) // To override the _s error

// Includes
#include <iostream>
#include <array>
#include <string.h>
#include "Plane.h"
#include "Pilot.h"
#include "Airport.h"
#include "Attendant.h"
#include "Luggage.h"
#include "SecurityGuard.h"
#include "Flight.h"
#include "FlightManagerSingleton.h"

using namespace std;

/** MAIN REGION **/
int main()
{
	int choice = 0, numOfAttendants = 3;
    FlightManagerSingleton * Singleton = FlightManagerSingleton::getInstance();
	Flight flight = *Singleton->getANewFlight();
	

	flight.addMainPilot(*Singleton->getANewPilot());
	flight.addCoPilot(*Singleton->getANewPilot());
	flight.addSecurityGuard1(*Singleton->getANewSecurityGuard());
	flight.addSecurityGuard2(*Singleton->getANewSecurityGuard());
	flight.addPlane(*Singleton->makeNewPlane());

	//state
	flight.setInMidFlyightState(new takeOffProtocol());

	for (int i = 0; i < numOfAttendants; i++)
		flight.addAttendant(*Singleton->getANewAttendant());

	do
	{
		//system("cls");
		cout << "Flight Management:\n\t1 : Crew\n\t2 : Customers\n\t3 :Flight details\n\t4 :TakeOff\n\t5 :landing\n\t6 :cleanLog\n\t-1 : Exit\n";
		choice = Singleton->getUserIntegerInput(-1, 6);
		switch (choice)
		{
		case CREW_MENU:
			Singleton->crewMenu(&flight);
			break;
		case CUSTOMERS_MENU:
			Singleton->customerMenu(&flight);
			break;
		case DETAILS_MENU:
			Singleton->flightDetailsMenu(&flight);
			break;
		case FLIGHT_TAKEOFF:
			Singleton->flightTakeOffProtocol(&flight);
			break;
		case FLIGHT_LANDING :
			Singleton->flightLandingProtocol(&flight);
			break;
		case CLEANLOG : 
			system("cls");
			break;
		default:
			break;
		}
	} while (choice != EXIT);
}