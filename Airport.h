#pragma once
#pragma warning (disable : 4996)
#include <iostream>
#include <string>

class Airport
{
private:
	std::string IATA;
	std::string countryName;

public:
	// Getters & Setters
	const std::string& getIATA() const;
	bool setIATA(const std::string& IATACode);

	const std::string& getCountryName() const;
	bool setCountryName(const std::string& countryName);

	// Constructors & Destructors
	Airport(const std::string& newIATA, const std::string& county)
		: IATA(newIATA), countryName(county)
	{}

	~Airport() = default;

	friend std::ostream& operator<<(std::ostream& os, const Airport& airport);
};
