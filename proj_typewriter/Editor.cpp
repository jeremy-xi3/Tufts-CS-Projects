/*
Typewriter: Editor.cpp
Jeremy Xie
2/17/26
Purpose: This file contains an implementation of the Editor Class.
*/


#include "Editor.h"
#include <iostream>

using namespace std;

/*
 * name:      Editor( )
 * purpose:   To construct an Editor class for when there is no logfile
 * present.
 * arguments: The filename of the file to be used in typewriter.
 * returns:   Nothing
 * effects:   Constructs a Editor class with the given text.
 * note:      N/A
 */
Editor::Editor(string filename){
    saveFilename = filename;
    ifstream infile(filename);
    if (infile.fail()) {
        ofstream outstream(filename);
        column = 0;
        row = 0;
    }
    string contents;
    getline(infile, contents);
    while(not infile.eof()){
        text.push_back(contents);
        getline(infile, contents);
    }
    column = 0;
    row = 0;
    if(text.empty()){
        text.push_back("");
    }
    UI.render(text, 0, 0);
}

/*
 * name:      Editor( )
 * purpose:   To construct an Editor class for when there is a logfile
 * present.
 * arguments: The filenames of the file to be used in typewriter and the
 * logfile to store the changes in.
 * returns:   Nothing
 * effects:   Constructs a Editor class with the given text.
 * note:      N/A
 */
Editor::Editor(string filename, string logfile){
    saveFilename = filename;
    ofstream outstream(logfile);
    UI.startLogMode(logfile);
    ifstream infile(filename);
    if (infile.fail()) {
        ofstream myoutstream(filename);
        column = 0;
        row = 0;
    }
    string contents;
    getline(infile, contents);
    while(not infile.eof()){
        text.push_back(contents);
        getline(infile, contents);
    }
    column = 0;
    row = 0;
    if(text.empty()){
        text.push_back("");
    }
    UI.render(text, 0, 0);
}

/*
 * name:      ~Editor
 * purpose:   To destruct the editor class
 * arguments: none
 * returns:   none
 * effects:   clears undo and redo stacks
 * note:      none
 */
Editor::~Editor(){
    redoStack.clear();
    undoStack.clear();
}

/*
 * name:      run
 * purpose:   To create a query for the client to run typewriter
 * arguments: none
 * returns:   none
 * effects:   Detects the client's key presses and reacts accordingly
 * note:      none
 */
void Editor::run(){
    int query = 0;
    while(query != 1000){
        query = UI.getChar();
        if(query ==  27){
            query = escapeQuery(query);
        }
        else if(query == KEY_BACKSPACE){
            backspaceFunction();
            redoStack.clear();
        }
        else if(query == KEY_LEFT){
            keyLeftFunction();
        }
        else if(query == 10){
            newLineFunction();
            redoStack.clear();
        }
        else if(query == KEY_RIGHT){
            keyRightFunction();
        }
        else if(query == KEY_UP){
            keyUpFunction();
        }
        else if(query == KEY_DOWN){
            keyDownFunction();
        }
        else{
            addPrintable(query);
            query = 100;
        }
        UI.render(text, column, row);
    }
}

/*
 * name:      escapeQuery
 * purpose:   To continue the query after escape has been pressed on the
 * client's computer
 * arguments: an integer, which should be equal to the ESC ASCII key.
 * returns:   the ASCII number of the query number chosen next, or 1000
 * if the user wishes to quit. 
 * effects:   none
 * note:      none
 */
int Editor::escapeQuery(int query){
    query = UI.getChar();
    if(query == 115){
        UI.displaySaveMessage();
        saveFunction();
    }
    if(query == 117){
        undoFunction();
    }
    if(query == 114){
        redoFunction();
    }
    if(query == 120){
        query = 1000;
        bool save = UI.savePrompt();
        if(save){
            saveFunction();
        }
        UI.close();
    }
    return query;
}

/*
 * name:      addPrintable
 * purpose:   To add a printable character
 * arguments: An integer denoting the character to be added to the text.
 * returns:   none
 * effects:   adds a character to the text, assuming that that character is
 * printable. Clears RedoStack
 * note:      none
 */
void Editor::addPrintable(int query){
    if(query >= 32 and query <= 127){
        char chars = query;
        undoStack.push(query, false, row, column);
        string convert(1, chars);
        text.at(row).insert(column, convert);
        column++;
        redoStack.clear();
    }
}

/*
 * name:      backspaceFunction
 * purpose:   deletes a printable character or newline
 * arguments: none
 * returns:   none
 * effects:   deletes the item to the left of the cursor position.
 * note:      none
 */
void Editor::backspaceFunction(){
    if(column != 0){
        undoStack.push(text.at(row).at(column - 1), true, row, column);
        text.at(row).erase(column - 1, 1);
        column--;
    }
    else if(row != 0){
        column = text.at(row - 1).size();
        text.at(row - 1).append(text.at(row));
        text.erase(text.begin() + row);
        row--;
        undoStack.push(0, true, row, column);
    }
}

/*
 * name:      saveFunction
 * purpose:   to save the given display at the time when the function is
 * called
 * arguments: none
 * returns:   none
 * effects:   Writes the contents of the text into an outstream file, which is
 * the second argument in the command line.
 * note:      none
 */
void Editor::saveFunction(){
    ofstream outstream(saveFilename);
    size_t lineNumber = 0;
    while(lineNumber != text.size()){
        outstream << text.at(lineNumber) << endl;
        lineNumber++;
    }
}

/*
 * name:      keyLeftFunction
 * purpose:   Moves the cursor one to the left
 * arguments: none
 * returns:   none
 * effects:   Moves the cursor to the previous row is column is at 0, does
 * nothing if the column and row are zero, and one to the left at all other
 * times
 * note:      none
 */
void Editor::keyLeftFunction(){
    if(column != 0){
        column--;
    }
    else if(row != 0){
        row--;
        column = text.at(row).size();
    }
    else{
        column = 0;
    }
}

/*
 * name:      keyRightFunction
 * purpose:   Moves the cursor one to the right
 * arguments: none
 * returns:   none
 * effects:   Moves the cursor to the next row is column is at the end of a 
 * line, does nothing if the column and row are at the end of the line and 
 * row, respectively and one to the right at all other times
 * note:      none
 */
void Editor::keyRightFunction(){
    if(column == text.at(row).length()){
        if(row + 1 == text.size()){
            column = text.at(row).length();
            return;
        }
        row++;
        column = 0;
    }
    else{
        column++;
    }
}

/*
 * name:      newLineFunction
 * purpose:   creates a new line
 * arguments: none
 * returns:   none
 * effects:   creates a new line wherever the cursor is
 * note:      none
 */
void Editor::newLineFunction(){
    if(column == text.at(row).length()){
        string newLine;
        vector<string>::iterator iterator = text.begin() + row + 1;
        text.insert(iterator, newLine);
    }
    else{
        string leftSubString;
        string rightSubString;
        leftSubString = text.at(row).substr(0, column);
        rightSubString = text.at(row).substr(column);
        text.at(row) = leftSubString;
        text.insert(text.begin() + row + 1, rightSubString);        
    }
    column = 0;
    row++;
    undoStack.push(0, false, row, column);
}

/*
 * name:      keyUpFunction
 * purpose:   Moves the cursor one row up
 * arguments: none
 * returns:   none
 * effects:   Moves the cursor to the previous row if it exists
 * note:      none
 */
void Editor::keyUpFunction(){
    if(row == 0 and (int) column < UI.getTerminalWidth()){
        row = 0;
        return;
    }
    else if((int) column >= UI.getTerminalWidth()){
        column -= UI.getTerminalWidth();
    }
    else if(text.at(row - 1).length() % UI.getTerminalWidth() <= column) {
        if(column > text.at(row - 1).length() % UI.getTerminalWidth()){
            column = text.at(row - 1).length();
        }
        row--;
    }
    else{
        row--;
    }
}

/*
 * name:      keyDownFunction
 * purpose:   Moves the cursor one row down
 * arguments: none
 * returns:   none
 * effects:   Moves the cursor to the next row if it exists
 * note:      none
 */
void Editor::keyDownFunction(){
    if(row + 1 == text.size() and text.at(row).length() /
     UI.getTerminalWidth() == column / UI.getTerminalWidth()){
        row = text.size() - 1;
        return;
    }
    else if(column + UI.getTerminalWidth() <= text.at(row).length()){
        column += UI.getTerminalWidth();
    }
    else if(column % UI.getTerminalWidth() > text.at(row).length() 
    % UI.getTerminalWidth()){
        column = text.at(row).length();
    }
    else if(column % UI.getTerminalWidth() > text.at(row + 1).length()){
        row++;
        column = text.at(row).length();
    }
    else{
        column = column % UI.getTerminalWidth();
        row++;
    }
}

/*
 * name:      undoFunction
 * purpose:   undoes the last series of actions done
 * arguments: none
 * returns:   none
 * effects:   undoes the last series of actions done or one iteration of a 
 * new line
 * note:      none
 */
void Editor::undoFunction(){
    if(undoStack.size() == 0){
        return;
    }
    if(undoStack.top().character == 0){
        ActionStack::Action a = undoStack.top();
        undoStack.pop();
        if(a.deleted){
            string left = text.at(a.line).substr(0, a.column);
            string right = text.at(a.line).substr(a.column);
            text.at(a.line) = left;
            text.insert(text.begin() + a.line + 1, right);
            row = a.line + 1;
            column = 0;
        }
        else{
            column = text.at(a.line - 1).size();
            text.at(a.line - 1).append(text.at(a.line));
            text.erase(text.begin() + a.line);
            row = a.line - 1;
        }
        redoStack.push(a);
        return;
    }
    bool undo = undoStack.top().deleted;
    if(not undo){
        while(undoStack.size() > 0 and not undoStack.top().deleted and
        (undoStack.top().character > 0)){
            text.at(undoStack.top().line).erase(undoStack.top().column, 1);
            column = undoStack.top().column;
            row = undoStack.top().line;
            redoStack.push(undoStack.top());
            undoStack.pop();
        }
    }
    if(undo){
        while(undoStack.size() > 0 and undoStack.top().deleted and
        (undoStack.top().character > 0)){
            text.at(undoStack.top().line).insert(text.at(undoStack.top().line)
            .begin() + undoStack.top().column - 1, undoStack.top().character);
            column = undoStack.top().column;
            row = undoStack.top().line;
            redoStack.push(undoStack.top());
            undoStack.pop();
        }
    }
}

/*
 * name:      redoFunction
 * purpose:   redoes the last series of actions done
 * arguments: none
 * returns:   none
 * effects:   redoes the last series of actions done or one iteration of a 
 * new line
 * note:      none
 */
void Editor::redoFunction(){
    if(redoStack.size() == 0){
        return;
    }
    if(redoStack.top().character == 0){
        if(redoStack.top().deleted){
            backspaceFunction();
        }
        else{
            newLineFunction();
        }
        redoStack.pop();
        return;
    }
    bool deletedAction = redoStack.top().deleted; //if deleted,
    if(deletedAction){
        while(redoStack.size() > 0 and redoStack.top().deleted == 
        deletedAction and redoStack.top().character > 0)
        {
            ActionStack::Action a = redoStack.top();
            text.at(a.line).erase(a.column, 1);
            column = a.column;
            row = a.line;
            undoStack.push(a);
            redoStack.pop();
        }
    }
    if(not deletedAction){
        while(redoStack.size() > 0 and deletedAction == 
        redoStack.top().deleted and redoStack.top().character > 0)
        {
            text.at(redoStack.top().line).insert(text.at(redoStack.top().line)
            .begin() + redoStack.top().column, redoStack.top().character);
            column = redoStack.top().column + 1;
            row = redoStack.top().line;
            undoStack.push(redoStack.top());
            redoStack.pop();
        }
    }
}