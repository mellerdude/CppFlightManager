#pragma once
#pragma warning (disable : 4996)
#include "Plane.h"


const char* Plane::getModel() const
{
    return model;
}

bool Plane::setModel(const char* plane_model)
{
	delete[] model;
	model = new char[strlen(plane_model) + 1];
	if (model == nullptr)
		return false;
	strcpy(model, plane_model);
	return true;
}

Seat* Plane::getSeatAt(int row, int col) const
{
	return seats[row][col];
}

void Plane::showSeats() const
{
    cout << "Seats in the plane:" << endl;

    for (int i = 0; i < ROWS_IN_PLANE; i++) {
        cout << endl;
        cout << "Row " << i << ":" << endl;

        for (int j = 0; j < SEATS_PER_ROW; j++) {
            cout << "Seat " << i << "," << j << ": ";

            if (seats[i][j]->isOccupied()) {
                cout << "Occupied by " << seats[i][j]->getCustomer()->getName() << endl;
            }
            else {
                cout << "Unoccupied" << endl;
            }
        }
    }
}


const Customer** Plane::getCustomers() const
{
    // Count the number of occupied seats
    int occupiedCount = 0;
    for (int i = 0; i < ROWS_IN_PLANE; i++) {
        for (int j = 0; j < SEATS_PER_ROW; j++) {
            if (seats[i][j]->isOccupied()) {
                occupiedCount++;
            }
        }
    }

    if (occupiedCount == 0)
        return nullptr;

    // Allocate memory for the customer array
    const Customer** customers = new const Customer * [occupiedCount];

    // Populate the customer array with occupied customer pointers
    int index = 0;
    for (int i = 0; i < ROWS_IN_PLANE; i++) {
        for (int j = 0; j < SEATS_PER_ROW; j++) {
            if (seats[i][j]->isOccupied()) {
                customers[index] = seats[i][j]->getCustomer();
                index++;
            }
        }
    }

    return customers;
}

Customer** Plane::getCustomersMutable() const
{
    // Count the number of occupied seats
    int occupiedCount = 0;
    for (int i = 0; i < ROWS_IN_PLANE; i++) {
        for (int j = 0; j < SEATS_PER_ROW; j++) {
            if (seats[i][j]->isOccupied()) {
                occupiedCount++;
            }
        }
    }
    if (occupiedCount == 0)
        return nullptr;
    // Allocate memory for the customer array
    Customer** customers = new Customer * [occupiedCount];

    // Populate the customer array with occupied customer pointers
    int index = 0;
    for (int i = 0; i < ROWS_IN_PLANE; i++) {
        for (int j = 0; j < SEATS_PER_ROW; j++) {
            if (seats[i][j]->isOccupied()) {
                customers[index] = seats[i][j]->getMutableCustomer();
                index++;
            }
        }
    }

    return customers;
}


bool Plane::addCustomer(Customer* cust)
{
    for (int i = 0; i < ROWS_IN_PLANE; i++) {
        for (int j = 0; j < SEATS_PER_ROW; j++) {
            if (!seats[i][j]->isOccupied()) {
                seats[i][j]->sitCustomer(cust);
                return true;
            }
        }
    }
    return false;
}

bool Plane::addCustomer(Customer* cust, const int row, const int col)
{
    if (seats[row][col]->isOccupied())
        return false;
    seats[row][col]->sitCustomer(cust);
	return true;
}

bool Plane::removeCustomer(Customer* cust)
{
    for (int i = 0; i < ROWS_IN_PLANE; i++) {
        for (int j = 0; j < SEATS_PER_ROW; j++) {
            if ((seats[i][j]->isOccupied()) && (*seats[i][j] == *cust)) {
                seats[i][j]->sitCustomer(nullptr);
                return true;
            }
        }
    }
    return false;
}

bool Plane::removeCustomer(const char* name)
{
    for (int i = 0; i < ROWS_IN_PLANE; i++) {
        for (int j = 0; j < SEATS_PER_ROW; j++) {
            if ((seats[i][j]->isOccupied()) && (strcmp(seats[i][j]->getCustomer()->getName(), name) == 0)) 
            {
                seats[i][j]->sitCustomer(nullptr);
                return true;
            }
        }
    }
    return false;
}

ostream& operator<<(ostream& os, const Plane& plane)
{
    os << "Plane model " << plane.getModel() << endl;
    os << "Seats in the plane:" << endl;

    for (int i = 0; i < ROWS_IN_PLANE; i++) {
        os << endl;
        os << "Row " << i << ":" << endl;

        for (int j = 0; j < SEATS_PER_ROW; j++) {
            os << "Seat " << i << "," << j << ": ";

            if (plane.seats[i][j]->isOccupied()) {
                os << "Occupied by " << plane.seats[i][j]->getCustomer()->getName() << endl;
            }
            else {
                os << "Unoccupied" << endl;
            }
        }
    }
    return os;
}
