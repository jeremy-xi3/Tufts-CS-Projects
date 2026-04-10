#include "processing.h"

string stripNonAlphaNum(string input) {
    while(input.at(0) < 48 or (input.at(0) > 57 and input.at(0) < 65) or 
    (input.at(0) > 90 and input.at(0) < 97) or input.at(0) > 122){
        input.erase(input.begin());
    }

    while(input.back() < 48 or (input.back() > 57 and input.back() < 65) or 
    (input.back() > 90 and input.back() < 97) or input.back() > 122){
        input.pop_back();
    }
    return input;
}

void traverseDirectory(string directory) {
    FSTree directory_tree(directory); 

    // calls recursive helper function
    traverseDirectoryHelper(directory_tree.getRoot(), 0);
}

void traverseDirectoryHelper(DirNode* node, int depth) {
    // Base Case
    if (node->isEmpty()) return;

    // Recursive Case, continues exploring into each subdirectory
    if (node->hasSubDir()) {
        for (int i = 0; i < node->numSubDirs(); i++) {
            traverseDirectoryHelper(node->getSubDir(i), ++depth);
        }
    } else if (node->hasFiles()) { // If no subdirectories, print files
        for (int i = 0; i < node->numFiles(); i++) {
            cout << node->getName();
        }
    }
}