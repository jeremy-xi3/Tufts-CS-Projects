/*
 *      AVLTree.h
 *      CS15 Lab 07: AVL Trees
 *
 *      AVLTree is a class that begins as an empty AVL Tree representation and 
 *      allows for the insertion of int values. Clients can also print a visual 
 *      representation of the AVL Tree. 
 * 
 *      Note: Balancing functions must be implemented by students to get an 
 *            accurate AVL tree representation.
 *
 *      2024-03-4 Modified by Skylar Gilfeather
 *                Edited documentation 
 *      2024-10-20 Modified by Kathy Quintanilla
 *                 Edited header to comply with style guide + removed remove() 
 *                 functions because they are not used.
 *      2025-03-31 Modified by Lindsay Ulrey
 *                 Added file header and updated function contracts.
 */

#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>

using namespace std;

/*
 * Note: Defined outside of the AVLTree class so that the code in
 *       pretty_print.cpp can work with Node. This is not good abstraction–
 *       don't do this in your code!
 */
struct Node {
        int   data;
        int   height;
        Node *left;
        Node *right;
};


/* defined in pretty_print.cpp */
void printPretty(Node *root, int level, int indentSpace, ostream &out);


class AVLTree {
    public:
        AVLTree();
        ~AVLTree();

        void insert(int value);
        bool remove(int value);

        void print_tree() const;

    private:
        Node *root; /* the root of the tree (starts as nullptr) */

        /*
         * the following functions are private helper functions
         * for the public functions. We do not want to expose the
         * internals of the tree publicly, so we pass the root (and
         * other information in some cases) to the functions below
         * from the public functions.
         */
        Node *insert (Node *node, int value);
        bool  remove (Node *node, int value);
        Node *balance(Node *node);

        Node *rightRotate(Node *node);
        Node *leftRotate (Node *node); 
        int   heightDiff (Node *node);
        int   nodeHeight (Node *node);

        void postOrderDelete(Node *node);
};

#endif
