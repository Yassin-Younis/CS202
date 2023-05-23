/**
* Title: Balanced search trees and hashing
* Author : Yassin Younis
* ID: 22101310
* Section : 2
* Homework : 4
* Description : Main, includes code to read commands.
*/

#include <iostream>
#include <sstream>
#include "Yassin_Younis_22101310_Kindergarten.h"

int main() {
    Kindergarten kg;
    std::string userInput;
    std::getline(std::cin, userInput);

    while (userInput[0] != 'X') {
        std::istringstream iss(userInput);
        char userCommand;
        iss >> userCommand;

        switch (userCommand) {
            case ('S'): {
                std::string args0;
                iss >> args0;
                kg.createSnack(args0);

                break;
            }
            case 'C': {
                std::string args0, args1;
                iss >> args0 >> args1;
                kg.matchSnacks(args0, args1);
                break;
            }
            case 'D': {
                std::string args0, args1;
                iss >> args0 >> args1;
                kg.unMatchSnacks(args0, args1);
                break;
            }
            case ('L'): {
                std::string args0;
                iss >> args0;
                kg.listMatches(args0);
                break;
            }
            case 'Q': {
                std::string args0, args1;
                iss >> args0 >> args1;
                kg.isAccompaniment(args0, args1);
                break;
            }
        }

        std::getline(std::cin, userInput);
    }

//    LinkedList<char> ls;
//    ls.add('a');
//    ls.add('b');
//    ls.remove('b');
//    ls.get(0);
    return 0;
}








