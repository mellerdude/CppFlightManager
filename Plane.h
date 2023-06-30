#pragma once
#pragma warning (disable : 4996)
#include "Customer.h"
#include "Seat.h"
#include <string>
#include "LinkedList.h"



const static int ROWS_IN_PLANE = 40;
const static int SEATS_PER_ROW = 6;

class Plane
{
private:
	std::string model;
	Seat* seats[ROWS_IN_PLANE][SEATS_PER_ROW];
	LinkedList<Seat*>* linkedSeats[ROWS_IN_PLANE];

public:
	// Getters & Setters
	std::string getModel() const;
	bool setModel(const std::string& model);
	Seat* getSeatAt(int row, int col);
	Seat* getSeatAt(int row, int col) const;

	void showSeats() const;

	

	// Constructors & Destructors
	Plane() : Plane("No Model Name")
	{}

	Plane(const char* modelName)  //TODO : remove Seat* seats
	{
		this->model = modelName;

		for (int i = 0; i < ROWS_IN_PLANE; i++) {
			linkedSeats[i] = new LinkedList<Seat*>;
			for (int j = 0; j < SEATS_PER_ROW; j++)
			{
				seats[i][j] = new Seat();
                linkedSeats[i]->insert(new Seat());
			}
			
		}
			
				
	}

	~Plane()
	{
		
		for (int i = 0; i < ROWS_IN_PLANE; i++) {
			for (int j = 0; j < SEATS_PER_ROW; j++)
			{
			getSeatAt(i, j)->~Seat();
			linkedSeats[i]->~LinkedList();
			}
		}
	}

	// Methods
	Customer** getCustomers();// get an array of pointers to all customers on the plane by iterating over the seats.
	bool addCustomer(const Customer* cust); // add to first available place. return false if plane is full
	bool addCustomer(const Customer* cust, const int row, const int col); // add to a specific seat. return false if occupied.
	bool removeCustomer(Customer* cust);
	bool removeCustomer(const string name);

	friend ostream& operator<<(ostream& os, const Plane& plane);

};