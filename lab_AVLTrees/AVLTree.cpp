/*
 *      AVLTree.cpp
 *      CS15 Lab 07: AVL Trees
 *
 *      Implementation of AVLTree.h.
 *
 *      2024-03-4 Modified by Skylar Gilfeather
 *                Rewrote documentation 
 *                Added ASCII AVL Trees to leftRotate() and rightRotate()
 *                Added and renamed local variables in leftRotate() and
 *                    rightRotate() to provide a template to students.
 *                Moved increment of node's height out of leftRotate() and
 *                    rightRotate() and into insert(), so that remove()
 *                    can properly update height with these rotation methods.
 *      2024-10-20 Modified by Kathy Quintanilla
 *                 Updated header + removed remove() functions because unused.
 *      2025-03-31 Modified by Lindsay Ulrey
 *                 Edited to follow CS15 style guide.
 *                 Added comments for clarity.
 *                 Simplified deleteNode() function.
 */

#include <iostream>

#include "AVLTree.h"

using namespace std;

/****************** node struct functions *****************/

/* newNode()
 *    Purpose: Creates a new AVL Tree Node on the heap.
 * Parameters: int data    - integer data stored in the Node
 *             int height  - height of the Node, i.e. max number of edges to a
 *                           leaf
 *             Node *left  - left child Node of the Node, or nullptr
 *             Node *right - right child Node of the Node, or nullptr
 *    Returns: Node *      - a pointer to a new Node on the heap
 */
static Node *newNode(int data, int height, Node *left, Node *right)
{
    Node *np = new Node(); /* allocates memory on heap */

    np->data   = data;
    np->height = height;
    np->left   = left;
    np->right  = right;

    return np;
} 


/* newNode()
 *    Purpose: Creates a new AVL Tree Node on the heap. Creates a 'leaf' Node
 *             with a height of 0 and no children.
 * Parameters: int data - integer data stored in the Node
 *    Returns: Node *   - a pointer to a new Node on the heap.
 */
static Node *newNode(int data)
{
    return newNode(data, 0, nullptr, nullptr);
}


/* deleteNode()
 *    Purpose: Deletes an AVL Tree Node on the heap.
 * Parameters: Node *node - node on the heap to delete
 *    Returns: None
 * 
 * Note: It is important to ensure that node's left and right pointers
 *       are null before deleting, as those nodes will no longer be
 *       accessible.       
 */
static void deleteNode(Node *node)
{
    delete node;            /* frees memory on heap */
}


/****************** AVLTree functions *****************/

/* Constructor
 *    Purpose: Creates a new, empty AVLTree.
 * Parameters: None
 *    Returns: N/A
 */
AVLTree::AVLTree()
{
    root = nullptr;
}


/* Destructor
 *    Purpose: Free any allocated memory from this AVL Tree.
 * Parameters: None
 *    Returns: N/A
 */
AVLTree::~AVLTree()
{
    /* Walk tree in post-order traversal and delete */
    postOrderDelete(root);
    root = nullptr;   /* Not really necessary, since the tree is going 
                        * away, but might want to guard against someone
                        * using a pointer after deleting 
                        */
}


/* postOrderDelete()
 *    Purpose: Delete the subtree rooted at node using a post-order traversal.
 * Parameters: Node *node - node at the root of the subtree to delete
 *    Returns: None
 * 
 * Note: Delete the left subtree, right subtree, and then the node itself
 */
void AVLTree::postOrderDelete(Node *node)
{
    if (node != nullptr) {
            postOrderDelete(node->left);
            postOrderDelete(node->right);
            deleteNode(node);
    }
}


/* insert()
 *    Purpose: Insert the value into the AVL Tree.
 * Parameters: int value - interger value to insert into the tree
 *    Returns: None
 *       Note: calls a recursive insert()
 */
void AVLTree::insert(int value)
{
    root = insert(root, value);
}


/* insert()
 *    Purpose: Insert the value into the subtree rooted at node.
 * Parameters: Node *node   - currently visited Node
 *             int value    - interger value to insert into the tree
 *    Returns: Node *       - the Node now in the position of node in the AVL 
 *                            tree: node, if no rotations were performed, or 
 *                            one of node's children, if a rotation was 
 *                            performed.
 * 
 * Note: Recursively traverse the AVL tree to the leaf position where value 
 *       should be inserted, and inserts it as a new Node.
 *       Balance the subtree rooted at node, if necessary, and return the Node 
 *       now in node's position.
 */
Node *AVLTree::insert(Node *node, int value)
{
    /* node is an empty position, a child of a leaf node: insert here! */
    if (node == nullptr) {
        return newNode(value);
    } 
    /* if value already exists in the AVL Tree, do not insert */
    else if (value == node->data) {
        return node;
    }
    /* traverse to and insert value somewhere in node's left subtree */
    else if (value < node->data) {
        node->left = insert(node->left, value);
    } 
    /* traverse to and insert value somewhere in node's right subtree */
    else if (value > node->data) {
        node->right = insert(node->right, value);
    }
    
    /* AVL Tree rebalancing starts */
    node->height = 1 + max(nodeHeight(node->left), 
        nodeHeight(node->right));
    
    Node *newNode = balance(node);
    /* AVL Tree rebalancing ends */
    
    return newNode;
}


/* balance()
 *    Purpose: Balance the AVL Tree to AVL standards.
 * Parameters: Node *node - node at the root of the subtree to rebalance
 *    Returns: Node *     - the Node now in the position of node in the AVL 
 *                          tree: node, if no rotations were performed, or one
 *                          of node's children, if a rotation was performed.
 * 
 * Note: Check if the subtree rooted at node is out of balance. Then, rebalance
 *       the subtree rooted at node if necessary, by calling leftRotate() and 
 *       rightRotate() to perform rotations.  
 */
Node *AVLTree::balance(Node *node) 
{
    int balanceFactor = heightDiff(node);
    
    cout << balanceFactor << endl;
    /* TODO: evaluate the balance factor to see if node is balanced.
     *       If not, handle the case: LL, LR, RR, or RL! 
     */
    // if(balanceFactor >= 2){

    // }
    if(balanceFactor == -2){
        leftRotate(node);
    }


    return node;
}


/* rightRotate()
 *    Purpose: Perform a single right rotation on the subtree rooted at node.
 * Parameters: Node *node - node at the root of the subtree to rebalance
 *    Returns: Node *     - the Node now in the position of node in the AVL 
 *                          tree: node, if no rotations were performed, or one 
 *                          of node's children, if a rotation was performed.  
 * 
 * Visual: A single right rotation should convert this subtree:
 * 
 *              [ node ]
 *              /       \
 *        [ leftChild ] [ rightChild ]
 *         /         \
 *   [ llTree ] [ lrTree ]
 * 
 * into this subtree:
 * 
 *               [ leftChild ]
 *                /          \
 *         [ llTree ]      [ node ]
 *                         /      \ 
 *                  [ lrTree ] [ rightChild ]
 */
Node *AVLTree::rightRotate(Node *node) 
{ 
    Node *leftChild  = node->left;
    Node *rightChild = node->right;
    
    Node *llTree = node->left->left;
    Node *lrTree = node->left->right;
    
    Node *placeholder = node;
    node = leftChild;
    node->right = placeholder;
    node->right->left = lrTree;
    node->right->right = rightChild;
    /* TODO: perform a single right rotation on node! */
    
    /* TODO: update heights of nodes that have moved! */
    node->height--;
    llTree->height++;
    rightChild->height--;
    leftChild->height++;
    return node; /* TODO: return the Node that has replaced node! */
} 


/* leftRotate()
 *    Purpose: Perform a left rotation on the subtree rooted at node.
 * Parameters: Node *node - node at the root of the subtree to rebalance
 *    Returns: Node *     - the Node now in the position of node in the AVL 
 *                          tree: node, if no rotations were performed, or one
 *                          of node's children, if a rotation was performed.  
 * 
 * Visual: A single left rotation should convert this subtree:
 * 
 *              [ node ]
 *              /       \
 *        [ leftChild ] [ rightChild ]
 *                        /         \
 *                  [ rlTree ] [ rrTree ]
 * 
 * into this subtree:
 * 
 *              [ rightChild ]
 *                /       \
 *           [ node ]   [ rrTree ]
 *          /       \         
 *   [ leftChild ]  [ rlTree ]
 */
Node *AVLTree::leftRotate(Node *node) 
{ 

    Node *leftChild  = node->left;
    Node *rightChild = node->right;
    
    Node *rrTree = node->right->right; 
    Node *rlTree = node->right->left;
    
    rightChild->left = node;
    rightChild->right = rrTree;
    // rightChild->left->left = leftChild;
    rightChild->left->right = rlTree;

    // rightChild->left->left->height = 0;
    rightChild->height = 2;
    rightChild->left->height = 1;
    rightChild->right->height = 1;

    return rightChild;
}
/* heightDiff()
 *    Purpose: Calculate the difference between the height of node's left child
 *             and the height of node's right child.
 * Parameters: Node *node - node to calculate the height difference for its 
 *                          children
 *    Returns: int        - the integer height difference: greater than 0, if 
 *                          node's left subtree is heavier, and less than 0, if
 *                          node's right subtree is heavier.
 */
int AVLTree::heightDiff(Node *node)
{
    int leftHeight  = nodeHeight(node->left);
    int rightHeight = nodeHeight(node->right);

    return leftHeight - rightHeight;
}


/* nodeHeight()
 *    Purpose: Returns the height of the node, or -1 if the node doesn't exist.
 * Parameters: Node *node - node to retrieve the height of
 *    Returns: int        - the node's set height, or -1 is the node doesn't 
 *                          exist
 */
int AVLTree::nodeHeight(Node *node) 
{ 
    if (node == nullptr) {
        return -1; 
    }
    return node->height; 
} 


/* print_tree()
 *    Purpose: Prints the AVL tree prettily.
 * Parameters: None
 *    Returns: None
 * 
 * Note: calls helper function in pretty_print.cpp
 */
void AVLTree::print_tree() const
{
    printPretty(root, 1, 0, cout);
}
