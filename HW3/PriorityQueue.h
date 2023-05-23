/**
* Author : Yassin Younis
* ID: 22101310
* Section : 002
* Homework : 3
* Description : Custom implementation of PriorityQueue
*/

#ifndef INC_202_3_PRIORITYQUEUE_H
#define INC_202_3_PRIORITYQUEUE_H

template<typename obj>
class PriorityQueue {
public:
    PriorityQueue() {
        max_size = 3;
        current_size = 0;
        heap_array = new obj[max_size];
    }

    ~PriorityQueue() {
        delete [] heap_array;
    }

    void heapRebuild(int root) {
        int child = 2 * root + 1;
        if (child < current_size) {
            int rightChild = child + 1;
            if ((rightChild < current_size) &&
                (heap_array[rightChild] > heap_array[child]))
                child = rightChild;
            if (heap_array[root] < heap_array[child]) {
                obj temp = heap_array[root];
                heap_array[root] = heap_array[child];
                heap_array[child] = temp;
                heapRebuild(child);
            }
        }
    }

    void remove() {
        if (current_size > 0) {
            heap_array[0] = heap_array[--current_size];
            heapRebuild(0);
        }
        else std::cout << "Heap is empty!" << std::endl;
    }

    void heapPrint() {
        for (int i=0; i<current_size; i++) {
            std::cout << heap_array[i];
        }
        std::cout << std::endl;
    }

    void insert(obj entry) {
        if (current_size == max_size) extendHeap();

        heap_array[current_size] = entry;
        int entry_index = current_size;
        int parent_index = (entry_index - 1) / 2;

        while (entry_index > 0 && heap_array[parent_index] < heap_array[entry_index]) {
            obj swap_temp = heap_array[parent_index];
            heap_array[parent_index] = heap_array[entry_index];
            heap_array[entry_index] = swap_temp;
            entry_index = parent_index;
            parent_index = (entry_index - 1) / 2;
        }

        current_size++;

    }

    void extendHeap() {
        obj *new_heap = new obj[max_size * 2];
        for (int i = 0; i < current_size; i++) {
            new_heap[i] = heap_array[i];
        }
        delete[] heap_array;
        max_size *= 2;
        heap_array = new_heap;
    }

    obj peek() {
        return heap_array[0];
    }

    obj pop() {
        obj temp_return =  heap_array[0];
        remove();
        return temp_return;
    }

    int current_size;
private:
    int max_size;
    obj *heap_array;
};

#endif
