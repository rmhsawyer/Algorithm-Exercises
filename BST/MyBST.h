// Minghe Ren U84996581

#ifndef __MYBST_H__
#define __MYBST_H__

#include "BST.h"

class MyBST : public BST
{
    public:
        MyBST(){};
        vector<Rotation> transform(MyBST target);
        std::vector<int> search(Node* root, int key);
        void Bringup(Node* root,int key);
    private:
        Node* rotateRight(Node* Q);
        Node* rotateLeft(Node* P);
};

#endif /* __MYBST_H__*/