/**
* Title: Balanced search trees and hashing
* Author : Yassin Younis
* ID: 22101310
* Section : 2
* Homework : 4
* Description : Handles most of the logic.
*/

#ifndef INC_202_4_KINDERGARTEN_H
#define INC_202_4_KINDERGARTEN_H

#include <string>
#include "Yassin_Younis_22101310_Snack.h"
#include "Yassin_Younis_22101310_AccompanimentHashing.h"
#include "Yassin_Younis_22101310_SnackHashing.h"

class Kindergarten {
public:
    void matchSnacks(const std::string &firstSnackName, const std::string &secondSnackName) {
        if (firstSnackName == secondSnackName)
            return; //• A snack is grouped or ungrouped with itself (i.e: D Apple Apple or C Cheese Cheese). In this case, theprogram should do nothing; it should not add the snack to his own accompaniments/group.

        std::string name;

        if (firstSnackName < secondSnackName) {
            name = firstSnackName + secondSnackName;
        } else {
            name = secondSnackName + firstSnackName;
        }
        if (ah.contains(name)) {
            std::cout << "Accompaniment already exists." << std::endl;
            return;
        }
        if (!sh.contains(firstSnackName) || !sh.contains(secondSnackName)) {
            std::cout << "One of the snacks doesnt exist." << std::endl;
            return;
        }

        Snack &firstSnack = sh.get(firstSnackName);
        Snack &secondSnack = sh.get(secondSnackName);
        firstSnack.accompaniments.push_front(secondSnack);
        secondSnack.accompaniments.push_front(firstSnack);
        if (firstSnackName < secondSnackName) {
            Accompaniment accompaniment(&firstSnack, &secondSnack);
            ah.insert(accompaniment);
        }
        else {
            Accompaniment accompaniment(&secondSnack, &firstSnack);
            ah.insert(accompaniment);
        }

    }

    void unMatchSnacks(const std::string &firstSnackName, const std::string &secondSnackName) {
        if (firstSnackName == secondSnackName)
            return; //• A snack is grouped or ungrouped with itself (i.e: D Apple Apple or C Cheese Cheese). In this case, the program should do nothing; it should not add the snack to his own accompaniments/group.
        if (!sh.contains(firstSnackName) || !sh.contains(secondSnackName)) {
            std::cout << "One of the snacks doesnt exist." << std::endl;
            return;
        }

        std::string name;
        if (firstSnackName < secondSnackName) {
            name = firstSnackName + secondSnackName;
            if (!ah.contains(name)) return;
            Accompaniment &temp = ah.get(name);
            temp.firstSnack->accompaniments.remove(secondSnackName);
            temp.secondSnack->accompaniments.remove(firstSnackName);
        } else {
            name = secondSnackName + firstSnackName;
            if (!ah.contains(name)) return;
            Accompaniment &temp = ah.get(name);
            temp.firstSnack->accompaniments.remove(firstSnackName);
            temp.secondSnack->accompaniments.remove(secondSnackName);
        }

        ah.remove(name);
    }

    void listMatches(const std::string &snackName) {
        if (!sh.contains(snackName)) return;
        sh.get(snackName).list();
    }

    void createSnack(const std::string &snackName) {
        if (sh.contains(snackName)) return;
        sh.insert(Snack(snackName));
        std::cout << "Snack ‘" << snackName << "’ created" << std::endl;
    }

    void isAccompaniment(std::string firstSnackName, std::string secondSnackName) {
        std::string name;

        if (firstSnackName < secondSnackName) {
            name = firstSnackName + secondSnackName;
        } else {
            name = secondSnackName + firstSnackName;
        }
        if (ah.contains(name)) {
            std::cout << "Yes" << std::endl;
        } else std::cout << "No" << std::endl;
    }

private:
    SnackHashing sh;
    AccompanimentHashing ah;

};

#endif //INC_202_4_KINDERGARTEN_H
