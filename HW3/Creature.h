/**
* Author : Yassin Younis
* ID: 22101310
* Section : 002
* Homework : 3
* Description : Creature object class.
*/

#ifndef INC_202_3_CREATURE_H
#define INC_202_3_CREATURE_H

#include <iomanip>

class Creature {
public:
    Creature(int id, double x, double y, int health) : id(id), x(x), y(y), health(health) {}

    friend std::ostream& operator<<(std::ostream& os, const Creature& creature) {
        os << "Creature " << creature.id << ": "
           << std::fixed << std::setprecision(2) << creature.x << ", "
           << std::fixed << std::setprecision(2) << creature.y << std::endl;
        return os;
    }

    friend bool operator<(const Creature& lhs, const Creature& rhs) {
        return lhs.id < rhs.id;
    }

    friend bool operator>(const Creature& lhs, const Creature& rhs) {
        return lhs.id > rhs.id;
    }

    double x, y;
    int id, health;
    bool alive = true;

    void healthDeduct() {
        health-=1;
        if (health<=0) kill();
    }

    void kill() {
        alive = false;
    }
};

#endif
