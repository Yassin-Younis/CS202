/**
* Title: Balanced search trees and hashing
* Author : Yassin Younis
* ID: 22101310
* Section : 2
* Homework : 4
*  Description : Accompaniment Hashtable.
*/

#ifndef INC_202_4_ACCOMPANIMENTHASHING_H
#define INC_202_4_ACCOMPANIMENTHASHING_H

#include "Yassin_Younis_22101310_Accompaniment.h"
#include "Yassin_Younis_22101310_LinkedList.h"
#include <algorithm>

class AccompanimentHashing {
public:
    ~AccompanimentHashing() {

    }

    void insert(const Accompaniment& accompaniment) {
        int bucketIndex = hash(accompaniment.name);
        arr[bucketIndex].add(accompaniment);
    }

    void remove(const std::string &key) {
        int bucketIndex = hash(key);
        arr[bucketIndex].remove(get(key));
    }

    bool contains(const std::string &key) {
        int bucketIndex = hash(key);
        return arr[bucketIndex].contains(Accompaniment(key));
    }

    Accompaniment& get(const std::string& key) {
        int bucketIndex = hash(key);
        if (contains(key)) return arr[bucketIndex].get(Accompaniment(key));
    }

    int hash(const std::string &key) {
        int ascii_sum = 0;
        for (char i: key) {
            ascii_sum += toascii(i);
        }
        return (ascii_sum % 11);
    }
private:
    //std::list<Accompaniment> arr[71];
    LinkedList<Accompaniment> arr[71];

};
#endif
