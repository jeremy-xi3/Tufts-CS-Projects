/*
 * evil.cpp
 * CS15 —— Lab 03: make, diff
 *
 * Driver file for Lab03. Sets the grades of Students on a roster to 0.
 *
 */

#include <iostream>

#include "roster.h"

using namespace std;

/* 
 * main
 * Purpose:     Professor Evil's main function to change the student grades!
 * Parameters:  int argc     - number of command line arguments
 *              char *argv[] - list of command line arguments
 * Returns:     int 0        - representing the successful exit of the program
 */
int main(int argc, char *argv[])
{
        if (argc < 2) {
                cout << "Usage:  ./evil [filename]" << endl;
                return 1;
        }
        Roster r;
        r.do_evil(argv[1]);

        return 0;
}
