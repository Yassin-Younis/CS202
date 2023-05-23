/**
* Title: Binary Search Trees
* Author : Yassin Younis
* ID: 22101310
* Section : 2
* Homework : 2
*/


#ifndef INC_202_2_BST_H
#define INC_202_2_BST_H
#include "BSTNODE.h"


class BST {
public:
    BST();
    ~BST();
    void insertItem(int key);
    void deleteItem(int key);
    int* inorderTraversal(int& length);
    bool hasSequence(int* seq, int length);
    int size;
private:
    BSTNode* headNode;
    void insertItem(int key, BSTNode*& currentHead);
    void deleteItem(int key, BSTNode*& currentHead);
    void getLeftmost(BSTNode*& currentHead, int& val);
    void inorderTraversal(int length, const BSTNode *currentNode, int *index, int *res);
    void hasSequence(int *seq, int length, const BSTNode *currentNode, int *sequenceCounter);
};


#endif //INC_202_2_BST_H
