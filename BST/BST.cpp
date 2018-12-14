//
//  bst.cpp
//

#include "BST.h"

/* constructs an empty Binary Search Tree */
BST::BST()
{
    root = nullptr;
}
    
/* constructs a one-node Binary Search Tree with the given key */
BST::BST(int num)
{
    root = new Node;
    root->key = num;
    root->left = nullptr;
    root->right = nullptr;
}
    
/* constructs a Binary Search Tree by repeatedly inserting ints in <nums>
   in the order they appear in the vector */
BST::BST(vector<int>& nums)
{
    root = new Node;
    root->key = nums[0];
    root->left = nullptr;
    root->right = nullptr;
    for (int i=1; i<nums.size(); i++)
        insert(nums[i]);
}
    
/* insert num as a new key to the BST */
void BST::insert(int num)
{
    if(root == nullptr){
        root = new Node;
        root->key = num;
        root->left = nullptr;
        root->right = nullptr;
    } else {
        insert(num, root);
    }
}


/* insert num as a new key to the BST at node 'leaf' */
void BST::insert(int num, Node *leaf)
{
    if (num > leaf->key) // insert to the right
    {
        if (leaf->right == nullptr)
        {
            leaf->right = new Node;
            leaf->right->key = num;
            leaf->right->left = nullptr;
            leaf->right->right = nullptr;
        }
        else
            insert(num, leaf->right);
    }
    else   // insert to the left
    {
        if (leaf->left == nullptr)
        {
            leaf->left = new Node;
            leaf->left->key = num;
            leaf->left->left = nullptr;
            leaf->left->right = nullptr;
        }
        else
            insert(num, leaf->left);
    }
}

/* return the BST rooted at this node as a human-readable string */
string BST::print()
{
    return print(root, 0);
}
    
/* return the BST rooted at leaf as a human-readable string,
   indented by <depth> characters */
string BST::print(Node *leaf, int depth)
{
    string result = "";
    
    result.append(to_string(leaf->key)); // output the key
    result.append("\n");
        
    if (leaf->left != nullptr)
    {
        result.append(RepeatChar(depth));
        result.append("L");
        result.append(print(leaf->left, depth+1));
    }
    if (leaf->right != nullptr)
    {
        result.append(RepeatChar(depth));
        result.append("R");
        result.append(print(leaf->right, depth+1));
    }
        
    return result;
}
    
/* return a string of <depth> spaces */
string BST::RepeatChar(int depth)
{
    string result = "";
        
    for (int i=0; i<depth; i++)
        result.append("-");
        
    return result;
}


/**
 * Represents one rotation (ZIG or ZAG) around one key in a Binary Search Tree
 */
Rotation::Rotation(int num, RotationType rot)
{
    myKey = num;
    myRot = rot;
}

/* return A human-readable description of the rotation */
string Rotation::print()
{
    string result="";
    
    switch (myRot)
    {
        case ZIG:
            result="ZIG";
            break;
        case ZAG:
            result="ZAG";
            break;
    }
    result.append(" on ");
    result.append(to_string(myKey));
    
    return result;
}

