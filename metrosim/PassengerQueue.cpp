/*
MetroSim: PassengerQueue.cpp
Jeremy Xie
2/6/26
Purpose: This file contains an implementation of the PassengerQueue Class.
*/

#include "PassengerQueue.h"
#include <iostream>

using namespace std;

Passenger PassengerQueue::front(){
    return lists.front();
}

void PassengerQueue::dequeue(){
    lists.pop_front();
}

void PassengerQueue::enqueue(const Passenger &passenger){
    lists.push_back(passenger);
}

int PassengerQueue::size(){
    return lists.size();
}

void PassengerQueue::print(ostream &output){
    list<Passenger> list2 = lists;
    Passenger placeholder = list2.front();
    for(int i = 0; i < size(); i++){
        placeholder = list2.front();
        placeholder.print(output);
        list2.pop_front();
    }
}