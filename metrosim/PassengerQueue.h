/*
MetroSim: PassengerQueue.h
Jeremy Xie
2/6/26
Purpose: PassengerQueue is a class meant to create a queue for passengers in
the simulation. It works like a typical queue but also allows clients to view
the information of all of the passengers in the queue by using the print 
function. 
*/

#include "Passenger.h"
#include <list>
#include <iostream>

using namespace std;

class PassengerQueue{
    public:
    Passenger front();
    void dequeue();
    void enqueue(const Passenger &passenger);
    int size();
    void print(ostream &output);

    private:
    string name;
    list<Passenger> lists;
};