//
//  BST.h
//

#ifndef BST_h
#define BST_h

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum RotationType {ZIG, ZAG};


/* A Binary Search Tree node */
struct Node
{
    int key;    // the key stored by this node
    Node *left;   // the left child of this node
    Node *right;  // the right child of this node
};


/**
 * Implements a Binary Search Tree keyed by Integers
 */
class BST{
public:
    /* constructs an empty Binary Search Tree */
    BST();
    
    /* constructs a one-node Binary Search Tree with the given key */
    BST(int num);
    
    /* constructs a Binary Search Tree by repeatedly inserting ints in <nums>
     in the order they appear in the vector */
    BST(vector<int>& nums);
    
    /* insert num as a new key to the BST */
    void insert(int num);
    
    /* return the BST rooted at this node as a human-readable string */
    string print();
    
private:
    /* insert num as a new key to the BST at node 'leaf' */
    void insert(int num, Node *leaf);    
    
    /* return the BST rooted at leaf as a human-readable string,
     indented by <depth> characters */
    string print(Node *leaf, int depth);
    
    /* return a string of <depth> spaces */
    string RepeatChar(int depth);
    
public:
    Node *root;
};


/**
 * Represents one rotation (ZIG or ZAG) around one key in a Binary Search Tree
 */
class Rotation{
public:
    /* constructs a rotation of type rot on key=num */
    Rotation(int num, RotationType rot);
    
    /* return A human-readable description of the rotation */
    string print();
    
private:
    int myKey;         // the key that is at the root of the rotation being performed
    RotationType myRot;    // the type of rotation being performed
};


#endif /* BST_h */
