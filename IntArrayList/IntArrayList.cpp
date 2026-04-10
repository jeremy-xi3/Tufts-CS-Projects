#include "IntArrayList.h"
#include <iostream>

using namespace std;

IntArrayList::IntArrayList(){
    data = nullptr;
    currSize = 0;
    capacity = 0;
}

IntArrayList::IntArrayList(int initialSize, int value){
    // 4, 10 -> [10, 10, 10, 10]
    capacity = initialSize * 2;
    data = new int[capacity];
    currSize = initialSize;
    for(int i = 0; i < currSize; i++){
        data[i] = value;
    }
}

IntArrayList::~IntArrayList(){
    delete [] data;
}

int IntArrayList::size(){
    return currSize;
}

bool IntArrayList::isEmpty(){
    return (currSize == 0);
}

int IntArrayList::elementAt(int index){
    return data[index];
}

void IntArrayList::addAtBack(int elem){
    if(currSize == capacity){
        expand();
    }

    data[currSize] = elem;
    currSize++;
}

void IntArrayList::expand(){
    int new_capacity = capacity*2 + 2;
    int *new_data = new int[new_capacity];

    for(int i = 0; i < currSize; i++){
        new_data[i] = data[i];
    }

    delete [] data;

    data = new_data;
    capacity = new_capacity;
}