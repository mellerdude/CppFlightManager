#pragma once
#pragma warning (disable : 4996)
#include "Crew.h"
#include "Luggage.h"

class Attendant :
	public Crew
{
private:
	int firstAidKnowledge;
	Luggage* luggage;

public:
	// Getters & Setters
	int getFirstAidKnowledge();
	void setFirstAidKnowledge(int firstAid);

	Luggage* getLuggage();
	void setLuggage(Luggage* l);

	// Constructors & Destructors
	Attendant(const int eid, const char* newName, const int firstAid, Luggage& newLuggage) 
		: Crew(eid, newName)
	{
		this->firstAidKnowledge = firstAid;
		this->luggage = &newLuggage;
	}
	bool operator==(Attendant& a);

	friend ostream& operator<<(ostream& os, const Attendant& att);
};