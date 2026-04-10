#ifndef _INTARRAYLIST_H_
#define _INTARRAYLIST_H_

/*
 * Class for ArrayList of Integers.
 */

class IntArrayList
{
public:
    IntArrayList();
    // Constructor below creates an array of size initialSize
    // filed with value in each slot.
    IntArrayList(int initialSize, int value);
    ~IntArrayList();

    // Let's start by implementing the below functions.
    int size();
    bool isEmpty();
    void addAtBack(int elem);
    int elementAt(int index);

    // We can implement these if we have more time.
    void addAtFront(int elem);
    void addAt(int elem, int index);
    void removeAt(int index);
    int indexOf(int elem);
    
    
private:
    int currSize, capacity;
    // data points to actual underlying array in heap.
    int *data;

    void expand();
};

#endif