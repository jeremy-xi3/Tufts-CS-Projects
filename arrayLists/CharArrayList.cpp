/*
 *  CharArrayList.cpp
 *  YOUR NAME HERE
 *  DATE CREATED
 *
 *  COMP 15 HW 1 Cheshire ConCATenation
 *
 *  FILE PURPOSE HERE
 *
 */
#include "CharArrayList.h"
#include <iostream>
#include <string>

using namespace std;
//constructors
CharArrayList::CharArrayList(){
    capacity = 0;
    currSize = 0;
    data = nullptr;
}

CharArrayList::CharArrayList(char c){
    capacity = 1;
    currSize = 1;
    data = new char[capacity];
    pushAtBack(c);
}

CharArrayList::CharArrayList(char arr[], int size){
    capacity = size;
    currSize = size;
    data = new char[size];
    for(int i = 0; i < size; i++){
        data[i] = arr[i];
    }
}

//destructor
CharArrayList::~CharArrayList(){
    delete [] data;
}

bool CharArrayList::isEmpty(){
    if(capacity == 0){
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
}

int CharArrayList::size(){
    return currSize;
}

char CharArrayList::first(){
    if(isEmpty() == true){
        cerr << "cannot get first of empty ArrayList";
    }
    else{
        return data[0];
    }
}

char CharArrayList::last(){
    if(isEmpty() == true){
        cerr << "cannot get last of empty ArrayList";
    }
    else{
        return data[currSize - 1];
    }
}

char CharArrayList::elementAt(int index){
    if(isEmpty() == true || index > currSize){
        cerr << "index " << index << " not in range [0.." << currSize << ")";
    }
    else{
        return data[index];
    }
}

string CharArrayList::toString(){
    string newstring = "[CharArrayList of size ";

    for(int i = 0; i < currSize; i++){
        cout << data[i];
    }
    cout << ">>]";
    return newstring;
}

string CharArrayList::toReverseString(){
    string newstring;
    return newstring;
}

void CharArrayList::expand(){
    if(isEmpty() == true){
        capacity = 1;
    }
    else{
        capacity = capacity * 2;
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
}

void CharArrayList::insertAt(char c, int index){
    if(index > currSize){
        cerr << "index " << index << " not in range [0.." << currSize << "]";
        return;
    }
    if(currSize == capacity){
        expand();
    }
    char *temp = new char[capacity];
    for(int i = 0; i < index; i++){
        temp[i] = data[i];
    }
    
}