/*
proj_Zap: main.cpp
Jeremy Xie
3/26/26
Purpose: This file contains the main function for zap and allows the program
to run.
*/
#include <iostream>
#include "HuffmanCoder.h"

using namespace std;

/*
 * name: main
 * purpose: Allows the program to run
 * arguments: The amount of arguments given on the command line and an array
 * containing those arguments. 
 * returns: An integer, usually 0, when the program finishes running.
 * effects: Either encodes or decodes a text, or provides an error message
 * other: Must take in exactly four command line arguments, have the second
 * argument be either "zap" or "unzap", and have the third command line 
 * provide a valid input file. 
 */
int main(int argc, char *argv[]){
    if(argc != 4 or (string(argv[1]) != "zap" and string(argv[1]) != "unzap")){
        cerr << "Usage: ./zap [zap | unzap] inputFile outputFile" << endl;
        return(EXIT_FAILURE);
    }
    HuffmanCoder submit;
    if(string(argv[1]) == "zap"){
        submit.encoder(argv[2], argv[3]);
    }
    else{
        submit.decoder(argv[2], argv[3]);
    }
}