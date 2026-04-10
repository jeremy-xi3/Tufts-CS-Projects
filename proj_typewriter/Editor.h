/*
Typewriter: Editor.h
Jeremy Xie
2/17/26
Purpose: Editor is a class that allows a typewriter to run. A client is
allowed to add printable characters, move their cursor, save their progress,
undo, and redo their typing. Specifically, this is implemented through a while
loop in the run function. 
*/
#include "ActionStack.h"
#include "TextUI.h"
#include <vector>

using namespace std;

class Editor {
    public:
    Editor(string filename);
    Editor(string filename, string logfile);
    ~Editor();
    void run();

    private:
    TextUI UI;
    vector<string> text;
    ActionStack undoStack;
    ActionStack redoStack;
    size_t column;
    size_t row;
    string saveFilename;
    int escapeQuery(int query);
    void saveFunction();
    void backspaceFunction();
    //Cursor movement functions
    void keyLeftFunction();
    void keyRightFunction();
    void keyUpFunction();
    void keyDownFunction();
    //add characters
    void addPrintable(int query);
    //undo/redo
    void undoFunction();
    void redoFunction();
    void newLineFunction();
};