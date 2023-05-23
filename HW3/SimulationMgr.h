/**
* Author : Yassin Younis
* ID: 22101310
* Section : 002
* Homework : 3
* Description : h file for simulation manager class.
*/
#ifndef INC_202_3_SIMULATIONMGR_H
#define INC_202_3_SIMULATIONMGR_H

#include <vector>
#include "iostream"
#include "Creature.h"
#include "Food.h"
#include "PriorityQueue.h"


class SimulationMgr {
public:
    SimulationMgr(std::string dataFilePath);
    void advance();
    void printState();
    void spawnFood();
private:
    PriorityQueue<Food> queued_food;
    PriorityQueue<Food> current_food;
    std::vector<Creature> creatures;
    int current_time = 0;
//    Creature creatures[];
//    Food foods[];
    void killSurroundings(Creature &creature);

    double euclideanDistance(Creature &creature, Creature &creature1);

    void eatSurroundings(Creature &creature);

    double euclideanDistance(Creature &first, Food &second);

    bool areCreaturesAlive();

    void move(Creature &creature);
};


#endif
