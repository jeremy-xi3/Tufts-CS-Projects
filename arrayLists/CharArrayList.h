/*
 *  CharArrayList.h
 *  YOUR NAME HERE
 *  DATE CREATED
 *
 *  COMP 15 HW 1 Cheshire ConCATenation
 *
 *  FILE PURPOSE HERE
 *
 */
#ifndef CHAR_ARRAY_LIST_H
#define CHAR_ARRAY_LIST_H
#include <string>

class CharArrayList {
    public:
    //Constructors
    CharArrayList();
    CharArrayList(char c);
    CharArrayList(char arr[], int size);
    // CharArrayList(const CharArrayList &other);

    //Destructor
    ~CharArrayList();
    // CharArrayList &operator=(const CharArrayList &other);
    
    //other functions
    bool isEmpty();
    void clear();
    int size();
    char first();
    char last();
    char elementAt(int index);
    string toString(); //work on this
    string toReverseString(); //work on this
    void pushAtBack(char c);
    void pushAtFront(char c);

    private:
    int capacity;
    int currSize;
    char *data;
    void expand();
};

#endif
