/*
MetroSim: Passenger.h
Jeremy Xie
2/6/26
Purpose: Passenger is a class for passengers in the simulation. Each passenger
starts with an id, starting station, and ending station. Clients can view this
information by using a print function. 
*/

#ifndef __PASSENGER_H__
#define __PASSENGER_H__

#include <iostream>

class Passenger {
   public:
    Passenger(int id, int startingStation, int endingStation);
    int getId();
    int getStartingStation();
    int getEndingStation();
    void print(std::ostream &output);

   private:
    int id;
    int startingStation;
    int endingStation;
};

#endif

