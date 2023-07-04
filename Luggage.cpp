#include "Luggage.h"

const double Luggage::getVolume() const
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

const double Luggage::getWeight() const
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
