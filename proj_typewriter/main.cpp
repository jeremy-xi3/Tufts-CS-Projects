/*
Typewriter: main.cpp
Jeremy Xie
2/17/26
Purpose: This file contains a way to run typewriter by constructing it and
starting the query loop. 
*/
#include "Editor.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc == 1 or argc > 3) {
        cerr << "Usage: ./typewriter textFile [logFile]" << endl;
        exit(1);
    }
    if(argc == 2){
        Editor textEditor(argv[1]);
        textEditor.run();
    }
    else if(argc == 3){
        Editor textEditor(argv[1], argv[2]);
        textEditor.run();
    }
    return 0;
}