/*
proj_Zap: HuffmanCoder.h
Jeremy Xie
3/25/26
Purpose: HuffmanCoder contains two public functions, encoder and decoder. 
Encoder takes in an input file that contains a text and outputs it in the
form of a binary string and a serialized HuffmanTree. On the other hand,
decoder takes in an input file that contains a binary string, which represents
the encoded text, and a serialized HuffmanTree, which contains the code in 
which the binary string was written. Together, these two functions combine to
create a way to encode and decode a given text. 
*/
#ifndef _HUFFMAN_CODER
#define _HUFFMAN_CODER

#include <string>
#include <istream>
#include <unordered_map>
#include "HuffmanTreeNode.h"
#include "ZapUtil.h"

using namespace std;
class HuffmanCoder {

    public:
    void encoder(const string &inputFile, const string &outputFile);
    void decoder(const string &inputFile, const string &outputFile);

    private:
    unordered_map<char, int> count_freqs(istream &text, string &code);
    string serialize_tree(HuffmanTreeNode *root);
    HuffmanTreeNode *deserialize_tree(const string &s);
    HuffmanTreeNode *deserialize_helper(const string &s, int &index);
    HuffmanTreeNode *treeConstructor(unordered_map<char, int> characters);
    unordered_map<char, string> char_codes(HuffmanTreeNode* tree);
    void char_codes_helper(HuffmanTreeNode* node, string code, 
    unordered_map<char, string> &map);
    string recurse_code(HuffmanTreeNode* node, string input);
    void treeCleaner(HuffmanTreeNode* node);
};

#endif