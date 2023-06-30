#include <iostream>
using namespace std;
#include "Luggage.h"

double Luggage::getVolume()
{
	return volume;
}

bool Luggage::setvolume(double v)
{
	if (v <= 0)
		return false;
	volume = v;
	return true;
}

double Luggage::getWeight()
{
	return weight;
}

bool Luggage::setWeight(double w)
{
	if (w <= 0)
		return false;
	weight = w;
	return true;
}

ostream& operator<<(ostream& os, const Luggage& luggage)
{
	return os << "Luggage weight: " << luggage.weight << " Luggage volume " << luggage.volume;
}
