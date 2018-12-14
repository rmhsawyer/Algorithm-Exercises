// Minghe Ren U84996581
//
//  MyBST.cpp
//  bst_transform
//

#include "MyBST.h"

// Global variables
std::vector<int> traverse;
vector<Rotation> result;


/**
 * Search the route to the parent of certain node with value key, 1 means go left subtree, 2 means go right subtree
 * Returns a vector of numbers indicating which route to go
 */
std::vector<int> MyBST::search(Node* leaf, int key)
{   
    //cout<< leaf->key<<endl;
    if (leaf->left != NULL && leaf->left->key == key){
        return traverse;  
    }

    if (leaf->right != NULL && leaf->right->key == key) 
        return traverse;
    if (leaf->key < key){
        traverse.push_back(2);
        return search(leaf->right, key); 
    }
    if ( leaf->key > key){
        traverse.push_back(1);
        return search(leaf->left, key); 
    }

}

/**
 * Bring a certain key in a tree up to root
 */
void MyBST::Bringup(Node* leaf, int key){

       int rootvalues = leaf->key;
        std::vector<int> v = search(leaf,key);
        traverse.clear(); 

        //Case that the parent of key is root
        if(leaf->left != NULL){
            if(v.empty() && leaf->left->key == key){
                Rotation rotations(leaf->key,ZIG);
                result.push_back(rotations);

                root = rotateRight(root);
                return;
            }
        }
        if(root->right != NULL){
            if(v.empty() && root->right->key == key){
                Rotation rotations(root->key,ZAG);
                result.push_back(rotations);
                root = rotateLeft(root);
                return;
            }
        }
        Node* temp = leaf;

        //Case that the parent of key is not root
        for(int i = 0;i<v.size();i++){
            if(v[0] == 1){
                temp= temp->left;
            }else
                temp = temp->right;
        }
        
        for(int i = 0;i<v.size()-1;i++){
            if(v[0] == 1)
                leaf = leaf->left;
            else
                leaf = leaf->right;
        }
        if(rootvalues >key){
            if(v[v.size()-1] == 1){
                Rotation rotations(temp->key,ZIG);
                result.push_back(rotations);
                leaf->left = rotateRight(temp);
            }else
            {
                Rotation rotations(temp->key,ZIG);
                result.push_back(rotations);
                leaf->right = rotateRight(temp);
            }
        }
        if(rootvalues <key){
            if(v[v.size()-1] == 1){
                Rotation rotations(temp->key,ZAG);
                result.push_back(rotations);
                leaf->left = rotateLeft(temp);
            }
            else{
                Rotation rotations(temp->key,ZAG);
                result.push_back(rotations);
                leaf->right = rotateLeft(temp);
            }
        }

        return;

}

/**
 * Computes how to transform this MyBST into the target MyBST using rotations.
 * Returns a vector of rotations indicating which rotations around which nodes
 * must be performed to transform this into the target.
 *
 * IMPORTANT: We want to transform T1 into T2 so the call should look like
 * rotations = t1.transform(t2)
 */
vector<Rotation> MyBST::transform(MyBST target) {
    int T2root = target.root->key;

    //Find the root of tree2 in tree1 and bring it up to root
    while(root->key != T2root){
        Bringup(root, T2root);
    }

    //Shape the left subtree
    Node* temp = target.root;
    while( root->left != NULL && root->left->key != temp->left->key){
        root = root->left;
        temp = temp->left;
        T2root = temp->key;
        
        string result1 = print();
        while(root->key != T2root){
            Bringup(root, T2root);
        }
    }
    //Shape the right subtree
    temp = target.root;
    while( root->right != NULL && root->right->key != temp->right->key){
        root = root->right;
        temp = temp->right;
        T2root = temp->key;
        
        string result1 = print();
        while(root->key != T2root){
            Bringup(root, T2root);
        }

    }
    return result;
}


Node* MyBST::rotateRight(Node* Q)
{
    Node* P = Q->left;
    Q->left = P->right;
    P->right = Q;
    return P;
}

Node* MyBST::rotateLeft(Node* P)
{
    Node* Q = P->right;
    P->right = Q->left;
    Q->left = P;
    return Q;
}
