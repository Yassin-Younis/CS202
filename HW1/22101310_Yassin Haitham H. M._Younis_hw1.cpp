/**
* Title: Algorithm analysis & Sorting
* Author : Yassin Younis
* ID: 22101310
* Section : 2
* Homework : 1
* Description : Main class with helper methods to help in initialising
 * requested arrays and testing sorting algo's.
*/

#include <iostream>
#include <valarray>
#include <iomanip>

void swap(int *arr, const int index0, const int index1) {
    int temp = arr[index0];
    arr[index0] = arr[index1];
    arr[index1] = temp;
}
void insertionSort(int *arr, const int size, int &compCount, int &moveCount) {

    int sortedUntilIndex = 0;
    while (sortedUntilIndex!=size) {
        int selectedIndex = sortedUntilIndex;
        for (int i=sortedUntilIndex+1; i<size; i++) { compCount++; //for for-loop and if statement
            if (arr[i]<arr[selectedIndex]) {
                selectedIndex = i; // moveCount++;
            }
        }
        swap(arr, sortedUntilIndex, selectedIndex); moveCount+=3;
        sortedUntilIndex++;
    }
}
void bubbleSort(int *arr, const int size, int &compCount, int &moveCount) {

    for (int i=0; i<size; i++) {
        for (int j=i+1; j<size; j++) { compCount++;
            if (arr[j]<arr[i]) {
                swap(arr, i , j); moveCount+=3;
            }
        }
    }

}
void merge(int *arr, const int size, int &compCount, int &moveCount) {

    int leftPartitionPtr = 0;
    int leftPartitionSize = size/2;

    int rightPartitionPtr = size/2;
    int rightPartitionSize = size - leftPartitionSize;

    int tempArr[size];
    int tempArrPtr = 0;

    while (leftPartitionPtr < leftPartitionSize && rightPartitionPtr < size) {
        compCount++;
        if (arr[rightPartitionPtr]<arr[leftPartitionPtr]) {
            tempArr[tempArrPtr] = arr[rightPartitionPtr];
            rightPartitionPtr++;
        }
        else {
            tempArr[tempArrPtr] = arr[leftPartitionPtr];
            leftPartitionPtr++;
        }
        moveCount++;
        tempArrPtr++;
    }

    for (; leftPartitionPtr < leftPartitionSize; leftPartitionPtr++) {
        moveCount++;
        tempArr[tempArrPtr] = arr[leftPartitionPtr];
        tempArrPtr++;
    }

    for (; rightPartitionPtr < size; rightPartitionPtr++) {
        moveCount++;
        tempArr[tempArrPtr] = arr[rightPartitionPtr];
        tempArrPtr++;
    }

    for (int i=0; i<size; i++) {
        moveCount++;
        arr[i] = tempArr[i];
    }

}
void mergeSort(int *arr, const int size, int &compCount, int &moveCount) { // 3 8 5 0 1, 5
    if (size>1) {
        mergeSort(arr, size/2, compCount, moveCount);
        mergeSort(arr + size/2, size - size/2, compCount, moveCount);
        merge (arr, size, compCount, moveCount);
    }
}

int partition(int *arr, const int size, int &compCount, int &moveCount) {
    int pivot = arr[size-1];

    int noOfElementsBeforePivot = 0;
    for (int i=0; i < size-1; i++) {
        compCount++;
        if (arr[i]<pivot) {
            moveCount+=3;
            swap(arr, i, noOfElementsBeforePivot);
            noOfElementsBeforePivot++;
        }
    }
    moveCount+=3;
    swap(arr, noOfElementsBeforePivot, size-1);

    return noOfElementsBeforePivot;
}
void quickSort(int *arr, const int size, int &compCount, int &moveCount) {
    if (size > 1) {
        int pivot = partition(arr, size, compCount, moveCount);
        quickSort(arr, pivot, compCount, moveCount);
        quickSort(arr+pivot+1, size - pivot - 1, compCount, moveCount);
    }
}
void hybridSort(int *arr, const int size, int &compCount, int &moveCount) {
    if (size > 1) {
        int pivot = partition(arr, size, compCount, moveCount);

        if (pivot>20) hybridSort(arr, pivot, compCount, moveCount);
        else bubbleSort(arr, pivot, compCount, moveCount);

        if (pivot>20) hybridSort(arr+pivot+1, size - pivot, compCount, moveCount);
        else bubbleSort(arr+pivot, size - pivot, compCount, moveCount);
    }
}



//int partition2(int* arr, int low, int high)
//{
//    int pivot = arr[high]; // pivot
//    int i
//            = (low
//               - 1); // Index of smaller element and indicates
//    // the right position of pivot found so far
//
//    for (int j = low; j <= high - 1; j++) {
//        // If current element is smaller than the pivot
//        if (arr[j] < pivot) {
//            i++; // increment index of smaller element
//            swap(arr, i, j);
//        }
//    }
//    swap(arr, i + 1, high);
//    return (i + 1);
//}
//
///* The main function that implements QuickSort
//arr[] --> Array to be sorted,
//low --> Starting index,
//high --> Ending index */
//void quickSort2(int* arr, int low, int high)
//{
//    if (low < high) {
//        /* pi is partitioning index, arr[p] is now
//        at right place */
//        int pi = partition2(arr, low, high);
//
//        // Separately sort elements before
//        // partition and after partition
//        quickSort2(arr, low, pi - 1);
//        quickSort2(arr, pi + 1, high);
//    }
//}




void randomizeArr(int*& arr1, int*& arr2, int*& arr3, int*& arr4, int*& arr5, int order, int SIZE) {
    // if order is 1=ascending, 0=random, -1=descending

    srand(time(nullptr));
    arr1 = new int[SIZE];
    arr2 = new int[SIZE];
    arr3 = new int[SIZE];
    arr4 = new int[SIZE];
    arr5 = new int[SIZE];

    int logOfSize = log2(SIZE);
    for (int i = 0; i < SIZE; i++) {
        if (order==0) {
            int val = rand() % SIZE;
            arr1[i] = val;
            arr2[i] = val;
            arr3[i] = val;
            arr4[i] = val;
            arr5[i] = val;
        }
        else if (order == 1) {
            int partition = (i/logOfSize);
            int val = (rand()%SIZE) + (partition)*SIZE;
            arr1[i] = val;
            arr2[i] = val;
            arr3[i] = val;
            arr4[i] = val;
            arr5[i] = val;
        }
        else if (order == -1) {
            int partition = (i/logOfSize);
            int val = (rand()%SIZE) + (partition)*SIZE;
            arr1[SIZE-1-i] = val;
            arr2[SIZE-1-i] = val;
            arr3[SIZE-1-i] = val;
            arr4[SIZE-1-i] = val;
            arr5[SIZE-1-i] = val;
        }
        else {
            std::cout << "Invalid Order" << std::endl;
            return;
        }
    }

}

void printArray(int* arr, int size) {
    for (int i=0;i <size; i++) {
        std::cout << arr[i] << ", ";
    }
    std::cout<< std::endl;
}

int main() {

    int* arr1;
    int compCount1 = 0, moveCount1 = 0;

    int* arr2;
    int compCount2 = 0, moveCount2 = 0;

    int* arr3;
    int compCount3 = 0, moveCount3 = 0;

    int* arr4;
    int compCount4 = 0, moveCount4 = 0;

    int* arr5;
    int compCount5 = 0, moveCount5 = 0;

    clock_t start;
    double elapsed;

    int SIZES[] = {1000, 5000, 10000, 20000};
    int SIZE;


    std::cout << "Part 2-b-1: Performance analysis of random integers array"<<std::endl;
    std::cout << "--------------------------------------------------------------------------------------------------------------------------------------"<<std::endl;
    std::cout << std::setw(40) <<"Elapsed time" << std::setw(40) << "Comp. count" << std::setw(40) << "Move count"<<std::endl;

    for (int i=0; i<4; i++) {
        SIZE = SIZES[i];
        randomizeArr(arr1, arr2, arr3, arr4, arr5, 0, SIZE);
        std::cout << "Array Size: " << SIZE << std::endl;

        start = clock();
        insertionSort(arr1,SIZE,compCount1, moveCount1);
        elapsed = (double)(clock() - start) / (CLOCKS_PER_SEC/1000);
        std::cout << "Insertion Sort" <<std::setw(24) <<elapsed<<"ms" << std::setw(40) << compCount1 << std::setw(40) << moveCount1<<std::endl;

        start = clock();
        bubbleSort(arr2,SIZE,compCount2, moveCount2);
        elapsed = (double)(clock() - start) / (CLOCKS_PER_SEC/1000);
        std::cout << "Bubble Sort" <<std::setw(27) <<elapsed<<"ms" << std::setw(40) << compCount2 << std::setw(40) << moveCount2<<std::endl;

        start = clock();
        mergeSort(arr3,SIZE,compCount3, moveCount3);
        elapsed = (double)(clock() - start) / (CLOCKS_PER_SEC/1000);
        std::cout << "Merge Sort" <<std::setw(28) <<elapsed<<"ms" << std::setw(40) << compCount3 << std::setw(40) << moveCount3<<std::endl;

        start = clock();
        quickSort(arr4,SIZE,compCount4, moveCount4);
        elapsed = (double)(clock() - start) / (CLOCKS_PER_SEC/1000);
        std::cout << "Quick Sort" <<std::setw(28) <<elapsed<<"ms" << std::setw(40) << compCount4 << std::setw(40) << moveCount4<<std::endl;

        start = clock();
        hybridSort(arr5,SIZE,compCount5, moveCount5);
        elapsed = (double)(clock() - start) / (CLOCKS_PER_SEC/1000);
        std::cout << "Hybrid Sort" <<std::setw(27) <<elapsed<<"ms" << std::setw(40) << compCount5 << std::setw(40) << moveCount5<<std::endl;

        std::cout << "--------------------------------------------------------------------------------------------------------------------------------------"<<std::endl;

        delete [] arr1;
        delete [] arr2;
        delete [] arr3;
        delete [] arr4;
        delete [] arr5;
    }


    std::cout << "Part 2-b-2: Performance analysis of partially ascending integers array"<<std::endl;
    std::cout << "--------------------------------------------------------------------------------------------------------------------------------------"<<std::endl;
    std::cout << std::setw(40) <<"Elapsed time" << std::setw(40) << "Comp. count" << std::setw(40) << "Move count"<<std::endl;

    for (int i=0; i<4; i++) {
        SIZE = SIZES[i];
        randomizeArr(arr1, arr2, arr3, arr4, arr5, 1, SIZE);
        std::cout << "Array Size: " << SIZE << std::endl;

        start = clock();
        insertionSort(arr1,SIZE,compCount1, moveCount1);
        elapsed = (double)(clock() - start) / (CLOCKS_PER_SEC/1000);
        std::cout << "Insertion Sort" <<std::setw(24) <<elapsed<<"ms" << std::setw(40) << compCount1 << std::setw(40) << moveCount1<<std::endl;

        start = clock();
        bubbleSort(arr2,SIZE,compCount2, moveCount2);
        elapsed = (double)(clock() - start) / (CLOCKS_PER_SEC/1000);
        std::cout << "Bubble Sort" <<std::setw(27) <<elapsed<<"ms" << std::setw(40) << compCount2 << std::setw(40) << moveCount2<<std::endl;

        start = clock();
        mergeSort(arr3,SIZE,compCount3, moveCount3);
        elapsed = (double)(clock() - start) / (CLOCKS_PER_SEC/1000);
        std::cout << "Merge Sort" <<std::setw(28) <<elapsed<<"ms" << std::setw(40) << compCount3 << std::setw(40) << moveCount3<<std::endl;

        start = clock();
        quickSort(arr4,SIZE,compCount4, moveCount4);
        elapsed = (double)(clock() - start) / (CLOCKS_PER_SEC/1000);
        std::cout << "Quick Sort" <<std::setw(28) <<elapsed<<"ms" << std::setw(40) << compCount4 << std::setw(40) << moveCount4<<std::endl;

        start = clock();
        hybridSort(arr5,SIZE,compCount5, moveCount5);
        elapsed = (double)(clock() - start) / (CLOCKS_PER_SEC/1000);
        std::cout << "Hybrid Sort" <<std::setw(27) <<elapsed<<"ms" << std::setw(40) << compCount5 << std::setw(40) << moveCount5<<std::endl;

        std::cout << "--------------------------------------------------------------------------------------------------------------------------------------"<<std::endl;
        delete [] arr1;
        delete [] arr2;
        delete [] arr3;
        delete [] arr4;
        delete [] arr5;
    }


    std::cout << "Part 2-b-3: Performance analysis of partially descending integers array"<<std::endl;
    std::cout << "--------------------------------------------------------------------------------------------------------------------------------------"<<std::endl;
    std::cout << std::setw(40) <<"Elapsed time" << std::setw(40) << "Comp. count" << std::setw(40) << "Move count"<<std::endl;
    for (int i=0; i<4; i++) {
        SIZE = SIZES[i];
        randomizeArr(arr1, arr2, arr3, arr4, arr5, -1, SIZE);
        std::cout << "Array Size: " << SIZE << std::endl;

        start = clock();
        insertionSort(arr1,SIZE,compCount1, moveCount1);
        elapsed = (double)(clock() - start) / (CLOCKS_PER_SEC/1000);
        std::cout << "Insertion Sort" <<std::setw(24) <<elapsed<<"ms" << std::setw(40) << compCount1 << std::setw(40) << moveCount1<<std::endl;

        start = clock();
        bubbleSort(arr2,SIZE,compCount2, moveCount2);
        elapsed = (double)(clock() - start) / (CLOCKS_PER_SEC/1000);
        std::cout << "Bubble Sort" <<std::setw(27) <<elapsed<<"ms" << std::setw(40) << compCount2 << std::setw(40) << moveCount2<<std::endl;

        start = clock();
        mergeSort(arr3,SIZE,compCount3, moveCount3);
        elapsed = (double)(clock() - start) / (CLOCKS_PER_SEC/1000);
        std::cout << "Merge Sort" <<std::setw(28) <<elapsed<<"ms" << std::setw(40) << compCount3 << std::setw(40) << moveCount3<<std::endl;

        start = clock();
        quickSort(arr4,SIZE,compCount4, moveCount4);
        //quickSort2(arr4,0,SIZE-1);
        elapsed = (double)(clock() - start) / (CLOCKS_PER_SEC/1000);
        std::cout << "Quick Sort" <<std::setw(28) <<elapsed<<"ms" << std::setw(40) << compCount4 << std::setw(40) << moveCount4<<std::endl;

        start = clock();
        hybridSort(arr5,SIZE,compCount5, moveCount5);
        elapsed = (double)(clock() - start) / (CLOCKS_PER_SEC/1000);
        std::cout << "Hybrid Sort" <<std::setw(27) <<elapsed<<"ms" << std::setw(40) << compCount5 << std::setw(40) << moveCount5<<std::endl;

        std::cout << "--------------------------------------------------------------------------------------------------------------------------------------"<<std::endl;

        delete [] arr1;
        delete [] arr2;
        delete [] arr3;
        delete [] arr4;
        delete [] arr5;
    }





    return 0;
}