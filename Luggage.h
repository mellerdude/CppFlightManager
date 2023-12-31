#pragma once
#pragma warning (disable : 4996)
#include <iostream>
using namespace std;
class Luggage
{
private:
	double volume;
	double weight;

public:
	// Getters & Setters
	const double getVolume() const;
	bool setvolume(double v);
	const double getWeight() const;
	bool setWeight(double w);

	// Constructors & Destructors
	Luggage(const double newWeight, const double newvolume)
	{
		this->weight = newWeight;
		this->volume = newvolume;
	}

	friend ostream& operator<<(ostream& os, const Luggage& luggage);
};