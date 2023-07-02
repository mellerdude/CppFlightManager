#include "FlightManagerSingleton.h"

FlightManagerSingleton* FlightManagerSingleton::instance = nullptr;

/** I/O METHODS ***/
void FlightManagerSingleton :: cleanBuffer()
{
	int c;

	do
	{
		c = getchar();
	} while ((c != EOF) && (c != '\n'));
}
int  FlightManagerSingleton::getUserIntegerInput(int min, int max)
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
Luggage* FlightManagerSingleton::getNewLuggage()
{
	return new Luggage((rand() % 10000) / 100.0, (rand() % 10000) / 100.0);
}
Pilot* FlightManagerSingleton::getANewPilot()
{
	const string pilotNames[] =
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
Attendant* FlightManagerSingleton::getANewAttendant()
{
	const string attendantNames[] =
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
SecurityGuard* FlightManagerSingleton::getANewSecurityGuard()
{
	const string guardsNames[] =
	{
		"PEW PEW PEW",
		"Yew shal newt pas",
		"Eyes on me, bucko",
		"Freaky ricky",
		"WHAT DO YOU MEAN I FAILED MEDICINE",
		"Revoked Driver Liscence number 5"
	};

	const string  weaponNames[] =
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

	string type = "SpecialTicket";
	//return new SecurityGuard();
	return new SecurityGuard(type, guardsNames[r], *getNewLuggage(), employeeID++, weaponNames[p]);
}
Plane* FlightManagerSingleton::makeNewPlane()
{
	const string planeModels[] =
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
Airport* FlightManagerSingleton::getNewAirport()
{
	const string IATAList[] =
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
	const string countryList[] =
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
Flight* FlightManagerSingleton::getANewFlight()
{
	return new Flight(*(getNewAirport()), *(getNewAirport()));
}

/** CREW REGION **/
/*Pilot*/
void  FlightManagerSingleton:: addPilot(Flight* flight, int designation) // main > CREW_MENU > PILOT_MENU > addPilot
{
	char name[100];

	cleanBuffer();
	cout << "Enter the pilot's name: ";
	cin >> name;

	if (designation == 1)
		flight->addMainPilot(*(new Pilot(employeeID++, name, licenseID++)));
	else
		flight->addCoPilot(*(new Pilot(employeeID++, name, licenseID++)));
}
void  FlightManagerSingleton::pilotsMenu(Flight* flight) // main > CREW_MENU > PILOT_MENU
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
void  FlightManagerSingleton::showAttendantsList(Flight* flight) // main > CREW_MENU > ATTENDANTS_MENU > showAttendantsList
{
	vector<Attendant*> allAttendants = flight->getAllAttendants();
	int numofAttendants = flight->getCurrentNumberOfAttendants();

	cout << "All attendants:\n";
	for (int i = 0; i < numofAttendants; i++)
		cout << *allAttendants[i] << "\n";
}
void  FlightManagerSingleton::addAttendant(Flight* flight) // main > CREW_MENU > ATTENDANTS_MENU > addAttendant
{
	char name[100];
	int firstAidKnowledge;
	double luggageWeight = 0, luggageVolume = 0;

	cleanBuffer();
	cout << "Enter the attendant's name: ";
	cin >> name;

	cout << "Enter the attendant's first aid knowledge (1-10): ";
	cin >> firstAidKnowledge;

	cout << "Enter Luggage weight and volume (e.g.: 60.3 5.4): ";
	cin >> luggageWeight, luggageVolume;

	flight->addAttendant(*(new Attendant(employeeID++, name, firstAidKnowledge, *(new Luggage(luggageWeight, luggageVolume)))));
}
void  FlightManagerSingleton::removeAttendant(Flight* flight)// main > CREW_MENU > ATTENDANTS_MENU > removeAttendant
{
	int attendantOffset = 0, numOfAttendants = flight->getCurrentNumberOfAttendants();

	cout << "Enter the attendant's offset (1-" << numOfAttendants << "): ";
	while (attendantOffset < 1)
		attendantOffset = getUserIntegerInput(0, numOfAttendants);

	flight->removeAttendantAt(attendantOffset);
}
void  FlightManagerSingleton::attendantMenu(Flight* flight) // main > CREW_MENU > ATTENDANTS_MENU
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
void  FlightManagerSingleton::addSecurityGuard(Flight* flight, int designation) // main > CREW_MENU > SECURITY_GUARDS_MENU > addGuard
{
	char name[100], weapon[100];
	double luggageWeight = 0, luggageVolume = 0;

	cleanBuffer();
	cout << "Enter the guard's name: ";
	cin >> name;

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
void  FlightManagerSingleton::guardsMenu(Flight* flight) // main > CREW_MENU > SECURITY_GUARDS_MENU
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
void  FlightManagerSingleton::crewMenu(Flight* flight) // main > CREW_MENU
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
void FlightManagerSingleton::addCustomerNoSit(Flight* flight) // main > CUSTOMERS_MENU > ADD_CUSTOMERS_MENU > add customer without seat
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
void FlightManagerSingleton::addCustomerWithSit(Flight* flight) // main > CUSTOMERS_MENU > ADD_CUSTOMERS_MENU > add customer with seat
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
	cin >> luggageWeight, luggageVolume;

	cout << "Enter a seat number:\n";
	cout << "Row: ";
	seatRow = getUserIntegerInput(1, ROWS_IN_PLANE);
	cout << "Column: ";
	seatColumn = getUserIntegerInput(1, SEATS_PER_ROW);

	flight->addCustomer(*(new Customer(ticketNum, name, *(new Luggage(luggageWeight, luggageVolume)))), seatRow, seatColumn);
}
void FlightManagerSingleton::addCustomerMenu(Flight* flight) // main > CUSTOMERS_MENU > ADD_CUSTOMERS_MENU
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
void FlightManagerSingleton::removeCustomerByName(Flight* flight) // main > CUSTOMERS_MENU > REMOVE_CUSTOMERS_MENU > REMOVE_CUSTOMER_BY_NAME
{
	char name[100];

	cleanBuffer();
	cout << "Enter the customer's name: ";
	cin >> name;

	flight->removeCustomerByName(name);
}
void FlightManagerSingleton::removeCustomerBySeat(Flight* flight) // main > CUSTOMERS_MENU > REMOVE_CUSTOMERS_MENU > REMOVE_CUSTOMER_BY_SEAT
{
	int seatRow, seatColumn;

	cout << "Enter a seat number:\n";
	cout << "Row: ";
	seatRow = getUserIntegerInput(1, ROWS_IN_PLANE);
	cout << "Column: ";
	seatColumn = getUserIntegerInput(1, SEATS_PER_ROW);

	flight->removeCustomerBySeat(seatRow, seatColumn);
}
void FlightManagerSingleton::removeCustomerMenu(Flight* flight) // main > CUSTOMERS_MENU > REMOVE_CUSTOMERS_MENU
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
void FlightManagerSingleton::resitCustomerByName(Flight* flight) // main > CUSTOMERS_MENU > RESIT_CUSTOMERS_MENU > RESIT_CUSTOMER_BY_NAME
{
	char name[100];
	int newSeatRow, newSeatColumn;

	cleanBuffer();
	cout << "Enter a customer's name: ";
	cin >> name;
	cout << "Enter a new seat number:\n";
	cout << "Row: ";
	newSeatRow = getUserIntegerInput(1, ROWS_IN_PLANE);
	cout << "Column: ";
	newSeatColumn = getUserIntegerInput(1, SEATS_PER_ROW);

	flight->resitCustomerByName(name, newSeatRow, newSeatColumn);
}
void FlightManagerSingleton::resitCustomerBySeat(Flight* flight) // main > CUSTOMERS_MENU > RESIT_CUSTOMERS_MENU > RESIT_CUSTOMER_BY_SEAT
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
void FlightManagerSingleton::resitCustomerMenu(Flight* flight) // main > CUSTOMERS_MENU > RESIT_CUSTOMERS_MENU
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
void FlightManagerSingleton::changeCustomerLuggage(Flight* flight) // main > CUSTOMERS_MENU > CHANGE_CUSTOMER_LUGGAGE
{
	char name[100];
	double luggageWeight = 0, luggageVolume = 0;

	cleanBuffer();
	cout << "Enter a customer's name: ";
	cin >> name;
	cout << "Enter Luggage weight and volume (e.g.: 60.3 5.4): ";
	cin >> luggageWeight, luggageVolume;

	flight->changeCustomerLuggageByName(name, new Luggage(luggageWeight, luggageVolume));
}
void FlightManagerSingleton::customerMenu(Flight* flight) // main > CUSTOMERS_MENU
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
void FlightManagerSingleton::setSourceAirport(Flight* flight) // main > DETAILS_MENU >> AIRPORT > set source
{
	char IATA[100], countryName[100];

	cleanBuffer();
	cout << "Enter the airport's IATA code: ";
	cin >> IATA;
	cleanBuffer();
	cout << "Enter the airport's country name: ";
	cin >> countryName;

	flight->setSourceAirport(new Airport(IATA, countryName));
}
void FlightManagerSingleton::setDestinationAirport(Flight* flight) // main > DETAILS_MENU >> AIRPORT > set Destination
{
	char IATA[100], countryName[100];

	cleanBuffer();
	cout << "Enter the airport's IATA code: ";
	cin >> IATA;
	cleanBuffer();
	cout << "Enter the airport's country name: ";
	cin >> countryName;

	flight->setDestinationAirport(new Airport(IATA, countryName));
}
void FlightManagerSingleton::airportsMenu(Flight* flight) // main > DETAILS_MENU >> AIRPORT
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
void FlightManagerSingleton::setTime(Flight* flight, int designation)
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

void FlightManagerSingleton::timesMenu(Flight* flight) // main > DETAILS_MENU > TIME_MENU
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
void FlightManagerSingleton::getStatusByTime(Flight* flight) // main > DETAILS_MENU > get status by time
{
	tm time;

	cout << "Enter status time [hour minute second] (e.g.: 5 30 00): ";
	cin >> time.tm_hour >> time.tm_min >> time.tm_sec;
	cout << flight->getStatusAt(time);
	cleanBuffer();

}
void FlightManagerSingleton::flightDetailsMenu(Flight* flight) // main > DETAILS_MENU
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

void  FlightManagerSingleton::flightTakeOffProtocol(Flight* flight) {
	flight->setInMidFlyightState(new takeOffProtocol());
	flight->performStateProtocol();
};
void FlightManagerSingleton::flightLandingProtocol(Flight* flight) {
	flight->setInMidFlyightState(new takeOffProtocol());
	flight->performStateProtocol();
};