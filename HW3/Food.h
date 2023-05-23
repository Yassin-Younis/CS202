/**
* Author : Yassin Younis
* ID: 22101310
* Section : 002
* Homework : 3
* Description : Food object class
*/


#ifndef INC_202_3_FOOD_H
#define INC_202_3_FOOD_H

#include <iostream>
#include <iomanip>

class Food {
public:
    Food() {};
    Food(int id, double x, double y, int quality, int spawnTime): id(id), x(x), y(y), quality(quality), spawnTime(spawnTime) {}

    double x, y;
     int id;
     int quality;
     int spawnTime;
     bool sortByTime = true;

     void sortByQuality() {
         sortByTime = false;
     }

    // Comparison operators based on spawnTime
    bool operator<(const Food& other) const {
        if (sortByTime) return spawnTime > other.spawnTime;
        else {
            if (quality==other.quality) return id > other.id;
            else return quality < other.quality;
        }
    }

    bool operator>(const Food& other) const {
        if (sortByTime) return spawnTime < other.spawnTime;
        else {
            if (quality==other.quality) return id < other.id;
            else return quality > other.quality;
        }
    }

    // Printing operator to work like toString()
    friend std::ostream& operator<<(std::ostream& os, const Food& food) {
        os << "Food " << food.id << ": "
           << std::fixed << std::setprecision(2) << food.x << ", "
           << std::fixed << std::setprecision(2) << food.y << std::endl;
        return os;
    }
};

#endif
