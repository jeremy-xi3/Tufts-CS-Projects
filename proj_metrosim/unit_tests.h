/*
MetroSim: unit_tests.h
Jeremy Xie
2/6/26
Purpose: This file contains tests for the PassengerQueue class.
*/
#include "MetroSim.h"
using namespace std;
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cassert>

void PassengerQueuePrint_test(){
    ofstream outstream;
    outstream.open("output.txt");
    PassengerQueue test;
    Passenger workshop(0, 2, 4);
    test.enqueue(workshop);
    ostringstream oss;
    ostream tester(string filename);
    test.print(oss);
    assert(oss.str() == "[0, 2->4]");
}