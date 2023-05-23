/**
* Title: Binary Search Trees
* Author : Yassin Younis
* ID: 22101310
* Section : 2
* Homework : 2
*/


#ifndef INC_202_2_BSTNODE_H
#define INC_202_2_BSTNODE_H


class BSTNode{
public:
    BSTNode();
    ~BSTNode();
    BSTNode(int value);
    BSTNode(int value ,BSTNode* rightChild, BSTNode* leftChild);
    int getNoOfChildren();

private:
    int value;
    BSTNode* rightChild;
    BSTNode* leftChild;

    friend class BST;
};



#endif