/*
 * CS15 Lab 10: Hash Tables
 * 
 * TurkeyChainingTable.h
 * This hash table maps dish names (strings) to information about
 * that dish: the serving size and preparation time in minutes.
 *
 * For the hash table, the dish name (strings) are keys and the
 * values are structs containing the serving size and preparation time.
 *
 * In a proper polymorphic (templated) hash table, this struct would 
 * be the value type and would be defined by the client independently
 * of the table. The key type would be string.
 * 
 * Based on a previous hash table lab I think created by Ben Hescott.
 *
 * (c) Mark A. Sheldon, Tufts University, Spring 2017
 */


#ifndef TURKEY_CHAINING_TABLE_H
#define TURKEY_CHAINING_TABLE_H

#include <string>
#include <vector>
#include <list>
#include "DishInfo.h" 
#include "HashFunction.h" 

/*
 * The following type definitions allow us to abstract the TurkeyChainingTable
 * class over the details of the key and value type.
 * In the implementation, the only code that depends on knowing the
 * types is the print function, which could be removed after
 * debugging. Then we could make this a template!
 */
typedef std::string   KeyType;
typedef DishInfo      ValueType;

class TurkeyChainingTable
{
public:
        TurkeyChainingTable();
        ~TurkeyChainingTable();

        int insertChaining(KeyType key, ValueType value,
                           HashFunction hashFunction);
        void print();

private:
        /*
        * Used by the chained version of collision handling.
        */
        struct ChainNode {
            KeyType    key;
            ValueType  value;
        };

        /*
        * Here is the table.
        * It's an std::vector initialized with a size = 0.
        * A chaining table is a vector of std::lists containing ChainNodes.
        */ 
        static const int INITIAL_TABLE_SIZE = 23;
        int currentTableSize;
        int numItemsInTable;

        std::vector<std::list<ChainNode>> chainedTable;

        /*
         *  Various private helper functions definitions
         */
        void  expand(HashFunction hashFunction);
        void  printChainNode(ChainNode node);
};
#endif    /* TURKEY_CHAINING_TABLE_H */
