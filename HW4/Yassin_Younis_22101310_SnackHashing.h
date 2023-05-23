/**
* Title: Balanced search trees and hashing
* Author : Yassin Younis
* ID: 22101310
* Section : 2
* Homework : 4
*  Description : Snack Hashtable.
*/

#ifndef INC_202_4_SNACKHASHING_H
#define INC_202_4_SNACKHASHING_H
#include "Yassin_Younis_22101310_Snack.h"
#include <algorithm>

class SnackHashing {
public:
    void insert(const Snack& snack) {
        int bucketIndex = hash(snack.snackName);
        arr[bucketIndex].add(snack);

    }

    bool contains(const std::string &key) {
        int bucketIndex = hash(key);
        return arr[bucketIndex].contains(Snack(key));
    }

    Snack& get(const std::string& key) {
        int bucketIndex = hash(key);
        if (contains(key)) return arr[bucketIndex].get(Snack(key));
    }

    int hash(const std::string &key) {
        int ascii_sum = 0;
        for (char i: key) {
            ascii_sum += toascii(i);
        }
        return (ascii_sum % 11);
    }

private:
    LinkedList<Snack> arr[11];
};


#endif
