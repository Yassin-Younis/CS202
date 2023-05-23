/**
* Title: Balanced search trees and hashing
* Author : Yassin Younis
* ID: 22101310
* Section : 2
* Homework : 4
* Description : Accompaniment object.
*/


#ifndef INC_202_4_ACCOMPANIMENT_H
#define INC_202_4_ACCOMPANIMENT_H

#include <string>
#include "Yassin_Younis_22101310_Snack.h"

struct Accompaniment {
    Accompaniment(Snack *firstSnack, Snack *secondSnack) : firstSnack(firstSnack), secondSnack(secondSnack) {

        if (firstSnack->snackName < secondSnack->snackName) {
            name = firstSnack->snackName + secondSnack->snackName;
        } else {
            name = secondSnack->snackName + firstSnack->snackName;
        }
    }

    Accompaniment(const std::string inName): name(inName) {
    }

    ~Accompaniment() {

    }

    bool operator==(const Accompaniment& other) const {
        return name == other.name;
    }

    bool operator!=( const Accompaniment& other) const {
        return name != other.name;
    }

    std::string name;
    Snack *firstSnack;
    Snack *secondSnack;
};

#endif
