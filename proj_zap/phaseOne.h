/*
proj_Zap: phaseOne.h
Jeremy Xie
3/25/26
Purpose: phaseOne contains 3 main functions, count_freqs, serialize_tree, and
deserialize_tree. These functions will provide the groundwork for an
implementation of the actual zap program, where count_freqs counts the
frequencies of each character, serialize_tree turns a HuffmanTreeNode and its
children into a string, and deserialize_tree turns a string into a Huffman
tree. 
*/
#ifndef __PHASEONE_H
#define __PHASEONE_H

#include <istream>
#include <string>
#include <unordered_map>
#include "HuffmanTreeNode.h"

void count_freqs(std::istream &text);
std::string serialize_tree(HuffmanTreeNode *root);
HuffmanTreeNode *deserialize_tree(const std::string &s);
HuffmanTreeNode *deserialize_helper(const std::string &s, int &index);
#endif