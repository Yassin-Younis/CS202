
/**
* Title: Binary Search Trees
* Author : Yassin Younis
* ID: 22101310
* Section : 2
* Homework : 2
*/


#include <iomanip>
#include "analysis.h"
using namespace std;
#include "iostream"
#include "BST.h"

void analysis::printDashedLine() {
    cout << "-----------------------------------------------------------------" <<endl;
}
void analysis::timeAnalysis() {
    BST testTree;

    int arrSize= 15000;
    int lapSize = 1500;
    int arr[arrSize];
    srand(time(NULL));
    for (int i = 0; i < arrSize; i++) {
        arr[i] = rand()%25000;
        //arr[i] = i;

    }


    cout << "Part e - Time analysis of Binary Search Tree - part 1" <<endl;
    printDashedLine();
    cout << "Tree Size" << setw(45) << "Time Elapsed" <<endl;
    printDashedLine();
    clock_t timeInstanceStart = clock();
    for (int i=0; i<arrSize; i++) {
        if ((i+1)%lapSize==0) {
            clock_t timeInstanceEnd = clock();
            cout << (i+1) << setw(43) <<   (timeInstanceEnd - timeInstanceStart) / (CLOCKS_PER_SEC/1000.0) << "ms" << endl;
            //timeInstanceStart = timeInstanceEnd;
        }
        testTree.insertItem(arr[i]);
    }
    printDashedLine();

    shuffleArray(arr, arrSize);

    cout << "Part e - Time analysis of Binary Search Tree - part 2" <<endl;
    printDashedLine();
    cout << "Tree Size" << setw(45) << "Time Elapsed" <<endl;
    printDashedLine();
    timeInstanceStart = clock();
    for (int i=0; i<arrSize; i++) {
        if ((i+1)%lapSize==0) {
            clock_t timeInstanceEnd = clock();
            cout << arrSize - (i+1) << setw(43) <<   (timeInstanceEnd - timeInstanceStart) / (CLOCKS_PER_SEC/1000.0) << "ms" << endl;
            //timeInstanceStart = timeInstanceEnd;
        }
        testTree.deleteItem(arr[i]);
    }
    printDashedLine();

}

void analysis::swap (int pInt[], int i0, int i1) {
    int temp = pInt[i0];
    pInt[i0] = pInt[i1];
    pInt[i1] = temp;
}

void analysis::shuffleArray(int pInt[], int size) {
    srand(time(NULL));
    for (int i=0; i<size*2; i++) {
        int randIndex0 = rand()%size;
        int randIndex1 = rand()%size;
        swap(pInt, randIndex0, randIndex1);
    }
}
