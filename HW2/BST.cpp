
/**
* Title: Binary Search Trees
* Author : Yassin Younis
* ID: 22101310
* Section : 2
* Homework : 2
*/



#include <iostream>
#include "BST.h"

BST::BST() {
    headNode = nullptr;
    size= 0;
}
BST::~BST() {
    while (size!=0) {
        deleteItem(headNode->value);
    }
}

void BST::insertItem(int key) {
    insertItem(key, headNode);
    size++;
}


void BST::insertItem(int key, BSTNode*& currentHead) {
    if (currentHead == nullptr) {
        currentHead = new BSTNode(key);
    }
    else if (currentHead->value < key) {
        insertItem(key, currentHead->rightChild);
    }
    else {
        insertItem(key, currentHead->leftChild);
    }
}

void BST::deleteItem(int key) {
    deleteItem(key, headNode);
    size--;
}

void BST::deleteItem(int key, BSTNode *&currentHead) {
    if (currentHead->value == key) {
        int noOfChildren = currentHead->getNoOfChildren();
        if (noOfChildren == 0) {
            delete currentHead;
            currentHead = nullptr;
        }
        else if (noOfChildren == 1) {
            if (currentHead->rightChild == nullptr) {
                BSTNode* leftChild = currentHead->leftChild;
                currentHead->leftChild = nullptr; //setting to nullptr to avoid auto deletion.
                delete currentHead;
                currentHead = leftChild;
            }
            else {
                BSTNode* rightChild = currentHead->rightChild;
                currentHead->rightChild = nullptr;
                delete currentHead;
                currentHead = rightChild;
            }
        }
        else { //get leftmost key of right subtree if the node to delete has 2 children
            int leftmostVal;
            getLeftmost(currentHead->rightChild, leftmostVal);
            currentHead->value = leftmostVal;
        }
    }

    else if (currentHead->value < key) {
        deleteItem(key, currentHead->rightChild);
    }
    else {
        deleteItem(key, currentHead->leftChild);
    }
}

void BST::getLeftmost(BSTNode*& currentHead, int& val) {
    if (currentHead->leftChild == nullptr) {
        val = currentHead->value;
        BSTNode* delPtr = currentHead;
        currentHead = currentHead->rightChild;
        delPtr->rightChild = nullptr; // remove pointer to avoid deconstruction
        delete delPtr;
    }
    else getLeftmost(currentHead->leftChild ,val);
}

void BST::inorderTraversal(int length, const BSTNode* currentNode, int* index, int* res) {
    if (currentNode->leftChild != nullptr) inorderTraversal(length, currentNode->leftChild, index, res);
    res[(*index)++] = currentNode->value;
    if (currentNode->rightChild != nullptr) inorderTraversal(length, currentNode->rightChild, index, res);
}

int* BST::inorderTraversal(int &length) {
    int* res = new int[length];
    int *index = new int(0);
    inorderTraversal(length, headNode, index, res);
    delete index;
    return res;
}

void BST::hasSequence(int *seq, int length, const BSTNode* currentNode, int* sequenceCounter) {
    if (length == *(sequenceCounter)) return;

    int arrayMin = seq[0], arrayMax = seq[length-1];
    std::cout << "Current Traversal Node Value: " << currentNode->value << std::endl;
    if (currentNode->leftChild != nullptr && arrayMin <= currentNode->value) hasSequence(seq, length, currentNode->leftChild, sequenceCounter);

    if (length!= *(sequenceCounter)) {
        if (currentNode->value == seq[*sequenceCounter]) (*sequenceCounter)++;
        else (*sequenceCounter) = 0;
    }

    if (currentNode->rightChild != nullptr && arrayMax >= currentNode->value) hasSequence(seq, length, currentNode->rightChild, sequenceCounter);
}

bool BST::hasSequence(int *seq, int length) {
    int *sequenceCounter = new int(0);
    hasSequence(seq, length, headNode, sequenceCounter);
    bool res = ((*sequenceCounter) == length);
    delete sequenceCounter;
    return res;
}


