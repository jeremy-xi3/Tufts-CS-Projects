/*
proj_Zap: phaseOne.cpp
Jeremy Xie
3/25/26
Purpose: This file contains an implementation for the functions required in
the phase one submission. 
*/

#include "phaseOne.h"
#include <iostream>
using namespace std;

/*
 * name:      count_freqs
 * purpose:   Counts the amount of times a character shows up in a text and
 * returns the results using the cout outstream.
 * arguments: An instream of text containing the chosen text.
 * returns:   None
 * effects:   Creates a message in cout.
 * other:     none
 */
void count_freqs(std::istream &text){
    char read;
    unordered_map<char, int> map{};
    while(text.get(read)){
        unordered_map<char, int>::const_iterator got = map.find(read);
        if(got == map.end()){
            map[read] = 1;
        }
        else{
            map[read]++;
        }
    }
    for(auto& x: map){
        cout << x.first << ": " << x.second << endl;
    }
}

/*
 * name:      serialize_tree
 * purpose:   translates a HuffmanTreeNode and its children into a string
 * which contains the same information in a preorder traversal order. 
 * arguments: The root of the HuffmanTree.
 * returns:   A string with the HuffmanTree's information.
 * effects:   none
 * other:     none
 */
string serialize_tree(HuffmanTreeNode *root){
    string submit;
    if(root == nullptr) return nullptr;
    if(root->is_leaf()){
        submit.push_back('L');
        submit.push_back(root->get_val());
    }
    else{
        submit.push_back('I');
        submit.insert(submit.size(), serialize_tree(root->get_left()));
        submit.insert(submit.size(), serialize_tree(root->get_right()));
    }
    return submit;
}

/*
 * name:      derserialize_tree
 * purpose:   takes in a string that contains the information of a Huffman
 * Tree in a preorder traversal order and converts it back into a Huffman Tree
 * arguments: A string with the Huffman Tree in a preorder traversal order.
 * returns:   The root of a Huffman Tree of the newly created tree.
 * effects:   None
 * other:     None
 */
HuffmanTreeNode *deserialize_tree(const std::string &s){
    int index = 0;
    if(s == "") {
        return nullptr;
    }
    HuffmanTreeNode* Node = deserialize_helper(s, index);
    return Node;
}

/*
 * name:      derserialize_helper
 * purpose:   Assists the deserialize_tree function by recursing through the
 * given string.
 * arguments: An integer containing The current position of the iterator in
 * the string and the original string. 
 * returns:   A Node in the Huffman Tree. 
 * effects:   None
 * other:     None
 */
HuffmanTreeNode *deserialize_helper(const std::string &s, int &index){
    if(s[index] == 'L'){
        index++;
        HuffmanTreeNode* Node = new HuffmanTreeNode(s[index]);
        return Node;
    }
    if(s[index] == 'I'){
        index++;
        HuffmanTreeNode* Node = new HuffmanTreeNode('\0');
        Node->set_left(deserialize_helper(s, index));
        Node->set_right(deserialize_helper(s, index));
        return Node;
    }
    else{
        index++;
        return deserialize_helper(s, index);
    }
}