/**
* Title: Binary Search Trees
* Author : Yassin Younis
* ID: 22101310
* Section : 2
* Homework : 2
* Description : Contains merge method, and main method with test operations.
*/



#include "iostream"
#include "BST.h"
#include "analysis.h"

using namespace std;

BST* merge( BST& tree1, BST& tree2) {
    int tr1size= tree1.size;
    int* tree1array = tree1.inorderTraversal(tr1size);

    int tr2size= tree2.size;
    int* tree2array = tree2.inorderTraversal(tr2size);

    BST* res = new BST;
    for (int i=0; i<tr1size; i++) {
        res->insertItem(tree1array[i]);
    }

    for (int i=0; i<tr2size; i++) {
        res->insertItem(tree2array[i]);
    }

    delete [] tree1array;
    delete [] tree2array;

    return res;
}

int main() {
    analysis anal;
    anal.timeAnalysis();

    BST bst;
    bst.insertItem(8);
    bst.insertItem(4);
    bst.insertItem(13);
    bst.insertItem(15);
    bst.insertItem(12);
    bst.insertItem(10);
    bst.insertItem(14);
    bst.insertItem(3);
    bst.insertItem(6);
    bst.insertItem(5);
    bst.insertItem(1);
    bst.insertItem(2);

    int* arr0 = new int[6]{1, 2, 3, 4, 5, 6};
    int* arr1 = new int[4]{10, 12, 13, 15};
    int* arr2 = new int[3]{10, 11, 12};


    if (bst.hasSequence(arr0, 6)) std::cout << "arr0 is a subarray of the inorder traversal of the tree." << std::endl;
    else  std::cout << "arr0 is NOT a subarray of the inorder traversal of the tree."<< std::endl;

    if (bst.hasSequence(arr1, 4)) std::cout << "arr1 is a subarray of the inorder traversal of the tree."<< std::endl;
    else  std::cout << "arr1 is NOT a subarray of the inorder traversal of the tree."<< std::endl;

    if (bst.hasSequence(arr2, 3)) std::cout << "arr2 is a subarray of the inorder traversal of the tree."<< std::endl;
    else  std::cout << "arr2 is NOT a subarray of the inorder traversal of the tree."<< std::endl;

    delete [] arr0;
    delete [] arr1;
    delete [] arr2;

    BST bst1;
    bst1.insertItem(38);
    bst1.insertItem(5);
    bst1.insertItem(0);
    bst1.insertItem(1);
    bst1.insertItem(23);
    bst1.insertItem(4);

    BST* merged = merge(bst1, bst);
    int* mergedArr = merged->inorderTraversal(merged->size);


    cout << "merged array: " << endl;
    for (int i=0; i<merged->size; i++) {
        std::cout << mergedArr[i] <<", ";
    }

    delete merged;
    delete [] mergedArr;

    std::cout << std::endl;
}
