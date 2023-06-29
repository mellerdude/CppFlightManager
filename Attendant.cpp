#include "Attendant.h"

int Attendant::getFirstAidKnowledge()
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

Luggage* Attendant::getLuggage()
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
