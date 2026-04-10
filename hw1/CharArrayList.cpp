/*
 *  CharArrayList.cpp
 *  Jeremy Xie
 *  1/24/26
 *
 *  COMP 15 HW 1 Cheshire ConCATenation
 *
 *  CharArrayList function definitions
 *
 */
#include "CharArrayList.h"
#include <iostream>
#include <string>
using std::range_error;

using namespace std;
//Things to implement
//- CharArrayList(const CharArrayList &other)
//- CharArrayList &operator=(const CharArrayList &other)
//- replaceAt(char c, int index)
//constructors
CharArrayList::CharArrayList(){
    capacity = 0;
    currSize = 0;
    data = nullptr;
}

CharArrayList::CharArrayList(char c){
    capacity = 0;
    currSize = 0;
    data = nullptr;
    expand();
    insertAt(c, 0);
}

CharArrayList::CharArrayList(char arr[], int size){
    capacity = size;
    currSize = size;
    data = new char[size];
    for(int i = 0; i < size; i++){
        data[i] = arr[i];
    }
}

CharArrayList::CharArrayList(const CharArrayList &other){
    capacity = other.capacity;
    currSize = other.currSize;
    data = new char[capacity];
    for(int i = 0; i < currSize; i++){
        data[i] = other.elementAt(i);
    }
}

//destructor
CharArrayList::~CharArrayList(){
    delete [] data;
}

//&operator=
CharArrayList& CharArrayList::operator=(const CharArrayList &other){
    delete [] data;
    capacity = other.capacity;
    currSize = other.currSize;
    data = new char[capacity];
    for(int i = 0; i < currSize; i++){
        data[i] = other.elementAt(i);
    }
    return *this;   
}

bool CharArrayList::isEmpty() const{
    if(currSize == 0){
        return true;
    }
    else{
        return false;
    }
}

void CharArrayList::clear(){
    delete [] data;
    capacity = 0;
    currSize = 0;
    data = nullptr;
}

int CharArrayList::size() const{
    return currSize;
}

char CharArrayList::first() const{
    if(currSize == 0){
        throw runtime_error("cannot get first of empty ArrayList");
    }
    else{
        return data[0];
    }
}

char CharArrayList::last() const{
    if(currSize == 0){
        throw runtime_error("cannot get last of empty ArrayList");
    }
    else{
        return data[currSize - 1];
    }
}

char CharArrayList::elementAt(int index) const{
    if(index < 0 or index >= currSize or currSize == 0){
        throw range_error(
            "index (" + to_string(index) + ") not in range [0.." 
            + to_string(currSize) + ")");
    }
    else{
        return data[index];
    }
}

string CharArrayList::toString() const{
    string str;
    for(int i = 0; i < currSize; i++){
        str += data[i];
    }
    string defaults = "[CharArrayList of size " + to_string(currSize);
    string submit = defaults + " <<" + str + ">>]";
    return submit;
}

string CharArrayList::toReverseString() const{
    string str;
    for(int i = 0; i < currSize; i++){
        str += data[currSize - i - 1];
    }
    string defaults = "[CharArrayList of size " + to_string(currSize);
    string submit = defaults + " <<" + str + ">>]";
    return submit;
}

void CharArrayList::expand(){
    if(capacity == 0){
        capacity = 4;
    }
    else{
        capacity = capacity * 3 + 8;
    }
    char *new_char = new char[capacity];
    for(int i = 0; i < currSize; i++){
        new_char[i] = data[i];
    }
    delete [] data;
    data = new_char;
}

void CharArrayList::pushAtBack(char c){
    if(currSize == capacity){
        expand();
    }
    data[currSize] = c;
    currSize++;
}

void CharArrayList::pushAtFront(char c){
    if(currSize == capacity){
        expand();
    }
    char *temp = new char[capacity];
    for(int i = 0; i < currSize; i++){
        temp[i+1] = data[i];
    }
    temp[0] = c;
    delete [] data;
    data = temp;
    currSize++;
}

void CharArrayList::insertAt(char c, int index){
    if(index > currSize or index < 0){
        throw range_error(
            "index (" + to_string(index) +
            ") not in range [0.." + to_string(currSize) + "]"
        );
    }
    else{
        if(currSize == capacity){
            expand();
        }
        char *temp = new char[capacity];
        for(int i = 0; i < index; i++){
            temp[i] = data[i];
        }
        temp[index] = c;
        for(int i = index; i < currSize; i++){
            temp[i + 1] = data[i];
        }
        currSize++;
        delete [] data;
        data = temp;
    }
}

void CharArrayList::insertInOrder(char c){
    if(currSize == capacity){
        expand();
    }
    int stop = currSize;
    for(int i = 0; i < currSize; i++){
        if(c < data[i] and stop == currSize){
            stop = i;
        }

    }
    insertAt(c, stop);
}

void CharArrayList::popFromFront(){
    if(isEmpty()){
        throw runtime_error("cannot pop from empty ArrayList");
        return;
    }
    char *temp = new char[capacity];
    for(int i = 1; i < currSize; i++){
        temp[i - 1] = data[i];
    }
    delete [] data;
    data = temp;
    currSize--;
}

void CharArrayList::popFromBack(){
    if(isEmpty()){
        throw runtime_error("cannot pop from empty ArrayList");
    }
    char *temp = new char[capacity];
    currSize--;
    for(int i = 0; i < currSize; i++){
        temp[i] = data[i];
    }
    delete [] data;
    data = temp;
}

void CharArrayList::removeAt(int index){
    if(index >= currSize or index < 0 or currSize == 0){
        throw range_error(
            "index (" + to_string(index) +
            ") not in range [0.." + to_string(currSize) + ")"
        );
    }
    for(int i = index; i < currSize-1; i++){
        data[i] = data[i+1];
    }
    currSize--;
}
void CharArrayList::replaceAt(char c, int index){
    if(index >= currSize or index < 0){
        throw range_error(
            "index (" + to_string(index) +
            ") not in range [0.." + to_string(currSize) + "]"
        );
    }
    data[index] = c;
}

void CharArrayList::concatenate(CharArrayList *other){
    while(currSize + other->currSize >= capacity){
        expand();
    }
    if(other == nullptr){
        return;
    }
    for(int i = 0; i < other->currSize; i++){
        data[currSize + i] = other->elementAt(i);
    }
    currSize += other->currSize;
}