/*
proj_Zap: unit_tests.h
Jeremy Xie
3/25/26
Purpose: This file contains tests for the phaseOne functions.
*/
#include "phaseOne.h"
#include <cassert>
#include <sstream>
#include <iostream>
using namespace std;

void count_freq_test_basic(){
    string test = "banana";
    istringstream file(test);
    count_freqs(file);
}

void count_freq_test_advanced(){
    string test = "One \n four five can't think of anything \n";
    istringstream file(test);
    count_freqs(file);
}

void count_freqs_empty_test(){
    istringstream file("");
    count_freqs(file);
}


void serialize_tree_test_basic(){
    HuffmanTreeNode* test1 = new HuffmanTreeNode('f');
    HuffmanTreeNode* test2 = new HuffmanTreeNode('c');
    HuffmanTreeNode* root = new HuffmanTreeNode(test1, test2);
    string test_string = serialize_tree(root);
    delete test1;
    delete test2;
    delete root;
    assert(test_string == "ILfLc");
}

void serialize_tree_test_advanced(){
    HuffmanTreeNode test1('1');
    HuffmanTreeNode test2('2');
    HuffmanTreeNode test3('3');
    HuffmanTreeNode test4('4');
    HuffmanTreeNode test5('5');
    HuffmanTreeNode root1(&test1, &test2);
    HuffmanTreeNode middle1(&root1, &test3);
    HuffmanTreeNode root2(&test4, &test5);
    HuffmanTreeNode middle2(&middle1, &root2);
    assert(serialize_tree(&middle2) == "IIIL1L2L3IL4L5");
}

void deserialize_tree_test_basic(){
    string test = "ILaLb";
    HuffmanTreeNode* Test_Node = deserialize_tree(test);
    assert(Test_Node->get_val() == '\0');
    // cout << Test_Node->get_right()->get_val() << endl;
    assert(Test_Node->get_left()->get_val() == 'a');
    assert(Test_Node->get_right()->get_val() == 'b');
}

void deserialzie_tree_test_advacned(){
    HuffmanTreeNode* Test_Node = deserialize_tree("IIIL1L2L3IL4L5");
    assert(serialize_tree(Test_Node) == "IIIL1L2L3IL4L5");
}

void deserialize_tree_null_test(){
    HuffmanTreeNode* Test_Node = deserialize_tree("");
    // assert(Test_Node == NULL);
}