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

using namespace std;

// Statics
static int licenseID = 0;
static int employeeID = 0;

// Defines
#define EXIT -1
#define BACK -1
#define MAIN_MENU 0

// inside main menu:
#define CREW_MENU 1
#define CUSTOMERS_MENU 2
#define DETAILS_MENU 3
#define FLIGHT_TAKEOFF 4
#define FLIGHT_LANDING 5
#define PlANVIEW 6
#define CLEANLOG 7


// inside crew menu:
#define PILOT_MENU 1
#define ATTENDANTS_MENU 2
#define SECURITY_GUARDS_MENU 3

// inside details menu:
#define DETAILS_AIRPORTS_MENU 1
#define DETAILS_TIMES_MENU 2


class FlightManagerDisplay { //for proxy
public:
	virtual void flightDetailsMenu(Flight* flight) = 0; 
};



class FlightManagerSingleton :FlightManagerDisplay {


    private:
        static FlightManagerSingleton* instance;
        // Private constructor to prevent direct instantiation
		FlightManagerSingleton() {}; //TODO  : can delete?

    public:
		// Static method to access the singleton instance
		static FlightManagerSingleton* getInstance() {
			if (instance == nullptr) {
				instance = new FlightManagerSingleton();
			}
			return instance;
		};


        void cleanBuffer();
        int getUserIntegerInput(int min, int max);

        /** AUTOMATIC OBJECT GENERATING REGION **/
        Luggage* getNewLuggage();
        Pilot* getANewPilot();
        Attendant* getANewAttendant();
        SecurityGuard* getANewSecurityGuard();
        Plane* makeNewPlane();
        Airport* getNewAirport();
        Flight* getANewFlight();


		/** CREW REGION **/
			/*Pilot*/
		void addPilot(Flight* flight, int designation); 
		void pilotsMenu(Flight* flight); 
		
		/*Attendant*/
		void showAttendantsList(Flight* flight);
		void addAttendant(Flight* flight);
		void removeAttendant(Flight* flight);
		void attendantMenu(Flight* flight);
		
		/*Security Gurad*/
		void addSecurityGuard(Flight* flight, int designation);
		void guardsMenu(Flight* flight);
		void crewMenu(Flight* flight);


		/** CUSTOMER REGION **/
		void addCustomerNoSit(Flight* flight); 
		void addCustomerWithSit(Flight* flight);
		void addCustomerMenu(Flight* flight);
		void removeCustomerByName(Flight* flight);
		void removeCustomerBySeat(Flight* flight);
		void removeCustomerMenu(Flight* flight);
		void resitCustomerByName(Flight* flight);
		void resitCustomerBySeat(Flight* flight);
		void resitCustomerMenu(Flight* flight);
		void changeCustomerLuggage(Flight* flight);
		void customerMenu(Flight* flight);
		
		/** FLIGHT REGION **/
		void setSourceAirport(Flight* flight);
		void setDestinationAirport(Flight* flight);
		void airportsMenu(Flight* flight);
		void setTime(Flight* flight, int designation);
		void timesMenu(Flight* flight);
		void getStatusByTime(Flight* flight);
		void flightDetailsMenu(Flight* flight) override;

		//state : 
		void flightTakeOffProtocol(Flight* flight);
		void flightLandingProtocol(Flight* flight);
};


//proxy
class AircraftFlightManagerDisplay : public FlightManagerDisplay {
private:
	FlightManagerSingleton* realFlightManger;
public:

	void flightDetailsMenu(Flight* flight) override {
		if (realFlightManger == nullptr) {
			realFlightManger = FlightManagerSingleton::getInstance();
		}
		realFlightManger->flightDetailsMenu(flight);
	}

};

