/*
MetroSim: MetroSim.h
Jeremy Xie
2/6/26
Purpose: MetroSim is a class that allows the simulation to run. Clients are
allowed to move the train in the simulation, add passengers to stations, and
end the simulation. 
 */

#ifndef _METROSIM_H_
#define _METROSIM_H_

#include "Passenger.h"
#include "PassengerQueue.h"
#include <vector>


class MetroSim
{

public:
    MetroSim(string filename);
    void incrementPassengers();
    void addPassenger(int arrival, int destination);
    void moveTrain();
    void stateOfSim();
    void commandSequence(string filename, ofstream &outstream);
    void dequeuePassengers(ofstream &outstream);
    void quit(string query);
private:
    struct Station{
        PassengerQueue station;
        string Name;
        int stationNumber;
    };
    vector<Station> stationList;
    vector<Station> passengerStationList;
    int numStations;
    int numPassengers;
    Station *currentStation;
};

#endif
