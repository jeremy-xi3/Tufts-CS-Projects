/*
 *
 */

#include <iostream>
#include <fstream>

#include "MetroSim.h"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 3){ //error message (no file)
        cerr << "Usage: ./MetroSim stationsFile outputFile [commandsFile]" 
        << endl;
        exit(EXIT_FAILURE);
    }
    MetroSim simulator(argv[1]);
    ofstream outstream(argv[2]);
    string query;
    if(argc == 4){
        simulator.commandSequence(argv[3], outstream);
    }
    else {
        while(query !=  "m f"){
            simulator.stateOfSim();
            cout << "Command? ";
            cin >> query;
            if(query == "m"){
                cin >> query;
                if(query == "m"){
                    simulator.moveTrain();
                    simulator.dequeuePassengers(outstream);
                }
                if(query == "f"){
                    simulator.quit(query);
                    query = "m f";
                }
            }
            else if(query == "p"){
                int arrival;
                int destination;
                cin >> arrival;
                cin >> destination;
                simulator.addPassenger(arrival, destination);
            }
        }
    }
    outstream.close();
}