/**
* Title: Balanced search trees and hashing
* Author : Yassin Younis
* ID: 22101310
* Section : 2
* Homework : 4
* Description : My linked list class from HW3 last semester
*/

#ifndef INC_202_4_YASSIN_YOUNIS_22101310_LINKEDLIST_H
#define INC_202_4_YASSIN_YOUNIS_22101310_LINKEDLIST_H

#include <ostream>
#include <iostream>

template<class object>
struct Node {
    object obj;
    Node<object> *next;


    Node(object obj) : obj(obj), next(nullptr) {}


};

template<class object>
class LinkedList {
public:
    LinkedList() : mCount(0), pHead(nullptr) {}

    ~LinkedList() {
        Node<object> *temp0 = pHead;
        Node<object> *temp1;
        for (int i = 0; i < mCount; i++) {
            temp1 = temp0->next;
            delete temp0;
            temp0 = temp1;
        }
    }

    void add(object entry) {
        Node<object> *temp = pHead;
        pHead = new Node<object>(entry);
        pHead->next = temp;
        mCount++;
    }

    void remove(object entry) {
        Node<object> *temp0 = pHead;
        Node<object> *temp1 = pHead;

        if ((temp0->obj) == entry)  //if entry to remove is the first element.
        {
            pHead = pHead->next;
            delete temp0;
            mCount--;
        } else {
            while (temp1->next != nullptr && (temp1->next->obj) != entry) {
                temp1 = temp1->next;
            }

            if (temp1->next == nullptr) return; //item doesnt exist

            temp0 = temp1->next->next;
            delete temp1->next;

            temp1->next = temp0;
            mCount--;

        }
    }

    bool contains(object entry) {
        if (mCount > 0) {
            Node<object> *temp = pHead;
            while (temp->next != nullptr) {
                if ((temp->obj) == entry) {
                    return true;
                }
                temp = temp->next;
            }
            if ((temp->obj) == entry) {
                return true;
            }
        }
        return false;
    }

    object& get(int pos) const {
        Node<object> *temp = pHead;
        if (pos >= mCount) {
            std::cout << "Index out of bounds" << std::endl;
        } else {
            for (int i = 0; i < pos; i++) {
                temp = temp->next;
            }

            return ((temp->obj));
        }
    }

    object& get(object obj) const {
        for (int i = 0; i < mCount; i++) {
            if (get(i) == obj) {
                return get(i);
            }
        }
    }

    int mCount;
private:
    Node<object> *pHead;
};


#endif //INC_202_4_YASSIN_YOUNIS_22101310_LINKEDLIST_H
