#include "Attendant.h"

int Attendant::getFirstAidKnowledge() const
{
	return firstAidKnowledge;
}

//If Attendant knowledge is out of bounds of firstAid knowledge, set as 1
void Attendant::setFirstAidKnowledge(int firstAid)
{
	if (firstAid >= 1 && firstAid <= 10)
		firstAidKnowledge = firstAid;
	else
		firstAidKnowledge = 1;
}

const Luggage* Attendant::getLuggage() const
{
	return luggage;
}

void Attendant::setLuggage(Luggage* l)
{
	luggage = l;
}

bool Attendant::operator==(Attendant& a)
{
	return getEmployeeID() == a.getEmployeeID() && getName() == a.getName() && getFirstAidKnowledge() == a.getFirstAidKnowledge();
}

ostream& operator<<(ostream& os, const Attendant& att)
{
	return os << "Attendant " << (Crew&)att << "First aid knowledge = " << att.firstAidKnowledge << endl;
}
