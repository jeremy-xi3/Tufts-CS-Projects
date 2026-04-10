/*
 *      BTree.h
 *      CS15 Lab 06: Tree Traversals
 *
 *      The BTree class is a simple class that represents a Binary Tree of integer 
 *      values. Clients can insert integers and print different order traversals to a
 *      given output!
 *
 *      2025-03-31 Modified by Lindsay Ulrey
 *                 Updated documentation.
 */

#ifndef BTREE_H
#define BTREE_H
 
#include <iostream>

using namespace std;
 
class BTree {
    public:
        BTree();
        ~BTree();
 
        void insert(int v);
 
        void inOrder   (ostream &out) const;
        void preOrder  (ostream &out) const;
        void levelOrder(ostream &out) const;
 
        void postOrderDelete();
 
    private:
        struct BTNode {
            int     value;
            BTNode *left;
            BTNode *right;
        };
 
        BTNode *root; /* the root of the tree (starts as nullptr) */
 
        BTNode *newBTNode(int v);
        BTNode *newBTNode(int v, BTNode *left, BTNode *right);
 
        BTNode *insert(BTNode *curr, int v);

        void inOrder   (BTNode *curr, ostream &out) const;
        void preOrder  (BTNode *curr, ostream &out) const;
        void levelOrder(BTNode *curr, ostream &out) const;

        void postOrderDelete(BTNode *curr);
};

#endif
