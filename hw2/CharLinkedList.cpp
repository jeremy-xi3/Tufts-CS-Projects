/*
 *  CharLinkedList.cpp
 *  Jeremy Xie
 *  1/31/26
 *
 *  CS 15 HW 2 Cheshire ConCATenation
 *
 *  Contains functions for CharLinkedList.h and the CharLinkedList class
 *
 */

#include "CharLinkedList.h"
#include <iostream>

using namespace std;
/*
 * name: CharLinkedList
 * purpose: Constructs an empty CharLinkedList
 * arguments: None
 * returns: None
 * effects: None
 * other: None
 */
CharLinkedList::CharLinkedList(){
    front = nullptr;
    listSize = 0;
}

/*
 * name: CharLinkedList
 * purpose: Constructs a CharLinkedList with one element
 * arguments: a character
 * returns: None
 * effects: None
 * other: None
 */
CharLinkedList::CharLinkedList(char c){
    front = nullptr;
    listSize = 0;
    pushAtFront(c);
}

/*
 * name: ~CharLinkedList
 * purpose: Destruct a CharLinkedList
 * arguments: None
 * returns: None
 * effects: deletes CharLinkedList
 * other: None
 */
CharLinkedList::~CharLinkedList(){
    destructHelper(front);
}

/*
 * name: CharLinkedList
 * purpose: Construct a CharLinkedList that takes in the elements in an array
 * of characters
 * arguments: a character array and an integer denoting the size of the array
 * returns: None
 * effects: None
 * other: None
 */
CharLinkedList::CharLinkedList(char arr[], int size){
    front = nullptr;
    listSize = 0;
    for(int i = 0; i < size; i++){
        pushAtFront(arr[size - i - 1]);
    }
}

/*
 * name: CharLinkedList
 * purpose: Construct a CharLinkedList that creates a deep copy of another
 * list
 * arguments: the address of another CharLinkedList
 * returns: None
 * effects: None
 * other: None
 */
CharLinkedList::CharLinkedList(const CharLinkedList &other){
    front = NULL;
    listSize = 0;
    Node* curr = other.front;
    while(curr->next != NULL){
        pushAtBack(curr->info);
        curr = curr->next;
    }
    pushAtBack(curr->info);
}

/*
 * name: CharLinkedList operator=
 * purpose: lets a CharLinkedList become a deep copy of another list
 * arguments: the address of another CharLinkedList
 * returns: None
 * effects: None
 * other: None
 */
CharLinkedList& CharLinkedList::operator=(const CharLinkedList &other){
    clear();
    Node* curr = other.front;
    while(curr->next != NULL){
        pushAtBack(curr->info);
        curr = curr->next;
    }
    pushAtBack(curr->info);
    return *this;
}

/*
 * name: destructHelper
 * purpose: Called recursively to clear/destruct a CharLinkedList
 * arguments: A pointer pointing to a Node in the Linked list
 * returns: Nothing
 * effects: Deletes heap memory recursively until all Nodes in the list are
 * deleted
 * other: none
 */
void CharLinkedList::destructHelper(Node *curr){
    if(curr == nullptr){
        return;
    }
    if(curr->next != nullptr){
        destructHelper(curr->next);
    }
    delete curr;
}

/*
 * name: isEmpty
 * purpose: Finds if a CharLinkedList is empty
 * arguments: None
 * returns: A boolean if the List is empty or not
 * effects: None
 * other: None
 */
bool CharLinkedList::isEmpty(){
    if(listSize == 0){
        return true;
    }
    else{
        return false;
    }
}

/*
 * name: clear
 * purpose: clears a CharLinkedList and deletes its memory
 * arguments: None
 * returns: None
 * effects: Deletes the characters in a CharLinkedList and reverts it to an
 * empty CharLinkedList
 * other: none
 */
void CharLinkedList::clear(){
    destructHelper(front);
    listSize = 0;
    front = nullptr;
}

/*
 * name: size
 * purpose: Finds the size of a CharLinkedList
 * arguments: None
 * returns: an integer with the size of teh CharLinkedList
 * effects: none
 * other: none
 */
int CharLinkedList::size(){
    return listSize;
}

/*
 * name: first
 * purpose: finds the first element in a CharLinkedList
 * arguments: None
 * returns: The first character in a CharLinkedList
 * effects: None
 * other: fails if linkedList is empty
 */
char CharLinkedList::first(){
    if(isEmpty()){
        throw runtime_error("cannot get first of empty LinkedList");
    }
    return front->info;
}

/*
 * name: last
 * purpose: finds the last element in a CharLinkedList
 * arguments: None
 * returns: The last character in a CharLinkedList
 * effects: none
 * other: fails if LinkedList is empty
 */
char CharLinkedList::last(){
    if(isEmpty()){
        throw runtime_error("cannot get last of empty LinkedList");
    }
    Node* lastNode = front;
    lastNode = reachBack(lastNode);
    return lastNode->info;
}

/*
 * name: elementAt
 * purpose: finds the element/character at a given index
 * arguments: an integer with the the desired index
 * returns: a character at the given index
 * effects: none
 * other: fails if index is out of range
 */
char CharLinkedList::elementAt(int index){
    if(index < 0 or index >= listSize or listSize == 0){
        throw range_error(
            "index (" + to_string(index) + ") not in range [0.." 
            + to_string(listSize) + ")");
    }
    Node* findNode = front;
    findNode = elementAt_Helper(findNode, index);
    return findNode->info;
}

/*
 * name: elementAt_Helper
 * purpose: recursively goes through a linked list to find a desired node
 * arguments: the current node and an integer denoting how far away the 
 * current node is from the desired node
 * returns: returns the node that is the index position in the list
 * effects: none
 * other: none
 */
CharLinkedList::Node* CharLinkedList::elementAt_Helper(Node* curr, int index){
    if(index == 0){
        return curr;
    }
    else{
        index--;
        return elementAt_Helper(curr->next, index);
    }
}

/*
 * name: toString
 * purpose: Translates a CharLinkedList into a string
 * arguments: None
 * returns: A string with the CharLinkedList's size and characters in order
 * effects: none
 * other: none
 */
string CharLinkedList::toString(){
    Node* getter = front;
    string submit = "";
    if(getter != NULL){
        while(getter->next != nullptr){
            submit += getter->info;
            getter = getter->next;
        }
        submit += getter->info;
    }
    string submit2 = "[CharLinkedList of size " + to_string(listSize) + " <<";
    submit = submit2 + submit + ">>]";
    return submit;
}

/*
 * name: toReverseString
 * purpose: Translates a CharLinkedList into a string in the list's opposite
 * order
 * arguments: None
 * returns: a string with the CharLinkedList's size and characters in 
 * reverse order
 * effects: none
 * other: none
 */
string CharLinkedList::toReverseString(){
    Node* getter = front;
    string submit = "";
    if(getter != NULL){
        while(getter->next != nullptr){
            submit = getter->info + submit;
            getter = getter->next;
        }
        submit = getter->info + submit;
    }
    string submit2 = "[CharLinkedList of size " + to_string(listSize) + " <<";
    submit = submit2 + submit + ">>]";
    return submit;
}

/*
 * name: pushAtBack
 * purpose: Adds a character to the end of a linked list
 * arguments: a character to be added
 * returns: nothing
 * effects: Adds a character to the end of the list and increments the size of
 * the list by 1. Also attaches the new node to the previous back node.
 * other: none
 */
void CharLinkedList::pushAtBack(char c){
    Node* newNodes = newNode(c);
    if(front == nullptr){
        front = newNodes;
    }
    else{
        Node* back = front;
        back = reachBack(back);
        back->next = newNodes;
    }
    listSize++;
}

/*
 * name: pushAtFront
 * purpose: Adds a character at the front of a linked list
 * arguments: a character to be added
 * returns: nothing
 * effects: adds a character to the front of the linked list and increments
 * the list by 1. Also changes the front node and links the previous front 
 * node to the new node.
 * other: none
 */
void CharLinkedList::pushAtFront(char c){
    Node* newNodes = newNode(c);
    if(front == nullptr){
        front = newNodes;
    }
    else{
        newNodes->next = front;
        front = newNodes;
    }
    listSize++;
}

/*
 * name: insertAt
 * purpose: Inserts a character to a linked list at a given index
 * arguments: a character to be added and an integer with the desired index
 * returns: None
 * effects: Adds a new node at a given index, increments the list size by one,
 * attaches the new node to the node before it, and attaches the next node in
 * in the list to the new node.  
 * other: fails if index is out of range
 */

void CharLinkedList::insertAt(char c, int index){
    if(index > listSize or index < 0 or (isEmpty() and index != 0)){
        throw range_error(
            "index (" + to_string(index) +
            ") not in range [0.." + to_string(listSize) + "]"
        );
    }
    if(index == 0){
        pushAtFront(c);
        return;
    }
    Node* newNodes = newNode(c);
    Node* nodeFinder = front;
    nodeFinder = elementAt_Helper(nodeFinder, index - 1);
    newNodes->next = nodeFinder->next;
    nodeFinder->next = newNodes;
    listSize++;
}

/*
 * name: insertInOrder
 * purpose: Creates a new node and attaches it to a sorted linked list
 * arguments: a character to be added to the list
 * returns: none
 * effects: finds the index where the character should be added, and adds it
 * there. Also attaches the new node to the previous one and its next one to
 * the new node. Finally, increments the size of the list.
 * other: none
 */
void CharLinkedList::insertInOrder(char c){
    Node* nodeFinder = front;
    if(c < nodeFinder->info){ //edgecase where c goes first
        pushAtFront(c);
        return;
    }
    nodeFinder = reachBack(nodeFinder);
    if(nodeFinder->info < c){ //edgecase where c goes last
        pushAtBack(c);
        return;
    }
    nodeFinder = front;
    Node* newNodes = newNode(c);
    while(nodeFinder->next->info < c){
        nodeFinder = nodeFinder->next;
    }
    newNodes->next = nodeFinder->next;
    nodeFinder->next = newNodes;
    listSize++;
}

/*
 * name: popFromFront
 * purpose: deletes the front of a CharLinkedList
 * arguments: none
 * returns: none
 * effects: deletes the first node in the CharLinkedList. Also reassigns the
 * front pointer to the new front of the CharLinkedList. Decrements the size
 * of the list.
 * other: fails if List is empty
 */
void CharLinkedList::popFromFront(){
    if(isEmpty()){
        throw runtime_error("cannot pop from empty LinkedList");
        return;
    }
    Node* deleted = front;
    front = front->next;
    delete deleted;
    listSize--;
}

/*
 * name: popFromBack
 * purpose: deletes the last element of a CharLinkedList
 * arguments: none
 * returns: none
 * effects: deletes the last node in the CharLinkedList. Also reassigns the
 * second to last node to be the new last node by deleting its next node 
 * pointer. Decrements the size of the list.
 * other: fails if LinkedList is empty
 */
void CharLinkedList::popFromBack(){
    if(isEmpty()){
        throw runtime_error("cannot pop from empty LinkedList");
        return;
    }
    Node* deleted = front; //node to delete
    deleted = elementAt_Helper(deleted, listSize-2); //second to last node
    Node* deletethis = deleted->next;
    deleted->next = nullptr;
    delete deletethis;
    listSize--;
}

/*
 * name: removeAt
 * purpose: removes a node from the CharLinkedList at the given index
 * arguments: an integer that holds the target index
 * returns: nothing
 * effects: removes the target node from the CharLinkedList and attaches the
 * node after the target index to the node before the chosen index. Decrements
 * the list's size.
 * other: fails if index is out of range
 */
void CharLinkedList::removeAt(int index){
    if(index >= listSize or index < 0 or listSize == 0){
        throw range_error(
            "index (" + to_string(index) +
            ") not in range [0.." + to_string(listSize) + ")"
        );
    }
    if(index == 0){ //front edgecase
        popFromFront();
        return;
    }
    if(index == listSize){ //back edgecase
        popFromBack();
        return;
    }
    Node* findNode = front;
    findNode = elementAt_Helper(findNode, index - 1);
    Node* deleteNode = findNode->next;
    findNode->next = deleteNode->next;
    delete deleteNode;
    listSize--;
}

/*
 * name: replaceAt
 * purpose: Replaces a node in the CharLinkedList with another node.
 * arguments: a character to create the node and an integer with where to 
 * place the node. 
 * returns: none
 * effects: Replaces a node in the CharLinkedList. Also attaches the next node
 * after the index and the new node to the previous node. 
 * other: fails if index is out of range
 */
void CharLinkedList::replaceAt(char c, int index){
    if(index >= listSize or index < 0){
        throw range_error(
            "index (" + to_string(index) +
            ") not in range [0.." + to_string(listSize) + "]"
        );
    }
    Node* findNode = front;
    findNode = elementAt_Helper(findNode, index);
    findNode->info = c;
}

/*
 * name: concatenate
 * purpose: adds a CharLinkedList to the back of an existing one.
 * arguments: A list pointer
 * returns: nothing
 * effects: adds the elements of a CharLinkedList to the back of an existing
 * one.
 * other: none
 */
void CharLinkedList::concatenate(CharLinkedList *other){
    if(other == NULL){
        return;
    }
    Node* copyNode = other->front;
    for(int i = 0; i < other->listSize; i++){
        pushAtBack(copyNode->info);
        copyNode = copyNode->next;
    }
}

/*
 * name: reachBack
 * purpose: reaches the last node in a CharLinkedList
 * arguments: A node pointer in the target list
 * returns: the last node in a CharLinkedList
 * effects: none
 * other: none
 */
CharLinkedList::Node* CharLinkedList::reachBack(Node* curr){
    return elementAt_Helper(curr, listSize-1);
}

/*
 * name: newNode
 * purpose: Creates a new node
 * arguments: a character for the node's information
 * returns: a Node pointer
 * effects: creates a new node on the heap
 * other: none
 */
CharLinkedList::Node* CharLinkedList::newNode(char c){
    Node* newNode = new Node;
    newNode->info = c;
    newNode->next = nullptr;
    return newNode;
}