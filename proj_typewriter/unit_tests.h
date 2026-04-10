/*
Typewriter: unit_tests.h
Jeremy Xie
2/17/26
Purpose: This file contains tests for the ActionStack class.
*/
#include "ActionStack.h"
#include <cassert>

using namespace std;
void ActionStackTest1(){
    ActionStack test;
    test.push('c', true, 1, 1);
    assert(test.top().character == 'c');
    test.push('b', true, 1, 1);
    assert(test.top().character == 'b');
    test.push('a', true, 1, 1);
    assert(test.top().character == 'a');
    test.clear();
    assert(test.size() == 0);
}