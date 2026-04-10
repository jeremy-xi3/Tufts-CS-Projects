/*
Typewriter: ActionStack.cpp
Jeremy Xie
2/17/26
Purpose: This file contains an implementation of the ActionStack Class.
*/
#include "ActionStack.h"
#include <stdexcept>

using namespace std;
using std::runtime_error;

/*
 * name:      ActionStack( )
 * purpose:   Creates an instance of ActionStack
 * arguments: none
 * returns:   none
 * effects:   Creates an ActionStack
 * note:      none
 */
ActionStack::ActionStack(){
}

/*
 * name:      ~ActionStack
 * purpose:   Destructs an ActionStack
 * arguments: none
 * returns:   none
 * effects:   Destructs an ActionStack
 * note:      none
 */
ActionStack::~ActionStack(){
}

/*
 * name:      isEmpty()
 * purpose:   Checks if the ActionStack is empty
 * arguments: none
 * returns:   boolean if the Action is empty
 * effects:   none
 * note:      none
 */
bool ActionStack::isEmpty() const{
    return stack.empty();
}

/*
 * name:      size
 * purpose:   finds the size of the ActionStack
 * arguments: none
 * returns:   returns size of ActionStack
 * effects:   none
 * note:      none
 */
int ActionStack::size() const {
    return stack.size();
}

/*
 * name:      top
 * purpose:   finds the top of the ActionSTack
 * arguments: none
 * returns:   the top Action in the ActionStack
 * effects:   returns error message if top does not exist
 * note:      none
 */
ActionStack::Action ActionStack::top() const {
    if(isEmpty()){
        throw runtime_error("empty_stack");
    }
    return stack.back();
}

/*
 * name:      pop
 * purpose:   removes the top of the ActionStack
 * arguments: none
 * returns:   none
 * effects:   removes teh top of the ActionStack unless it is empty
 * note:      none
 */
void ActionStack::pop() {
    if(isEmpty()){
        throw runtime_error("empty_stack");
    }
    stack.pop_back();
}

/*
 * name:      push
 * purpose:   adds an action onto the ActionStack
 * arguments: an Action to be added
 * returns:   none
 * effects:   adds an action onto the ActionStack
 * note:      none
 */
void ActionStack::push(Action elem) {
    stack.push_back(elem);
}

/*
 * name:      push
 * purpose:   adds an action onto the ActionStack
 * arguments: the elements and members of the Action struct to be added
 * returns:   none
 * effects:   adds an action onto the ActionStack
 * note:      none
 */
void ActionStack::push(char c, bool was_delete, std::size_t line, 
    std::size_t column) {
    Action add;
    add.character = c;
    add.deleted = was_delete;
    add.column = column;
    add.line = line;
    push(add);
}

/*
 * name:      clear
 * purpose:   clears the action stack
 * arguments: none
 * returns:   none
 * effects:   clears the action stack
 * note:      none
 */
void ActionStack::clear() {
    while(stack.size() != 0){
        stack.pop_back();
    }
}