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

// inside crew menu:
#define PILOT_MENU 1
#define ATTENDANTS_MENU 2
#define SECURITY_GUARDS_MENU 3

// inside details menu:
#define DETAILS_AIRPORTS_MENU 1
#define DETAILS_TIMES_MENU 2

/** I/O METHODS ***/
void cleanBuffer()
{
	int c;

	do
	{
		c = getchar();
	} while ((c != EOF) && (c != '\n'));
}
int getUserIntegerInput(int min, int max)
{
	int input = -1000;

	while ((input < min) || (input > max))
	{
		cout << "Please enter a valid number between" << min << " and " << max << " (inclusive): ";
		cin >> input;
	}

	return input;
}

/** AUTOMATIC OBJECT GENERATING REGION **/
Luggage* getNewLuggage()
{
	return new Luggage((rand() % 10000) / 100.0, (rand() % 10000) / 100.0);
}
Pilot* getANewPilot()
{
	const char* pilotNames[] =
	{
		"Bruce Lee the fighter Jet",
		"Woking Nao, the chinese prodigy",
		"Dum dum the best pilot in uganda",
		"Debili debby is a valid guy",
		"Mr Bean Ledden",
		"I was born in 9/11",
		"DRONE STRIKES EVERYWHERE AAAAHHHHH",
		"Another one drives the bus"
	};

	int r = rand() % (end(pilotNames) - begin(pilotNames));
	int licNum = rand() % 10000;
	return new Pilot(employeeID++, pilotNames[r], licNum);
}
Attendant* getANewAttendant()
{
	const char* attendantNames[] =
	{
		"Delores hates everyone",
		"Woking nao",
		"Mrs. fukAll",
		"I can do CPR, the giant transgender",
		"WHAT DO YOU MEAN I FAILED MEDICINE"
	};

	int r = rand() % (end(attendantNames) - begin(attendantNames));
	int AidKnowledge = 1 + (rand() % 10);
	return new Attendant(employeeID++, attendantNames[r], AidKnowledge, *getNewLuggage());
}
SecurityGuard* getANewSecurityGuard()
{
	const char* guardsNames[] =
	{
		"PEW PEW PEW",
		"Yew shal newt pas",
		"Eyes on me, bucko",
		"Freaky ricky",
		"WHAT DO YOU MEAN I FAILED MEDICINE",
		"Revoked Driver Liscence number 5"
	};

	const char* weaponNames[] =
	{
		"Magnum choclate",
		"Rocket launcher 555",
		"Hot cakes",
		"Helicopter. Just a helicopter. Really.",
		"WHAT DO YOU MEAN I FAILED MEDICINE. NO, YOU FAILED!!!",
		"Dragon ballz"
	};

	int r = rand() % (end(guardsNames) - begin(guardsNames));
	int p = rand() % (end(weaponNames) - begin(weaponNames));
	return new SecurityGuard("SpecialTicket", guardsNames[r], *getNewLuggage(), employeeID++, weaponNames[p]);
}
Plane* makeNewPlane()
{
	const char* planeModels[] =
	{
		"Bravo Alphak you",
		"Malaysia Airlines Flight 370",
		"The plane from 'LOST', flight 850",
		"The plane from 'Final destination' 1",
		"Frenchie",
		"Snoop droop the fighter jet",
		"Bro do you even lift"
	};

	int r = rand() % (end(planeModels) - begin(planeModels));
	return new Plane(planeModels[r]);
}
Airport* getNewAirport()
{
	const char* IATAList[] =
	{
		"NOP",
		"HEL",
		"AAH",
		"SIT",
		"FUK",
		"SSS",
		"BRO",
		"DAM",
		"NAH",
		"WHY",
		"NVM",
		"GUY"
	};
	const char* countryList[] =
	{
		"Uganda",
		"Prague but different",
		"Narnia",
		"Hogwarts the country, not the school",
		"Hell, France",
		"King Kai's planet",
		"Palas, tine",
		"Taco Tuesday"
	};

	int r = rand() % (end(IATAList) - begin(IATAList));
	int q = rand() % (end(countryList) - begin(countryList));
	return new Airport(IATAList[r], countryList[q]);
}
Flight* getANewFlight()
{
	return new Flight(*(getNewAirport()), *(getNewAirport()));
}

/** CREW REGION **/
/*Pilot*/
void addPilot(Flight* flight, int designation) // main > CREW_MENU > PILOT_MENU > addPilot
{
	char name[100];

	cleanBuffer();
	cout << "Enter the pilot's name: ";
	cin >> name;
	cleanBuffer();
	if (designation == 1)
		flight->addMainPilot(*(new Pilot(employeeID++, name, licenseID++)));
	else
		flight->addCoPilot(*(new Pilot(employeeID++, name, licenseID++)));
}
void pilotsMenu(Flight* flight) // main > CREW_MENU > PILOT_MENU
{
	int choice = 0;
	do
	{
		cout << "Pilots:\n\t1 : Add main pilot\n\t2 : Remove main pilot\n\t3 : Add co-pilot\n\t4 : Remove co-pilot\n\t-1 : Back\n";
		choice = getUserIntegerInput(-1, 4);
		switch (choice)
		{
		case 1:
			addPilot(flight, 1);
			break;
		case 2:
			flight->removeMainPilot();
			break;
		case 3:
			addPilot(flight, 2);
			break;
		case 4:
			flight->removeCoPilot();
			break;
		default:
			break;
		}
	} while (choice != -1);
}
/*Attendant*/
void showAttendantsList(Flight* flight) // main > CREW_MENU > ATTENDANTS_MENU > showAttendantsList
{
	Attendant** allAttendants = flight->getAllAttendants();
	int numofAttendants = flight->getCurrentNumberOfAttendants();

	cout << "All attendants:\n";
	for (int i = 0; i < numofAttendants; i++)
		cout << *allAttendants[i] << "\n";
}
void addAttendant(Flight* flight) // main > CREW_MENU > ATTENDANTS_MENU > addAttendant
{
	char name[100];
	int firstAidKnowledge;
	double luggageWeight = 0, luggageVolume = 0;

	cleanBuffer();
	cout << "Enter the attendant's name: ";
	cin >> name;
	cleanBuffer();
	cout << "Enter the attendant's first aid knowledge (1-10): ";
	cin >> firstAidKnowledge;

	cout << "Enter Luggage weight and volume (e.g.: 60.3 5.4): ";
	cin >> luggageWeight, luggageVolume;

	flight->addAttendant(*(new Attendant(employeeID++, name, firstAidKnowledge, *(new Luggage(luggageWeight, luggageVolume)))));
}
void removeAttendant(Flight* flight)// main > CREW_MENU > ATTENDANTS_MENU > removeAttendant
{
	int attendantOffset = 0, numOfAttendants = flight->getCurrentNumberOfAttendants();
	if (numOfAttendants != 0) {
		cout << "Enter the attendant's offset (1-" << numOfAttendants << "): ";
		while (attendantOffset < 1)
			attendantOffset = getUserIntegerInput(0, numOfAttendants);

		flight->removeAttendantAt(attendantOffset);
	}
	else {
		cout << "No Attendants" << endl;
	}
}
void attendantMenu(Flight* flight) // main > CREW_MENU > ATTENDANTS_MENU
{
	int choice = 0;
	do
	{
		cout << "Attendants:\n\t1 : Show attendants list\n\t2: Add attendant\n\t3 : Remove attendant\n\t4: Clear all\n\t-1 : Back\n";
		choice = getUserIntegerInput(-1, 4);
		switch (choice)
		{
		case 1:
			showAttendantsList(flight);
			break;
		case 2:
			addAttendant(flight);
			break;
		case 3:
			removeAttendant(flight);
			break;
		case 4:
			flight->removeAllAttendants();
			break;
		default:
			break;
		}
	} while (choice != -1);
}
/*Security Gurad*/
void addSecurityGuard(Flight* flight, int designation) // main > CREW_MENU > SECURITY_GUARDS_MENU > addGuard
{
	char name[100], weapon[100];
	double luggageWeight = 0, luggageVolume = 0;

	cleanBuffer();
	cout << "Enter the guard's name: ";
	cin >> name;
	cleanBuffer();
	cout << "Enter Luggage weight and volume (e.g.: 60.3 5.4): ";
	cin >> luggageWeight, luggageVolume;

	cleanBuffer();
	cout << "Enter the guard's weapon: ";
	cin >> weapon;

	if (designation == 1)
		flight->addSecurityGuard1(*(new SecurityGuard("SpecialTicket", name, *(new Luggage(luggageWeight, luggageVolume)), employeeID++, weapon)));
	else
		flight->addSecurityGuard2(*(new SecurityGuard("SpecialTicket", name, *(new Luggage(luggageWeight, luggageVolume)), employeeID++, weapon)));
}
void guardsMenu(Flight* flight) // main > CREW_MENU > SECURITY_GUARDS_MENU
{
	int choice = 0;
	do
	{
		cout << "Security Guards:\n\t1 : Add guard 1\n\t2: Remove guard 1\n\t3 : Add guard 2\n\t4: Remove guard 2\n\t-1 : Back\n";
		choice = getUserIntegerInput(-1, 4);
		switch (choice)
		{
		case 1:
			addSecurityGuard(flight, 1);
			break;
		case 2:
			flight->removeSecurityGuard1();
			break;
		case 3:
			addSecurityGuard(flight, 2);
			break;
		case 4:
			flight->removeSecurityGuard2();
			break;
		default:
			break;
		}
	} while (choice != -1);
}
void crewMenu(Flight* flight) // main > CREW_MENU
{
	int choice = 0;
	do
	{
		cout << "Crew:\n\t1 : Pilots\n\t2 : Attendants\n\t3 : Security Guards\n\t-1 : Back\n";
		choice = getUserIntegerInput(-1, 3);

		switch (choice)
		{
		case PILOT_MENU:
			pilotsMenu(flight);
			break;
		case ATTENDANTS_MENU:
			attendantMenu(flight);
			break;
		case SECURITY_GUARDS_MENU:
			guardsMenu(flight);
			break;
		default:
			break;
		}
	} while (choice != -1);
}

/** CUSTOMER REGION **/
void addCustomerNoSit(Flight* flight) // main > CUSTOMERS_MENU > ADD_CUSTOMERS_MENU > add customer without seat
{
	char name[100], ticketNum[100];
	double luggageWeight = 0, luggageVolume = 0;

	cleanBuffer();
	cout << "Enter the customer's name: ";
	cin >> name;

	cleanBuffer();
	cout << "Enter the ticket number: ";
	cin >> ticketNum;

	cout << "Enter Luggage weight and volume (e.g.: 60.3 5.4): ";
	cin >> luggageWeight, luggageVolume;

	*flight += *(new Customer(ticketNum, name, *(new Luggage(luggageWeight, luggageVolume))));
}
void addCustomerWithSit(Flight* flight) // main > CUSTOMERS_MENU > ADD_CUSTOMERS_MENU > add customer with seat
{
	char name[100], ticketNum[100];
	double luggageWeight = 0, luggageVolume = 0;
	int seatRow, seatColumn;

	cleanBuffer();
	cout << "Enter the customer's name: ";
	cin >> name;

	cleanBuffer();
	cout << "Enter the ticket number: ";
	cin >> ticketNum;

	cout << "Enter Luggage weight and volume (e.g.: 60.3 5.4): ";
	cin >> luggageWeight >> luggageVolume;

	cout << "Enter a seat number:\n";
	cout << "Row: ";
	seatRow = getUserIntegerInput(1, ROWS_IN_PLANE);
	cout << "Column: ";
	seatColumn = getUserIntegerInput(1, SEATS_PER_ROW);

	flight->addCustomer(*(new Customer(ticketNum, name, *(new Luggage(luggageWeight, luggageVolume)))), seatRow, seatColumn);
}
void addCustomerMenu(Flight* flight) // main > CUSTOMERS_MENU > ADD_CUSTOMERS_MENU
{
	int choice = 0;
	do
	{
		cout << "Add customers:\n\t1 : Add customer without sitting\n\t2 : Add new customer with sitting\n\t-1 : Back\n";
		choice = getUserIntegerInput(-1, 2);
		switch (choice)
		{
		case 1:
			addCustomerNoSit(flight);
			break;
		case 2:
			addCustomerWithSit(flight);
			break;
		default:
			break;
		}
	} while (choice != -1);
}
void removeCustomerByName(Flight* flight) // main > CUSTOMERS_MENU > REMOVE_CUSTOMERS_MENU > REMOVE_CUSTOMER_BY_NAME
{
	char name[100];

	cleanBuffer();
	cout << "Enter the customer's name: ";
	cin >> name;
	cleanBuffer();
	flight->removeCustomerByName(name);
}
void removeCustomerBySeat(Flight* flight) // main > CUSTOMERS_MENU > REMOVE_CUSTOMERS_MENU > REMOVE_CUSTOMER_BY_SEAT
{
	int seatRow, seatColumn;

	cout << "Enter a seat number:\n";
	cout << "Row: ";
	seatRow = getUserIntegerInput(1, ROWS_IN_PLANE);
	cout << "Column: ";
	seatColumn = getUserIntegerInput(1, SEATS_PER_ROW);
	cleanBuffer();
	flight->removeCustomerBySeat(seatRow, seatColumn);
}
void removeCustomerMenu(Flight* flight) // main > CUSTOMERS_MENU > REMOVE_CUSTOMERS_MENU
{
	int choice = 0;
	do
	{
		cout << "Remove customer:\n\t1 : Remove customer by name\n\t2 : Remove customer by seat\n\t-1 : Back\n";
		choice = getUserIntegerInput(-1, 2);
		switch (choice)
		{
		case 1:
			removeCustomerByName(flight);
			break;
		case 2:
			removeCustomerBySeat(flight);
			break;
		default:
			break;
		}
	} while (choice != -1);
}
void resitCustomerByName(Flight* flight) // main > CUSTOMERS_MENU > RESIT_CUSTOMERS_MENU > RESIT_CUSTOMER_BY_NAME
{
	char name[100];
	int newSeatRow, newSeatColumn;

	cleanBuffer();
	cout << "Enter a customer's name: ";
	cin >> name;
	cleanBuffer();
	cout << "Enter a new seat number:\n";
	cout << "Row: ";
	newSeatRow = getUserIntegerInput(1, ROWS_IN_PLANE);
	cout << "Column: ";
	newSeatColumn = getUserIntegerInput(1, SEATS_PER_ROW);
	cleanBuffer();
	flight->resitCustomerByName(name, newSeatRow, newSeatColumn);
}
void resitCustomerBySeat(Flight* flight) // main > CUSTOMERS_MENU > RESIT_CUSTOMERS_MENU > RESIT_CUSTOMER_BY_SEAT
{
	int oldSeatRow, oldSeatColumn, newSeatRow, newSeatColumn;

	cout << "Enter a seat number:\n";
	cout << "Row: ";
	oldSeatRow = getUserIntegerInput(1, ROWS_IN_PLANE);
	cout << "Column: ";
	oldSeatColumn = getUserIntegerInput(1, SEATS_PER_ROW);

	cout << "Enter a new seat number:\n";
	cout << "Row: ";
	newSeatRow = getUserIntegerInput(1, ROWS_IN_PLANE);
	cout << "Column: ";
	newSeatColumn = getUserIntegerInput(1, SEATS_PER_ROW);

	flight->resitCustomerBySeat(oldSeatRow, oldSeatColumn, newSeatRow, newSeatColumn);
}
void resitCustomerMenu(Flight* flight) // main > CUSTOMERS_MENU > RESIT_CUSTOMERS_MENU
{
	int choice = 0;
	do
	{
		cout << "Resit customer:\n\t1 : Pick customer by name\n\t2 : Pick customer by seat\n\t-1 : Back\n";
		choice = getUserIntegerInput(-1, 2);
		switch (choice)
		{
		case 1:
			resitCustomerByName(flight);
			break;
		case 2:
			resitCustomerBySeat(flight);
			break;
		default:
			break;
		}
	} while (choice != -1);
}
void changeCustomerLuggage(Flight* flight) // main > CUSTOMERS_MENU > CHANGE_CUSTOMER_LUGGAGE
{
	char name[100];
	double luggageWeight = 0, luggageVolume = 0;

	cleanBuffer();
	cout << "Enter a customer's name: ";
	cin >> name;
	cleanBuffer();
	cout << "Enter Luggage weight and volume (e.g.: 60.3 5.4): ";
	cin >> luggageWeight, luggageVolume;
	cleanBuffer();
	flight->changeCustomerLuggageByName(name, new Luggage(luggageWeight, luggageVolume));
}
void customerMenu(Flight* flight) // main > CUSTOMERS_MENU
{
	int choice = 0;

	do
	{
		cout << "Customers:\n\t1 : Add customer\n\t2 : Remove customer\n\t3 : Re-sit customer\n\t4 : Change customer's luggage\n\t-1 : Back\n";
		choice = getUserIntegerInput(-1, 4);
		switch (choice)
		{
		case 1:
			addCustomerMenu(flight);
			break;
		case 2:
			removeCustomerMenu(flight);
			break;
		case 3:
			resitCustomerMenu(flight);
			break;
		case 4:
			changeCustomerLuggage(flight);
		default:
			break;
		}
	} while (choice != -1);
}

/** FLIGHT REGION **/
void setSourceAirport(Flight* flight) // main > DETAILS_MENU >> AIRPORT > set source
{
	char IATA[100], countryName[100];

	cleanBuffer();
	cout << "Enter the airport's IATA code: ";
	cin >> IATA;
	cleanBuffer();
	cout << "Enter the airport's country name: ";
	cin >> countryName;
	cleanBuffer();
	flight->setSourceAirport(new Airport(IATA, countryName));
}
void setDestinationAirport(Flight* flight) // main > DETAILS_MENU >> AIRPORT > set Destination
{
	char IATA[100], countryName[100];

	cleanBuffer();
	cout << "Enter the airport's IATA code: ";
	cin >> IATA;
	cleanBuffer();
	cout << "Enter the airport's country name: ";
	cin >> countryName;
	cleanBuffer();
	flight->setDestinationAirport(new Airport(IATA, countryName));
}
void airportsMenu(Flight* flight) // main > DETAILS_MENU >> AIRPORT
{
	int choice = 0;

	do
	{
		cout << "Airports:\n\t1 : Set Source Airport\n\t2: Set Destination Airport\n\t-1 : Back\n";
		choice = getUserIntegerInput(-1, 2);
		switch (choice)
		{
		case 1: setSourceAirport(flight);
			break;
		case 2: setDestinationAirport(flight);
			break;
		default:
			break;
		}
	} while (choice != -1);
}
void setTime(Flight* flight, int designation)
{
	tm time;

	if (designation == 1)
		cout << "Enter takeoff time [hour minute second] (e.g.: 5 30 00): ";
	else
		cout << "Enter landing time [hour minute second] (e.g.: 5 30 00): ";

	cin >> time.tm_hour >> time.tm_min >> time.tm_sec;

	if (designation == 1)
		flight->setTakeoffTime(time);
	else
		flight->setLandingTime(time);

	cleanBuffer();
}

void timesMenu(Flight* flight) // main > DETAILS_MENU > TIME_MENU
{
	int choice = 0;

	do
	{
		cout << "Airports:\n\t1 : Set Takeoff Time\n\t2: Set Landing Time\n\t-1 : Back\n";
		choice = getUserIntegerInput(-1, 2);
		switch (choice)
		{
		case 1: setTime(flight, 1);
			break;
		case 2: setTime(flight, 2);
			break;
		default:
			break;
		}
	} while (choice != -1);
}
void getStatusByTime(Flight* flight) // main > DETAILS_MENU > get status by time
{
	tm time;

	cout << "Enter status time [hour minute second] (e.g.: 5 30 00): ";
	cin >> time.tm_hour >> time.tm_min >> time.tm_sec;
	cout << flight->getStatusAt(time);
	cleanBuffer();

}
void flightDetailsMenu(Flight* flight) // main > DETAILS_MENU
{
	int choice = 0;

	do
	{
		cout << "Details:\n\t1 : Show Details\n\t2: Status By Time:\n\t3: Airports\n\t4: Times\n\t-1: Back\n";
		choice = getUserIntegerInput(-1, 4);
		switch (choice)
		{
		case 1:
			cout << *flight;
			break;
		case 2:
			getStatusByTime(flight);
			break;
		case 3:
			airportsMenu(flight);
			break;
		case 4:
			timesMenu(flight);
			break;
		default:
			break;
		}
	} while (choice != -1);
}

/** MAIN REGION **/
int main()
{
	int choice = 0, numOfAttendants = 3;
	Flight flight = *getANewFlight();

	flight.addMainPilot(*getANewPilot());
	flight.addCoPilot(*getANewPilot());
	flight.addSecurityGuard1(*getANewSecurityGuard());
	flight.addSecurityGuard2(*getANewSecurityGuard());
	flight.addPlane(*makeNewPlane());

	for (int i = 0; i < numOfAttendants; i++)
		flight.addAttendant(*getANewAttendant());

	do
	{
		system("cls");
		cout << "Flight Management:\n\t1 : Crew\n\t2 : Customers\n\t3 : Flight details\n\t-1 : Exit\n";
		choice = getUserIntegerInput(-1, 3);
		switch (choice)
		{
		case CREW_MENU:
			crewMenu(&flight);
			break;
		case CUSTOMERS_MENU:
			customerMenu(&flight);
			break;
		case DETAILS_MENU:
			flightDetailsMenu(&flight);
			break;
		default:
			break;
		}
	} while (choice != EXIT);
}