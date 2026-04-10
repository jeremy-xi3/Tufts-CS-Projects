/*
MetroSim: MetroSim.cpp
Jeremy Xie
2/6/26
Purpose: This file contains an implementation of the MetroSim Class.
*/

#include "MetroSim.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

/*
 * name:      MetroSim( )
 * purpose:   This is the constructor for the simulation
 * arguments: A string containing a filename full of stations
 * returns:   none
 * effects:   Constructs a MetroSim with the provided stations
 * other:     none
 */
MetroSim::MetroSim(string filename) {
    ifstream infile(filename);
    if (infile.fail()) { //Error message(mispelled filename/file doesn't exist)
        cerr << "Error: could not open file " << filename << endl;
        exit(EXIT_FAILURE);
    }
    string stationName;
    numPassengers = 1;
    numStations = 0;
    getline(infile, stationName);
    while(not infile.eof()) {
        Station newstation; //create station for the train
        newstation.Name = stationName;
        newstation.stationNumber = numStations;
        PassengerQueue queue;
        newstation.station = queue;
        Station newPassengerStation; //create station where passengers wait
        newPassengerStation.Name = stationName;
        newPassengerStation.stationNumber = numStations;
        PassengerQueue newQueue;
        newPassengerStation.station = queue;
        numStations++;
        passengerStationList.push_back(newPassengerStation);
        stationList.push_back(newstation);
        getline(infile, stationName);
    }
    infile.close();
    currentStation = &stationList.at(0);
}

/*
 * name:      incrementPassengers( )
 * purpose:   increments the amount of passengers on the train as they get
 * added on.
 * arguments: none
 * returns:   none
 * effects:   adds another passenger on the train for ids
 * other:     none
 */
void MetroSim::incrementPassengers() {
    numPassengers++;
}

/*
 * name:      moveTrain( )
 * purpose:   moves the train/current station to the next station
 * arguments: none
 * returns:   none
 * effects:   enqueues all the passengers waiting at the station and moves the
 * current station to the next station
 * other:     none
 */
void MetroSim::moveTrain() {
    Station* back = &stationList.back();
    int current = currentStation->stationNumber;
    while(passengerStationList.at(current).station.size() != 0) { 
        //adds passengers from station to train
        Passenger add = passengerStationList.at(current).station.front();
        for(int o = 0; o < numStations; o++) {
            if(add.getEndingStation() == o) {
                stationList.at(o).station.enqueue(add);
                passengerStationList.at(current).station.dequeue();
            }
        }
    }
    if(back == currentStation) { //goes to next station
        currentStation = &stationList.at(0);
    }
    else {
        currentStation = &stationList.at(currentStation->stationNumber + 1);
    }
}

/*
 * name:      addPassenger( )
 * purpose:   adds a new passenger to a station
 * arguments: the desired beginning and ending stations
 * returns:   none
 * effects:   constructs a passenger and adds it to its starting statoin
 * other:     Increases amount of passengers in the simulation
 */
void MetroSim::addPassenger(int arrival, int destination) {
    Passenger newpassenger(numPassengers, arrival, destination);
    for(int i = 0; i < numStations; i++) { //adds passenger to station
        if(arrival == passengerStationList.at(i).stationNumber) {
            passengerStationList.at(i).station.enqueue(newpassenger);
        }
    }
    incrementPassengers();
}

/*
 * name:      stateOfSim( )
 * purpose:   prints out the current map of the train stations
 * arguments: none
 * returns:   none
 * effects:   displays where the train is and the passengers on the train
 * other:     none
 */
void MetroSim::stateOfSim() {
    cout << "Passengers on the train: {";
    for(int i = 0; i < numStations; i++) {
        stationList.at(i).station.print(cout);
    }
    cout << "}" << endl; //finds where train is
    for(int i = 0; i < numStations; i++) {
        if(currentStation == &stationList.at(i)) {
            cout << "TRAIN: [";
        }
        else {
            cout << "       [";
        }
        cout << i << "] " << passengerStationList.at(i).Name << " {";
        passengerStationList.at(i).station.print(cout);
        cout << "}" << endl;
    }
}

/*
 * name:      commandSequence
 * purpose:   runs MetroSim when a command file exists
 * arguments: the name of the command file and an outstream file to print when
 * passengers leave the train
 * returns:   none
 * effects:   runs MetroSim
 * other:     none
 */
void MetroSim::commandSequence(string filename, ofstream &outstream) {
    ifstream infile(filename);
    if (infile.fail()) {//Error message(mispelled filename/file doesn't exist)
        cerr << "Error: could not open file " << filename << endl;
        exit(EXIT_FAILURE);
    }
    string query;   
    while(query !=  "m f") {
        stateOfSim();
        cout << "Command? ";
        infile >> query;
        if(query == "m") {
            infile >> query;
            if(query == "m") {
                moveTrain();
                dequeuePassengers(outstream);
            }
            if(query == "f" or infile.eof()) {
                query = "m f";
                cout << "Thanks for playing MetroSim. Have a nice day!" << endl;
            }
        }
        else if(query == "p") {
            int arrival;
            int destination;
            infile >> arrival;
            infile >> destination;
            addPassenger(arrival, destination);
        }
    }
    infile.close();
}

/*
 * name:      dequeuePassengers( )
 * purpose:   dequeues passengers as the train arrives to the next station
 * arguments: outstream that reports when a passenger gets off the train
 * returns:   none
 * effects:   dequeues passengers and reports when they get dequeued
 * other:     none
 */
void MetroSim::dequeuePassengers(ofstream &outstream) {
    int dequeue = currentStation->stationNumber;
    while(stationList.at(dequeue).station.size() != 0) {
        outstream << "Passenger " << stationList.at(dequeue).
        station.front().getId() << " left train at station " 
        << currentStation->Name << endl;
        stationList.at(dequeue).station.dequeue();
    }
}

/*
 * name:      quit( )
 * purpose:   sets up MetroSim to quit when simulation is finished
 * arguments: the query string
 * returns:   none
 * effects:   prints "goodbye" message
 * other:     none
 */
void MetroSim::quit(string query) {
    query = "m f";
    cout << "Thanks for playing MetroSim." <<
    " Have a nice day!" << endl;
}