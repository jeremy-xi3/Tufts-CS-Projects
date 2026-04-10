/*
proj_Zap: HuffmanCoder.cpp
Jeremy Xie
3/26/26
Purpose: This file contains an implementation for the functions in
the HuffmanCoder class. 
*/

#include "HuffmanCoder.h"
#include <fstream>
#include <queue>
#include <iostream>

using namespace std;

/*
 * name: encoder
 * purpose: Encodes a text given by a string and saves the result in a given
 * output file.
 * arguments: The name of the input file containing the text and the name of
 * the output file.
 * returns: none
 * effects: creates/modifies an output file with the encoded code
 * other: none
 */
void HuffmanCoder::encoder(const std::string &inputFile,
    const std::string &outputFile){
    ifstream infile(inputFile);
    ofstream outfile(outputFile);
    if(infile.fail()) {
        throw runtime_error("Unable to open file " + inputFile);
    }
    string text;
    unordered_map<char, int> order = count_freqs(infile, text);
    HuffmanTreeNode *tree = treeConstructor(order);
    unordered_map<char, string> codes = char_codes(tree);
    string decoded;
    for(int i = 0; i < int(text.length()); i++){
        decoded += codes[text[i]];
    }
    string submit_serialize_tree = serialize_tree(tree);
    cout << "Success! Encoded given text using " << decoded.length() << 
    " bits." << endl;
    writeZapFile(outputFile, submit_serialize_tree, decoded);
    treeCleaner(tree);
}

/*
 * name: decoder
 * purpose: Decodes a text given by an input file and saves the result in a
 * given output file.
 * arguments: The name of the input file containing the character codes of 
 * the text and a serialized Huffman tree, and the name of the output file.
 * returns: none
 * effects: creates/modifies an output file with the original text
 * other: none
 */
void HuffmanCoder::decoder(const string &inputFile, const string &outputFile){
    pair<string, string>input = readZapFile(inputFile);
    HuffmanTreeNode *deserializedInputTree = deserialize_tree(input.first);
    string character_code = recurse_code(deserializedInputTree, input.second);
    ofstream outFile(outputFile);
    outFile << character_code;
    treeCleaner(deserializedInputTree);
}

/*
 * name: treeCleaner
 * purpose: Deletes a huffman tree in a postorder traversal.
 * arguments: The pointer to the root node
 * returns: none
 * effects: clears a tree and its nodes from memory. 
 * other: none
 */
void HuffmanCoder::treeCleaner(HuffmanTreeNode* node){
    if(node == nullptr){
        return;
    }
    treeCleaner(node->get_left());
    treeCleaner(node->get_right());
    delete node;
}

/*
 * name: recurse_code
 * purpose: Returns the original string given in the input file.
 * arguments: The name of the input file containing the text and the name of
 * the output file.
 * returns: none
 * effects: creates/modifies an output file with the encoded code
 * other: none
 */
string HuffmanCoder::recurse_code(HuffmanTreeNode* node, string input){
    string submit_string = "";
    char iterate = input.at(0);
    int current = 0;
    string total = "";
    HuffmanTreeNode beginning = *node;
    while(current < int(input.length())){
        iterate = input.at(current);
        if(node->get_val() != '\0'){
            submit_string.push_back(node->get_val());
            node = &beginning;
        }
        else{
            current++;
            if(iterate == '0'){
                if(node->get_left() != nullptr){
                    node = node->get_left();
                }
                if(current == int(input.length())){
                    submit_string.push_back(node->get_val());
                }
            }
            else{
                if(node->get_right() != nullptr){
                    node = node->get_right();
                }
                if(current == int(input.length())){
                    submit_string.push_back(node->get_val());
                }
            }
        }
        if(current == int(input.length()) and node->get_val() == '\0'){
            throw runtime_error("Encoding did not match Huffman tree.");
        }
    }
    return submit_string;
}

/*
 * name:      treeConstructor
 * purpose:   Creates a Huffman tree out of the characters in an unordered map
 * arguments: An unordered map with the frequencies of characters
 * returns:   The root of a Huffman tree that contains every character in the
 * map.
 * effects:   none
 * other:     none
 */
HuffmanTreeNode *HuffmanCoder::treeConstructor(unordered_map<char, int> 
    characters){
    unordered_map<char, int>::const_iterator got = characters.begin();
    priority_queue<HuffmanTreeNode *, vector<HuffmanTreeNode *>,
    NodeComparator> my_pq;
    for (auto const& pair: characters){ //iterates through unordered map 
        if(pair.second > 0){ //and sorts by frequency
            HuffmanTreeNode *Node = new HuffmanTreeNode(pair.first, 
            pair.second);
            my_pq.push(Node);
        }
    }

    while (my_pq.size() > 1){ //combine all the trees into one
        HuffmanTreeNode* left = my_pq.top();
        my_pq.pop();
        HuffmanTreeNode* right = my_pq.top();
        my_pq.pop();
        HuffmanTreeNode* parent = new HuffmanTreeNode('\0', left->get_freq() +
        right->get_freq());
        parent->set_left(left);
        parent->set_right(right);
        my_pq.push(parent);
    }

    return my_pq.top();
}

/* 
 * name:      char_codes
 * purpose:   Creates an unordered map containing all of the characters that
 * appear in a huffman tree node and its descendants, along with the character
 * codes that go along with them. 
 * arguments: The root of the HuffmanTreeNode to be recorded
 * returns:   An unordered map containing the key for each character in
 * the tree.
 * effects:   none
 * other:     none
 */
unordered_map<char, string> HuffmanCoder::char_codes(HuffmanTreeNode* tree){
    unordered_map<char, string> submit_map;
    if(tree->get_val() != '\0'){
        submit_map[tree->get_val()] = "0";
    }
    else{
        char_codes_helper(tree->get_left(), "0", submit_map);
        char_codes_helper(tree->get_right(), "1", submit_map);
    }
    return submit_map;
}

/* 
 * name:      char_codes_helper
 * purpose:   Recurses through a HuffmanTreeNode and its descendents to create
 * a string that will represent its unique character code. 
 * arguments: The current HuffmanTreeNode, a string representing the current
 * state of the code, and the address to the unordered map where the codes and
 * characters are stored. 
 * returns:   None
 * effects:   Updates the unordered map when a character node is found and 
 * recurses to the node's children when a character node is not given in 
 * the arguments. 
 * other:     none
 */
void HuffmanCoder::char_codes_helper(HuffmanTreeNode* node, string code,
    unordered_map<char, string> &map){
    if(node->get_val() != '\0'){
        map[node->get_val()] = code;
        return;
    }
    else{
        char_codes_helper(node->get_left(), code + "0", map);
        char_codes_helper(node->get_right(), code + "1", map);
    }
}

/*
 * name:      count_freqs
 * purpose:   Counts the amount of times a character shows up in a text and
 * returns the results in an unorderedmap.
 * arguments: An instream of text containing the chosen text.
 * returns:   An unordered map containing the frequency of each character in
 * the text.
 * effects:   none
 * other:     none
 */
unordered_map<char, int> HuffmanCoder::count_freqs(std::istream &text,
     string &code){
    char read;
    unordered_map<char, int> map{};
    while(text.get(read)){
        code.push_back(read);
        unordered_map<char, int>::const_iterator got = map.find(read);
        if(got == map.end()){
            map[read] = 1;
        }
        else{
            map[read]++;
        }
    }
    return map;
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
string HuffmanCoder::serialize_tree(HuffmanTreeNode *root){
    string submit;
    if(root == nullptr) return "";
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
HuffmanTreeNode *HuffmanCoder::deserialize_tree(const std::string &s){
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
HuffmanTreeNode *HuffmanCoder::deserialize_helper(const std::string &s,
    int &index){
    if(s[index] == 'L'){
        index++;
        HuffmanTreeNode* Node = new HuffmanTreeNode(s[index]);
        index++;
        return Node;
    }
    else{ //case if current index will give an empty node
        index++;
        HuffmanTreeNode* Node = new HuffmanTreeNode('\0');
        Node->set_left(deserialize_helper(s, index));
        Node->set_right(deserialize_helper(s, index));
        return Node;
    }
}