#pragma once
#pragma warning (disable : 4996)
#include <iostream>
using namespace std;
#include <string>

class Airport
{
private:
	std::string IATA;
	std::string countryName;

public:
	// Getters & Setters
	const string& getIATA() const;
	bool setIATA(const string& IATACode);

	const string& getCountryName() const;
	bool setCountryName(const string& countryName);

	// Constructors & Destructors
	Airport(const string& newIATA, const string& county)
		: IATA(newIATA), countryName(county)
	{}

	~Airport() = default;

	friend std::ostream& operator<<(std::ostream& os, const Airport& airport);
};
