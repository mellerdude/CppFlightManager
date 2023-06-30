#pragma once
#pragma warning (disable : 4996)
#include "Customer.h"
#include "Seat.h"

const static int ROWS_IN_PLANE = 40;
const static int SEATS_PER_ROW = 6;

class Plane
{
private:
	char* model;
	Seat* seats[ROWS_IN_PLANE][SEATS_PER_ROW];

public:
	// Getters & Setters
	char* getModel() const;
	bool setModel(char* model);

	Seat* getSeatAt(int row, int col);

	void showSeats() const;

	// Constructors & Destructors
	Plane() : Plane("No Model Name")
	{}

	Plane(const char* modelName)
	{
		this->model = new char[strlen(modelName) + 1];
		strcpy(this->model, modelName);

		for (int i = 0; i < ROWS_IN_PLANE; i++)
			for (int j = 0; j < SEATS_PER_ROW; j++)
				seats[i][j] = new Seat();
	}

	~Plane()
	{
		
		for (int i = 0; i < ROWS_IN_PLANE; i++)
			for (int j = 0; j < SEATS_PER_ROW; j++)
				seats[i][j]->~Seat();
		
		delete[] model;
	}

	// Methods
	Customer** getCustomers();// get an array of pointers to all customers on the plane by iterating over the seats.
	bool addCustomer(const Customer* cust); // add to first available place. return false if plane is full
	bool addCustomer(const Customer* cust, const int row, const int col); // add to a specific seat. return false if occupied.
	bool removeCustomer(Customer* cust);
	bool removeCustomer(const char* name);

	friend ostream& operator<<(ostream& os, const Plane& plane);

};