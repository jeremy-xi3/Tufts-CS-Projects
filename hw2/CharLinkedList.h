/*
 *  CharLinkedList.h
 *  Jeremy Xie
 *  1/31/26
 *
 *  CS 15 HW 2 Cheshire ConCATenation
 *
 *  FILE PURPOSE HERE
 *
 */

#ifndef CHAR_LINKED_LIST_H
#define CHAR_LINKED_LIST_H
#include <iostream>

using namespace std;

class CharLinkedList {
   public:
   //constructors
   CharLinkedList();
   CharLinkedList(char c);
   CharLinkedList(char arr[], int size);
   CharLinkedList(const CharLinkedList &other);

   CharLinkedList &operator=(const CharLinkedList &other);

   bool isEmpty();
   void clear();
   int size();
   char first();
   char last();
   char elementAt(int index);
   string toString();
   string toReverseString();
   void pushAtBack(char c);
   void pushAtFront(char c);
   void insertAt(char c, int index);
   void insertInOrder(char c);
   void popFromFront();
   void popFromBack();
   void removeAt(int index);
   void replaceAt(char c, int index);
   void concatenate(CharLinkedList *other);

    ~CharLinkedList();

   private:
   struct Node{
    char     info;
    Node     *next;
   };
   Node* reachBack(Node *curr);
   void destructHelper(Node *curr);
   Node* newNode(char c);
   Node *front;
   Node* elementAt_Helper(Node *curr, int index);
   int listSize;
};

#endif
