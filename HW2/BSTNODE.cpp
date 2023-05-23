/**
* Title: Binary Search Trees
* Author : Yassin Younis
* ID: 22101310
* Section : 2
* Homework : 2
*/


#include "BSTNODE.h"



BSTNode::BSTNode():value(0), leftChild(nullptr), rightChild(nullptr) {}

BSTNode::BSTNode(int value): value(value), leftChild(nullptr), rightChild(nullptr) {}

BSTNode::BSTNode(int value, BSTNode *rightChild, BSTNode *leftChild) : value(value), rightChild(rightChild),
leftChild(leftChild) {}

BSTNode::~BSTNode() = default;

int BSTNode::getNoOfChildren() {
    if (leftChild == nullptr && rightChild == nullptr) return 0;
    else if (leftChild != nullptr && rightChild != nullptr) return 2;
    else return 1;
}


