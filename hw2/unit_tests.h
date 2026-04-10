/*
 *  unit_tests.h
 *  Jeremy Xie
 *  1/31/26
 *
 *  CS 15 HW 2 Cheshire ConCATenation
 *
 *  Purpose: to test teh functions written in CharLinkedList.cpp
 *
 */
#include <cassert>
#include "CharLinkedList.h"

 void sizeList0_print(){
    CharLinkedList test_list;
    assert(test_list.toString() == "[CharLinkedList of size 0 <<>>]");
 }

 void empty_test(){
    CharLinkedList test_list;
    assert(test_list.isEmpty());
 }
 void constructor_Test(){
    CharLinkedList test_list;
    test_list.pushAtFront('a');
    assert(test_list.size() == 1);
    assert(test_list.first() == 'a');
 }

  void constructor_Test2(){
    CharLinkedList test_list('a');
    assert(test_list.size() == 1);
    assert(test_list.first() == 'a');
 }

 void constructor_test3(){
    char test_arr[9] = {'a', 'b', 'c', 'z', 'd', 'e', 'f', 'g', 'h'};
    CharLinkedList test_list(test_arr, 9);
    assert(test_list.toString() == "[CharLinkedList of size 9 <<abczdefgh>>]");
 }

 void clear_test(){
    char test_arr[9] = {'a', 'b', 'c', 'z', 'd', 'e', 'f', 'g', 'h'};
    CharLinkedList test_list(test_arr, 9);
    test_list.clear();
    //makes sure list is empty
    assert(test_list.isEmpty());
}

void first_and_last_test(){
    char test_arr[9] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'j'};
    CharLinkedList test_list(test_arr, 9);
    assert(test_list.first() == 'a');
    assert(test_list.last() == 'j');    
}

void last_test(){
    CharLinkedList test_list;
    test_list.pushAtFront('a');
    test_list.pushAtFront('b');
    test_list.pushAtFront('c');
    // assert(test_list.size() == 2);
    assert(test_list.last() == 'a');
}

void string_test(){
    CharLinkedList test_list;
    test_list.pushAtBack('a');
    test_list.pushAtBack('b');
    test_list.pushAtBack('c');
    assert(test_list.toString() == "[CharLinkedList of size 3 <<abc>>]");
}

void insertAt_many_elements() {
    CharLinkedList test_list;

    // insert 1000 elements
    for (int i = 0; i < 1000; i++) {
        // always insert at the back of the list
        test_list.pushAtFront('a');
    }

    assert(test_list.size() == 1000);

    for (int i = 0; i < 1000; i++) {
        assert(test_list.elementAt(i) == 'a');
    }
}

void reverseString_test(){
    char test_arr[9] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'j'};
    CharLinkedList test_list(test_arr, 9);
    assert(test_list.toReverseString() == 
    "[CharLinkedList of size 9 <<jhgfedcba>>]");
}

void insertAt_middle_large_list() {
    char test_arr[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    CharLinkedList test_list(test_arr, 8);

    test_list.insertAt('z', 3);
    assert(test_list.size() == 9);
    assert(test_list.elementAt(3) == 'z');
    assert(test_list.toString() == "[CharLinkedList of size 9 <<abczdefgh>>]");
}

void ElementAt_test(){
    CharLinkedList test_list;
    test_list.pushAtBack('a');
    test_list.pushAtBack('b');
    test_list.pushAtBack('c');
    assert(test_list.elementAt(0) == 'a');
    assert(test_list.elementAt(1) == 'b');
    assert(test_list.elementAt(2) == 'c');
}

void InsertInOrder_test(){
    char test_arr[9] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'j'};
    CharLinkedList test_list(test_arr, 9);
    test_list.insertInOrder('i');
    assert(test_list.toString() == 
    "[CharLinkedList of size 10 <<abcdefghij>>]");
}

//tests InsertInOrder function in front edgecase
void InsertInOrder_test_front(){
    char test_arr[9] = {'b', 'c', 'd', 'e', 'f', 'g', 'h', 'j', 'l'};
    CharLinkedList test_list(test_arr, 9);
    test_list.insertInOrder('a');
    assert(test_list.toString() == 
    "[CharLinkedList of size 10 <<abcdefghjl>>]");
}

//tests InsertInOrder function in back edgecase
void InsertInOrder_test_back(){
    char test_arr[9] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'j'};
    CharLinkedList test_list(test_arr, 9);
    test_list.insertInOrder('z');
    assert(test_list.toString() == 
    "[CharLinkedList of size 10 <<abcdefghjz>>]");
}

void InsertInOrder_test2(){
    char test_arr[9] = {'a', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
    CharLinkedList test_list(test_arr, 9);
    test_list.insertInOrder('b');
    assert(test_list.toString() == 
    "[CharLinkedList of size 10 <<abcdefghij>>]");
}

void pop_fromFront_test(){
    char test_arr[9] = {'a', 'b', 'c', 'z', 'd', 'e', 'f', 'g', 'h'};
    CharLinkedList test_list(test_arr, 9);
    test_list.popFromFront();
    assert(test_list.toString() == "[CharLinkedList of size 8 <<bczdefgh>>]");
}

void pop_fromBack_test(){
    char test_arr[9] = {'a', 'b', 'c', 'z', 'd', 'e', 'f', 'g', 'h'};
    CharLinkedList test_list(test_arr, 9);
    test_list.popFromBack();
    assert(test_list.toString() == "[CharLinkedList of size 8 <<abczdefg>>]");
}

void removeAt_test(){
    char test_arr[9] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'j'};
    CharLinkedList test_list(test_arr, 9);
    test_list.removeAt(5);
    assert(test_list.toString() == 
    "[CharLinkedList of size 8 <<abcdeghj>>]");
}

void removeAtFront_test(){
    char test_arr[9] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'j'};
    CharLinkedList test_list(test_arr, 9);
    test_list.removeAt(0);
    assert(test_list.toString() == 
    "[CharLinkedList of size 8 <<bcdefghj>>]");
}

void removeAtBack_test(){
    char test_arr[9] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'j'};
    CharLinkedList test_list(test_arr, 9);
    test_list.removeAt(8);
    assert(test_list.toString() == 
    "[CharLinkedList of size 8 <<abcdefgh>>]");
}

void removeAt_empty_test(){
    bool range_error_thrown = false;
    std::string error_message = "";
    CharLinkedList test_list;
    try {
        test_list.removeAt(1);
    }
    catch (const std::range_error &e) {
        range_error_thrown = true;
        error_message = e.what();
    }
    assert(range_error_thrown);
    assert(test_list.size() == 0);
    assert(error_message == "index (1) not in range [0..0)");
}

void replace_at_test(){
    char test_arr[9] = {'a', 'b', 'c', 'z', 'd', 'e', 'f', 'g', 'h'};
    CharLinkedList test_list(test_arr, 9);
    test_list.replaceAt('i', 4);
    assert(test_list.toString() == "[CharLinkedList of size 9 <<abcziefgh>>]");
}

void concatenate_test(){
    //creates two lists and combines them to get "testing"
    char test_arr1[4] = {'t', 'e', 's', 't'};
    char test_arr2[3] = {'i', 'n', 'g'};
    CharLinkedList test_list1(test_arr1, 4);
    CharLinkedList test_list2(test_arr2, 3);
    test_list1.concatenate(&test_list2);
    assert(test_list1.toString() == "[CharLinkedList of size 7 <<testing>>]");
}

//old tests
void replaceAt_fewer_range_test(){
    bool range_error_thrown = false;
    std::string error_message = "";
    CharLinkedList test_list;
    test_list.pushAtFront('a');
    test_list.pushAtFront('b');
    test_list.pushAtFront('c');
    try {
        // insertAt for out-of-range index
        test_list.replaceAt('i',-2);
    }
    catch (const std::range_error &e) {
        range_error_thrown = true;
        error_message = e.what();
    }
    assert(range_error_thrown);
    assert(error_message == "index (-2) not in range [0..3]");
}

void replaceAt_greater_range_test(){
    bool range_error_thrown = false;
    std::string error_message = "";
    CharLinkedList test_list;
    test_list.pushAtFront('a');
    test_list.pushAtFront('b');
    test_list.pushAtFront('c');
    try {
        // insertAt for out-of-range index
        test_list.replaceAt('p', 3);
    }
    catch (const std::range_error &e) {
        range_error_thrown = true;
        error_message = e.what();
    }
    assert(range_error_thrown);
    assert(error_message == "index (3) not in range [0..3]");
}

void replaceAt_empty_test(){
    bool range_error_thrown = false;
    std::string error_message = "";
    CharLinkedList test_list;
    try {
        test_list.replaceAt('j', 1);
    }
    catch (const std::range_error &e) {
        range_error_thrown = true;
        error_message = e.what();
    }
    assert(range_error_thrown);
    assert(test_list.size() == 0);
    assert(error_message == "index (1) not in range [0..0]");
}
void removeAt_fewer_range_test(){
    bool range_error_thrown = false;
    std::string error_message = "";
    CharLinkedList test_list;
    test_list.pushAtFront('a');
    test_list.pushAtFront('b');
    test_list.pushAtFront('c');
    try {
        // insertAt for out-of-range index
        test_list.removeAt(-2);
    }
    catch (const std::range_error &e) {
        range_error_thrown = true;
        error_message = e.what();
    }
    assert(range_error_thrown);
    assert(error_message == "index (-2) not in range [0..3)");
}

void removeAt_greater_range_test(){
    bool range_error_thrown = false;
    std::string error_message = "";
    CharLinkedList test_list;
    test_list.pushAtFront('a');
    test_list.pushAtFront('b');
    test_list.pushAtFront('c');
    try {
        // insertAt for out-of-range index
        test_list.removeAt(6);
    }
    catch (const std::range_error &e) {
        range_error_thrown = true;
        error_message = e.what();
    }
    assert(range_error_thrown);
    assert(error_message == "index (6) not in range [0..3)");
}

void popFromFront_falseTest(){
    bool runtime_error_thrown = false;
    std::string error_message = "";
    CharLinkedList test_list;
    try {
        test_list.popFromFront();
    }
    catch (const std::runtime_error &e) {
        runtime_error_thrown = true;
        error_message = e.what();
    }
    assert(runtime_error_thrown);
    assert(error_message == "cannot pop from empty LinkedList");
}

void popFromBack_falseTest(){
    bool runtime_error_thrown = false;
    std::string error_message = "";
    CharLinkedList test_list;
    try {
        test_list.popFromBack();
    }
    catch (const std::runtime_error &e) {
        runtime_error_thrown = true;
        error_message = e.what();
    }
    assert(runtime_error_thrown);
    assert(error_message == "cannot pop from empty LinkedList");
}

void insertAt_fewer_range_test(){
    bool range_error_thrown = false;
    std::string error_message = "";
    CharLinkedList test_list;
    test_list.pushAtFront('a');
    test_list.pushAtFront('b');
    test_list.pushAtFront('c');
    try {
        // insertAt for out-of-range index
        test_list.insertAt('i',-2);
    }
    catch (const std::range_error &e) {
        range_error_thrown = true;
        error_message = e.what();
    }
    assert(range_error_thrown);
    assert(error_message == "index (-2) not in range [0..3]");
}

void insertAt_greater_range_test(){
    bool range_error_thrown = false;
    std::string error_message = "";
    CharLinkedList test_list;
    test_list.pushAtFront('a');
    test_list.pushAtFront('b');
    test_list.pushAtFront('c');
    try {
        // insertAt for out-of-range index
        test_list.insertAt('p', 4);
        cout << test_list.toString() << endl;
    }
    catch (const std::range_error &e) {
        range_error_thrown = true;
        error_message = e.what();
    }
    assert(range_error_thrown);
    assert(error_message == "index (4) not in range [0..3]");
}

void insertAt_empty_test(){
    bool range_error_thrown = false;
    std::string error_message = "";
    CharLinkedList test_list;
    try {
        // insertAt for out-of-range index
        test_list.insertAt('j', 1);
    }
    catch (const std::range_error &e) {
        // if insertAt is correctly implemented, a range_error will be thrown,
        // and we will end up here
        range_error_thrown = true;
        error_message = e.what();
    }
    assert(range_error_thrown);
    assert(test_list.size() == 0);
    assert(error_message == "index (1) not in range [0..0]");
}

void elementAt_fewer_range_test(){
    bool range_error_thrown = false;
    std::string error_message = "";
    CharLinkedList test_list;
    test_list.pushAtFront('a');
    test_list.pushAtFront('b');
    test_list.pushAtFront('c');
    try {
        // insertAt for out-of-range index
        test_list.elementAt(-2);
    }
    catch (const std::range_error &e) {
        range_error_thrown = true;
        error_message = e.what();
    }
    assert(range_error_thrown);
    assert(error_message == "index (-2) not in range [0..3)");
}

void elementAt_greater_range_test(){
    bool range_error_thrown = false;
    std::string error_message = "";
    CharLinkedList test_list;
    test_list.pushAtFront('a');
    test_list.pushAtFront('b');
    test_list.pushAtFront('c');
    try {
        // insertAt for out-of-range index
        test_list.elementAt(6);
    }
    catch (const std::range_error &e) {
        range_error_thrown = true;
        error_message = e.what();
    }
    assert(range_error_thrown);
    assert(error_message == "index (6) not in range [0..3)");
}

void elementAt_empty_test(){
    bool range_error_thrown = false;
    std::string error_message = "";
    CharLinkedList test_list;
    try {
        test_list.elementAt(1);
    }
    catch (const std::range_error &e) {
        range_error_thrown = true;
        error_message = e.what();
    }
    assert(range_error_thrown);
    assert(test_list.size() == 0);
    assert(error_message == "index (1) not in range [0..0)");
}
//first empty test
void first_empty_incorrect() {
    bool runtime_first_error_thrown = false;
    std::string error_message = "";
    CharLinkedList test_list;
    try {
        test_list.first();
    }
    catch (const std::runtime_error &e) {
        runtime_first_error_thrown = true;
        error_message = e.what();
    }
    assert(runtime_first_error_thrown);
    assert(error_message == "cannot get first of empty LinkedList");
}

//last empty test
void last_empty_incorrect() {
    // var to track whether range_error is thrown
    bool runtime_last_error_thrown = false;
    std::string error_message = "";
    CharLinkedList test_list;
    try {
        test_list.last();
    }
    catch (const std::runtime_error &e) {
        runtime_last_error_thrown = true;
        error_message = e.what();
    }

    assert(runtime_last_error_thrown);
    assert(error_message == "cannot get last of empty LinkedList");
}

//tests =operator
void operator_test(){
    char test_arr[9] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'j'};
    CharLinkedList test_list(test_arr, 9);
    CharLinkedList test_list2;
    test_list2 = test_list;
    assert(test_list.elementAt(7) == test_list2.elementAt(7));
    assert(test_list.toReverseString() == test_list2.toReverseString());
}
//tests elementAt function
void elementAt_test(){
    char test_arr[9] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'j'};
    CharLinkedList test_list(test_arr, 9);
    assert(test_list.elementAt(7) == 'h');
}

//tests fourth constructor
void constructor4_test(){
    //creates list
    char test_arr[9] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'j'};
    CharLinkedList test_list(test_arr, 9);
    //duplicates list
    CharLinkedList test_list2(test_list);
    assert(test_list2.toString() == 
    "[CharLinkedList of size 9 <<abcdefghj>>]");
}

//tests reverseToString function
void reverse_toString_test(){
    char test_arr[9] = {'a', 'b', 'c', 'z', 'd', 'e', 'f', 'g', 'h'};
    CharLinkedList test_list(test_arr, 9);
    assert(test_list.toReverseString() == 
    "[CharLinkedList of size 9 <<hgfedzcba>>]");
}

//tests second constructor
void constructor_test(){
    CharLinkedList test_list('a');
    assert(test_list.size() == 1);
    assert(test_list.elementAt(0) == 'a');
}

//other tests
void insertAt_empty_correct() {
    CharLinkedList test_list;
    test_list.insertAt('a', 0);
    assert(test_list.size() == 1);
    assert(test_list.elementAt(0) == 'a');
}

// Tests incorrect insertion into an empty AL.
// Attempts to call insertAt for index larger than 0.
// This should result in an std::range_error being raised.
void insertAt_empty_incorrect() {
    // var to track whether range_error is thrown
    bool range_error_thrown = false;

    // var to track any error messages raised
    std::string error_message = "";

    CharLinkedList test_list;
    try {
        // insertAt for out-of-range index
        test_list.insertAt('a', 42);
    }
    catch (const std::range_error &e) {
        // if insertAt is correctly implemented, a range_error will be thrown,
        // and we will end up here
        range_error_thrown = true;
        error_message = e.what();
    }

    // out here, we make our assertions
    assert(range_error_thrown);
    assert(error_message == "index (42) not in range [0..0]");
}

// Tests correct insertAt for front of 1-element list.
void insertAt_front_singleton_list() {
    // initialize 1-element list
    CharLinkedList test_list('a');

    // insert at front
    test_list.insertAt('b', 0);

    assert(test_list.size() == 2);
    assert(test_list.elementAt(0) == 'b');
    assert(test_list.elementAt(1) == 'a');
}

// Tests correct insertAt for back of 1-element list.
void insertAt_back_singleton_list() {
    // initialize 1-element list
    CharLinkedList test_list('a');

    // insert at back
    test_list.insertAt('b', 1);

    assert(test_list.size() == 2);
    assert(test_list.elementAt(0) == 'a');
    assert(test_list.elementAt(1) == 'b');
}

// Tests insertion into the back of a larger list
void insertAt_back_large_list() {
    char test_arr[10] = {'y', 'a', 'b', 'c', 'z', 'd', 'e', 'f', 'g', 'h'};
    CharLinkedList test_list(test_arr, 10);

    test_list.insertAt('x', 10);

    assert(test_list.size() == 11);
    assert(test_list.elementAt(10) == 'x');
    assert(test_list.toString() ==
           "[CharLinkedList of size 11 <<yabczdefghx>>]");
}

// Tests out-of-range insertion for a non-empty list.
void insertAt_nonempty_incorrect() {
    char test_arr[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    CharLinkedList test_list(test_arr, 8);

    // var to track whether range_error is thrown
    bool range_error_thrown = false;

    // var to track any error messages raised
    std::string error_message = "";

    try {
        test_list.insertAt('a', 42);
    } catch (const std::range_error &e) {
        range_error_thrown = true;
        error_message = e.what();
    }

    assert(range_error_thrown);
    assert(error_message == "index (42) not in range [0..8]");
}
