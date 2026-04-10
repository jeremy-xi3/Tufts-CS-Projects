/*
 * TurkeyLinearTable.cpp --- compare two different hash functions. This table
 * uses linear probing to handle collisions
 *
 * Based on a previous lab by Ben Hescott, I think.
 *
 * Mark A. Sheldon, Tufts University, Spring 2017
 * Edited by Kathy Quintanilla, November 2024
 *      added function contracts + fixed style
 * Edited by Hameedah Lawal, November 2024
 *      switched arraylist and linked list table implementations 
 *      to std::vector and std::list ones + separated hash tables 
 *      into different classes + added thanksgiving theme
 */

#include <iostream>
#include <stdio.h>
#include <functional>

#include "TurkeyLinearTable.h"

using namespace std;


/*
 * Name:      TurkeyLinearTable()
 * Purpose:   Initialize the member variables of the TurkeyLinearTable class
 * Arguments: None
 * Returns:   None
 * Effects:   Constructor allocates and initializes two empty tables of the 
 *            INITIAL_TABLE_SIZE
 */
TurkeyLinearTable::TurkeyLinearTable()
{
        currentTableSize = INITIAL_TABLE_SIZE;
        numItemsInTable  = 0;

        /* std::vectors and std::lists start off empty, 
           so resize() will allocate the necessary space */
        linearTable.resize(currentTableSize);

        for (int i = 0; i < currentTableSize; i++) {
            linearTable.at(i).isEmpty = true;
        }
}


/*
 * Name:      ~TurkeyLinearTable()
 * Purpose:   Recycle all memory used in class
 * Arguments: None
 * Returns:   None
 * Effects:   Recycles all memory
 */
TurkeyLinearTable::~TurkeyLinearTable()
{
}


/*
 * Name:      good_hash_function(KeyType key)
 * Purpose:   Gets the index of where to insert a value in the hash table from a
 *            given key
 * Arguments: KeyType key that the index value should be hashed from
 * Returns:   size_t of the index of where to insert
 */
static size_t good_hash_function(KeyType key)
{
        return std::hash<KeyType>{}(key);
}


/*
 * Name:      bad_hash_function(KeyType key)
 * Purpose:   Gets the index of where to insert a value in the hash table from a
 *            given key
 * Arguments: KeyType key that the index value should be hashed from
 * Returns:   size_t of the index of where to insert
 */
static size_t bad_hash_function(KeyType key)
{
        return key.length();
}


/*
 * Name:      hashValue(KeyType key, HashFunction hashFunction)
 * Purpose:   Hashes a given key with the given hash function
 * Arguments: KeyType key to be hashed and a HashFunction hashFunction that is 
 *            the HashFunction we should use to hash the key
 * Returns:   size_t of the index of where to insert
 */
static size_t hashValue(KeyType key, HashFunction hashFunction)
{
        if (hashFunction == BAD_HASH_FUNCTION) {
                return bad_hash_function(key);
        } else {
                return good_hash_function(key);
        }
}


/*
 * Name:      insertProbing(KeyType key, ValueType value,
 *                          HashFunction hashFunction)
 * Purpose:   Insert a given value into a linear probing hash table
 * Arguments: The KeyType of the value to be hashed, the ValueType of the key 
 *            to be inserted into the table, and the HashFunction to hash the 
 *            key
 * Returns:   int of the number of collisions that happened before finding a 
 *            spot
 */
int TurkeyLinearTable::insertProbing(KeyType key, ValueType value,
                                     HashFunction hashFunction)
{
        int    attempt = 0;
        bool   found   = false;

        /* NOTE:  You can put things here if it helps you */

        while (not found) {
                /* 
                 * TODO:  Students write code here
                 *        (you may write code outside the loop, too)
                 */
        }

        return attempt;
}


/*
 * Name:      expand(HashFunction hashFunction)
 * Purpose:   Expand `linearTable`
 * Arguments: The HashFunction to use to rehash the index of the values in the 
 *            table
 * Returns:   None
 * Effects:   Expands `linearTable` and rehashes each value before moving the 
 *            values over to the new table.
 */
void TurkeyLinearTable::expand(HashFunction hashFunction)
{
        /* TODO: Students write code here */
}


/*
 * Name:      printTableEntry(TableEntry entry)
 * Purpose:   Prints a TableEntry's information
 * Arguments: The TableEntry to be printed
 * Returns:   None
 */
void TurkeyLinearTable::printTableEntry(TableEntry entry)
{
        if (entry.isEmpty) {
                cout << "empty";
        } else {
                cout << "key:  "
                     << entry.key
                     << "; value:  {"
                     << entry.value.servingSize
                     << ", "
                     << entry.value.prepTime
                     << "}";
        }
}


/*
 * Name:      print()
 * Purpose:   Prints the hash table
 * Arguments: None
 * Returns:   None
 */
void TurkeyLinearTable::print()
{
        cout << "Linear table" << endl;
        
        for (int i = 0; i < currentTableSize; ++i) {
                cout << i << ":  ";
                printTableEntry(linearTable.at(i));
                cout << endl;
        }
}