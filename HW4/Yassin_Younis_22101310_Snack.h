/**
* Title: Balanced search trees and hashing
* Author : Yassin Younis
* ID: 22101310
* Section : 2
* Homework : 4
*  Description : Snack Object.
*/

#ifndef INC_202_4_SNACK_H
#define INC_202_4_SNACK_H

#include <string>
#include <list>
#include <iostream>
#include "Yassin_Younis_22101310_LinkedList.h"

struct Snack {
    Snack(const std::string& snackName) : snackName(snackName) {}

    Snack(Snack const &snack) {
        accompaniments = snack.accompaniments;
        snackName = snack.snackName;
    }
    Snack() {

    }

    bool operator==( const Snack& other) const {
        return snackName == other.snackName;
    }

    bool operator!=( const Snack& other) const {
        return snackName == other.snackName;
    }


    std::list<Snack> accompaniments;
    std::string snackName;

    void list() {
        for (auto& it : accompaniments) {
            std::cout << it.snackName << " ";
        }
        std::cout << std::endl;
    }
};

#endif