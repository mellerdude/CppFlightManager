#pragma once
#pragma warning (disable : 4996)

class Luggage
{
private:
	double volume;
	double weight;

public:
	// Getters & Setters
	double getVolume();
	bool setvolume(double v);
	double getWeight();
	bool setWeight(double w);

	// Constructors & Destructors
	Luggage(const double newWeight, const double newvolume)
	{
		this->weight = newWeight;
		this->volume = newvolume;
	}
};